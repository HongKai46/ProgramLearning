#include<bits/stdc++.h>
using namespace std;
int x,y,w,v,n;
int dp[10];
int main()
{
	ios::sync_with_stdio(0);
	cin>>x>>y;
	for(int i=1;i<=x;i++)
	{
		cin>>w>>v>>n;
		for(int j=y;j>0;j--)
		{
			if(w<=j){
				int t=j;
				while(w<=t&&(j-t)/w<n)
				{
					t-=w;
					dp[j] = max(dp[j],dp[t]+(j-t)/w*v);
				}
			}
		}
	}
	cout<<dp[y];
}
