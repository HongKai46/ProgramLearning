#include<bits/stdc++.h>
using namespace std;
vector<array<int,120> > vec;//存定义的数组
vector<int> siz;//表示数组大小
map<string,int> ston;//将数组名转为下标
int now=0;//当前数组数量
array<int,120> a{};
int intpre(string s)
{
	if(s.find('[')==string::npos)
	{
		return stoi(s);
	}
	int pos1 = s.find('[');
	int pos2 = s.find(']');
	string name = s.substr(0,pos1);
	int i = intpre(s.substr(pos1+1,pos2-pos1-1));
	if (!ston.count(name)) return -1;
	if(i==-1||i>=siz[ston[name]]) return -1;
	else return vec[ston[name]][i];
}
int main()
{
	ios::sync_with_stdio(0);
	string s;
	while(cin>>s)
	{
		if(s=="int")
		{
			cin>>s;
			vec.push_back(a);
			int pos1 = s.find('[');
			int pos2 = s.find(']');
			string name = s.substr(0,pos1);
			int si = intpre( s.substr(pos1+1,pos2-pos1-1) );
			if(si<=0){
				cout<<-1<<"\n";
				return 0;
			}
			ston[name]=now++;
			siz.push_back(si);
		}
		else if(s=="cout")
		{
			cin>>s;
			int r = intpre(s);
			if(r==-1){
				cout<<-1<<"\n";
				return 0;
			}
			else cout<<r<<"\n";
		}
		else
		{
			int n=0;
			string ss;
			cin>>ss;
			n = intpre(ss);
			if(n==-1)
			{
				cout<<-1<<"\n";
				return 0;
			}
			int pos1 = s.find('[');
			int pos2 = s.find(']');
			int p = intpre(s.substr(pos1+1,pos2-pos1-1));
			string name = s.substr(0,pos1);
			if(p==-1||p>=siz[ston[name]])
			{
				cout<<-1<<"\n";
				return 0;
			}
			else{
				vec[ston[name]][p]=n;
			}
		}
	}
}