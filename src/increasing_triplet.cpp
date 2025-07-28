#include <bits/stdc++.h>
using namespace std;

// 返回第一个大于 num 的元素的索引
int findnum_up(vector<int>& vec, int num) {
    int l = 0, r = vec.size();
    while (l < r) {
        int mid = (l + r) / 2;
        if (vec[mid] > num) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return r;
}

// 返回最后一个小于 num 的元素的索引（保持 l < r 条件）
int findnum_down(vector<int>& vec, int num) {
    int l = 0, r = vec.size() - 1; // 修正：r 初始化为 vec.size()-1
    while (l < r) {
        int mid = (l + r + 1) / 2; // 上取整，防止死循环
        if (vec[mid] < num) {
            l = mid; // 向右收缩区间
        } else {
            r = mid - 1; // 向左收缩区间
        }
    }
    return (vec[l] < num) ? l : -1; // 最终检查是否满足条件
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) cin >> c[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[0] >= b[i]) continue; // 保证至少存在一个 a[j] < b[i]
        if (c[n-1] <= b[i]) break;

        int j = findnum_down(a, b[i]);
        int k = findnum_up(c, b[i]);
        ans += (long long)(j + 1) * (n - k);
    }
    cout << ans;
    return 0;
}