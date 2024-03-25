#include <iostream>
using namespace std;

// #include "solution.h"
#include<vector>
class PriorityQueue {
    // Declare the data members here
    vector<int> pq;
   public:
    PriorityQueue() {
        // Implement the constructor here
    }

    /**************** Implement all the public functions here ***************/

    void insert(int element) {
        // Implement the insert() function here
        pq.push_back(element);
        int i=pq.size()-1;
        while((pq[i]>pq[(i-1)/2])&&i>0){
            int temp=pq[i];
            pq[i]=pq[(i-1)/2];
            pq[(i-1)/2]=temp;
            i=(i-1)/2;
        }
        return;
    }

    int getMax() {
        // Implement the getMax() function here
        if(pq.size()==0){
            return 0;
        }else{
            return pq[0];
        }
    }

    int removeMax() {
        // Implement the removeMax() function here
        if(pq.size()==0){
            return -1;
        }
        int temp=pq[0];
        pq[0]=pq[pq.size()-1];
        pq.pop_back();
        // down heapify
        int i=0;
        while((i<pq.size())&&(pq[i]<pq[2*i+1]||pq[i]<pq[2*i+2])&&(2*i+1)<pq.size()&&(2*i+2)<pq.size()){
            int k=max(pq[2*i+1],pq[2*i+2]);
            int j;
            if(k==pq[2*i+1]){
                j=2*i+1;
                int t=pq[i];
                pq[i]=pq[2*i+1];
                pq[2*i+1]=t;
            }else if(k==pq[2*i+2]){
                j=2*i+2;
                int t=pq[i];
                pq[i]=pq[2*i+2];
                pq[2*i+2]=t;
            }
            i=j;
        }
        return temp;
    }

    int getSize() { 
        // Implement the getSize() function here
        return pq.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function here
        return (pq.size()==0);
    }
};

int main() {
    PriorityQueue pq;
    int choice;
    cin >> choice;

    while (choice != -1) {
        switch (choice) {
            case 1:  // insert
                int element;
                cin >> element;
                pq.insert(element);
                break;
            case 2:  // getMax
                cout << pq.getMax() << "\n";
                break;
            case 3:  // removeMax
                cout << pq.removeMax() << "\n";
                break;
            case 4:  // size
                cout << pq.getSize() << "\n";
                break;
            case 5:  // isEmpty
                cout << (pq.isEmpty() ? "true\n" : "false\n");
            default:
                return 0;
        }
        
        cin >> choice;
    }
}