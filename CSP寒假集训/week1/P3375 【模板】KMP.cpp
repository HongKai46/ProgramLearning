#include<bits/stdc++.h>
using namespace std;

vector<int> build_next(string s)
{
	vector<int> next(1,0);
	int prefix_len=0;
	int i=1;
	while(i<(int)s.size())
	{
		if(s[prefix_len]==s[i])
		{
			prefix_len++;
			next.push_back(prefix_len);
			i++;
		}
		else
		{
			if(prefix_len==0)
			{
				next.push_back(0);
				i++;
			}
			else
			{
				prefix_len=next[prefix_len-1];
			}
		}
	}
	return next;
}
void kmp_search(string& S,string& s,vector<int>& next)
{
	int i=0,j=0;
	while(i<(int)S.size())
	{
		if(S[i]==s[j])
		{
			i++;
			j++;
		}
		else if(j>0) j=next[j-1];
		else i++;
		if(j==(int)s.size())
		{
			cout<<i-s.size()+1<<"\n";
			j=next[j-1];
		}
	}
}
int main()
{
	string S;
	string s;
	cin>>S>>s;
	vector<int> a=build_next(s);
	kmp_search(S,s,a);
	for(int i=0;i<(int)a.size();i++) cout<<a[i]<<" ";
}
