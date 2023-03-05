// Cho dãy số A[] gồm N số. 
// Nhiệm vụ của bạn là tìm tổng lớn nhất của dãy 
// con được sắp theo thứ tự tăng dần của dãy A[]. 
// Ví dụ với dãy A[] = {1, 101, 2, 3, 100, 4, 5} ta có kết quả 
// là 106 = 1 + 2 + 3 + 100. Với dãy A[] = {10, 7, 5} ta có kết quả là 10. Với dãy A[] = {1, 2, 3, 5} ta có kết quả là 11.

// Input Format

// Dòng đầu tiên đưa vào N là số phần tử của dãy A[]; Dòng tiếp theo đưa vào N số A[i]; các số được viết cách nhau một vài khoảng trống.

// Constraints

// 1≤N≤1000; 0≤A[i]≤1000.

// Output Format

// Đưa ra kết quả của bài toán trên 1 dòng

// Sample Input 0

// 8
// 2 12 3 15 3 16 11 4 
// Sample Output 0

// 45
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin>>n;
    long long a[n],dp[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        dp[i]=a[i];
    }
    long long max1=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(a[i]>a[j])
            {
                dp[i]=max(dp[i],dp[j]+a[i]);
                max1=max(dp[i],max1);
            }
        }
    }
    cout<<max1;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
