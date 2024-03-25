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
#include <climits>
bool isBSTh(BinaryTreeNode<int> *root, int minVal = INT_MIN, int maxVal = INT_MAX) {
    if (root == NULL) {
        return true;
    }

    if (root->data < minVal || root->data > maxVal) {
        return false;
    }

    return isBSTh(root->left, minVal, root->data - 1) &&
           isBSTh(root->right, root->data + 1, maxVal);
}
bool isBST(BinaryTreeNode<int> *root) {
	// this code doesnt tk care of cases with a single child
	// it doesnt ensure all elements of the right are greater than the root 
	// if(root==NULL){
	// 	return true;
	// }
	// if(root->left&&root->right){
	// 	if(root->left->data<root->data&&root->right->data>root->data){
	// 		return (isBST(root->left)&&isBST(root->right));
	// 	}else{
	// 		return false;
	// 	}
	// }else if(!root->left&&root->right){
	// 	if(root->right->data>root->data){
	// 		return isBST(root->right);
	// 	}else{
	// 		return false;
	// 	}
	// }else if(!root->right&&root->left){
	// 	if(root->left->data<root->data){
	// 		return isBST(root->left);
	// 	}else{
	// 		return false;
	// 	}
	// }
	// 	return true;
	return isBSTh(root);
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