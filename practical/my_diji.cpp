#include <bits/stdc++.h>
using namespace std;

#define n 6

int min_dist(int dist[],bool sptSet[]){
    int min=INT_MAX;
    int min_index;
    for(int i=0;i<n;i++){
        if(sptSet[i]==false && dist[i]<=min){
            min=dist[i];
            min_index=i;
        }
    }
    return min_index;
}

void display(int dist[]){
    //cout<<"Distance from source = "<<endl;
    for(int i=0;i<n;i++){
        cout<<i<<"    "<<dist[i]<<endl;
    }
}

void construct_path(int prev[],int dest){
    vector<int> path;
    stack<int> s;
    int curr=dest;
    while(curr!=-1){
        s.push(curr);
        curr=prev[curr];
    }

    while(!s.empty()){
        path.push_back(s.top());
        s.pop();
    }

    for(int i=0;i<path.size();i++){
        cout<<path[i];
        if (i!= path.size() - 1) {
            cout << " -> ";
         }
    }
    
}

// void dis2(int dist[]){
    
//         for(int j=0;j<n;j++){
//             cout<<dist[j]<<" ";
//         }
//         cout<<endl;
    
// }

void dijkstra(int graph[n][n],int src){
    
    int dist[n];
    bool sptSet[n];
    int prev[n];
    for(int i=0;i<n;i++){
        dist[i]=INT_MAX;
        sptSet[i]=false;
        prev[i]=-1;
    }
    dist[src]=0;
    
    for(int count=0;count<n-1;count++){
        int u=min_dist(dist,sptSet);
        sptSet[u]=true;
        
        for(int i=0;i<n;i++){
            if(!sptSet[i] && graph[u][i] && dist[u]!=INT_MAX && dist[u]+graph[u][i]<dist[i]){
                dist[i]=dist[u]+graph[u][i];
                prev[i]=u;
            }
        }

        
    }
    display(dist);
 
    cout << "Shortest distances from source node " << src << ":\n";
    for (int i = 0; i < n; ++i) {
        cout << "Node " << i << ": " << dist[i] << "\tPath: ";
        construct_path(prev,i);
        cout<<endl;
    }
    

    
    
}






int main(){
    int e;
    // cout<<"Enter number of nodes = ";
    // cin>>n;
    cout<<"number of nodes = "<<n<<endl;
    cout<<"Enter number of edges = ";
    cin>>e;

	int adj[n][n];
	
	for (int i = 0; i< n; i++){
		for (int j = 0; j < n; j++){
			adj[i][j] = 0;
        }
    }
    cout<<"enter connecting edges & distance = ";
    for(int i=0;i<e;i++){
        int u,v;
        int wt;
        
        cin>>u>>v>>wt;
        adj[u][v]=wt;
        adj[v][u]=wt;

    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Shortest path for 0 "<<endl;
    for(int i=0;i<n;i++){
        cout<<i<<" ";
    }
    cout<<endl;
    dijkstra(adj,0);

    
    
    // cout<<"Distance from all elements "<<endl;


    // for(int i=0;i<n;i++){
    //     //cout<<"Distance from source = "<<endl;
    //     cout<<i<<" : ";
    //     dijkstra(adj,i);
    // }
   

    return 0;
}