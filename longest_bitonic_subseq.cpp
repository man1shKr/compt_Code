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
    int a[n],dp[n],dp1[n],dp2[n];
    for(i=0;i<n;i++)
    {
       cin>>a[i];
       dp[i]=1;
       dp1[i]=1;
    }
    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(a[j]<a[i])
                dp[i]=mx(dp[j]+1,dp[i]);
        }
    }
    for(i=n-2;i>=0;i--)
    {
        for(j=n-1;j>i;j--)
        {
            if(a[j]<a[i])
                dp1[i]=mx(dp1[j]+1,dp1[i]);
        }
    }
    for(int k=0;k<n;k++)
    {
        dp2[k]=dp[k]+dp1[k]-1;
    }
    sort(dp2,dp2+n);
    cout<<"length of longest bitonic subsequence is : "<<dp2[n-1]<<"\n";
    return 0;
}
