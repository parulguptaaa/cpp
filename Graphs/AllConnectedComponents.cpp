#include <iostream>
#include<queue>
#include <algorithm>
using namespace std;
void BFS(int**edges, int n,int sv,bool*visited,vector<vector<int>>&output){
    vector<int>result;
    queue<int>pendingVertices;
    pendingVertices.push(sv);
    visited[sv]=true;
    while(!pendingVertices.empty()){
        int currentVertex=pendingVertices.front();
        pendingVertices.pop();
        result.push_back(currentVertex);
        for(int i=0;i<n;i++){
            if(i==currentVertex){
                continue;
            }
            if (edges[currentVertex][i] == 1 && !visited[i]) {
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }
    sort(result.begin(),result.end());
    output.push_back(result);
}
void DisconnectedVertices(int** edges, int n,vector<vector<int>>&output) {
    bool* visited = new bool[n]();
        for(int i=0;i<n;i++){
        visited[i]=false;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            BFS(edges, n, i,visited,output);
        }
    }

    delete[] visited;
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
    vector<vector<int>>output;
    DisconnectedVertices(edges, n,output);
    for(int i=0;i<output.size();i++){
        for(int j=0;j<output[i].size();j++){
            cout<<output[i][j]<<" ";
        }
        cout<<endl;
    }
}