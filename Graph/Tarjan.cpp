#include<bits/stdc++.h>
using namespace std;
int low[1005], disc[1005];
int n, m, cnt;
bool visited[1005];
vector<int> adj[1005], AP;
void init()
{
    cin>>n>>m;
    while(m--)
    {
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cnt=0;
    memset(low, 0, sizeof(low));
    memset(disc, 0, sizeof(disc));
    memset(visited, false, sizeof(visited));
}
void Tarjan(int u, int rep) // Dinh tru
{
    visited[u]=true;
    low[u]=disc[u]=++cnt;
    int child=0;
    for(int v :adj[u])
    {
        if(v == rep) continue;
        if(!visited[v])
        {
            Tarjan(v, u);
            child++;
            low[u] = min(low[u], low[v]);
            if(rep != -1 && disc[u]<=low[v])
            {
                AP.push_back(u);
            }
        }
        else
        {
            low[u] = min(low[u], disc[v]);
        }
    }
    if(rep == -1 && child > 1) AP.push_back(u);
}
vector<pair<int,int>> edge;
void DFS(int u, int par){ // Canh cau
    visited[u]=1;
    low[u]=disc[u]=++cnt;

    for(int v : adj[u])
    {
        if(v==par) continue;
        if(!visited[v])
        {
            DFS(v,u);
            low[u]=min(low[u],low[v]);
            if(disc[u]<low[v] && par!=-1)
            {
                edge.push_back({u,v});
            }
        }
        else
        {
            low[u]=min(low[u],low[v]);
        }    
        if(par==-1 && disc[u]<low[v]) edge.push_back({u,v});

    }
}
int main ()
{
    init();
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            Tarjan(i, -1);
        }
    }
    for(int x : AP) cout<<x<<" ";
}