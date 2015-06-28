
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
#define fn "a"
#define f first
#define s second

string s;
int a, b, ok;
int n;

vector <pii> v;

int main()
{
	#ifdef LOCAL
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d", &a, &b);
	cin >> s;
	v.pb(mp(0, 0));
	n = int(s.size());
	for (int i = 0; i < n; i++)
	{
		int x = v.back().f, y = v.back().s;
		if (s[i] == 'U')
			v.pb(mp(x, y + 1));
		if (s[i] == 'R')
			v.pb(mp(x + 1, y));
		if (s[i] == 'L')
			v.pb(mp(x - 1, y));
		if (s[i] == 'D')
			v.pb(mp(x, y - 1));
		//printf("%d %d\n", v.back().f, v.back().s);
	}
	//puts("");
	int dx = v.back().f, dy = v.back().s;
	//printf("%d %d\n", dx, dy);
	if (dx == 0 || dy == 0)
	{
		if (dx == 0 && dy == 0)
		{
			if (a != dx || b != dy)
			{
				puts("No");
				return 0;
			}
			puts("Yes");
			return 0;
		}
		if (a == dx && b == dy)
		{
			puts("Yes");
			return 0;
		}
		if (dx == 0)
		{
			if (a == 0 && b % dy == 0)
				ok = 1;
			else
				ok = 0;
		}
		if (dy == 0)
		{
			if (b == 0 && a % dx == 0)
				ok = 1;
			else
				ok = 0;
		}
		puts(ok ? "Yes" : "No");
		return 0;
	}

	//printf("%d %d\n", dx, dy);

	for (int i = 0; i < int(v.size()); i++)
	{
		int x = a - v[i].f, y = b - v[i].s;
		//printf("%d %d %d %d\n", x, y, v[i].f, v[i].s);
		if (x % dx == 0 && y % dy == 0 && x / dx == y / dy && x / dx > 0)
		{
			puts("Yes");
			return 0;
		}
	}
	puts("No");
}