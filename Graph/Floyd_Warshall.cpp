//Input:
//5 6
//1 2 6
//1 3 7
//2 4 8
//3 4 9
//3 5 1
//4 5 2
//3
//1 5
//2 5
//4 3
//Output:
//
//8
//10
//3

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
int d[101][101];

void input(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j) d[i][j]=0;
            else d[i][j]=1e9;
        }
    }
    while(m--)
    {
        int x, y, w;
        cin>>x>>y>>w;
        d[x][y]=d[y][x]=w;
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                d[i][j]=min(d[i][j], d[i][k]+d[k][j]);
            }
        }
    }
    int q;
    cin>>q;
    while(q--)
    {
        int x, y; cin>>x>>y;
        cout<<d[x][y]<<"\n";
    }
}

int main() {
    input();
    return 0;
}
