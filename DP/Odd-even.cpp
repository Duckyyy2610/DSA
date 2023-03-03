// Bạn được cung cấp một mảng A gồm N giá trị nguyên dương. Một mảng con của mảng này được gọi là mảng con Chẵn lẻ nếu số lượng các số nguyên lẻ trong mảng con này bằng số lượng các số nguyên chẵn trong mảng con này.

// Tìm số mảng con Lẻ-Chẵn cho mảng đã cho.

// Input Format

// Dòng đầu chứa N; Dòng thứ 2 chứa N số nguyên trong dãy

// Constraints

// 1<=N<=2.10^5; 1<=A[i]<=10^9;

// Output Format

// In ra đáp án của bài toán

// Sample Input 0

// 4
// 1 2 1 2
// Sample Output 0

// 4
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    int n;
    cin>>n;
    map<int,int> mp;
    mp[0]=1;
    int odd=0, even=0, ans=0;   
    while(n--)
    {
        int x;
        cin>>x;
        if(x%2) odd++;
        else even++;
        
        ans+=mp[odd-even]++;
    }
    cout<<ans;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
