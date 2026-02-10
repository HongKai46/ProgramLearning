#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int read()
{
	int r=0,k=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') k=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		r=r*10+ch-48;
		ch=getchar();
	}
	return r*k;
}
const int maxn = 5e5+5;
int tree[maxn],n,m,op,x,y,arr[maxn];
void Add(int x,int y)
{
	while(x<=n)
	{
		int d =x&(-x);
		tree[x]+=y;
		x+=d;
	}
}
ll Sum(int x)
{
	ll ret=0;
	while(x>0)
	{
		ret+=tree[x];
		x-=(x&(-x));
	}
	return ret;
}
int main()
{
	n=read(),m=read();
	for(int i=1;i<=n;i++) arr[i]=read(),Add(i,arr[i]);
	for(int i=1;i<=m;i++)
	{
		op=read(),x=read(),y=read();
		if(op==1) Add(x,y);
		else
		{
			ll ans = Sum(y)-Sum(x-1);
			printf("%lld\n",ans);
		}
	}
}
