#include <bits/stdc++.h>
using namespace std;
#define EMPTY_STRING ""
//Write a C++ program to implement Huffman coding text compression algorithm.
//Build the Huffman Tree using characters and their frequencies input from user.
//Encode a given string by using codes generated from Huffman tree and decode the bit sequence entered by the user
//Test case:
//Character and frequency: a-1, b-2, c-3,d-4,e-5,f-6,g-7,h-8
class node{
    public:
        char c;
        int f;
        node* left;
        node*right;
};

node* getnode(char c,int f,node* left,node* right){
    node * n=new node();
    n->c=c;
    n->f=f;
    n->left=left;
    n->right=right;
    return n;
}

class comp{

    public:
        bool operator()(node*l,node*r){
        return l->f>r->f;
    }
};

bool isleaf(node* n){
    if(n->left==NULL and n->right==NULL){
        return true;
    }
    else{
        return false;
    }
}

void encode(node* root,string s,unordered_map<char,string>&huffmantable){
    if(root==NULL){
        return;
    }
    if (isleaf(root)) {
        if (s != EMPTY_STRING) {
            huffmantable[root->c] = s;
        } else {
            huffmantable[root->c] = "1";
        }
    }
    encode(root->left, s + "0", huffmantable);
    encode(root->right, s + "1", huffmantable);

}

void huffman(){
    unordered_map<char,int>freq;
    for(int i=0;i<8;i++){
        cout<<"enter the char : ";
        char c;cin>>c;
        cout<<"enter the freq : ";
        int f;cin>>f;
        freq.insert({c,f});
    }
    //---
    priority_queue<node*,vector<node*>,comp>pq;
    //---
    for(auto par:freq){
        pq.push(getnode(par.first,par.second,NULL,NULL));
    }
    while(pq.size()!=1){
        node* left=pq.top();
        pq.pop();
        node* right=pq.top();
        pq.pop();
        int sum=left->f+right->f;
        pq.push(getnode('#',sum,left,right));
    }
    node* root=pq.top();
    unordered_map<char,string>huffmantable;
    encode(root,EMPTY_STRING,huffmantable);
    cout << " Encoded Huffman Codes are:\n" << endl;
    for(auto par:huffmantable){
        cout<<par.first<<"--------"<<par.second<<endl;
    }
    cout<<"enter the code to be decoded"<<endl;
    string f;
    cin>>f;
    for(auto par:huffmantable){
        if(par.second==f){
            cout<<par.first<<endl;
            break;
        }
    }
}

int main(){
huffman();
return 0;
}