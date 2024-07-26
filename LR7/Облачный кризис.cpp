#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

struct Node {
    char data;
    int val;
    Node* left;
    Node* right;

    Node(char data, int val) : data(data), val(val), left(nullptr), right(nullptr) {}
};

struct Compare {
    bool operator()(Node* left, Node* right) {
        return (left->val > right->val);
    }
};

void G(Node* root, string code, unordered_map<char, string>& codes) {
    if (!root) {
        return;
    }
    if (root->data != '$') {
        codes[root->data] = code;
    }
    G(root->left, code + "0", codes);
    G(root->right, code + "1", codes);
}

void encode(const string& text) {
    unordered_map<char, int> val;
    int res;
    for (char c : text) {
        val[c]++;
    }

    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (auto pair : val) {
        pq.push(new Node(pair.first, pair.second));
    }

    while (pq.size() != 1) {
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();

        Node* parent = new Node('$', left->val + right->val);
        parent->left = left;
        parent->right = right;
        pq.push(parent);
    }

    Node* root = pq.top();

    unordered_map<char, string> codes;
    G(root, "", codes);
    int resBit= 0;
    for (char c : text) {
        resBit += codes[c].length(); 
    }

    cout << resBit;
}

int main() {
    string text;
    getline(cin, text);
    encode(text);
    return 0;
}

