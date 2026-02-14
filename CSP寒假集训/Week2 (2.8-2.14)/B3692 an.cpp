#include <bits/stdc++.h> // 万能头
#define ll long long

using namespace std;

// 结构体

struct Problem
{
	Problem()
	{
		flag = 0,time = 0;
	}
	int flag; // 0 ：未通过，1 ：已通过
	int time; // 总罚时
};

struct Team
{
	Team()
	{
		solved = 0,total = 0;
	}
	string name;    // 队伍名称
	Problem a[26];  // 每一道题目的通过状态
	int solved;     // 总通过题目数量
	int total;      // 所有题目的总罚时
	int first_submit; // 首次提交记录
};

map<string, Team> ta; // 封榜之前每个队伍完成的题目情况
map<string, Team> tb; // tb 代表最终每个队伍完成题目的情况
Team bangdan[1005];
int n, m, k, copy_flag = 0;

// 两支队伍排序的比较规则
bool cmp(Team a, Team b)
{
	if (a.solved != b.solved) 
	{
		return a.solved > b.solved;
	}
	if (a.total != b.total) 
	{
		return a.total < b.total;
	}
	return a.first_submit < b.first_submit;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 0;i<k;i++)
	{
		char ch;
		int xx,yy,zz,ss;
		string name, result;
		cin >> xx >> ch >> yy >> ch >> zz; // 读入时间
		cin >> ch; // 读入题目编号
		cin >> name; // 读入队伍名称
		getline(cin, result); // 读入判题结果
		//去除前导空格
		size_t pos = result.find_first_not_of(' ');
		if (pos != string::npos) {
			result = result.substr(pos);
		} else {
			result = "";  // 全是空格的情况
		}
		ss = xx * 3600 + yy * 60 + zz;
		if (ss <= 4*3600)
		{
			// 如果是第一次出现这个队伍，就记录这个队伍第一次提交的时间
			if (ta.find(name) == ta.end())
			{
				ta[name].first_submit = i;
				ta[name].name = name;
			}
			// 如果在4个小时以内，就把数据存储到 ta 中
			// 如果这道题目之前通过了，就跳过本次的提交记录
			if (ta[name].a[ch - 'A'].flag == 1)
			{
				continue;
			}
			// 如果之前没有通过，那就处理本条提交记录
			if (result == "Accepted")
			{
				ta[name].a[ch - 'A'].flag = 1;
				ta[name].a[ch - 'A'].time += xx * 60 + yy;
				ta[name].solved += 1;
				ta[name].total  += ta[name].a[ch - 'A'].time;
			}
			else
			{
				ta[name].a[ch - 'A'].time += 20;
			}
		}
		else
		{
			// 第一次封榜以后，先把数据拷贝给tb
			if (copy_flag == 0)
			{
				tb = ta;
				copy_flag = 1;
			}
			// 如果是第一次出现这个队伍，就记录这个队伍第一次提交的时间
			if (tb.find(name) == tb.end())
			{
				ta[name].first_submit = i;
				ta[name].name = name;
				tb[name].first_submit = i;
				tb[name].name = name;
			}
			// 之后的数据，就存储在 tb 当中
			if (tb[name].a[ch - 'A'].flag == 1)
			{
				continue;
			}
			// 如果之前没有通过，那就处理本条提交记录
			if (result == "Accepted")
			{
				tb[name].a[ch - 'A'].flag = 1;
				tb[name].a[ch - 'A'].time += xx * 60 + yy;
				tb[name].solved += 1;
				tb[name].total  += tb[name].a[ch - 'A'].time;
			}
			else
			{
				tb[name].a[ch - 'A'].time += 20;
			}
		}
	}
	// 将封榜之前的所有队伍的做题信息整理到榜单上
	int bangdan_cnt = 0;
	for (auto t:ta)
	{
		bangdan[bangdan_cnt++] = t.second;
	}
	// 对榜单排序
	sort(bangdan + 0, bangdan + ta.size(), cmp);
	/* 检验封榜之前的榜单正确性
	for (int i = 0; i < ta.size(); i++) {
	string name = bangdan[i].name;
	cout << name << " : ";
	for (int j = 0; j < n; j++) {
	if (ta[name].a[j].flag == 0) continue;
	cout << "(" << char(j + 'A') << ", " << ta[name].a[j].time << ") ";
	}
	cout << endl;
	}
	cout << endl;
	检验最终的榜单的正确性
	for (int i = 0; i < ta.size(); i++) {
	string name = bangdan[i].name;
	cout << name << " : ";
	for (int j = 0; j < n; j++) {
	if (tb[name].a[j].flag == 0) continue;
	cout << "(" << char(j + 'A') << ", " << tb[name].a[j].time << ") ";
	}
	cout << endl;
	}*/ 
	
	// 开始滚榜
	int ind = ta.size() - 1;
	string pre_name = "";
	while (ind != -1)
	{
		int flag = 0; // 当前队伍是否需要向上滚榜
		string name = bangdan[ind].name;
		if (name != pre_name)
		{
			cout << name << "\n"; // 输出当前被念到的榜单名字
			pre_name = name;
		}
		for (int i = 0; i < n; i++)
		{
			if (tb[name].a[i].flag != bangdan[ind].a[i].flag)
			{
				bangdan[ind].a[i] = tb[name].a[i];
				bangdan[ind].solved += 1;
				bangdan[ind].total  += bangdan[ind].a[i].time;
				flag = 1;
				break;
			}
		}
		if (flag)
		{
			int j = ind;
			while (j > 0 && cmp(bangdan[j], bangdan[j - 1]))
			{
				swap(bangdan[j], bangdan[j - 1]);
				j -= 1;
			}
		}
		else
		{
			ind -= 1;
		}
		return 0;//撒花 
	}
}	
