#include<bits/stdc++.h>
using namespace std;
void plcs(string a, string b)
{
    int m= a.length();
    int n= b.length();
    int t[m+1][n+1];
    for(int i=0;i<=m;i++)
        for(int j=0;j<=n;j++)
        if(i==0||j==0)
        t[i][j]=0;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
    {
        if(a[i-1]==b[j-1])
            t[i][j]=1+t[i-1][j-1];
        else
            t[i][j]=max(t[i-1][j],t[i][j-1]);
    }
    string s="";
    int i=m,j=n;
    while(i>0 || j>0)
    {
        if(a[i-1]==b[j-1])
        {
            s.push_back(b[j-1]);
            i--;
            j--;
        }
        else
        {
            if(t[i][j-1]>t[i-1][j])
            j--;
            else
                i--;
        }
    }
    reverse(s.begin(),s.end());
    cout<<s;
}
int main()
{
    string a,b;
    cin>>a;
    cin>>b;
    plcs(a,b);
    return 0;
}

