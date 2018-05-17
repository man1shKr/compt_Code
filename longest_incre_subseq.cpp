#include <bits/stdc++.h>

using namespace std;
int mx(int a,int b)
{
    if(a>=b)
        return a;
    else
        return b;
}
int main()
{
    int n,i,j;
    cout<<"enter length of sequence : ";
    cin>>n;
    int a[n],dp[n];
    for(i=0;i<n;i++)
    {
       cin>>a[i];
       dp[i]=1;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(a[j]<a[i])
                dp[i]=mx(dp[j]+1,dp[i]);
        }
    }
    sort(dp,dp+n);
    cout<<"length of longest increasing subsequence is : "<<dp[n-1]<<"\n";
    return 0;
}
