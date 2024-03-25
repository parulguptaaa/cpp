#include <iostream>
using namespace std;
#include<queue>
template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};
void printTreeLevelWise(BinaryTreeNode<int> *root){
    if (root == NULL){
        return;
    }
    queue<BinaryTreeNode<int>*>pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        BinaryTreeNode<int>*front=pendingNodes.front();
        cout<<front->data<<":";
        pendingNodes.pop();
        cout<<"L:"<<front->left->data<<",";
        pendingNodes.push(front->left);
        cout<<"R:"<<front->right->data<<endl;
        pendingNodes.push(front->right);
    }
}
// inorder
void inorder(BinaryTreeNode<int> *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
// DIAMETER OF BT
// height O(n)
int height(BinaryTreeNode<int>*root){
    if(root==NULL){
        return 0;
    }
    return 1+max(height(root->left),height(root->right));
}
int diameter (BinaryTreeNode<int>*root){
    if(root==NULL){
        return 0;
    }
    int option1=height(root->left)+height(root->right);
    int option2=diameter(root->left);
    int option3=diameter(root->right);
    return max(option1,max(option2,option3));
}
// better DIAMETER
pair<int,int>heightDiameter(BinaryTreeNode<int>*root){
    if(root==NULL){
        pair<int,int>p;
        p.first=0;
        p.second=0;
        return p;
    }
    pair<int,int>leftAns=heightDiameter(root->left);
    pair<int,int>rightAns=heightDiameter(root->right);
    int lh=leftAns.first;
    int ld=leftAns.second;
    int rh=rightAns.first;
    int rd=rightAns.second;
    int height=1+max(lh,rh);
    int diameter=max(lh+rh,max(ld,rd));
    pair<int,int>p;
    p.first=height;
    p.second=diameter;
    return p;
}

// COUNT NODES
int numNodes(BinaryTreeNode<int>*root){
    if(root==NULL){
        return 0;
    }
    return 1+ numNodes(root->left)+numNodes(root->right);
}
BinaryTreeNode<int>*takeInputLevelWise(){
    int rootData;
    cout<<"enter root data "<<endl;
    cin>>rootData;
    if(rootData==-1){
        return NULL;
    }
    BinaryTreeNode<int>*root=new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*>pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        BinaryTreeNode<int>*front=pendingNodes.front();
        pendingNodes.pop();
        cout<<"enter left child of "<<front->data<<endl;
        int leftChildData;
        cin>>leftChildData;
        if(leftChildData!=-1){
            BinaryTreeNode<int>*child=new BinaryTreeNode<int>(leftChildData);
            front->left=child;
            pendingNodes.push(child);
        }
        cout<<"enter right child of "<<front->data<<endl;
        int rightChildData;
        cin>>rightChildData;
        if(rightChildData!=-1){
            BinaryTreeNode<int>*child=new BinaryTreeNode<int>(rightChildData);
            front->right=child;
            pendingNodes.push(child);
        }
    }
    return root;
}
void printTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << ":";
    if (root->left != NULL)
    {
        cout << "L " << root->left->data;
    }
    if (root->right != NULL)
    {
        cout << "R " << root->right->data;
    }
    cout << endl;
    printTree(root->left);
    printTree(root->right);
}
// #include<bits.h>
vector<int>* RootToNodePath(BinaryTreeNode<int> *root,int data){
    if(root==NULL){
        return NULL;
    }
    if(root->data==data){
        vector<int>*output=new vector<int>();
        output->push_back(root->data);
        return output;
    }
    vector<int>* Loutput=RootToNodePath(root->left,data);
    if(Loutput!=NULL && !Loutput->empty()){
        Loutput->push_back(root->data);
        return Loutput;
    }
    vector<int>* Routput=RootToNodePath(root->right,data);
    if(Routput!=NULL){
        Routput->push_back(root->data);
        return Routput;
    }else{
        return NULL;
    }
}
BinaryTreeNode<int> *takeInput(){
    int rootData;
    cout<<"enter root data "<<endl;
    cin>>rootData;
    if(rootData==-1){
        return NULL;
    }
    BinaryTreeNode<int>*root=new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int>*leftChild=takeInput();
    BinaryTreeNode<int>*rightChild=takeInput();
    root->left=leftChild;
    root->right=rightChild;
    return root;
}
int main()
{
    /*BinaryTreeNode<int>*root=new BinaryTreeNode<int>(1);
    BinaryTreeNode<int>*node1=new BinaryTreeNode<int>(2);
    BinaryTreeNode<int>*node2=new BinaryTreeNode<int>(3);
    root->left=node1;
    root->right=node2;*/
    BinaryTreeNode<int> *root = takeInput();
    printTree(root);
    cout<<"number of nodes are: "<<numNodes(root)<<endl;
    int data;
    cout<<"enter data to be searched ";
    cin>>data;
    vector<int>*ans=RootToNodePath(root,data);
    for(int i=0;i<ans->size();i++){
        cout<<ans->at(i)<<endl;
    }
    delete ans;
    delete root;
}