// Một tên trộm có 1 cái túi có thể mang các đố vật với trọng lượng tối đa là V. 
// Hiện tại tên trộm muốn lựa chọn các đồ vật trong N đồ vật để ăn trộm, 
// mỗi đồ vật có trọng lượng là w[i] và giá trị là v[i]. 
// Hãy xác định tổng giá trị lớn nhất của các đồ vật mà tên trộm này lựa chọn sao cho trọng lượng của chúng không vượt quá V.

// Input Format

// Dòng đầu ghi 2 số N và V. Dòng tiếp theo ghi N số của mảng w. Sau đó là một dòng ghi N số của mảng v.

// Constraints

// V<=1000; N≤1000; 1<=w[i], c[i]<=500;

// Output Format

// In ra giá trị lớn nhất có thể đạt được.

// Sample Input 0

// 6 22
// 39 44 4 59 91 70 
// 47 26 92 33 6 69 
// Sample Output 0

// 92
// Sample Input 1

// 7 22
// 10 3 22 50 83 16 41 
// 99 97 54 19 50 70 48 
// Sample Output 1

// 196
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long f[1001][1001];
int main() {
    int n,V;
    cin>>n>>V;
    int v[n], w[n];
    for(int &x : w) cin>>x;
    for(int &x : v) cin>>x;
    long long Max=0;
    for(int i=0; i<n; i++)
    {
        for(int j=V; j>=0; j--)
        {
            f[i][j]=f[i-1][j];
            if(j>=w[i])
            {
                f[i][j]=max(f[i-1][j], f[i-1][j-w[i]] + v[i]);
                Max = max(Max, f[i][j]);
            }
        }
    }
    cout<<Max;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
