#include<iostream>
using namespace std;
#include<queue>
void print(int**edges, int n,int sv){
    queue<int>pendingVertices;
    bool*visited=new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    pendingVertices.push(sv);
    visited[sv]=true;
    while(!pendingVertices.empty()){
        int currentVertex=pendingVertices.front();
        pendingVertices.pop();
        cout<<currentVertex<<endl;
        for(int i=0;i<n;i++){
            if(i==currentVertex){
                continue;
            }
            if(edges[currentVertex][i]==1 &&!visited[i]){
                pendingVertices.push(i);
                visited[i]=true;
            }
        }
    }
    delete [] visited;
}
int main(){
    int n;
    int e;
    cin>>n>>e;
    int**edges=new int*[n];
    for(int i=0;i<n;i++){
        edges[i]=new int[n];
        for(int j=0;j<n;j++){
            edges[i][j]=0;
        }
    }
    for(int i=0;i<e;i++){
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }
    bool*visited=new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=0;
    }
    print(edges,n,0);
    // delete all the memory
}