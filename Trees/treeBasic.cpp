#include<iostream>
#include<queue>
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
    //Example 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
    /*
    
                  1    
                /   \  
               2     3 
              / \   / \
             4   5 6   7
 
    */
}

void levelOrderTraversal(Node* root){
    
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){

        Node* temp = q.front();
        cout<<temp->data<<" ";
        q.pop();


        if(temp->left){
            q.push(temp->left);
        }

        if(temp->right){
            q.push(temp->right);
        }
    }
}

int main(){
    Node* root = NULL;
    root = buildTree(root);
    levelOrderTraversal(root);
    return 0;
}