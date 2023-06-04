#include<bits/stdc++.h>
using namespace std;

queue <int> que;

int main(){
    int n,e;
    cout<<"Enter number of nodes = ";
    cin>>n;
    cout<<"Enter number of edges = ";
    cin>>e;

	

	int adj[n][n];
	int indegree[n] = {0};
	
	for (int i = 0; i< n; i++){
		for (int j = 0; j < n; j++){
			adj[i][j] = 0;
        }
    }
	
    for(int i=0;i<e;i++){
        int u,v;
        cout<<"Enter edges connecting = ";
        cin>>u>>v;
        adj[u][v]=1;
        indegree[v]++;
    }
	
	for (int i = 0; i < n; i++){
		if (indegree[i] == 0){
			que.push(i);
			
		}
	}

	if(que.empty()){
		cout<<"\nNot an acyclic directed graph!!";
	}
    vector<int> sorted;
	cout<<"topological Sort: ";
    while(!que.empty()){
	    int z=que.front();
	    que.pop();
	    sorted.push_back(z);
	    for(int i=0;i<n;i++){
	        indegree[i]--;
	        if(indegree[i]==0){
	            que.push(i);
	        }
	                                 
	                             
	    }
	                             
	                         
	                         
	}
	                         
	for(int i=0;i<sorted.size();i++){
	    cout<<sorted[i]<<" ";
	}
	cout<<endl;


	
}

