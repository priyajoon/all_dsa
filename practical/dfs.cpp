#include <bits/stdc++.h>
using namespace std;
#define MAX 10
class graph{

	int n,connected;
	int adj[10][10];
	bool visited[10];
	public:
        graph(int size=10){
			n=size;
			connected=0;
			for(int i=0;i<n;i++){
				visited[i]=false;
				for(int j=0;j<n;j++){
					adj[i][j]=0;
				}
			}
		}

		void input(){
			int e;
			cout<<"Enter number of edges = ";
			cin>>e;
			for(int i=0;i<e;i++ ){
				int u,v;
				cout<<"Enter connecting edge = ";
				cin>>u>>v;
				adj[u][v]=1;
				adj[v][u]=1;
			}
		}

		void display(){
			cout<<"Graph"<<endl;
			for(int i=0;i<n;i++){
				cout<<"  "<<i<<" ";
			}
			cout<<endl;
			for(int i=0;i<n;i++){
				cout<<i<<" : "<<" ";
				for(int j=0;j<n;j++){
					cout<<adj[i][j]<<" ";

				}
				cout<<endl;
			}
			cout<<endl;

		}

		void addedge(int u,int v){
			adj[u][v]=1;
			adj[v][u]=1;
		}

		void removeedge(int u,int v){
			adj[u][v]=0;
			adj[v][u]=0;
		}

		void clear_visited(){
			for(int i=0;i<n;i++){
				visited[i]=false;
			}
		}

		void dfs(int vertex){
			visited[vertex]=true;
			connected++;
			cout<<vertex<<" ";
			for(int i=0;i<n;i++){
				if(adj[vertex][i]==1 and visited[i]==false){
					dfs(i);
				}
			}
			return;
		}

		void bfs(int vertex){
			queue<int> q;
			visited[vertex]=true;
			q.push(vertex);
			while(!q.empty()){
				int x=q.front();
				q.pop();
				cout<<x<<" ";
				for(int i=0;i<n;i++){
					if(adj[x][i]==1 and visited[i]==false){
						q.push(i);
						visited[i]=true;
					}
				}
			}
			return;
		}

		bool is_connected(){
			clear_visited();
			connected=0;
			dfs(0);
			if(connected==n){
				return true;
			}
			int count=1;
			for(int i=0;i<n;i++){
				if(visited[i]==false){
					dfs(i);
					count++;
				}
			}
			cout<<endl;
			cout<<"Number of components = "<<count<<endl;
			return false;
		}

};

int main(){

	int n,u,v,vertex;
	cout<<"Number of nodes = ";
	cin>>n;
	graph g(n);
	int ch;

	do{
		cout<<"1. Input"<<endl;
		cout<<"2. display"<<endl;
		cout<<"3. Add Edge"<<endl;
		cout<<"4. Remove Edeg"<<endl;
		cout<<"5. DFS"<<endl;
		cout<<"6. BFS"<<endl;
		cout<<"7. Check if graph is connected or not"<<endl;
		cout<<"8. EXIT"<<endl;
		cout<<"enter your chpoice = ";
		cin>>ch;
		switch(ch){
			case 1:
			     g.input();
				 break;
		 	case 2:
			    g.display();
				break;
			case 3:
				cout<<"Enter first node= ";
				cin>>u;
				cout<<"Enter seconf node= ";
				cin>>v;
				g.addedge(u,v);
				break;
			case 4:
				cout<<"Enter first node= ";
				cin>>u;
				cout<<"Enter seconf node= ";
				cin>>v;
				g.removeedge(u,v);
				break;
			case 5:
				g.clear_visited();
			    cout<<"Enter vertex = ";
				cin>>vertex;
				g.dfs(vertex);
				cout<<endl;
				break;
			case 6:
				g.clear_visited();
			    cout<<"Enter vertex = ";
				cin>>vertex;
				g.bfs(vertex);
				cout<<endl;
				break;
			case 7:
			    if (g.is_connected())
                    cout << "The graph is Connected!"<<endl;
                else
                    cout << "The graph is NOT Connected!"<<endl;
                break;
			case 8:
				exit(0);

			
		}

	}while(ch!=8);
	return 0;
}
