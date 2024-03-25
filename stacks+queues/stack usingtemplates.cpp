#include<iostream>
#include<climits>
using namespace std;
template <typename T>
class StackUsingArray{
    T* data;
    int nextIndex;
    int capacity;
    public:
    StackUsingArray(){
        data=new T[capacity];
        nextIndex=0;
        capacity=4;
    }
    int size(){
        return nextIndex;
    }
    bool isEmpty(){
        return nextIndex==0;
    }
    void push(T element){
        if(nextIndex==capacity){
            // cout<<"stack full"<<endl;
            T *newData=new T[2*capacity];
            for(int i=0;i<capacity;i++){
                newData[i]=data[i];
            }
            capacity*=2;
            delete [] data;
            data=newData;
        }
        data[nextIndex]=element;
        nextIndex++;
        return;
    }
    T pop(){
        if(isEmpty()){
            cout<<"stack is empty"<<endl;
            return 0;
        }
        nextIndex--;
        return data[nextIndex];
    }
    T top(){
        if(isEmpty()){
            cout<<"stack is empty"<<endl;
            return 0;
        }
        return data[nextIndex-1];
    }
};
int main(){
    StackUsingArray <char>s;
    s.push(100);
    s.push(101);
    s.push(102);
    s.push(103);
    s.push(104);
    cout<<s.top()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.size()<<endl;
    cout<<s.isEmpty()<<endl;

}