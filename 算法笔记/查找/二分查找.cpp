#include<bits/stdc++.h>
using namespace std;
int a[100] = {0,1,2,3,4,5,6,7,8,9,10,12,14,16,20,100};
int len=15;
//查找第一个大于等于x的数
int my_upper_bound(int x)
{
	int l=0,r=len;
	int mid = (l+r)/2;
	while(l+1<r)
	{
		if(a[mid]>=x) r=mid;
		else l = mid;
		mid = (l+r)/2;
	}
	return r;
}
//查找最后一个小于等于x的数
int find(int x)
{
	int l=0,r=len;
	int mid = (l+r)/2;
	while(l+1<r)
	{
		if(a[mid]<=x) l=mid;
		else r = mid;
		mid = (l+r)/2;
	}
	return l;
}
int main()
{
	cout<<a[my_upper_bound(11)]<<"\n";
	cout<<a[find(11)]<<"\n";
}
