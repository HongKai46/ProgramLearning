#include<bits/stdc++.h>
using namespace std;
double a,b,c,d;
double fun(double x)
{
	return a*x*x*x+b*x*x+c*x+d;
}
double find(double l,double r)
{
	double mid = (l+r)/2;
	while(r-l>1e-4)
	{
		if(fun(mid) * fun(r)<0) l=mid;
		else r = mid;
		mid = (l+r)/2;
	}
	return l;
}
int main()
{
	ios::sync_with_stdio(0);
	int count=0;
	cin>>a>>b>>c>>d;
	for(int i=-100;count<3&&i<=100;i++)
	{
		if(fun(i)==0){
			count++;
			printf("%.2lf ",(double)i);
			continue;
		}
		if(fun(i)*fun(i+1)<0) printf("%.2lf ",find(i,i+1)),count++;
		
	}
}
