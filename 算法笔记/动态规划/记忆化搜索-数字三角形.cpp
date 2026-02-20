#include<bits/stdc++.h>
using namespace std;
const int n = 4;
int a[9][9]={
	{1},
	{4,6},
	{8,3,9},
	{5,7,2,1}
};
int f[9][9];
int dfs(int x,int y)
{
	if(f[x][y]!=0) return f[x][y];
	if(x==n-1) f[x][y] = a[x][y];
	else f[x][y] = a[x][y] + max(dfs(x+1,y),dfs(x+1,y+1));
	return f[x][y];
}
int main()
{
	ios::sync_with_stdio(0);
	cout<<dfs(0,0);
}
