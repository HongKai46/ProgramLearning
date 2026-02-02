/*
  <三角函数><贪心？>
  这次自己独自想出思路，但最后有一个小问题导致WA，是AI辅助找出的bug，其实自己手动调试应该也能找出来，应该多自己调，不要偷懒
*/
#include<bits/stdc++.h>

using namespace std;
bool cmp(const pair<double,double> a,const pair<double,double> b)
{
	if(a.first==b.first) return a.second>b.second;
	return a.first<b.first;
}
int main()
{
	//思路，直接计算圆心角，再把范围存起来，排序后，计算空白的范围
	int n=0;cin>>n;
	double x,y,r,L,R;
	vector<pair<double,double> > range;
	for(int i=0;i<n;i++)
	{
		cin>>x>>y>>r;
		//计算角度与范围
		double Sin=r/sqrt(x*x+y*y);
		L=atan2(y,x)-asin(Sin);
		R=atan2(y,x)+asin(Sin);
		if(L<0)L=0;
		if(R>M_PI/2)R=M_PI/2;
		range.push_back({L,R});
	}
	//排序
	sort(range.begin(),range.end(),cmp);
	double ans=range[0].second-range[0].first;
	for(int i=1;i<n;i++)
	{
		
		if(range[i].first>=range[i-1].first&&range[i].first<range[i-1].second)
		{
			if(range[i].second<=range[i-1].second) 
			{
				range[i].second=range[i-1].second;
				continue;
			}
			else 
			{
				ans+=range[i].second-range[i-1].second;
			}
		}
		else if(range[i].first>=range[i-1].second) ans+=range[i].second-range[i].first;
	}
	ans=1-2*ans/M_PI;
	printf("%.3f",ans);
}
