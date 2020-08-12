#include<bits/stdc++.h>
using namespace std;

int subsetsum(int arr[],int n,int sum)
{
    bool t[n+1][sum+1];
    for(int i=0;i<n+1;i++)
        for(int j=0;j<sum+1;j++)
    {
        if(i==0)
            t[i][j]=false;
        if(j==0)
            t[i][j]=true;
    }
    for(int i=1;i<n+1;i++)
        for(int j=1;j<sum+1;j++)
    {
        if(arr[i-1]<=j)
            t[i][j]= t[i-1][j-arr[i-1]] || t[i-1][j];
        else
            t[i][j]=t[i-1][j];
    }
    vector<int> v;
    for(int i=0;i<=sum/2;i++)
    {
        if(t[n][i])
        v.push_back(i);
    }
    int l=v.size();
    int mn= sum - (2*v[l-1]);
    return mn;
}
int main()
{
    int n,sum=0;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int i=0;i<n;i++)
        sum+=arr[i];
    int res = subsetsum(arr,n,sum);
    cout<<res;
}
