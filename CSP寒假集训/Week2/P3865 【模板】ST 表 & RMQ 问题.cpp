#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;

int read()
{
	int x = 0, k = 1; char ch = getchar();
	while (ch < '0' || ch>'9')
	{
		if (ch == '-') k *= -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		x =( x << 1) + (x << 3) + ch - 48;
		ch = getchar();
	}
	return x*k;
}
const int maxn = 1e5 + 5;
int n, m;
int st[maxn][20];
int main()
{
	n = read(), m = read();
	for (int i = 1; i <= n; i++) st[i][0] = read();
	for (int j = 1; j <= 20; j++)
	{
		for (int i = 1; i + (1<<j)-1 <= n; i++)
		{
			st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1)) ][j - 1]);
		}
	}
	int l, r, k;
	for (int i = 1; i <= m; i++)
	{
		l = read(), r = read();
		k = log2(r - l + 1);
		printf("%d\n", max(st[l][k], st[r - (1 << k) + 1][k]));
	}
}
