// #include<iostream>
// #include<string>


#include <bits/stdc++.h>
using namespace std;
template<typename V>
class mapNode{
    public:
        string key;
        V value;
        mapNode*next;
        
        mapNode(string key, V value){
            this->key=key;
            this->value=value;
            next=NULL;
        }
        ~mapNode(){
            delete next;
        }
};
template<typename V>
class ourmap{
    mapNode<V>**buckets;
    int count;
    int numBuckets;
    public:
    ourmap(){
        count=0;
        numBuckets=5;
        buckets=new mapNode<V>*[numBuckets];
        for(int i=0;i<numBuckets;i++){
            buckets[i]=NULL;
        }
    }
    ~ourmap(){
        for(int i=0;i<numBuckets;i++){
            delete buckets[i];
        }
        delete [] buckets;
    }
    // ~ourmap(){
    // for(int i=0;i<numBuckets;i++){
    //     deleteLinkedList(buckets[i]);
    // }
    //     delete [] buckets;
    // }
    int msize(){
        return count;
    }
    void deleteLinkedList(mapNode<V>* head) {
        while (head != NULL) {
            mapNode<V>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    V getValue(string key){
        int bucketIndex=getBucketIndex(key);
        mapNode<V>* head=buckets[bucketIndex];
        while(head!=NULL){
            if(head->key==key){
                return head->value;
            }
            head=head->next;
        }
        return 0;
    }
    private:
    int getBucketIndex(string key){
        int hashCode=0;
        int currCoeff=1;
        for(int i=key.length()-1;i>=0;i--){
            hashCode+=key[i]*currCoeff;
            hashCode=hashCode%numBuckets;
            currCoeff*=37;
            currCoeff=currCoeff%numBuckets;
        }
        return hashCode%numBuckets;
    }
    void rehash(){
        mapNode<V>**temp=buckets;
        buckets=new mapNode<V>*[2*numBuckets];
        for(int i=0;i<2*numBuckets;i++){
            buckets[i]=NULL;
        }
        int oldBucketCount=numBuckets;
        numBuckets*=2;
        count=0;
        for(int i=0;i<oldBucketCount;i++){
            mapNode<V>*head=temp[i];
            while(head!=NULL){
                string key=head->key;
                V value=head->value;
                insert(key,value);
                head=head->next;
            }
        }
        for(int i=0;i<oldBucketCount;i++){
            mapNode<V>*head=temp[i];
            delete head;
        }
        delete [] temp;
    }
    public:
    double getLoadFactor(){
        return (1.0*count)/numBuckets;
    }
    void insert(string key, V value){
        int bucketIndex=getBucketIndex(key);
        mapNode<V>*head=buckets[bucketIndex];
        while(head!=NULL){
            if(head->key==key){
                head->value=value;
                return;
            }
            head=head->next;
        }
        head=buckets[bucketIndex];
        mapNode<V>*node=new mapNode<V>(key,value);
        node->next=head;
        buckets[bucketIndex]=node;
        count++;
        double loadFactor=(1.0*count)/numBuckets;
        if(loadFactor>0.7){
            rehash();
        }
    }
    V remove(string key){
        int bucketIndex=getBucketIndex(key);
        mapNode<V>* head=buckets[bucketIndex];
        mapNode<V>* prev=NULL;
        while(head!=NULL){
            if(head->key==key){
                if(prev==NULL){
                    buckets[bucketIndex]=head->next;
                }else{
                    prev->next=head->next;
                }
                V val=head->value;
                head->next=NULL;
                delete head;
                count--;
                return val;
            }
            prev=head;
            head=head->next;
        }
        return 0;
    }
};
int main(){
    ourmap<int> map;
    for(int i=0;i<10;i++){
        char c='0'+i;
        string key="abc";
        key=key+c;
        int value=i+1;
        map.insert(key,value);
        cout<<"load factor is: "<<map.getLoadFactor()<<endl;
    }
    map.remove("abc2");
    map.remove("abc7");
    
    for(int i=0;i<10;i++){
        char c='0'+i;
        string key="abc";
        key=key+c;
        cout<<key<<" : "<<map.getValue(key)<<endl;
    }
    cout<<map.msize()<<endl;
}