

#include <iostream>
#include <vector>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    int maxDepth(Node* root) {
        if(!root)
            return 0;
        int max_depth = 1;
        DFS(root,1,max_depth);
        return max_depth;
    }

    void DFS(Node *node, int depth, int &max_depth){
        if(!node) return;
        if((node->children).empty())
            max_depth = max(depth,max_depth);

        for(auto tmp_node:node->children)
            DFS(tmp_node,depth+1,max_depth);
    }
};

int main(int argc, char const *argv[])
{
    Solution solu;
    return 0;
}