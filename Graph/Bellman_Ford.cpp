// Input:

// 2

// 3  3

// 1  2 -1

// 2  3  4

// 3  1 -2

// 3  3

// 1  2 -1

// 2  3  2

// 3  1 -2

//Output: 

//0

//1
 
#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int x, y, w;
};
int n, m;
vector<edge> Edge;

void init()
{
	Edge.clear();
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x, y, w;
		cin>>x>>y>>w;
		Edge.push_back(edge{x, y, w});	
	}
}
bool Bellman_Ford(int s)
{	
	int d[n+1];
	fill(d+1, d+n+1, (int)1e9);
	d[s]=0;
	for(int i=1;i<=n-1;i++)
	{
		for(edge e : Edge)
		{
			int u=e.x, v=e.y, w=e.w;
			if(d[u]<(int)1e9)
			{
				d[v]=min(d[v], d[u]+w);
			}
		}
	}
	for(int i=1;i<=n-1;i++)
	{
		for(edge e : Edge)
		{
			int u = e.x, v=e.y, w=e.w;
			if(d[u]<(int)1e9)
			{
				if(d[v]>d[u]+w)
				{
					d[v]=d[u]+w;
					return true;
				}
			}
		}
	}
	return false;
}
bool negativeCycle()
{
	int d[n+1];
	fill(d+1, d+n+1, (int)1e9);
	for(int i=1;i<=n;i++)
	{
		if(d[i]==(int)1e9)
		{
			if(Bellman_Ford(i))
			{
				return true;
			}
		}
	}
	return false;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		init();
//		for(edge x : Edge)
//		{
//			cout<<x.x<<" "<<x.y<<" "<<x.w<<"\n";
//		}
		if(negativeCycle()) cout<<1;
		else cout<<0;
		cout<<endl;
	}
}