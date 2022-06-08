#include <iostream>
using namespace std;

struct Node
{
    Node(int dat):data(dat), parent(nullptr), left(nullptr), right(nullptr){}
    int data;
    Node* parent;
    Node* left;
    Node* right;
};

class Tree
{
public:
    Tree():root(nullptr){}
    void insertNode(Node* newNode, bool& toInsert);
        void insertNodeHelper(Node* root, Node* newNode, bool& toInsert);
    void printAllNodes() const;
        void printAllNodesHelper(Node* root) const;
    
private:
    Node* root;
};

void Tree::insertNodeHelper(Node* root, Node* newNode, bool& toInsert)
{
    if (root == nullptr)
    {
        toInsert = true;
        return;
    }
    
    if (newNode->data < root->data)
        insertNodeHelper(root->left, newNode, toInsert);

    else if (newNode->data > root->data)
        insertNodeHelper(root->right, newNode, toInsert);

    else
        toInsert = false;

    if (toInsert == true)
    {
        newNode->parent = root;
        if (newNode->data < root->data)
            root->left = newNode;
            
        else
            root->right = newNode;
        toInsert = false;
    }
}

void Tree::insertNode(Node* newNode, bool& toInsert)
{
    if (root == nullptr)
    {
        newNode->parent = nullptr;
        root = newNode;
    }
    else
    {
        insertNodeHelper(root, newNode, toInsert);
    }
}

void Tree::printAllNodes() const
{
    printAllNodesHelper(root);
    cout << "===========================" << endl;
}

void Tree::printAllNodesHelper(Node* root) const
{
    if (root == nullptr)    return;
    cout << root->data << endl;
    printAllNodesHelper(root->left);
    printAllNodesHelper(root->right);
}

int main()
{
    //construct a basic tree
    Tree* trie = new Tree();
    Node* alpha = new Node(5);

    bool toInsert = false;
    trie->insertNode(alpha, toInsert);
    trie->printAllNodes();

    
    Node* gamma = new Node(3);
    trie->insertNode(gamma, toInsert);
    trie->printAllNodes();
    
    Node* delta = new Node(6);
    trie->insertNode(delta, toInsert);
    trie->printAllNodes();
    
    Node* beta = alpha;
    trie->insertNode(beta, toInsert);
    trie->printAllNodes();
    
    Node* epsilon = gamma;
    trie->insertNode(epsilon, toInsert);
    trie->printAllNodes();
    
    Node* zeta = new Node(9);
    trie->insertNode(zeta, toInsert);
    trie->printAllNodes();
    
    Node* eta = new Node(7);
    trie->insertNode(eta, toInsert);
    trie->printAllNodes();
    
    Node* theta = new Node(10);
    trie->insertNode(theta, toInsert);
    trie->printAllNodes();
}
