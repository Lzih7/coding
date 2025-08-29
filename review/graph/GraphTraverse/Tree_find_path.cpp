#include <bits/stdc++.h>
using namespace std;

typedef struct Node {
    int val;
    vector<Node*> children;

    Node(int x) : val(x) {}
}Node;
list<Node*> path;

void traverse(Node* root, Node* targetNode) {
    if(root == nullptr) {
        return;
    }
    if(root->val == targetNode->val) {
        path.emplace_back(root);
        for(auto node : path) {
            cout << node->val << " ";
        }
        cout << endl;
    }
    path.emplace_back(root);
    for(auto child : root->children) {
        traverse(child, targetNode);
    }
    path.pop_back();
}

int main() {
    // 创建示例树：
    //       1
    //     / | \
    //    2  3  4
    //   /|    |
    //  5 6    7
    //    |
    //    8

    Node* root = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);
    Node* node6 = new Node(6);
    Node* node7 = new Node(7);
    Node* node8 = new Node(8);

    // 构建父子关系
    root->children.push_back(node2);
    root->children.push_back(node3);
    root->children.push_back(node4);

    node2->children.push_back(node5);
    node2->children.push_back(node6);

    node6->children.push_back(node8);

    node4->children.push_back(node7);

    // 测试查找路径：从根到节点 7
    cout << "\n--- Testing traversal to node 7 ---" << endl;
    path.clear(); // 清空路径
    traverse(root, node7);

    // 测试查找路径：从根到节点 8
    cout << "\n--- Testing traversal to node 8 ---" << endl;
    path.clear(); // 清空路径
    traverse(root, node8);

    // 测试查找路径：从根到节点 5
    cout << "\n--- Testing traversal to node 5 ---" << endl;
    path.clear(); // 清空路径
    traverse(root, node5);

    // 测试查找不存在的节点
    cout << "\n--- Testing traversal to non-existent node 9 ---" << endl;
    path.clear(); // 清空路径
    Node* node9 = new Node(9);
    traverse(root, node9);

    // 释放内存（简单版本，实际项目建议用智能指针）
    // 这里只释放部分节点，避免内存泄漏（简化处理）
    delete node2; delete node3; delete node4;
    delete node5; delete node6; delete node7; delete node8;
    delete node9;
    delete root;

    return 0;
}