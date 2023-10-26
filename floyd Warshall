#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> APSP_floyd(vector<vector<int>>weight,int n)
{
    vector<vector<int>>dis(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=n;j++)
      {
        if((weight[i][j]==0) && i!=j)
        {
           dis[i][j]=INT_MAX/2;
        }
        else
        {
            dis[i][j]=weight[i][j];
        }
      }
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
   return dis;

}
int main()
{
    int v,e;
    cin>>v>>e;
    vector<vector<int>>weight(v+1,vector<int>(v+1,0));
    for(int i=1;i<=e;i++)
    {
        int a,b,w;
        cin>>a>>b>>w;
        weight[a][b]=w;
    }
   vector<vector<int>>ans=APSP_floyd(weight,v);
    for(int i=1;i<=v;i++)
    {
        for(int j=1;j<=v;j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
