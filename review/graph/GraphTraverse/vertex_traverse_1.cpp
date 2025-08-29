#include <bits/stdc++.h>
using namespace std;
// 遍历图的所有节点
class Graph{
public:
    struct Edge{
        int to;
        Edge(int to) : to(to) {}
    };
    struct vertex {
        int id;
        int content;
        vertex(int id, int content) : id(id), content(content) {}
    };
private:
    vector<list<Edge>> adj_list;
    int numVertices;
public:
    Graph(int numVertices) : numVertices(numVertices) {
        adj_list.resize(numVertices);
    }
    void addEdge(int from, int to) {
        if(from < 0 || from >=numVertices ||to < 0 || to >= numVertices) {
            throw out_of_range("Invalid vertex");
        }
        adj_list[from].emplace_back(to);
    }
    int size() const {
        return numVertices;
    }
    const list<Edge>& neighbors(int start) const {
        if(start < 0 || start >=numVertices) {
            throw out_of_range("Invalid vertex");
        }
        return adj_list[start];
    }
};
void traverse(const Graph& graph, int s, std::vector<bool>& visited) {
    // base case
    if (s < 0 || s >= graph.size()) {
        return;
    }
    if (visited[s]) {
        // 防止死循环
        return;
    }
    // 前序位置
    visited[s] = true;
    std::cout << "visit " << s << std::endl;
    for (const Graph::Edge& e : graph.neighbors(s)) {
        traverse(graph, e.to, visited);
    }
    // 后序位置
}

int main(){
    Graph graph(5);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 4);
    printf("Graph size: %d\n", graph.size());
    std::vector<bool> visited(graph.size(), false);
    traverse(graph, 0, visited);
    return 0;
}