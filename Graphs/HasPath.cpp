#include <iostream>
using namespace std;
bool haspath(int sv, int ev,bool*visited,int**edges,int n){
    if(!visited[sv]){
        visited[sv]=true;
        if(sv==ev){
            return true;
        }
        for(int i=0;i<n;i++){
            if(edges[sv][i]==1&&!visited[i]){
                if(i==ev){
                    return true;
                }
                return haspath(i, ev, visited, edges, n);
                visited[i]=true;
            }
        }
        return false;
    }
}
int main() {
    // Write your code here
    int n,e;
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
        edges[s][f]=1;
        edges[f][s]=1;
    }
    bool*visited=new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    int sv,ev;
    cin>>sv>>ev;
    if(haspath(sv,ev,visited,edges,n)){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
}