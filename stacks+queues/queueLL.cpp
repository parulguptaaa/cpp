#include<iostream>
using namespace std;
template <typename T>
class Node{
public:
    T data;
    Node<T>*next;

    Node(T data){
        this->data=data;
        next=NULL;
    };
};
template <typename T>
class queueLL{
    Node<T>*head;
    Node<T>*tail;
    int size;

    public:
    queueLL(){
        head=NULL;
        tail=NULL;
        size=0;
    };
    int getSize(){
        return size;
    }
    bool isEmpty(){
        return size==0;
    }
    T front(){
        if(head==NULL){
            return -1;
        }
        return head->data;
    }
    void enqueue(T element){
        Node<T>*newNode=new Node<T>(element);
        if(head==NULL){
            head=newNode;
            tail=newNode;
            size++;
            return;
        }
        tail->next=newNode;
        tail=newNode;
        size++;
        return;
    }
    T dequeue(){
        if(head==NULL){
            return -1;
        }
        T a=head->data;
        Node<T>*y=head;
        delete head;
        head=y->next;
        size--;
        return a;
    }
};
int main() {
    
    queueLL <int>q;
    int t;
    cin >> t;

    while (t--) {
        int choice, input;
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                q.enqueue(input);
                break;
            case 2:
                cout << q.dequeue() << "\n";
                break;
            case 3:
                cout << q.front() << "\n";
                break;
            case 4:
                cout << q.getSize() << "\n";
                break;
            default:
                cout << ((q.isEmpty()) ? "true\n" : "false\n");
                break;
        }
    }
}

