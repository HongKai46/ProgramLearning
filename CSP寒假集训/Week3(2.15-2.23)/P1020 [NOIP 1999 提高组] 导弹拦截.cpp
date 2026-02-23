#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int a[maxn];
vector<int> b;
//寻找第一个小于x的数
int find1(int x)
{
	int l=0,r=b.size();
	int mid = (l+r)/2;
	while(l+1<r)
	{
		if(b[mid]<x) r=mid;
		else l=mid;
		mid = (l+r)/2;
	}
	if(r==(int)b.size()) return -1;
	return r;
}
//获取最长不增子序列长度
int lis1(int n)
{
	for(int i=0;i<n;i++)
	{
		int r = find1(a[i]);
		if(r==-1) b.push_back(a[i]);
		else b[r] = a[i];
	}
	return b.size()-1;
}
//寻找第一个大于等于x的数
int find2(int x)
{
	int l=0,r=b.size(),mid=(l+r)/2;
	while(l+1<r)
	{
		if(b[mid]>=x) r=mid;
		else l = mid;
		mid = (l+r)/2;
	}
	if(r==(int)b.size()) return -1;
	return r;
}
//获取最长递增子序列长度
int lis2(int n)
{
	for(int i=0;i<n;i++)
	{
		int r = find2(a[i]);
		if(r==-1) b.push_back(a[i]);
		else b[r] = a[i];
	}
	return b.size()-1;
}
int main()
{
	b.push_back(0);
	ios::sync_with_stdio(0);
	int n=0;
	while(cin>>a[n])
	{
		n++;
	}
	cout<<lis1(n)<<"\n";
	b.clear();
	b.push_back(0);	
	cout<<lis2(n)<<"\n";
}
