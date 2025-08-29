#include <stdio.h>
#include <stdbool.h>

#define MAX_N 100001  // 定义最大人数

int n;               // 人数
int a[MAX_N];        // 存储每个小朋友崇拜的对象
bool visited[MAX_N]; // 标记是否访问过某个小朋友
int max_circle = 0;  // 记录最大圈的长度

// 深度优先搜索函数
void dfs(int current, int start, int depth) {
    // 如果当前节点已经访问过，说明可能形成了一个圈
    if (visited[current]) {
        // 如果当前节点指向的起始节点，说明是一个完整的圈
        if (current == start) {
            // 更新最大圈的长度
            if (depth > max_circle) {
                max_circle = depth;
            }
        }
        return;
    }

    // 标记当前节点为已访问
    visited[current] = true;
    // 递归访问下一个节点
    dfs(a[current], start, depth + 1);
    visited[current] = false;
}

int main() {
    // 输入人数
    scanf("%d", &n);

    // 输入每个小朋友崇拜的对象
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    // 对每个小朋友作为起点进行DFS搜索
    for (int i = 1; i <= n; i++) {
        // 如果当前小朋友未被访问过，则进行DFS
        if (!visited[i]) {
            dfs(i, i, 0);  // 从当前小朋友开始搜索，初始深度为0
        }
    }

    // 输出最大圈的长度
    printf("%d\n", max_circle);

    return 0;
}