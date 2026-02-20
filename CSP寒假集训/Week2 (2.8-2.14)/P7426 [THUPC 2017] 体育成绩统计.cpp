#include<bits/stdc++.h>
using namespace std;
int n,m;
struct Stu
{
	Stu()
	{
		grade=0;
		sex=0;
		classtime=0;
		runningtime=0;
	}
	string id;
	int grade;
	int sex;
	int classtime;
	int runningtime;
};
map<string,Stu> stus;
map<string,pair<string,int> > last;
int Running(const string& S,char sex)
{
	
	stringstream ss(S);
	char ch;int m=0,s=0;
	ss>>m>>ch>>s;
	int t = m*60+s;
	if(sex=='F')
	{
		if(t<=6*60+40) return 20;
		else if(t<=6*60+57) return 18;
		else if(t<=7*60+14) return 16;
		else if(t<=7*60+31) return 14;
		else if(t<=7*60+50) return 12;
		else if(t<=8*60+5)  return 10;
		else if(t<=8*60+20) return 8;
		else if(t<=8*60+35) return 6;
		else if(t<=8*60+50) return 4;
		else if(t<=9*60) return 2;
		else return 0;
	}
	else
	{
		if(t<=12*60+30) return 20;
		else if(t<=13*60) return 18;
		else if(t<=13*60+30) return 16;
		else if(t<=14*60) return 14;
		else if(t<=14*60+30) return 12;
		else if(t<=15*60+10) return 10;
		else if(t<=15*60+50) return 8;
		else if(t<=16*60+30) return 6;
		else if(t<=17*60+10) return 4;
		else if(t<=18*68) return 2;
		else return 0;
	}
}
int is_wrong(string& id,string& date,int h,int m,int s)
{
	if(!last.count(id)) return 0;
	int t=h*3600+m*60+s;
	if(date==last[id].first){
		if(t-last[id].second<=6*3600) return 1;
		else return 0;
	}
	else if(date.substr(0,date.size()-1)==last[id].first.substr(0,date.size()-1)&&date[7]-last[id].first[7]==1)
	{
		if(t+(24*3600-last[id].second)<=6*3600) return 1;
		else return 0;
	}
	else return 0;
}
int is_legal(string& id,float km,int t,int stop_time,int steps)
{
	if(stus[id].sex){
		if(km<3) return 0;
	}else {
		if(km<1.5) return 0;
	}
	if(1000*km/t<2||1000*km/t>5) return 0;
	if(stop_time>4*60+30) return 0;
	if(1000*km/steps>1.5) return 0;
	return 1;
}
int runtime(int x)
{
	if(x>=21) return 10;
	else if(x>=19) return 9;
	else if(x>=17) return 8;
	else if(x>=14) return 7;
	else if(x>=11) return 6;
	else if(x>=7) return 4;
	else if(x>=3) return 2;
	else return 0;
}
int daka(int x)
{
	if(x>=18) return 5;
	else if(x>=15) return 4;
	else if(x>=12) return 3;
	else if(x>=9) return 2;
	else if(x>=6) return 1;
	else return 0;
}
string grade(int x)
{
	if(x>=95) return "A";
	else if(x>=90) return "A-";
	else if(x>=85) return "B+";
	else if(x>=80) return "B";
	else if(x>=77) return "B-";
	else if(x>=73) return "C+";
	else if(x>=70) return "C";
	else if(x>=67) return "C-";
	else return "F";
}
int main()
{
	cin>>n;
	string id;char sex;int grade1=0;string running;char pass;int grade2,classtimes=0;
	for(int i=1;i<=n;i++)
	{
		//解析n个同学的数据
		cin>>id>>sex>>grade1>>running>>pass>>grade2>>classtimes;
		stus[id].id=id;stus[id].classtime=classtimes;
		if(sex=='M') stus[id].sex=1;
		else stus[id].sex=0;
		stus[id].grade+=grade1+grade2+Running(running,sex);
		if(pass=='P')stus[id].grade+=10;
	}
	cin>>m;
	string date;int h1,m1,s1,h2,m2,s2,stopm,stops,steps;char ch;
	float km=0.0f;
	for(int i=1;i<=m;i++)
	{
		cin>>date>>id>>h1>>ch>>m1>>ch>>s1>>h2>>ch>>m2>>ch>>s2>>km>>stopm>>ch>>stops>>ch>>steps;
		int t = h2*3600+m2*60+s2-h1*3600+m1*60+s1;
		if(!is_wrong(id,date,h1,m1,s1))
		{
			if(is_legal(id,km,t,stopm*60+stops,steps))
				stus[id].runningtime++,last[id].first=date,last[id].second=h2*3600+m2*60+s2;
		}
		else 
		{
			if(is_legal(id,km,t,stopm*60+stops,steps))
				last[id].first=date,last[id].second=h2*3600+m2*60+s2;
		}
	}
	for(auto i:stus)
	{
		i.second.grade+=runtime(i.second.runningtime)+daka(i.second.runningtime+i.second.classtime);
		cout<<i.second.id<<" "<<i.second.grade<<" "<<grade(i.second.grade)<<"\n";
		
	}
	
}
