// Bạn được cung cấp một ma trận nhị phân có N dòng và M cột chỉ bao gồm các số 0 và 1, hãy tìm hình vuông lớn nhất trong ma trận mà chỉ chứa toàn số 1.

// Input Format

// Dòng đầu tiên gồm 2 số N và M; N dòng tiếp theo mỗi dòng M số nguyên;

// Constraints

// 1<=N,M<=500; 0<=A[i][j]<=1;

// Output Format

// In ra kết quả đáp án của bài toán

// Sample Input 0

// 4 4
// 1 1 0 0
// 1 1 1 1
// 1 1 0 1
// 1 0 1 0
// Sample Output 0

// 2
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n,m;
    cin>>n>>m;
    int a[n+1][m+1];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
            // cout<<a[i][j]<<" ";
        }
        // cout<<"\n";
    }
    int Max=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][j])
            {
                if(i>1 && j>1)
                {
                   a[i][j]= min({a[i-1][j], a[i][j-1], a[i-1][j-1]})+1;
                    Max=max(Max, a[i][j]);
                
                }
            }
            
        }
    }
    cout<<Max;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
