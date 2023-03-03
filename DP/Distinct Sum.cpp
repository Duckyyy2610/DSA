// Cho mảng A[] gồm N phần tử là số nguyên dương, xét tất cả các tập con của A[] và tính tổng các phần tử trong tập này (bao gồm cả tập rỗng), sau đó liệt kê các tổng khác nhau có thể tạo thành theo thứ tự tăng dần.

// Input Format

// Dòng đầu tiên là N : số lượng phần tử trong mảng; Dòng thứ 2 gồm N phần tử của mảng A[]

// Constraints

// 1<=N<=100; 1<=A[i]<=100;

// Output Format

// In ra các tổng có thể tạo thành từ các tập con của A[]

// Sample Input 0

// 3
// 4 1 2 
// Sample Output 0

// 0 1 2 3 4 5 6 7 

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int max(int a, int b){
    if(a<b) return b;
    return a;
}
int main() {
    int n;
    cin>>n;
    int a[n+1], sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    int dp[n+1][sum+1];
    memset(dp,0, sizeof(dp));
    for(int i=0;i<n;i++)
    {
        dp[i][0]=1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            dp[i][j]=dp[i-1][j];
            if(j>=a[i])
            {
                dp[i][j]=max(dp[i][j], dp[i-1][j-a[i]]);
            }
        }
    }
    for(int i=0;i<=sum;i++)
    {
        if(dp[n][i]) cout<<i<<" ";
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
