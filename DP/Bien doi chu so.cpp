// Cho hai xâu ký tự str1, str2 bao gồm các ký tự in thường và các thao tác dưới đây: Insert: chèn một ký tự bất kỳ vào str1. Delete: loại bỏ một ký tự bất kỳ trong str1. Replace: thay một ký tự bất kỳ trong str1. Nhiệm vụ của bạn là đếm số các phép Insert, Delete, Replace ít nhất thực hiện trên str1 để trở thành str2.

// Input Format

// Dòng 1 là xâu str1; Dòng 2 là xâu str2;

// Constraints

// 1<=len(str1), len(str2)<=100;

// Output Format

// Đưa ra kết quả của bài toán

// Sample Input 0

// geek gesek
// Sample Output 0

// 1

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;


int main() {
    string s, t;
    cin>>s>>t;
    int n=s.size(), m=t.size();
    int dp[n+1][m+1];
    memset(dp, 0, sizeof(dp));
    for(int i=1;i<=n;i++)
    {
        dp[i][0]=i;
    }
    for(int i=1;i<=m;i++)
    {
        dp[0][i]=i;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s[i-1]==t[j-1])
            {
                dp[i][j]=dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]})+1;
            }
        }
    }
    cout<<dp[n][m];
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
