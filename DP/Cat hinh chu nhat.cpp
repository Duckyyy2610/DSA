// Cho một hình chữ nhật a × b, nhiệm vụ của bạn là cắt nó thành các hình vuông. Trên mỗi lần cắt, bạn có thể chọn một hình chữ nhật và cắt nó thành hai hình chữ nhật sao cho tất cả độ dài các cạnh vẫn là số nguyên. Số lần di cắt tối thiểu có thể là bao nhiêu?

// Input Format

// Dòng duy nhất chứa 2 số nguyên a và b.

// Constraints

// 1<=a,b<=500;

// Output Format

// In ra số lần cắt tối thiểu

// Sample Input 0

// 3 5
// Sample Output 0

// 3
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int dp[502][502];

int main() {
    int a,b; cin>>a>>b;
    for(int i=1;i<=a;i++)
    {
        for(int j=1;j<=b;j++) dp[i][j]=1e9;
    }
    for(int i=1;i<=a;i++)
    {
        dp[i][i]=0;
    }
    for(int i=1;i<=a;i++)
    {
        for(int j=1;j<=b;j++)
        {
            for(int k=1;k<i;k++)
            {
                dp[i][j]=min(dp[i][j], dp[k][j] + dp[i-k][j] +1);
            }
            for(int k=1;k<j;k++)
            {
                dp[i][j]=min(dp[i][j], dp[i][k] + dp[i][j-k] + 1);
            }
        }
    }
    cout<<dp[a][b];
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
