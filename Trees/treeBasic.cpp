#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree(Node* root){
    cout<<"Enter the data: "<<endl;
    int data;
    cin>>data;
    root = new Node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"Enter the data to insert at left: "<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the data to insert at right: "<<endl;
    root->right = buildTree(root->right);
    return root;
}

void levelOrderTraversal(Node* root) {
    if (root == NULL) return; 

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL) { 
            cout << endl; 
            if(!q.empty()) { 
                q.push(NULL); 
            }
        }
        else {
            cout << temp->data << " "; 

            if(temp->left) {
                q.push(temp->left);
            }

            if(temp->right) {
                q.push(temp->right);
            }
        }
    }
}

void reverselevelOrderTraversal(Node* root) {
    if (root == NULL) return; 

    queue<Node*> q;
    stack<Node*> s;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* temp = q.front();
        s.push(temp);
        q.pop();

        if(temp == NULL) { 
            if(!q.empty()) { 
                q.push(NULL); 
            }
        }
        else {
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }

    while(!s.empty()) {
        Node* temp = s.top();
        s.pop(); 
        if(temp == NULL){
            cout << endl;
        }
        else {
            cout<<temp->data<<" ";
        }
    }
}

void preOrder(Node* root){
    if(root == NULL) return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void preOrderIterative(Node* root){
    if(root == NULL) return;

    stack<Node*> s;
    s.push(root);
    
    while(!s.empty()){
        Node* temp = s.top();
        s.pop();

        cout<<temp->data<<" ";
        if(temp->right)
            s.push(temp->right);
        if(temp->left)
            s.push(temp->left);
    }
}

Node* buildpreOrder() {
    int data;
    cout << "Enter the data (-1 for NULL): ";
    cin >> data;

    if (data == -1) {
        return NULL;
    }

    Node* root = new Node(data);

    cout << "Entering left of " << data << endl;
    root->left = buildpreOrder();

    cout << "Entering right of " << data << endl;
    root->right = buildpreOrder();

    return root;
}

void inOrder(Node* root){
    if(root == NULL) return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void inOrderIterative(Node* root) {
    if (root == NULL) return;

    stack<Node*> s;
    Node* curr = root;

    while (curr != NULL || !s.empty()) {
        while (curr != NULL) {
            s.push(curr);
            curr = curr->left;
        }

        curr = s.top();
        s.pop();

        cout << curr->data << " "; 
        curr = curr->right;
    }
}

void postOrder(Node* root){
    if(root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

void postOrderIterative(Node* root) {
    if (root == NULL) return;

    stack<Node*> s1, s2;
    s1.push(root);

    while (!s1.empty()) {
        Node* temp = s1.top();
        s1.pop();
        s2.push(temp); 

        if (temp->left)
            s1.push(temp->left);
        if (temp->right)
            s1.push(temp->right);
    }

    while (!s2.empty()) {
        cout << s2.top()->data << " ";
        s2.pop();
    }
}

// -------------------------------------------------------------
// NEW ADDITIONS BELOW
// -------------------------------------------------------------

// Helper function to find the index of a value in the Inorder array
int findPosition(int in[], int inorderStart, int inorderEnd, int element) {
    for (int i = inorderStart; i <= inorderEnd; i++) {
        if (in[i] == element) {
            return i;
        }
    }
    return -1;
}

// 1. Build Tree from Inorder and Preorder Sequences
Node* buildTreeFromInorderPreorder(int in[], int pre[], int& preIndex, int inorderStart, int inorderEnd) {
    if (inorderStart > inorderEnd) {
        return NULL;
    }

    // Create a node with the current element from Preorder
    int element = pre[preIndex++];
    Node* root = new Node(element);

    // Find its position in Inorder array
    int position = findPosition(in, inorderStart, inorderEnd, element);

    // Build left and right subtrees
    root->left = buildTreeFromInorderPreorder(in, pre, preIndex, inorderStart, position - 1);
    root->right = buildTreeFromInorderPreorder(in, pre, preIndex, position + 1, inorderEnd);

    return root;
}

// 2. Build Tree from Inorder and Postorder Sequences
Node* buildTreeFromInorderPostorder(int in[], int post[], int& postIndex, int inorderStart, int inorderEnd) {
    if (inorderStart > inorderEnd) {
        return NULL;
    }

    // Create a node with the current element from Postorder (reading backwards)
    int element = post[postIndex--];
    Node* root = new Node(element);

    // Find its position in Inorder array
    int position = findPosition(in, inorderStart, inorderEnd, element);

    // IMPORTANT: When building from Postorder, build the RIGHT subtree first!
    root->right = buildTreeFromInorderPostorder(in, post, postIndex, position + 1, inorderEnd);
    root->left = buildTreeFromInorderPostorder(in, post, postIndex, inorderStart, position - 1);

    return root;
}

// 3. Delete Tree (Memory Management using Post-Order Traversal)
void deleteTree(Node* root) {
    if (root == NULL) return;

    // Delete left and right subtrees first
    deleteTree(root->left);
    deleteTree(root->right);

    // Then delete the parent node
    cout << "Deleting node: " << root->data << endl;
    delete root;
}

// -------------------------------------------------------------
// MAIN FUNCTION
// -------------------------------------------------------------

int main(){
    Node* root = NULL;

    /*
    cout<<"\nBuild From preOrder (Manual Input):\n";
    root = buildpreOrder();
    cout << "\nLevel Order Traversal:\n";
    levelOrderTraversal(root);
    */

    // --- Example: Build from Inorder & Preorder ---
    int in[] = {7, 3, 11, 1, 17, 5};
    int pre[] = {1, 3, 7, 11, 5, 17};
    int n = sizeof(in) / sizeof(in[0]);
    int preIndex = 0;
    
    cout << "\n--- Building Tree from Inorder & Preorder ---" << endl;
    root = buildTreeFromInorderPreorder(in, pre, preIndex, 0, n - 1);
    
    cout << "Level Order Traversal of built tree:" << endl;
    levelOrderTraversal(root);


    // --- Example: Build from Inorder & Postorder ---
    // (Uncomment to test)
    /*
    int in2[] = {7, 3, 11, 1, 17, 5};
    int post2[] = {7, 11, 3, 17, 5, 1};
    int n2 = sizeof(in2) / sizeof(in2[0]);
    int postIndex = n2 - 1; // Start from the end of Postorder array
    
    cout << "\n--- Building Tree from Inorder & Postorder ---" << endl;
    Node* root2 = buildTreeFromInorderPostorder(in2, post2, postIndex, 0, n2 - 1);
    
    cout << "Level Order Traversal of built tree:" << endl;
    levelOrderTraversal(root2);
    */

    // --- Deleting the tree ---
    cout << "\n--- Cleaning up memory ---" << endl;
    deleteTree(root);
    root = NULL; // Prevent dangling pointer

    return 0;
}