
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define maxn int(2e6 + 12)
#define maxb int(2e6 + 12)
#define inf int(1e9 + 7)
#define linf ll(1e18 + 12)
#define shift 1000
#define eps 1e-7
#define mp make_pair
#define pb push_back
#define fn "c"
#define F first
#define S second

char a[2010][1010];
int n, b[1010];
int x, y;

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", b + i);
	x = 0, y = 0;
	int u = -1000, d = 1000;
	for (int i = 1; i <= n; i++)
	{
		if (i & 1)
		{
			for (int k = 1; k <= b[i]; k++)
			{
				u = max(u, y);
				d = min(d, y);
				a[y + shift][x] = 47;
				x++, y--;
			}
			y++;
		}
		else
		{
			for (int k = 1; k <= b[i]; k++)
			{
				u = max(u, y);
				d = min(d, y);
				a[y + shift][x] = 92;
				x++, y++;
			}
			y--;
		}
	}
	//printf("%d %d\n%d %d\n", 0, x, u, d);
	for (int j = d + shift; j <= u + shift; j++)
	{
		//putchar('!');
		for (int i = 0; i < x; i++)
			putchar(!a[j][i] ? ' ' : a[j][i]);
		//putchar('!');
		if (j != u + shift)
			puts("");
	}
}