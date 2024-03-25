#include <iostream>
#include <queue>

template <typename T>
class Node {
   public:
    T data;
    Node<T>* next;
    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};

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
Node<int>*addNode(BinaryTreeNode<int> *currBSTnode,Node<int>*currLLnode){
	Node<int>*temp=new Node<int>(currBSTnode->data);
	currLLnode->next=temp;
	currLLnode=temp;
	return currLLnode;
}
Node<int> *helper(BinaryTreeNode<int> *currBSTnode,Node<int>*currLLnode) {
	if(currBSTnode==NULL){
		return currLLnode;
	}
	if(currBSTnode->left){
		currLLnode=helper(currBSTnode->left,currLLnode);
	}
	currLLnode=addNode(currBSTnode,currLLnode);
	if(currBSTnode->right){
		currLLnode=helper(currBSTnode->right,currLLnode);
	}
	return currLLnode;
}

Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
	// Write your code here
	if(root==NULL){
		return NULL;
	}
	Node<int>*head=new Node<int>(root->data);
	Node<int>*temp=helper(root,head);
	return head->next;
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
    Node<int>* head = constructLinkedList(root);

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}