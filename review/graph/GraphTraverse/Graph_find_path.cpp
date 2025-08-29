// 下面的算法代码可以遍历图的所有路径，寻找从 src 到 dest 的所有路径

// onPath 和 path 记录当前递归路径上的节点
vector<bool> onPath(graph.size());
list<int> path;

void traverse(Graph& graph, int src, int dest) {
    // base case
    if (src < 0 || src >= graph.size()) {
        return;
    }
    if (onPath[src]) {
        // 防止死循环（成环）
        return;
    }
    if (src == dest) {
        // 找到目标节点
        cout << "find path: ";
        for (auto it = path.begin(); it != path.end(); it++) {
            cout << *it << "->";
        }
        cout << dest << endl;
        return;
    }

    // 前序位置
    onPath[src] = true;
    path.push_back(src);
    for (const Edge& e : graph.neighbors(src)) {
        traverse(graph, e.to, dest);
    }
    // 后序位置
    path.pop_back();
    onPath[src] = false;
}