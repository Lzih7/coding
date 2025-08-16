class Solution {
public:
    /* BFS遍历求最长路径 */
    int findLongestNode(int u, vector<int>& parent, vector<vector<int>>& adj) {
        int n = adj.size();
        queue<int> q;
        q.push(u);
        vector<bool> vis(n, false);
        vis[u] = true;
        int node = -1;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            node = curr;
            for (auto& v : adj[curr]) {
                if (!vis[v]) {
                    vis[v] = true;
                    parent[v] = curr;
                    q.push(v);
                }
            }
        }
        return node;
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) {
            return {0};
        }
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> parent(n, -1);
        int x = findLongestNode(0, parent, adj);
        int y = findLongestNode(x, parent, adj);
        vector<int> path;
        parent[x] = -1;
        while (y != -1) {
            path.push_back(y);
            y = parent[y];
        }
        int m = path.size();
        if(m % 2 == 0) {
            return {path[m / 2 - 1], path[m / 2]};
        } else {
            return {path[m / 2]};
        }
    }
};