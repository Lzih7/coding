#include <iostream>
#include <vector>

// 图的定义
class Graph {
public:
    struct Edge {
        int to;    // 边的终点
        Edge(int t) : to(t) {}
    };

    Graph(int n) : adj_(n) {} // 构造函数，初始化n个节点的邻接表

    // 添加边
    void addEdge(int from, int to) {
        adj_[from].push_back(Edge(to));
    }

    // 获取某个节点的邻接边
    const std::vector<Edge>& neighbors(int v) const {
        return adj_[v];
    }

    // 获取图的大小（节点数）
    int size() const {
        return adj_.size();
    }

private:
    std::vector<std::vector<Edge>> adj_; // 邻接表
};

// 从起点 s 开始遍历图的所有边
void traverseEdges(const Graph& graph, int s, std::vector<std::vector<bool>>& visited) {
    // base case
    if (s < 0 || s >= graph.size()) {
        return;
    }
    for (const Graph::Edge& e : graph.neighbors(s)) {
        // 如果边已经被遍历过，则跳过
        if (visited[s][e.to]) {
            continue;
        }
        // 标记并访问边
        visited[s][e.to] = true;
        std::cout << "visit edge: " << s << " -> " << e.to << std::endl;
        traverseEdges(graph, e.to, visited);
    }
}

int main() {
    // 创建一个图，包含4个节点
    Graph graph(4);

    // 添加边（示例图）
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);
    graph.addEdge(3, 0);

    // 初始化visited数组
    int n = graph.size();
    std::vector<std::vector<bool>> visited(n, std::vector<bool>(n, false));

    // 从节点0开始遍历
    std::cout << "Starting edge traversal from node 0:" << std::endl;
    traverseEdges(graph, 0, visited);

    return 0;
}