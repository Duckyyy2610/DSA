#include<bits/stdc++.h>
using namespace std;
int n, m;
int parent[1005], size[1005];
void init()
{
    for(int i=1;i<=n;i++)
    {
        parent[i]=i;
        size[i]=1;
    }
}
int Find(int u)
{
    if(u == parent[u]) return u;
    else return parent[u]=Find(parent[u]);
}
bool Union(int u, int v)
{
    u=Find(u);
    v=Find(v);
    if(u == v) return false;
    if(size[u]<size[v])
    {
        size[v]+=size[u];
        parent[u]=v;
    }
    else
    {
        size[u]+=size[v];
        parent[v]=u;
    }
    return true;
}
int main()
{
    init();
    Union(1, 2);
    Union(2, 3);
    Union(5, 6);
    Union(3, 5);
    cout<<parent[3];
}