#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;
struct TeamStatu{
	TeamStatu(){
		times=0;
		name="";
		acs=0;
		memset(is_prob_ac,false,sizeof(is_prob_ac));
		memset(fail_time,0,sizeof(fail_time));
		memset(problem_time,0,sizeof(problem_time));
		first_sub=1000000000;
	}
	int times;
	string name;
	int acs;
	bool is_prob_ac[30];
	int fail_time[30];
	int problem_time[30];
	int first_sub;
};
map<string,TeamStatu> teams1;
map<string,TeamStatu> teams2;
vector<TeamStatu> ranks(1005);
int problem_num,team_num,sub_num;
bool cmp(TeamStatu& a,TeamStatu& b)
{
	if(a.acs!=b.acs) return a.acs<b.acs;
	if(a.times!=b.times) return a.times>b.times;
	return a.first_sub>b.first_sub;
}
int main()
{
	ios::sync_with_stdio(0);
	cin>>problem_num>>team_num>>sub_num;
	//读入数据
	bool flag=true;
	for(int i=1;i<=sub_num;i++)
	{
		int h,m,s;char ch;
		string t_name,statu;
		char p_name;
		cin>>h>>ch>>m>>ch>>s>>p_name>>t_name;
		getline(cin,statu);
		if(h<4||(h==4&&m==0&&s==0))
		{
			if(teams1.count(t_name)==0)
			{
				teams1[t_name].name=t_name;
				teams1[t_name].first_sub=h*3600+m*60+s;
			}
			if(teams1[t_name].is_prob_ac[p_name-'A']) continue;
			auto it = statu.find_first_not_of(' ');
			if(it==string::npos){
				cout<<"error\n";
				return 1;
			}
			else statu=statu.substr(it);
			if(statu=="Accepted")
			{
				teams1[t_name].acs++;
				teams1[t_name].is_prob_ac[p_name-'A']=true;
				teams1[t_name].times+=teams1[t_name].fail_time[p_name-'A']*20+h*60+m;
			}
			else
			{
				teams1[t_name].fail_time[p_name-'A']++;
			}
		}
		else
		{
			if(flag) teams2=teams1,flag=false;
			if(teams2.count(t_name)==0)
			{
				teams1[t_name].name=t_name;
				teams1[t_name].first_sub=h*3600+m*60+s;
				teams2[t_name].name=t_name;
				teams2[t_name].first_sub=h*3600+m*60+s;
			}
			if(teams2[t_name].is_prob_ac[p_name-'A']) continue;
			auto it = statu.find_first_not_of(' ');
			if(it==string::npos){
				cout<<"error\n";
				return 1;
			}
			else statu=statu.substr(it);
			if(statu=="Accepted")
			{
				teams2[t_name].acs++;
				teams2[t_name].is_prob_ac[p_name-'A']=true;
				teams2[t_name].problem_time[p_name-'A']= h*60+m+teams2[t_name].fail_time[p_name-'A']*20;
			}
			else
			{
				teams2[t_name].fail_time[p_name-'A']++;
			}
		}
	}
	int now=1;
	for(auto i:teams1)
	{
		ranks[now++]=i.second;
	}
	sort(ranks.begin()+1,ranks.begin()+teams1.size()+1,cmp);
	now=1;
	string lname;
	while(now<=(int)teams1.size())
	{
		string name = ranks[now].name;
		if(ranks[now].name!=lname)
		{
			cout<<name<<"\n";
			lname = ranks[now].name;
		}
		int ok=1;
		for(int i=0;i<problem_num;i++)
		{
			if(teams1[name].is_prob_ac[i]) continue;
			if(teams2[name].is_prob_ac[i]){
				ranks[now].acs++;
				ranks[now].times+=teams2[name].problem_time[i];
				teams1[name].is_prob_ac[i]=true;
				ok=0;
				sort(ranks.begin()+1,ranks.begin()+teams1.size()+1,cmp);	
				break;
			}
		}
		if(ok) now++;
	}
	
}
//4 4 15
//0:00:01 A dabc Wrong Answer
//0:00:08 A dabc Wrong Answer
//0:01:09 A qwq Accepted
//1:19:08 B qwq Accepted
//2:53:48 B dabc Wrong Answer
//4:00:00 A dabc Accepted
//4:00:03 A homo Accepted
//4:00:04 B homo Accepted
//4:00:05 C homo Accepted
//4:00:06 D homo Runtime Error
//4:50:08 A homo Runtime Error
//4:59:13 C qwq Accepted
//4:59:48 D qwq Accepted
//5:00:00 D dabc Wrong Answer
//5:00:00 C dabc Accepted
//homo
//dabc
//homo
//dabc
//homo
//qwq
//homo
//qwq
