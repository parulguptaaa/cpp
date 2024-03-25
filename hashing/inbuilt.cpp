#include <iostream>
#include<unordered_map>
#include<string>
using namespace std;
int main(){
    unordered_map<string,int> ourmap;
    // insert
    pair<string,int>p("abc",1);
    ourmap.insert(p);
    ourmap["def"]=2;
    // access
    cout<<ourmap["abc"]<<endl;
    cout<<ourmap.at("def")<<endl;
    // ourmap.at(ghi)=> error as key not found
    // ourmap["ghi"]=>gives zero if key does not exist 

    cout<<"size: "<<ourmap.size()<<endl;
    cout<<ourmap["ghi"]<<endl;
    cout<<"size: "<<ourmap.size()<<endl;

    // check presence
    // count can be only either 1 or 0
    if(ourmap.count("ghi")>0){
        cout<<"ghi is present"<<endl;
    }
    // erase 
    ourmap.erase("ghi");
    // iterator
    unordered_map<string,int> resmap;
    resmap["abc"]=0;
    resmap["abc1"]=1;
    resmap["abc2"]=2;
    resmap["abc3"]=3;
    resmap["abc4"]=4;
    unordered_map<string,int> ::iterator it=resmap.begin();
    while(it!=resmap.end()){
        cout<<"key:"<<it->first<<"value:"<<it->second<<endl;
        it++;
    }

}