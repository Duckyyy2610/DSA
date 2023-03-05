// Có n dự án bạn có thể tham dự. Đối với mỗi dự án, 
// bạn biết ngày bắt đầu và ngày kết thúc của dự án và số tiền bạn sẽ nhận được khi hoàn thành nó. 
// Bạn chỉ có thể tham dự một dự án trong một ngày. Số tiền tối đa bạn có thể kiếm được là bao nhiêu?

// Input Format

// Dòng đầu tiên chứa số nguyên n: số lượng dự án. Sau đó, có n dòng. Mỗi dòng như vậy có ba số nguyên ai, bi và pi: ngày bắt đầu, ngày kết thúc và tiền thưởng.

// Constraints

// 1≤n≤2⋅10^5; 1≤ai≤bi≤10^9; 1≤pi≤10^9;

// Output Format

// In ra đáp án của bài toán

// Sample Input 0

// 4
// 2 4 4
// 3 6 6
// 6 8 2
// 5 7 3
// Sample Output 0

// 7
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct Project{
    int s, e, w;
    friend istream& operator >>(istream&in , Project &a)
    {
        in>>a.s>>a.e>>a.w;
        return in;
    }
};
int binary(Project a[], int i){
    int l=0, r=i-1, res=-1;
    while(l<=r)
    {
        int m=(l+r)/2;
        if(a[m].e<a[i].s)
        {
            res=m;
            l=m+1;
        }
        else r=m-1;
    }
    return res;
}
int main() {
    int n;
    cin>>n;
    Project a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n,[](Project a, Project b)->bool{
        return a.e<b.e;
    });
    long long dp[n]={0};
    dp[0]=a[0].w;
    for(int i=1;i<n;i++)
    {
        long long tmp=a[i].w;
        int res=binary(a, i);
        if(res!=-1)
        {
            tmp+=dp[res];
        }
        dp[i]=max(dp[i-1],tmp);
    }
    cout<<dp[n-1];
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
