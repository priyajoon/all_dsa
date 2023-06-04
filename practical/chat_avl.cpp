#include <iostream>
#include <queue>
using namespace std;

// AVL Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
};

class avl{

    public:
		Node *root;
		avl()
		{
			root=NULL;
		}



// Function to get the height of a node
int getHeight(Node* node) {
    if (node == NULL)
        return -1;
    return node->height;
}

// Function to update the height of a node
void updateHeight(Node* node) {
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
}

// Function to perform right rotation
Node* rotateRight(Node* root) {
    Node* newRoot = root->left;
    root->left = newRoot->right;
    newRoot->right = root;

    updateHeight(root);
    updateHeight(newRoot);

    return newRoot;
}

// Function to perform left rotation
Node* rotateLeft(Node* root) {
    Node* newRoot = root->right;
    root->right = newRoot->left;
    newRoot->left = root;

    updateHeight(root);
    updateHeight(newRoot);

    return newRoot;
}

// Function to perform left-right rotation
Node* rotateLeftRight(Node* root) {
    root->left = rotateLeft(root->left);
    return rotateRight(root);
}

// Function to perform right-left rotation
Node* rotateRightLeft(Node* root) {
    root->right = rotateRight(root->right);
    return rotateLeft(root);
}

// Function to balance the AVL Tree
Node* balance(Node* root) {
    int balanceFactor = getHeight(root->left) - getHeight(root->right);

    if (balanceFactor > 1) {
        if (getHeight(root->left->left) >= getHeight(root->left->right))
            root = rotateRight(root);
        else
            root = rotateLeftRight(root);
    }
    else if (balanceFactor < -1) {
        if (getHeight(root->right->right) >= getHeight(root->right->left))
            root = rotateLeft(root);
        else
            root = rotateRightLeft(root);
    }

    return root;
}

// Function to insert a node in the AVL Tree
Node* insert(Node* root, int data) {
    if (root == NULL) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->height = 0;
        return newNode;
    }
    else if (data < root->data) {
        root->left = insert(root->left, data);
    }
    else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    updateHeight(root);
    root = balance(root);

    return root;
}

// Function for level order traversal
void levelOrderTraversal(Node* root) {
    if (root == NULL)
        return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        cout << current->data << " ";

        if (current->left)
            q.push(current->left);

        if (current->right)
            q.push(current->right);
    }
}

void preorder(Node *root){
    if(root!=NULL){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
// Function to print the height of the tree
void printHeight(Node* root) {
    if (root == NULL)
        cout << "Tree is empty." << endl;
    else
        cout << "Height of the tree is: " << root->height << endl;
}


};

int main() {
   // Node* root = NULL;
    avl t;
    //t.root=t.insert(t.root,10);
     //root = insert(root, 10);
    t.root = t.insert(t.root, 30);
    t.root = t.insert(t.root, 31);
    t.root = t.insert(t.root, 32);
    t.root = t.insert(t.root, 23);
    t.root = t.insert(t.root, 22);
    t.root = t.insert(t.root, 28);
    t.root = t.insert(t.root, 24);
    t.root = t.insert(t.root, 29);
    t.root = t.insert(t.root, 26);
    t.root = t.insert(t.root, 27);
    t.levelOrderTraversal(t.root);

    cout<<endl;
    t.preorder(t.root);
    cout<<endl;
    t.printHeight(t.root);

    return 0;
}
   
