// 10 16
// 9 10
// 6 4
// 6 1
// 6 3
// 9 2
// 3 9
// 9 4
// 3 8
// 3 5
// 6 7
// 6 10
// 9 6
// 6 8
// 3 7
// 6 5
// 9 7

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <cstring>
using namespace std;
set<int> adj[1005];
int in[1005],n,m;
void input(){
    cin>>n>>m;
    memset(in, 0, sizeof(in));
    while(m--)
    {
        int x,y ;
        cin>>x>>y;
        adj[x].insert(y);
        in[y]++;
    }
}
void BFS(){
    queue<int> q;
    vector<int>topological;
    for(int i=1;i<=n;i++)
    {
        if(in[i]==0)q.push(i);
    }
    while(!q.empty())
    {
        int x=q.front(); q.pop();
        topological.push_back(x);
        for(int v : adj[x])
        {
            in[v]--;
            if(in[v]==0)
            {
                q.push(v);
                topological.push_back(v);
            }
            
        }
    }
    for(int x : topological) cout<<x<<" ";
    // if(topological.size()<n)cout<<1;
    // else cout<<0;
}
int main() {
    input();
    BFS();
    return 0;
}
