
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = int(1e5 + 12);
int const maxb = int(2e6 + 12);
int const inf = int(1e9 + 7);
ll const linf = ll(1e18 + 12);
double const eps = 1e-7;
double const pi = acos(-1);
#ifdef _WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define next MyLittleNext
//#define end MyLittleEnd
#define all(x) x.begin(), x.end()
#define fn "tic-tac-toe"

char s[1010][1010];
int n, m;

bool check(int x, int y)
{
	char & c = s[x][y];
	if (c == '.')
		return false;
	bool ok = true;
	if (x + 4 <= n)
	{
		for (int i = 1; i <= 4; i++)
			if (s[i + x][y] != c)
			{
				ok = false;
				break;
			}
		if (ok)
			return ok;
	}
	if (y + 4 <= m)
	{
		ok = true;
		for (int i = 1; i <= 4; i++)
			if (s[x][y + i] != c)
			{
				ok = false;
				break;
			}
		if (ok)
			return ok;
	}
	if (x + 4 <= n && y + 4 <= m)
	{
		ok = true;
		for (int i = 1; i <= 4; i++)
			if (s[x + i][y + i] != c)
			{
				ok = false;
				break;
			}
		if (ok)
			return true;
	}
	if (x + 4 <= n && 5 <= y)
	{
		ok = true;
		for (int i = 1; i <= 4; i++)
			if (s[x + i][y - i] != c)
			{
				ok = false;
				break;
			}
		if (ok)
			return true;
	}
	if (5 <= x && y + 4 <= m)
	{
		ok = true;
		for (int i = 1; i <= 4; i++)
			if (s[x - i][y + i] != c)
			{
				ok = false;
				break;
			}
		if (ok)
			return ok;
	}
	if (5 <= x && 5 <= y)
	{
		ok = true;
		for (int i = 1; i <= 4; i++)
			if (s[x - i][y - i] != c)
			{
				ok = false;
				break;
			}
		if (ok)
			return ok;
	}
	return false;
}


int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%s", s[i] + 1);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (check(i, j))
			{
				puts("Yes");
				return 0;
			}
	puts("No");
}
