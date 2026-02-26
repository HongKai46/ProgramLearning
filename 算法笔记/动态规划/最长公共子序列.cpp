#include<bits/stdc++.h>
using namespace std;
string a="ADABEC";
string b="DBDCA";
int mat[10][10];
//mat[i][j]表示字符串a的第i个字符之前和字符串b的第j个字符之前最长公共子序列的长度
//注意下标：mat[1][1]代表a[0]与b[0]之前的（包括a[0],b[0]）
int main()
{
	for(int i=1;i<=(int)a.size();i++)
	{
		for(int j=1;j<=(int)b.size();j++)
		{
			if(a[i-1]==b[j-1]) mat[i][j]=mat[i-1][j-1]+1;
			else mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
		}
	}
	cout<<mat[a.size()][b.size()]<<"\n";
	string ans;
	int x=a.size(),y=b.size();
	//获取路径
	while(x>0&&y>0)
	{
		if(a[x-1]==b[y-1]){
			ans+=a[x-1];
			x--,y--;
		}
		else if(mat[x][y-1]<mat[x-1][y]){
			x--;
		}
		else{
			y--;
		}
	}
	reverse(ans.begin(),ans.end());
	cout<<ans<<"\n";
}
