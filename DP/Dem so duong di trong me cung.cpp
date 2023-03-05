// // Cho mê cung được mô tả bởi một ma trận kí tự gồm N hàng và N cột. Mỗi ô trên ma trận chứa kí tự '.' 
// tương ứng với đường đi và dấu * tương ứng với bẫy. Một con chuột muốn đi từ ô (1, 1) tới ô (N, N) và 
// chỉ được di chuyển khi một ô nào đó là đường đi và nó được di chuyển sang phải hoặc xuống dưới. 
// Hãy đếm số cách con chuột có thể di chuyển tới đích. Vì kết quả quá lớn nên hãy lấy dư với 10^9 + 7

// Input Format

// Dòng đầu tiên là N; N dòng tiếp theo mỗi dòng là N kí tự

// Constraints

// 1<=N<=1000

// Output Format

// Số đường đi tối đa

// Sample Input 0

// 4
// ....
// .*..
// ...*
// *...
// Sample Output 0

// 3
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
long long mod=1e9+7;
int main() {
    int n;
    cin>>n;
    char a[n+1][n+1];int dp[n+1][n+1];
    memset(dp, 0, sizeof(dp));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
        }
    }
    dp[1][1]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i][j]=='*') dp[i][j]=0;
            else
            {
                if(i>1)
                {
                    dp[i][j]+=dp[i-1][j];
                    dp[i][j]%=mod;
                }
                if(j>1)
                {
                    dp[i][j]+=dp[i][j-1];
                    dp[i][j]%=mod;
                }
            }
        }
    }
    cout<<dp[n][n];
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
