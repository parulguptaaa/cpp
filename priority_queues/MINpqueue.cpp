#include<vector>
#include<iostream>
using namespace std;
class PriorityQueue{
    vector<int> pq;
    public:
    PriorityQueue(){

    }
    bool isEmpty(){
        return pq.size()==0; 
    }
    int getSize(){
        return pq.size(); 
    }
    int getMin(){
        if(isEmpty()){
            return 0;
        }
        return pq[0];
    }
    void insert(int element){
        pq.push_back(element);
        int i=pq.size()-1;
        while((pq[i]<pq[(i-1)/2])&&i>0){
            int temp=pq[i];
            pq[i]=pq[(i-1)/2];
            pq[(i-1)/2]=temp;
            i=(i-1)/2;
        }
        return;
    }
    void print(){
        if(pq.size()==0){
            return;
        }
        for (int i=0;i<pq.size();i++){
            cout<<pq[i]<<" ";
        }
        return;
    }
    int removeMin(){
        if(pq.size()==0){
            return -1;
        }
        int temp=pq[0];
        pq[0]=pq[pq.size()-1];
        pq.pop_back();
        // down heapify
        int i=0;
        while((i<pq.size())&&(pq[i]>pq[2*i+1]||pq[i]>pq[2*i+2])&&(2*i+1)<pq.size()&&(2*i+2)<pq.size()){
            int k=min(pq[2*i+1],pq[2*i+2]);
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
};
// int main(){
//     PriorityQueue pq;
//     pq.insert(12);
//     pq.insert(6);
//     pq.insert(5);
//     pq.insert(100);
//     pq.insert(1);
//     pq.insert(9);
//     pq.insert(0);
//     pq.insert(14);
//     pq.removeMin();
//     pq.print();
// }
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
            case 2:  // getMin
                cout << pq.getMin() << "\n";
                break;
            case 3:  // removeMax
                cout<< pq.removeMin()<<"\n";
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
    // outplace heap sort
    // T(n)=O(nlogn), S(n)=O(n)
    while(!pq.isEmpty()){
        cout<<pq.removeMin()<<" ";
    }
}