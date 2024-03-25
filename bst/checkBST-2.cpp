
#include <iostream>
#include <queue>
#include<climits>
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
// T(n)=O(n)
class isBSTreturn{
    public:
        bool isBST;
        int minimum;
        int maximum;
};
isBSTreturn isBSTcheck(BinaryTreeNode<int>*root){
    if(root==NULL){
        isBSTreturn output;
        output.isBST=true;
        output.maximum=INT_MIN;
        output.minimum=INT_MAX;
        return output;
    }
    isBSTreturn leftOuput=isBSTcheck(root->left);
    isBSTreturn rightOuput=isBSTcheck(root->right);
    int minimum=min(root->data,min(leftOuput.minimum,rightOuput.minimum));
    int maximum=max(root->data,max(leftOuput.maximum,rightOuput.maximum));
    bool isBSTfinal=(root->data>leftOuput.maximum)&&(root->data<rightOuput.minimum)&&(leftOuput.isBST)&&(rightOuput.isBST);
    isBSTreturn output;
    output.minimum=minimum;
    output.maximum=maximum;
    output.isBST=isBSTfinal;
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
    cout <<isBSTcheck(root).isBST;
}