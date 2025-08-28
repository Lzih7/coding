// 本文件核心使用到的 <cmath> 函数与返回值类型：
// sin/cos/tanh/sqrt/hypot(double) -> double
// 其余为 STL 算法与向量容器操作
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

// 拟合 y = a*sin(bx+c) + d 的一个简单打分
int main() {
    vector<double> xs, ys;
    for (int i = 0; i <= 100; ++i) {
        double x = i * 0.06283185307; // ~ pi/50
        double y = 2.0 * sin(3.0*x + 0.5) + 1.0 + 0.1 * sin(50*x); // 加了高频噪声
        xs.push_back(x);
        ys.push_back(y);
    }

    // 平滑去噪: 简单滑动平均
    vector<double> smooth(ys.size());
    int k = 2;
    for (size_t i = 0; i < ys.size(); ++i) {
        double s = 0; int cnt = 0;
        for (int j = -k; j <= k; ++j) {
            int t = (int)i + j;
            if (t >= 0 && t < (int)ys.size()) { s += ys[t]; ++cnt; }
        }
        smooth[i] = s / cnt;
    }

    // 统计特征
    double mean = 0.0;
    for (double v : smooth) mean += v; mean /= smooth.size();
    double var = 0.0;
    for (double v : smooth) var += (v-mean)*(v-mean); var /= smooth.size();
    double stddev = sqrt(var);

    cout << "mean=" << mean << ", stddev=" << stddev << "\n";
    cout << "hypot(mean, stddev)=" << hypot(mean, stddev) << "\n";

    // 对每个值做标准化和非线性变换
    double score = 0.0;
    for (size_t i = 0; i < xs.size(); ++i) {
        double z = (smooth[i] - mean) / stddev;
        // 使用 tanh 做压缩
        score += tanh(z) * cos(xs[i]);
    }
    cout << "score=" << score << "\n";
    return 0;
}