#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int const N=100000;
vector<int>g[N];
int deg[N];
int vis[N];
int mod=1000000007;

void topo(int n){
    queue<int>q;
    for(int i=0;i<n;i++){
        if(deg[i]==0) q.push(i);
    }
    while(q.size()>0){
        int v=q.front();
        q.pop();
        for(auto c : g[v]){
            deg[c]--;
            if(deg[c]==0) q.push(c);
        }
        cout<<v<<" ";
    }
}
void dfs(int s){
    cout<<s<<" ";
    vis[s]=1;
    for(auto c : g[s]){
        if(vis[c]) continue;
        dfs(c);
    }
}

void bfs(int startVertex) {
    
    queue<int> queue; 
    vis[startVertex] = true;
    queue.push(startVertex);

    while (!queue.empty()) {
        int currentVertex = queue.front();
        queue.pop();
        cout << currentVertex << " "; 
        for (int adjacentVertex : g[currentVertex]) {
            if (!vis[adjacentVertex]) {
                vis[adjacentVertex] = true;
                queue.push(adjacentVertex);
            }
        }
    }
}

void bfsDisconnected(int n) {

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            bfs(i);
        }
    }
}

signed main(){
    cout<<"enter the number of nodes : ";
    int n;cin>>n;

    cout<<"enter the number of edeges : ";
    int m;cin>>m;

    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        g[x].push_back(y);
        deg[y]++;
    }
    while(true){
        cout<<"1.DFS traversal"<<endl;
        cout<<"2.topological sort"<<endl;
        cout<<"3.BFS"<<endl;
        cout<<"4.EXIT"<<endl;
        cout<<"enter the choice : ";
        int ch;cin>>ch;
        if(ch==1){
            // cout<<"enter the start point of traversal : ";
            // int s;cin>>s;
            for(int i=0;i<n;i++){
                if(vis[i]) continue;
                dfs(i);
            }
            //dfs(s);
            cout<<endl;
            for(int i=0;i<n;i++){
                vis[i]=0;
            }
        }
        else if(ch==2){
            topo(n);
            for(int i=0;i<n;i++){
                vis[i]=0;
            }
            cout<<endl;
        }
        else if(ch==3){
            // cout<<"enter the start point of traversal : ";
            // int s;cin>>s;
            
            bfsDisconnected(n);
            cout<<endl;
            for(int i=0;i<n;i++){
                vis[i]=0;
            }
        }
        else{
            break;
        }
    }
    
    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
// 	int n, m;
// 	cout << "Enter the Number of Vertices and Edges :" << endl;
// 	cin >> n >> m;
// 	vector<int> graph[n + 1];
// 	queue<int> q;
// 	int arr[n + 1] = {0};
// 	for (int i = 0; i < m; i++)
// 	{
// 		int v1, v2;
// 		// cout << "E1-E2 : ";
// 		cin >> v1 >> v2;

// 		graph[v1].push_back(v2);
// 	}

// 	for (int i = 0; i < m; i++)
// 	{
// 		for (auto child : graph[i])
// 		{
// 			arr[child]++;
// 		}
// 	}

// 	for (int i = 0; i < n; i++)
// 	{
// 		if (arr[i] == 0)
// 		{
// 			q.push(i);
// 		}
// 	}
// 	// cout << q.size() << endl;

// 	while (q.size())
// 	{
// 		int x = q.front();
// 		for (auto child : graph[x])
// 		{
// 			arr[child]--;
// 			if (arr[child] == 0)
// 				q.push(child);
// 		}
// 		q.pop();
// 		cout << x << " ";
// 	}
// }