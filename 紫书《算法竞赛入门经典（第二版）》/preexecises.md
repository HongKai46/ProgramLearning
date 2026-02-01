# 第二章

## 习题2-4

```c++
#include<bits/stdc++.h>

using namespace std;

int main()

{

  while(1)

  {

    int n,m;

    cin>>n>>m;

    if(n==m&&n==0)

    {

      break;

    }

    double ans=0.0;

    for(int i=n;i<=m;i++)

    {

      ans+=1.0/i/i;

    }

    printf("%.5lf\n",ans);

  }

}
```

### Tip

``ans+=1.0/i/i;``不写为``(i*i)``是防止数据溢出

## 习题2-5

```c++
#include<stdio.h>
#define LOCAL
int main()
{
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int a,b,c,sum=0;
    while(scanf("%d %d %d",&a,&b,&c)==3)
    {
        if(a==0&&b==0&&c==0)
        {
            break;
        }
        sum++;
        double m = (double) a / b ;
        printf("Case %d: %.*lf\n", sum, c, m);
    }
    #ifdef LOCAL
        fclose(stdin);
        fclose(stdout);
    #endif
    return 0;
}
```

### Tips

``printf("%.*lf")`` *用于不定宽度（width）的占位符

# 第三章

## 3-1 得分 UVA1585

```c++
#include<stdio.h>
#include<string.h>

char str[100];

int main()
{
	int n=0;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s",str);
		int len = strlen(str);
		int contin = 0;
		int ans =0;
		for(int i=0;i<len;i++)
		{
			if(str[i]=='O')
			{
				ans+=++contin;
			}
			else if(str[i]=='X')
			{
				contin=0;
			}
		}
		printf("%d\n",ans);
	}
}
```

## 3-2分子量UVA1586

```c++
#include<stdio.h>
#include<string.h>
#include<ctype.h>
char s[100];
double cton(char c)
{
	if(c=='C') return 12.01;
	else if(c=='H') return 1.008;
	else if(c=='O') return 16.0;
	else if(c=='N') return 14.01;
	return 0;
}
int main()
{
	int n=0;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s",s);
		int len = strlen(s);
		double ans =0.0;
		for(int i=0;i<len;i++)
		{
			//省略1的情况
			if(isalpha(s[i]))
			{
				if(i+1>=len || isalpha(s[i+1]))
				{
					ans+=cton(s[i]);
					continue;
				}
			}
			//带数字的
			if(isalpha(s[i])&&(i+1<len)&&(s[i+1]>='0'&&s[i+1]<='9'))
			{
				//获取数字
				int num=0;
				//一位数
				if(i+2>=len)
				{
					num = s[i+1] - 48;
					ans+=cton(s[i])*num;
					continue;
				}
				if(i+2<len&&isalpha(s[i+2]))
				{
					num = s[i+1] - 48;
					ans+=cton(s[i])*num;
					continue;
				}
				//两位数
				if(i+2<len&&(s[i+2]>='0'&&s[i+2]<='9'))
				{
					num = s[i+2]-48 + (s[i+1]-48)*10;
					ans+=cton(s[i])*num;
					continue;
				}
			}
		}
		printf("%.3lf\n",ans);
	}
}
```

## 3-4周期串UVA455

```c++
#include<stdio.h>
#include<string.h>
char s[100];
int main()
{
	int n=0;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s",s);
		int len = strlen(s);
		int ans=100;
		for(int i=1;i<=len;i++)
		{
			if(len%i!=0) continue;
			int now=0;
			int size = len/i;
			int flag=1;
			while(flag&&now+size<len)
			{
				for(int i=now;i<size+now;i++)
				{
					if(s[i]!=s[i+size]) 
					{
						flag=0;
						break;
					}
				}
				now+=size;
			}
			if(flag&&ans>size)
			{
				ans=size;
			}
		}
		printf("%d\n",ans);
		if(n==0) continue;
		printf("\n");
	}
}
```

## 3-5谜题UVA227

这道题我现在只有其他人的题解了，我自己的找不到了。[原文](https://blog.csdn.net/tigerisland45/article/details/52079935)

```c++
/* UVA227 Puzzle */
#include <stdio.h>
#define MAXN 5
#define LOCAL
char grid[MAXN][MAXN];
int blankrow, blankcol, nextrow, nextcol;

// 移动：如果指令正确则移动，并且返回0;否则返回1。
int move(char move)
{
	if(move == 'A') {
		nextrow = blankrow - 1;
		nextcol = blankcol;
	} else if(move == 'B') {
		nextrow = blankrow + 1;
		nextcol = blankcol;
	} else if(move == 'L') {
		nextrow = blankrow;
		nextcol = blankcol - 1;
	} else if(move == 'R') {
		nextrow = blankrow;
		nextcol = blankcol + 1;
	} else
		return 1;
	
	if(nextrow >= 0 && nextrow < MAXN && nextcol >= 0 && nextcol < MAXN) {
		grid[blankrow][blankcol] = grid[nextrow][nextcol];
		grid[nextrow][nextcol] = ' ';
		
		blankrow = nextrow;
		blankcol = nextcol;
		return 0;
	} else
		return 1;
}

int main(void)
{
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	int caseno=0, okflag, i, j;
	char c;
	
	while((c=getchar()) != 'Z') {
		// 读入数据
		for(i=0; i<MAXN; i++)
			for(j=0; j<MAXN; j++) {
				grid[i][j] = c;
				if(c == ' ' ||c=='\n') {
					blankrow = i;
					blankcol = j;
					grid[i][j] = ' ';
				}
				c = getchar();
				if(j == MAXN-1 && c == '\n')
					c = getchar();
			}
		
		// 模拟过程：一边读入命令行，一边移动
		okflag = 1;
		while(c != '0') {
			if(c != '\n') {
				if(move(c)){
					okflag = 0;
					break;
				}
			}
			c = getchar();
			if(c == '\n')
				c = getchar();
		}
		while(c != '0')     // 跳过‘0’及以前的字符
			c = getchar();
		while(c != '\n')    // 跳过‘\n’及以前的字符
			c = getchar();
		
		// 输出结果
		if(++caseno > 1)
			printf("\n");
		printf("Puzzle #%d:\n", caseno);
		if(okflag) {
			for(i=0; i<MAXN; i++)
				printf("%c %c %c %c %c\n", grid[i][0], grid[i][1], grid[i][2], grid[i][3], grid[i][4]);
		} else
			printf("This puzzle has no final configuration.\n");
	}
#ifdef LOCAL
	fclose(stdin);
	fclose(stdout);
#endif
	return 0;
}
```

## 3-6纵横字谜的答案UVA232

```c++
#include<stdio.h>
#include<string.h>
//#define LOCAL
int flag_across(char mat[][10],int row,int col)
{
	if(mat[row][col]=='*') return 0;
	if(col==0) return 1;
	else if(col>0&&mat[row][col-1]=='*') return 1;
	return 0;
}
int flag_down(char mat[][10],int row,int col)
{
	if(mat[row][col]=='*') return 0;	
	if(row==0) return 1;
	else if(row>0&&mat[row-1][col]=='*') return 1;
	return 0;
}
char mat[10000][10];
char mat_flag[10000][10];
int main()
{
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	
	int row,col;
	int round=0;
	while(1)
	{
		scanf("%d",&row);
		if(row==0) break;
		scanf("%d",&col);

		memset(mat,0,sizeof(mat));
		memset(mat_flag,0,sizeof(mat_flag));
		//input
		for(int i=0;i<row;i++)
		{
			for(int j=0;j<col;j++)
			{
				scanf(" %c",&mat[i][j]);
			}
		}
		//flag black and num
		if(++round>1) printf("\n");
		printf("puzzle #%d:\n",round);
		printf("Across\n");
		int sum=1;
		for(int i=0;i<row;i++)
		{
			for(int j=0;j<col;j++)
			{
				if(flag_across(mat,i,j))
				{
					printf("%3d.",sum);
					int t=j;
					while(mat[i][t]!='*'&&t<col)
					{
						printf("%c",mat[i][t]);
						t++;
					}
					printf("\n");
				}
				if(flag_across(mat,i,j)||flag_down(mat,i,j)) sum++;
				
			}
		}
		
		printf("Down\n");
		sum=1;
		for(int i=0;i<row;i++)
		{
			for(int j=0;j<col;j++)
			{
				if(flag_down(mat,i,j))
				{
					printf("%3d.",sum);
					int t=i;
					while(mat[t][j]!='*'&&t<row)
					{
						printf("%c",mat[t][j]);
						t++;
					}
					printf("\n");
				}
				if(flag_across(mat,i,j)||flag_down(mat,i,j)) sum++;
			}
		}
	}	
}
```

## 3-7DNA序列UVA1368

```c++
#include<stdio.h>
#include<string.h>

//#define LOCAL
int chart[100];
char mat[55][1005];
char ans[1005];
long long error_sum=0;
int main()
{
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	int z=0;
	scanf("%d",&z);
	while(z--)
	{
		memset(ans,0,sizeof(ans));
		error_sum=0;
		int row,col;
		scanf("%d %d",&row,&col);
		for(int i=1;i<=row;i++)
		{
			for(int j=1;j<=col;j++)
			{
				scanf(" %c",&mat[i][j]);
			}
		}
		for(int c=1;c<=col;c++)
		{
			memset(chart,0,sizeof(chart));
			for(int r=1;r<=row;r++)
			{
				chart[ (int)mat[r][c] ]++;
			}
			int max=0;
			char an=0;
			for(int i='A';i<='Z';i++)
			{
				if(chart[i]>max) 
				{
					max=chart[i];
					an=i;
				}
			}
			ans[c]=an;
			error_sum+=(row-max);
		}
		for(int i=1;i<=col;i++)
		{
			printf("%c",ans[i]);
		}
		printf("\n%lld\n",error_sum);
		
	}
#ifdef LOCAL
	fclose(stdin);
	fclose(stdout);
#endif
}
```

## 3-8循环小数UVA202

```c++
#include<stdio.h>
#include<string.h>
using namespace std;
//#define LOCAL
int arr[1000];
char ans[100];
int find(int* arr,int m,int a)
{
	for(int i=1;i<m;i++)
	{
		if(a==arr[i]) return i;
	}
	return 0;
}
int main()
{
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	int a,b;
	while(scanf("%d %d",&a,&b)==2)
	{
		memset(arr,0,sizeof(arr));
		int round=1;
		int l=0;
		int ok=0;
		while(true)
		{
			if(round==1)
			{
				printf("%d/%d = %d.",a,b,a/b);
			}
			a=(a%b)*10;
			if(round<=50)
				ans[round]=a/b+48;
			if(find(arr,round,a))
			{
				l=find(arr,round,a);
			}
			if(a==0)
			{
				ok=1;
			}
			else
				arr[round]=a;
			if(ok)
			{
				if(round>51)
				{
					for(int i=1;i<=50;i++)
					{
						if(i==l) printf("(");
						printf("%c",ans[i]);
					}
					printf("...)\n");
				}
				else
				{
					for(int i=1;i<=round;i++)
					{
						if(i==round) printf("(");
						printf("%c",ans[i]);
					}
					printf(")\n");
				}
				printf("   %d = number of digits in repeating cycle\n",1);
				break;
			}
			if(l)
			{
				if(round>51)
				{
					for(int i=1;i<=50;i++)
					{
						if(i==l) printf("(");
						printf("%c",ans[i]);
					}
					printf("...)\n");
				}
				else
				{
					for(int i=1;i<round;i++)
					{
						if(i==l) printf("(");
						printf("%c",ans[i]);
					}
					printf(")\n");
				}
				printf("   %d = number of digits in repeating cycle\n",round-l);
				break;
			}
			round++;
		}
		printf("\n");
	}
#ifdef LOCAL
	fclose(stdin);
	fclose(stdout);
#endif
}
```

## 3-9 All in all UVA10340

```c++
#include<iostream>
#include<string>
using namespace std;
int judge(string &a,string &b)
{
	int la=a.size();
	int lb=b.size();
	int now=0;
	for(int i=0;i<lb;i++)
	{
		if(a[now]==b[i]) now++;
		if(now==la) return 0;
	}
	return 1;
}
int main()
{
	string a,b;
	while(cin>>a>>b)
	{
		judge(a,b)?cout<<"No\n":cout<<"Yes\n";
	}
}
```

## 3-10 盒子 UVA1587

```c++
#include<iostream>
#include<vector>
#include<map>
//#define LOCAL
using namespace std;
int judge_len(vector<int>& vec)
{
	map<int,int> mp;
	for(int i=1;i<=12;i++)
	{
		mp[vec[i]]++;
	}
	if(mp.size()==3)
	{
		for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++)
		{
			if(it->second!=4) return 0;
		}
		return 1;
	}
	else if(mp.size()==2)
	{
		for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++)
		{
			if(it->second!=4&&it->second!=8) return 0;
		}
		return 1;
	}
	else if(mp.size()==1)
	{
		for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++)
		{
			if(it->second!=12) return 0;
		}
		return 1;
	}
	return 0;
}
int judge_squre(vector<int>& vec)
{
	vector<pair<int,int>> squre(6);
	for(int i=1;i<=11;i+=2)
	{
		vec[i]>vec[i+1]?(squre[i/2]={vec[i+1],vec[i]}):(squre[i/2]={vec[i],vec[i+1]});
	}
	pair<int,int> p={0,0};
	for(int i=0;i<6;i++)
	{ 
		if(squre[i]==p) continue;
		int flag=1;
		for(int j=0;j<6;j++)
		{
			if(i==j||squre[j]==p) continue;
			if(squre[i]==squre[j])
			{
				squre[i]={0,0};
				squre[j]={0,0};
				flag=0;
			}
		}
		if(flag)
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	vector<int> vec(20,0);
	while(cin>>vec[1]>>vec[2]>>vec[3]>>vec[4]>>vec[5]>>vec[6]>>vec[7]>>vec[8]
		  >>vec[9]>>vec[10]>>vec[11]>>vec[12])
	{
		int ok=1;
		if(!judge_len(vec)||!judge_squre(vec)) ok=0;
		ok?cout<<"POSSIBLE\n":cout<<"IMPOSSIBLE\n";
	}
#ifdef LOCAL
	fclose(stdin);
	fclose(stdout);
#endif
}
```

## 3-11 Kickdown UVA1588

```c++
#include<string>
#include<iostream>
#include<algorithm>
//#define LOCAL
using namespace std;
string rever(string& s)
{
	string ret;
	for(int i=s.size()-1;i>=0;i--)
	{
		ret+=s[i];
	}
	return ret;
}
//默认s2是长的且在下面，s1是短的且在上面
int anslen(string& s1,string& s2)
{
	int len1=s1.size();
	int len2=s2.size();
	int ans=len1+len2;
	for(int i=0;i<len2;i++)
	{
		int ok=1;
		for(int j=i;j<len1+i;j++)
		{
			if(j>=len2) continue;
			if(s1[j-i]+s2[j]-48>'3')
			{
				ok=0;
				break;
			}
		}
		if(ok)
		{
			if(len1+i>len2)
			{
				ans=len1+i;
				break;
			}
			else return len2;
		}
	}
	for(int i=1;i<len1;i++)
	{
		int ok=1;
		for(int j=0;j<len1-i;j++)
		{
			if(s1[j+i]+s2[j]-48>'3')
			{
				ok=0;
				break;
			}
		}
		if(ok)
		{
			if(ans>len2+i)
			{
				return len2+i;
			}
			else break;
		}
	}
	return ans;
}
int main()
{
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	string s1,s2;
	while(cin>>s2>>s1)
	{
		if(s2.size()>=s1.size())
			cout<<anslen(s1,s2)<<"\n";
		else     
		{
			s2=rever(s2);
			s1=rever(s1);
			cout<<anslen(s2,s1)<<"\n";
		}
	}
#ifdef LOCAL
	fclose(stdin);
	fclose(stdout);
#endif
}
```

# 第四章

## 程序4-2 组合数

```c++
long long C(int n,int m)
{
	if(m<n-m) m=n-m;
    long long ans=1;
    for(int i=m+1;i<=n;i++) ans*=i;
    for(int i=1;i<=n-m;i++) ans/=i;
    return ans;
}
```

### tips

为什么``if(m<n-m) m=n-m``?利用组合数的性质，将m转为较大的一个，让分子小一些，防止数值溢出

## 指针

``char* const *(*next)()`` next是一个指针，指向一个函数，这个函数没有接受参数，返回一个指针，这个指针指向一个char* const的指针常量
