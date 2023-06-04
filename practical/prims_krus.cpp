#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int>> pairInt;

class mst{
    int n,m;
    int adj[100][100];
    int id[100];
    bool visited[100];
    vector<pair<int, pair<int, int>>> p;
    
    public:
        mst(){
            n=0;
            m=0;
            for(int i=0;i<100;i++){
                id[i]=i;
            }
            for(int i=0;i<100;i++){
                for(int j=0;j<100;j++){
                    adj[i][j]=0;
                }
            }
        }

        void input(){
            cout << "ENTER NUMBER OF NODES AND EDGES " << endl;
            cin >> n >> m;
            cout << "ENTER EDGES CONNECTING NODES AND EDGE's WEIGHT" << endl;
            for (int i = 0; i < m; i++)
            {
                int x, y, weight;
                cin >> x >> y >> weight;
                p.push_back(make_pair(weight, make_pair(x, y)));
                adj[x][y] = weight;
                adj[y][x] = weight;
            }
        }

        void Union(int x,int y){
            id[root(x)]=root(y);
        }

        int root(int x){
            if(id[x]==x){
                return x;
            }
            else{
                return root(id[x]);
            }
        }

        void kruskals(){
            int mncost=0;
            sort(p.begin(),p.end());
            cout<<"Weight and edges selected = "<<endl;
            for(int i=0;i<m;i++){
                if(root(p[i].second.first)!=root(p[i].second.second)){
                    cout<<"WEIGHT : "<<p[i].first<<" NODES : "<<p[i].second.first<<" "<<p[i].second.second<<" "<<endl;
                    mncost+=p[i].first;
                    Union(p[i].second.first,p[i].second.second);
                }
            }
            cout << "COST BY KRUSHKALS IS :" << mncost << endl;


        }

        void Prims(){
            //memset(visited, false, sizeof(visited));
            for(int i=0;i<n;i++){
                visited[i]=false;
            }
            visited[0]=true;
            int mncost=0;
            
            for(int k=0;k<n-1;k++){
                int min=INT_MAX;
                int start, end;
                for(int i=0;i<n;i++){
                    if(visited[i]==false){
                        continue;
                    }

                    for(int j=0;j<n;j++){
                        if(adj[i][j]==0 || visited[j]==true){
                            continue;
                        }
                        if(adj[i][j]<min){
                            start=i;
                            end=j;
                            min=adj[i][j];
                        }
                    }
                }
                cout << "WEIGHT :  " << adj[start][end] << " NODES : " << start << " " << end << endl;
                mncost += adj[start][end];
                visited[start] = true;
                visited[end] = true;

            }
            cout << "COST BY PRIMS : " << mncost << endl;
        }

};

int main()
{
    int in;
    mst t;
    do
    {
        cout << "----------------------------------------------------" << endl;
        cout << "1. ENTER INPUT " << endl;
        cout << "2. KRUSHKALS " << endl;
        cout << "3. PRIMS" << endl;
        cout << "0. EXIT" << endl;
        cout << "----------------------------------------------------" << endl;
        cin >> in;
        switch (in)
        {
        case 1:
            t.input();
            break;
        case 2:
            t.kruskals();
            break;
        case 3:
            t.Prims();
            break;
        default:
            cout << "END" << endl;
        }
    } while (in);
}
