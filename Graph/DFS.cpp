// Cho đồ thị vô hướng G = được biểu diễn dưới dạng danh sách cạnh. Hãy thực hiện in ra danh sách các đỉnh được duyệt theo thuật toán DFS(s).

// Input Format

// Dòng đầu tiên là 2 số n và m và s, tương ứng với số lượng đỉnh, cạnh của đồ thị và đỉnh bắt đầu duyệt. Các đỉnh của đồ thị được đánh số từ 1 tới n. m dòng tiếp theo mỗi dòng chứa đỉnh u, v (u != v) tương ứng với một cạnh của đồ thị.

// Constraints

// 1<=s<=n<=1000; 1<=m<=n*(n-1)/2;

// Output Format

// In ra các đỉnh được duyệt theo thuật toán DFS(s). Chú ý trong quá trình mở rộng các đỉnh của thuật toán DFS luôn lựa chọn duyệt các đỉnh có thứ tự nhỏ hơn trước.

// Sample Input 0

// 5 5 3
// 5 2
// 3 2
// 5 4
// 5 3
// 5 1
// Sample Output 0

// 3 2 5 1 4 
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
vector<int>adj[1005];
bool visited[1005];

void DFS(int u){
    visited[u]=true;
    cout<<u<<" ";
    for(int v:adj[u])
    {
        if(!visited[v])DFS(v);
    }
}

int main() {
    int n,m,s;
    cin>>n>>m>>s;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        sort(adj[i].begin(),adj[i].end());
    }
    memset(visited, false, sizeof(visited));
    DFS(s);
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
