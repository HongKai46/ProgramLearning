#include<bits/stdc++.h>
using namespace std;
const int n = 9;
int a[20] = {5,7,1,9,4,6,2,8,3};
int b[20];
vector<vector<int> > c(20);
int main()
{
	int Max=0;vector<int> ans;
	for(int i=0;i<n;i++)
	{
		vector<int> ret;
		for(int j=0;j<i;j++)
		{
			if(a[j]<a[i]&&b[j]>=b[i]) b[i]=b[j]+1,c[i]=c[j];
		}
		c[i].push_back(a[i]);
		if(Max<b[i]) Max=b[i],ans=c[i];
	}
	cout<<Max+1<<"\n";
	for(int i=0;i<(int)ans.size();i++)
	{
		if(i>0) cout<<"-->";
		cout<<ans[i];
	}
}
