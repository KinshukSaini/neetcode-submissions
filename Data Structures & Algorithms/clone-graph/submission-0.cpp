/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void traversal(Node* original, Node* copy, map<Node*, Node*>& mpp){
        mpp[original] = copy;
        for(auto node : original->neighbors){
            if(mpp.find(node) == mpp.end()){
                Node* newNode = new Node(node->val);
                (copy->neighbors).push_back(newNode);
                traversal(node, newNode, mpp);
            }
            else{
                (copy->neighbors).push_back(mpp[node]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(!node) return node;

        map<Node*, Node*> mpp;
        Node* newNode = new Node(node->val);
        traversal(node, newNode, mpp);
        return newNode;
    }
};
