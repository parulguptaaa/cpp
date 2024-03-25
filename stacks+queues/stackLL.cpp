#include<iostream>
using namespace std;
template <typename T>
class Node{
    public:
    T data;
    Node<T>* next;
    Node(T data){
        this->data=data;
        next=NULL;
    }
};
template <typename T>
class Stack{
    Node<T>*head;
    int size;
    public:
    Stack(){
        head=NULL;
        size=0;
    }
    int getSize(){
        return size;
    }
    bool isEmpty(){
        return size==0;
    }
    void push(T element){
        Node<T>*newNode=new Node<T>(element);
        if(head==NULL){
            head=newNode;
        }else{
            newNode->next=head;
            head=newNode;
        }
        size++;
        return;
    }
    T pop(){
        if(head==NULL){
            return 0;
        }else{
            T y=head->data;
            Node<T>*a=head->next;
            head->next=NULL;
            delete head;
            head=a;
            size--;
            return y;
        }
    }
    T top(){
        if(head==NULL){
            return 0;
        }else{
            return head->data;
        }
    }
};
int main(){
    Stack <char>s;
    s.push(100);
    s.push(101);
    s.push(102);
    s.push(103);
    s.push(104);
    cout<<s.top()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.getSize()<<endl;
    cout<<s.isEmpty()<<endl;

}
