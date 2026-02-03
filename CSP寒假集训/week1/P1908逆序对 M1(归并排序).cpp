//思路：归并排序
#include<bits/stdc++.h>
using namespace std;
int a[500005],c[500005],n;
long long ans=0;
void msort(int l,int r)//核心代码（归并排序）
{
	if(l==r) return;
	int mid=(l+r)/2;
	msort(l,mid),msort(mid+1,r);
	int i=l,j=mid+1,k=i;
	while(i<=mid&&j<=r)
	{
		if(a[i]>a[j])
		{
			c[k++]=a[j++];
			ans+=mid-i+1;
		}
		else
		{
			c[k++]=a[i++];
		}
	}
	while(i<=mid) c[k++]=a[i++];
	while(j<=r) c[k++]=a[j++];
	for(int m=l;m<=r;m++)
	{
		a[m]=c[m];
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	msort(1,n);
	cout<<ans;
}

