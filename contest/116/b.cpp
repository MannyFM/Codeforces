
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
#define eps 1e-7
#define mp make_pair
#define pb push_back
//#define fn "a"
#define F first
#define S second

int n, m, ans;
char s[20][20];

int f(int x, int y)
{
	if (s[x][y] != 'W')
		return 0;
	for (int dx = -1; dx < 2; dx++)
		for (int dy = -1; dy < 2; dy++)
			if (abs(dx) + abs(dy) == 1)
				if (s[x + dx][y + dy] == 'P')
					return 1;
	return 0;
}

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("\n%s", s[i] + 1);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			ans += f(i, j);
	printf("%d", ans);
}
