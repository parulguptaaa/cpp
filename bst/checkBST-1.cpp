#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;
// #include "solution.h"
// T(n)=2T(n/2)+kn : if the tree is equally divided : height is logn: T(n)=O(nlogn)
// T(n)=T(n-1)+kn : if the tree is one sided: height is n: T(n)=O(n^2)
// this the T(n)=O(nh); h is the height of the tree
int maximum(BinaryTreeNode<int>*root){
    if(root==NULL){
        return INT_MIN;
    }
    return max(root->data,max(maximum(root->left),maximum(root->right)));
}
int minimum(BinaryTreeNode<int>*root){
    if(root==NULL){
        return INT_MAX;
    }
    return min(root->data,min(minimum(root->left),minimum(root->right)));
}
bool isBST(BinaryTreeNode<int> *root) {
    if(root==NULL){
        return true;
    }
    int leftMax=maximum(root->left);
    int rightMin=minimum(root->right);
    bool output=(root->data>leftMax)&&(root->data<rightMin)&&isBST(root->left)&&isBST(root->right);
    return output;
}

BinaryTreeNode<int>* takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    cout << (isBST(root) ? "true" : "false");
}