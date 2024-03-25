#include <iostream>
using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class BST
{
    BinaryTreeNode<int> *root;

public:
    BST()
    {
        root == NULL;
    }
    ~BST()
    {
        delete root;
    }
    // int minimum(BinaryTreeNode<int>*root){
    //     if(root==NULL){
    //         return INT_MAX;
    //     }
    //     return min(root->data,min(minimum(root->left),minimum(root->right)));
    // }
    // BinaryTreeNode<int>* Nodesearch(int data, BinaryTreeNode<int>*node){
    //     if(node==NULL){
    //         return NULL;
    //     }
    //     if(node->data==data){
    //         return node;
    //     }else if(data<node->data){
    //         return Nodesearch(data,node->left);
    //     }else{
    //         return Nodesearch(data,node->right);
    //     }
    // }
    BinaryTreeNode<int> *removeHelper(int data, BinaryTreeNode<int> *root)
    {
        if (root == NULL)
        {
            return NULL;
        }
        if (root->data == data)
        {
            if (!root->left && !root->right)
            {
                delete root;
                return NULL;
            }
            else if (!root->left && root->right)
            {
                BinaryTreeNode<int> *temp = root->right;
                delete root;
                root = temp;
                return temp;
            }
            else if (root->left && !root->right)
            {
                BinaryTreeNode<int> *temp = root->left;
                delete root;
                root = temp;
                return temp;
            }
            else
            {
                // int minimumRight=minimum(root->right);
                // BinaryTreeNode<int>*minimumRightNode=Nodesearch(minimumRight,root->right);
                BinaryTreeNode<int> *minRightNode = root->right;
                while (minRightNode->left != NULL)
                {
                    minRightNode = minRightNode->left;
                }
                root->data = minRightNode->data;
                root->right = removeHelper(minRightNode->data, root->right);
                return root;
            }
        }
        else if (data > root->data)
        {
            root->right = removeHelper(data, root->right);
        }
        else if (data < root->data)
        {
            root->left = removeHelper(data, root->left);
        }
        return root;
    }
    void remove(int data)
    {
        root = removeHelper(data, root);
        return;
    }
    void printh(BinaryTreeNode<int> *root)
    {
        // Implement the print() function
        if (root == NULL)
        {
            return;
        }
        cout << root->data << ":";
        if (root->left != NULL)
        {
            cout << "L:" << root->left->data << ",";
        }
        if (root->right != NULL)
        {
            cout << "R:" << root->right->data;
        }
        cout << endl;
        printh(root->left);
        printh(root->right);
        return;
    }
    void print()
    {
        printh(root);
        return;
    }
    BinaryTreeNode<int> *insertHelper(BinaryTreeNode<int> *root, int data)
    {
        if (root == NULL)
        {
            BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(data);
            return newNode;
        }
        if (root->data < data)
        {
            root->right = insertHelper(root->right, data);
        }
        else
        {
            root->left = insertHelper(root->left, data);
        }
        return root;
    }
    void insert(int data)
    {
        root = insertHelper(root, data);
        return;
    }

private:
    bool search(int data, BinaryTreeNode<int> *node)
    {
        if (node == NULL)
        {
            return false;
        }
        if (node->data == data)
        {
            return true;
        }
        else if (data < node->data)
        {
            return search(data, node->left);
        }
        else
        {
            return search(data, node->right);
        }
    }

public:
    bool search(int data)
    {
        return search(data, root);
    }
};
int main()
{
    BST *tree = new BST();
    int choice, input, q;
    cin >> q;
    while (q--)
    {
        cin >> choice;
        switch (choice)
        {
        case 1:
            cin >> input;
            tree->insert(input);
            break;
        case 2:
            cin >> input;
            tree->remove(input);
            break;
        case 3:
            cin >> input;
            cout << ((tree->search(input)) ? "true\n" : "false\n");
            break;
        default:
            tree->print();
            break;
        }
    }
}