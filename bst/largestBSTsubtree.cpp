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
    ~BinaryTreeNode() {
        if (left) delete left;
        if (right) delete right;
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
    return isBSTh(root->left, minVal, root->data - 1) && isBSTh(root->right, root->data + 1, maxVal);
}
int height(BinaryTreeNode<int> *root){
	if(root==NULL){
		return 0;
	}
	return max(height(root->left),height(root->right))+1;
}
int largestBSTSubtree(BinaryTreeNode<int> *root) {
    // Write your code here
	if(root==NULL){
		return -1;
	}
	if(isBSTh(root)){
		return height(root);
	}else if(root->left&&root->right){
		if(isBSTh(root->left)&&isBSTh(root->right)){
			return max(height(root->left),height(root->right));
		}else if(isBSTh(root->left)&&!isBSTh(root->right)){
			return max(height(root->left),largestBSTSubtree(root->right));
		}else if(!isBSTh(root->left)&&isBSTh(root->right)){
			return max(height(root->right),largestBSTSubtree(root->left));
		}else{
			return max(largestBSTSubtree(root->left),largestBSTSubtree(root->right));
		}
	}else if(root->left &&!root->right){
		if(isBSTh(root->left)){
			return height(root->left);
		}else{
			return largestBSTSubtree(root->left);
		}
	}else if(!root->left &&root->right){
		if(isBSTh(root->right)){
			return height(root->right);
		}else{
			return largestBSTSubtree(root->right);
		}
	}
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
    cout << largestBSTSubtree(root);
    delete root;
}