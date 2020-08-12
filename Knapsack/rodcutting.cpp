#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,W;
    cin>>n>>W;
    int len[n],price[n];
    for(int i=0;i<n;i++)
        cin>>len[i];
    for(int i=0;i<n;i++)
        cin>>price[i];
    int t[n+1][n+1];
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
    {
        if(i==0||j==0)
            t[i][j]=0;
    }
    for(int i=1;i<n+1;i++)
        for(int j=1;j<n+1;j++)
    {
        if(len[i-1]<=j)
            t[i][j]= max(price[i-1]+ t[i][j-len[i-1]],t[i-1][j]);
        else
            t[i][j]=t[i-1][j];
    }
    cout<<t[n][n];
    return 0;
}

