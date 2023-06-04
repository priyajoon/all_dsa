#include<bits/stdc++.h>
using namespace std;

const int size=10;

typedef struct node{
    int prn;
    int marks;
    int link;
}node;

class Hash{

    public:
    node arr[size];

    void init(){
        for(int i=0;i<size;i++){
            
                arr[i].prn=-1;
                arr[i].marks=-1;
                arr[i].link=-1;
            
        }
    }

    void display(){
        cout<<"Index"<<setw(7)<<"PRN"<<setw(11)<<"Marks"<<setw(10)<<"Link"<<endl;
        for(int i=0;i<size;i++){
            cout<<i<<setw(10)<<arr[i].prn<<setw(10)<<arr[i].marks<<setw(10)<<arr[i].link<<endl;
        }
    }

    int isfull(){
        for(int i=0;i<size;i++){
            if(arr[i].prn==-1){
                return 0;
            }
        }
        return 1;
    }

    int hashfunc(int key){
        return key%size;
    }

    void insert(){
        node x;
        int index,prev,prevl,prmark;
        if(isfull()){
            cout<<"table is full"<<endl;
        }

        cout<<"enter prn = ";
        cin>>x.prn;
        cout<<"enter marks = ";
        cin>>x.marks;
        x.link=-1;
        index=hashfunc(x.prn);

        if(arr[index].prn==-1){
            arr[index]=x;
        }
        else if(index==hashfunc(arr[index].prn)){
            while(arr[index].link!=-1){
                index=arr[index].link;
            }

            prev=index;
            while(arr[index].prn!=-1){
                index=(index+1)%size;
            }
            arr[index]=x;
            arr[prev].link=index;
        }
        else{
            
            prev=arr[index].prn;
            prevl=arr[index].link;
            prmark=arr[index].marks;
            int purana=index;

            arr[index]=x;

            while(arr[index].prn!=-1){
                index=(index+1)%size;
            }

            arr[index].prn=prev;
            arr[index].link=prevl;
            arr[index].marks=prmark;

            for(int i=0;i<10;i++){
                if(arr[i].link==purana){
                    arr[i].link=index;
                    break;
                }
            }
        }
    }

    void search(int key){
        int index;
        index=hashfunc(key);
        while(arr[index].prn!=key){
            index=(index+1)%size;
        }
        if(arr[index].prn==key){
             cout<<"PRN is present in table"<<endl;
            cout<<"PRN = "<<arr[index].prn<<"   "<<"Marks = "<<arr[index].marks<<endl;
        }
         else{
            cout<<"PRN not found !!!"<<endl;
        }
    }


    int del(int key){
        node temp,dummy;
        dummy.prn=-2;
        dummy.marks=-2;
        int ind;
        ind=hashfunc(key);
        while(arr[ind].prn!=-1){
            if(arr[ind].prn==key){
                temp=arr[ind];
                arr[ind]=dummy;
                return temp.prn;
            }
            ind=(ind+1)%size;


        }
        return -1;

    }


};

int main(){
    int prn,x,y,n;
    Hash h;
    h.init();
    int ch;
    char c;
    do{
        cout<<"********Hash Table***"<<endl;
        cout<<"1. Insert "<<endl;
        cout<<"2. Search "<<endl;
        cout<<"3. Delete "<<endl;
        cout<<"4. Display "<<endl;
        cout<<"5. exit "<<endl;
        cout<<"Enter your choice = ";
        cin>>ch;
        switch(ch){
            case 1:
                cout<<"To insert "<<endl;
                cout<<"enter nu. of values you want to insert = ";
                cin>>n;
                for(int i=0;i<n;i++){
                    h.insert();
                }
                
                
                
                
                cout<<"element inserted"<<endl;
                break;

            case 2:
                cout<<"Enter prn to search ";
                cin>>prn;
                h.search(prn);
                break;

            case 3:
                //cout<<"not done"<<endl;
                cout<<"Enter prn to Delete ";
                cin>>prn;
                x=h.del(prn);
                if(x==-1){
                    cout<<"not found"<<endl;
                }
                else{
                    cout<<"prn = "<<x<<" is deleted"<<endl;
                }

                break;

            case 4:
                h.display();
                break;
            case 5:
                 exit(0);
                 break;
            
        }
        //cout<<"do you want to continue y/n = ";
        fflush(stdin);
        //cin>>c;


    }while(1);
    return 0;
}