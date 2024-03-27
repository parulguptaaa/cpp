#include <iostream>
using namespace std;
#include<unordered_map>
#include <queue>
bool getPath(int**edges,int n,int sv,int ev,unordered_map<int,int>&map){
    queue<int>pendingVertices;
    bool*visited=new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    pendingVertices.push(sv);
    visited[sv]=true;
    map[sv]=-1;
    while(!pendingVertices.empty()){
        int currentVertex=pendingVertices.front();
        if(currentVertex==ev){
            return true;
        }
        pendingVertices.pop();
        for(int i=0;i<n;i++){
            if(i==currentVertex){
                continue;
            }
            if(edges[currentVertex][i]==1 &&!visited[i]){
                pendingVertices.push(i);
                visited[i]=true;
                map[i]=currentVertex;
            }
        }
    }
    return false;
}
void printPath(unordered_map<int,int>map,int sv,int ev){
    while (ev != -1) {
        cout << ev << " ";
        ev = map[ev];
    }
}
int main() {
    // Write your code here
    int n, e;
    cin >> n >> e;
    int** edges = new int*[n];
    for (int i = 0; i < n; i++) {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++) {
            edges[i][j] = 0;
        }
    }
    for (int i = 0; i < e; i++) {
        int f, s;
        cin >> f >> s;
        edges[s][f] = 1;
        edges[f][s] = 1;
    }
    int sv, ev;
    cin >> sv >> ev;  
    unordered_map<int, int>map;
    if (getPath(edges, n, sv, ev, map)) {
        printPath(map,sv,ev);
    }else{
        cout<<endl;
    }
}