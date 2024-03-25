#include <vector>
#include <climits>
#include <iostream>
using namespace std;
// #include "Solution.h"
class Polynomial {
    
        // Name of your array (Don't change this)
    int capacity;
    // Complete the class
    public:
    int *degCoeff;  
    Polynomial(){
        degCoeff=new int[5];
        capacity=5;
    }
    Polynomial(Polynomial const &p){
        this->degCoeff= new int[p.capacity];
        for(int i=0;i<p.capacity;i++){
                this->degCoeff[i]=p.degCoeff[i];
        }
        this->capacity=p.capacity;
    }
    void setCoefficient(int degree,int coeff){
        while(degree>=capacity){
            int* arr=new int[2*capacity];
            for(int i=0;i<capacity;i++){
                arr[i]=degCoeff[i];
            }
        delete [] degCoeff;
        degCoeff=arr;
        capacity*=2;
        }
        degCoeff[degree]=coeff;
    }
    Polynomial operator+(Polynomial p2){
        // int c=capacity+p2.capacity;
        for(int i=0;i<capacity&& i<p2.capacity;i++){
            degCoeff[i]+=p2.degCoeff[i];
            // this->setCoefficient(i,degCoeff[i]);
        }
                    // this->setCoefficient(i,degCoeff[i]);

        return *this;
    }
    Polynomial operator-(Polynomial const &p2){

        for (int i = 0; i < capacity&& i<p2.capacity; i++) {
            degCoeff[i] -= p2.degCoeff[i];
        }
        return *this;
    }
    Polynomial operator*(Polynomial const &p2){
        Polynomial p;
        int*arr=new int[this->capacity+p2.capacity];
        delete [] p.degCoeff;
        p.degCoeff=arr;
        // for(int i=0;i<(this->capacity+p2.capacity);i++){
        //     arr[i]=0;
        // }
        for(int i=0;i<this->capacity;i++){
            for(int j=0;j<p2.capacity;j++){
                arr[i+j]=this->degCoeff[i]*p2.degCoeff[j];
            }
        }
        // delete [] degCoeff;
        // degCoeff=arr;
        return p;
    }
    Polynomial operator=(Polynomial const &p){
        this->degCoeff= new int[p.capacity];
        for(int i=0;i<p.capacity;i++){
                this->degCoeff[i]=p.degCoeff[i];
        }
        this->capacity=p.capacity;
    }
    void print(){
        for(int i=0;i<this->capacity;i++){
            if(degCoeff[i]!=0){
                cout<<degCoeff[i]<<"x"<<i<<" ";
            }
        }
        cout<<endl;
    }
};



//Driver program to test above functions
int main()
{
    int count1,count2,choice;
    cin >> count1;
    
    int *degree1 = new int[count1];
    int *coeff1 = new int[count1];
    
    for(int i=0;i < count1; i++) {
        cin >> degree1[i];
    }
    
    for(int i=0;i < count1; i++) {
        cin >> coeff1[i];
    }
    
    Polynomial first;
    for(int i = 0; i < count1; i++){
        first.setCoefficient(degree1[i],coeff1[i]);
    }
    
    cin >> count2;
    
    int *degree2 = new int[count2];
    int *coeff2 = new int[count2];
    
    for(int i=0;i < count2; i++) {
        cin >> degree2[i];
    }
    
    for(int i=0;i < count2; i++) {
        cin >> coeff2[i];
    }
    
    Polynomial second;
    for(int i = 0; i < count2; i++){
        second.setCoefficient(degree2[i],coeff2[i]);
    }
    
    cin >> choice;
    
    switch(choice){
            // Add
        case 1:
        {
            Polynomial result1 = first + second;
            result1.print();
            break;
        }
            // Subtract
        case 2 :
        {
            Polynomial result2 = first - second;
            result2.print();
            break;
        }
            // Multiply
        case 3 :
        {
            Polynomial result3 = first * second;
            result3.print();
            break;
        }
        case 4 : // Copy constructor
        {
            Polynomial third(first);
            if(third.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
        case 5 : // Copy assignment operator
        {
            Polynomial fourth(first);
            if(fourth.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
    }
    
    return 0;
}