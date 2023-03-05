
// 6 10 1 6
// 1 2 16
// 1 3 13
// 2 3 10
// 2 4 12
// 3 2 4
// 3 5 14
// 4 3 9
// 4 6 20
// 5 4 7
// 5 6 4
//Output: 23
#include<bits/stdc++.h>
using namespace std;
int n, m, graph[1005][1005], rgraph[1005][1005], s, t, parent[1005];
void init()
{
	cin>>n>>m>>s>>t;
	while(m--)
	{
		int x, y, flowCapacity;
		cin>>x>>y>>flowCapacity;
		graph[x][y]=flowCapacity;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			rgraph[i][j]=graph[i][j];
		}
	}
	memset(parent, 0, sizeof(parent));
	parent[s]=-1;
}
bool BFS(int s, int t, int n)
{
	bool visited[n+1];
	memset(visited, false, sizeof(visited));
	queue<int> q;
	q.push(s);
	visited[s]=true;
	while(!q.empty())
	{
		int u=q.front(); q.pop();
		for(int v=1;v<=n;v++)
		{
			if(!visited[v] && rgraph[u][v])
			{
				q.push(v);
				visited[v]=true;
				parent[v]=u;
			}
		}
	}
	return visited[t]==true;
}
void Ford_Fulkerson()
{
	int source=s, sink=t, maxFlowToSink=0;
	while(BFS(s, t, n))
	{
		int minFlow=(int)1e9;
		int v=sink;
		while(v!=source)
		{
			int prev=parent[v];
			minFlow=min(minFlow, rgraph[prev][v]);
			v=prev;
		}
		v=sink;
		while(v!=source)
		{
			int prev=parent[v];
			rgraph[prev][v]-=minFlow;
			rgraph[v][prev]+=minFlow;
			v=prev;
		}
		maxFlowToSink+=minFlow;
	}
	cout<<maxFlowToSink;
}
int main()
{
	init();
	Ford_Fulkerson();
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)
//		{
//			cout<<rgraph[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
}