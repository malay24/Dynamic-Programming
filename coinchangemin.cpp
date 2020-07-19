#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,sum;
    cin>>n;
    cin>>sum;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[n];
    int t[n+1][sum+1];
    for(int i=0;i<n+1;i++)
        for(int j=0;j<sum+1;j++)
    {
        if(j==0)
        t[i][j]=0;
        if(i==0)
            t[i][j]=INT_MAX-1;
    }
    for(int j=1;j<sum+1;j++)
    {
        if(j%arr[0]==0)
            t[1][j]=j/arr[0];
            else
                t[1][j]= INT_MAX-1;
        //cout<<t[1][j];
    }
    for(int i=2;i<n+1;i++)
        {
            for(int j=1;j<sum+1;j++)
    {
        if(arr[i-1]<=j)
            t[i][j]= min(t[i][j-arr[i-1]]+1,t[i-1][j]);
        else
            t[i][j]=t[i-1][j];
    }
        }
    cout<<t[n][sum]<<endl;
    return 0;
}
