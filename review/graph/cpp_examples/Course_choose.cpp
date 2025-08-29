class Solution {
private:
    vector<vector<int>> graph;
    vector<int> vis; // 0, 1, 2三个值可减少一个数组
    vector<int> res; // 相当于一个栈
    bool valid = true;

public:
    void dfs(int u) {
        vis[u] = 1;
        for (int v : graph[u]) {
            if (vis[v] == 0) {
                dfs(v);
                if (!valid) {
                    return;
                }
            } else if (vis[v] == 1) {
                valid = false;
                return;
            }
        }
        vis[u] = 2;
        res.push_back(u); // 后序位置
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        graph = vector<vector<int>>(numCourses);
        vis = vector<int>(numCourses);
        for (auto& info : prerequisites) {
            graph[info[1]].emplace_back(info[0]);
        }
        for (int i = 0; i < numCourses && valid; i++) {
            if (!vis[i]) {
                dfs(i);
            }
        }
        if (!valid) {
            return {};
        }
        reverse(res.begin(), res.end()); // 反转结果
        return res;
    }
};