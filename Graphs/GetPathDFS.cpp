#include <iostream>
#include <vector>
using namespace std;

bool getPath(int** edges, int n, int sv, int ev, bool* visited,vector<int>&output) {
    if (sv == ev) {
        output.push_back(sv);
        return true;
    }
    if (!visited[sv]) {
        output.push_back(sv);
        visited[sv] = true;
        for (int i = 0; i < n; i++) {
            if (edges[sv][i] == 1 && !visited[i]) {
              if (getPath(edges, n, i, ev, visited, output)) {
                return true;
              }
            }
        }

        output.pop_back();
    }
    return false;
}

int main() {
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
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    int sv, ev;
    cin >> sv >> ev;
    vector<int>output;
    if(getPath(edges, n, sv, ev, visited,output)){
        for (int i = output.size()-1; i >=0; i--) {
            cout << output[i] << " ";
        }
    }else{
        cout<<endl;
    }

    for (int j = 0; j < n; j++) {
        delete[] edges[j];
    }
    delete[] edges;
    delete[] visited;

    return 0;
}