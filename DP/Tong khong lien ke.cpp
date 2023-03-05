// Cho mảng A[] gồm N phần tử, nhiệm vụ của bạn là tính tổng lớn nhất của dãy con 
// trong mảng với một điều kiện đó là trong dãy con này không được có 2 phần tử nằm liền kề nhau.

// Input Format

// Dòng đầu tiên là N : số lượng phần tử trong mảng; Dòng thứ 2 là A[i];

// Constraints

// 1<=N<=10^6; 1<=A[i]<=1000;

// Output Format

// In ra kết quả của bài toán

// Sample Input 0

// 7
// 314 514 148 451 896 589 296 
// Sample Output 0

// 1706
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin>>n;
    long long a[n+1], dp[n+1];
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    dp[0]=0, dp[1]=a[1];
    long long Max=0;
    for(int i=2;i<=n;i++)
    {
        dp[i]=max(dp[i-1],dp[i-2]+a[i]);
        Max=max(dp[i], Max);

    }
    cout<<Max;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
