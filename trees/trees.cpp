#include<iostream>
#include<vector>
#include<queue>
using namespace std;
template<typename T>
class TreeNode{
    public:
    T data;
    vector<TreeNode<T>*>children;
    TreeNode(T data){
        this->data=data;
    }
    ~TreeNode(){
        for(int i=0;i<children.size();i++){
            cout<<"deleted "<<children[i]->data<<endl;
            delete children[i];
        }
    }
};
#include <climits>

template <typename T>
class MaxNodePair {
   public:
    TreeNode<T> *node;
    int sum;
};

MaxNodePair<int> *maxSumNodeHelper(TreeNode<int> *root) {
    if (root == NULL) {
        MaxNodePair<int> *pair = new MaxNodePair<int>();
        pair->node = NULL;
        pair->sum = INT_MIN;
        return pair;
    }

    int sum = root->data;

    for (int i = 0; i < root->children.size(); i++) {
        sum += root->children[i]->data;
    }

    MaxNodePair<int> *ans = new MaxNodePair<int>();
    ans->node = root;
    ans->sum = sum;

    for (int i = 0; i < root->children.size(); i++) {
        MaxNodePair<int> *childAns = maxSumNodeHelper(root->children[i]);
        if (childAns->sum > ans->sum) {
            ans = childAns;
        }
    }
    
    return ans;
}

TreeNode<int> *maxSumNode(TreeNode<int> *root) {
    return maxSumNodeHelper(root)->node;
}
TreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout<<"enter data"<<endl;
    cin>>rootData;
    TreeNode<int>*root =new TreeNode<int> (rootData);
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        TreeNode<int>* front=pendingNodes.front();
        pendingNodes.pop();
        cout<<"enter number of children of "<<front->data<<endl;
        int numChild;
        cin>>numChild;
        for(int i=0;i<numChild;i++){
            int childData;
            cout<<"enter "<<i<<"th child of "<<front->data<<endl;
            cin>>childData;
            TreeNode<int>*child=new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}
TreeNode<int>* takeInput(){
    int rootData;
    cout<<"enter data"<<endl;
    cin>>rootData;
    TreeNode<int>*root =new TreeNode<int> (rootData);
    int n;
    cout<<"enter number of children of root data"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        TreeNode<int>*child  =takeInput();
        root->children.push_back(child);
    }
    return root;
}
void printTreeLevelWise(TreeNode<int>*root){
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        TreeNode<int>*front=pendingNodes.front();
        pendingNodes.pop();
        cout<<front->data<<":";
        for(int i=0;i<front->children.size();i++){
            cout<<front->children[i]->data<<",";
            pendingNodes.push(front->children[i]);
        }
        cout<<endl;
    }
}
void printTree(TreeNode<int>*root){
    // edge case;
    if(root==NULL){
        return;
    }
    cout<<root->data<<":";
    for(int i=0;i<root->children.size();i++){
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++){
        printTree(root->children[i]);
    }
}
int numNodes(TreeNode<int>*root ){

    int ans=1;
    for(int i=0;i<root->children.size();i++){
        ans+=numNodes(root->children[i]);
    }
    return ans;
}
int sumOfNodes(TreeNode<int>* root) {
    int ans=root->data;
    for(int i=0;i<root->children.size();i++){
        ans+=sumOfNodes(root->children[i]);
    }
    return ans;
}
TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    if(root==NULL){
        return NULL;
    }
    queue<TreeNode<int>*>max;
    max.push(root);
    for(int i=0;i<root->children.size();i++){
       
        TreeNode<int>* front=max.front();
         TreeNode<int>* val=maxDataNode(root->children[i]);
        if (val->data > front->data) {
          max.pop();
          max.push(val);
        }
    }
    return max.front();
}
int getHeight(TreeNode<int>* root) {
    if(root==NULL){
        return 0;
    }
    int max=1;
    for(int i=0;i<root->children.size();i++){
        int ans=1+getHeight(root->children[i]);
        if(ans>max){
            max=ans;
        }
    }
    return max;
}
void printAtLevelK(TreeNode<int>*root,int k){
    if(root==NULL){
        return;
    }
    if(k==0){
        cout<<root->data<<endl;
        return;
    }
    for(int i=0;i<root->children.size();i++){
        printAtLevelK(root->children[i],k-1);
    }
}
int getLeafNodeCount(TreeNode<int>*root) {
    int ans=0;
    if(root->children.size()==0){
        return 1;
    }
    for(int i=0;i<root->children.size();i++){
        ans+=getLeafNodeCount(root->children[i]);
    }
    return ans;
}
void preorder(TreeNode<int>*root){
    cout<<root->data<<" ";
    for(int i=0;i<root->children.size();i++){
        preorder(root->children[i]);
    }
}
void postorder(TreeNode<int>*root){
    for(int i=0;i<root->children.size();i++){
        postorder(root->children[i]);
    }
    cout<<root->data<<" ";
}
void deleteTree(TreeNode<int>*root){
    for(int i=0;i<root->children.size();i++){
        deleteTree(root->children[i]);
    }
    delete root;
}
bool isPresent(TreeNode<int>* root, int x) {
    if(root->data==x){
        return true;
    }
    for(int i=0;i<root->children.size();i++){
        if( isPresent(root->children[i],x)){
            return true;
        }
    }
}
bool areIdentical(TreeNode<int> *root1, TreeNode<int> * root2) {
    if(root1==NULL&&root2==NULL){
        return true;
    }
    if(root1->data!=root2->data){
        return false;
    }
    if(root1->children.size()!=root2->children.size()){
        return false;
    }
    for(int i=0;i<root1->children.size();i++){
        if(root1->children[i]->data==root2->children[i]->data){
            return areIdentical(root1->children[i], root2->children[i]);
        }else{
            return false;
        }
    }
    return true;
}
TreeNode<int>* getNextLargerElement(TreeNode<int>* root, int x) {
    if(root==NULL){
        return root;
    }
    TreeNode<int>* ans=NULL;
    if(root->data>x){
        ans=root;
    }
    for(int i=0;i<root->children.size();i++){
        TreeNode<int>*temp=getNextLargerElement(root->children[i],x);
        if(ans==NULL){
            ans=temp;
        }else if(temp!=NULL&&temp->data<ans->data){
            ans=temp;
        }
    }
    return ans;
}
int getLargeNodeCount(TreeNode<int>* root, int x) {
    int ans=0;
    if(root->data>x){
        ans++;
    }
    for(int i=0;i<root->children.size();i++){
        ans+=getLargeNodeCount(root->children[i],x);
    }
    return ans;
}
int main(){
    // 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
    // TreeNode<int>*root =new TreeNode<int> (1);
    // TreeNode<int>*node1 =new TreeNode<int> (2);
    // TreeNode<int>*node2 =new TreeNode<int> (3);
    // root->children.push_back(node1);
    // root->children.push_back(node2);
    TreeNode<int>*root =takeInputLevelWise();
    // printTree(root);
    // printTreeLevelWise(root);
    preorder(root);
    cout<<endl;
    delete root;
}