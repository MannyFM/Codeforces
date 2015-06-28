
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
#define mp make_pair
#define pb push_back
//#define fn "a"
#define F first
#define S second

string s[120];
char _s[120];
int n, m;
set <string> pre[120];
set <string> suf[120];

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", _s);
		s[i] = string(_s);
	}
	puts("");

	sort (s, s + n);
	for (int i = 0; i < n; i++)
		puts(s[i].c_str());
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			pre[j + 1].insert(s[i].substr(0, j + 1));
			suf[m - j].insert(s[i].substr(j, m - j));
		}
	}
	for (int len = 1; len < m; len++)
	{
		printf("%d\n", int(pre[len].size()));
		for (auto i : pre[len])
			puts(i.c_str());
	}
	for (int len = m - 1; len > 0; len--)
	{
		printf("%d\n", int(suf[len].size()));
		for (auto i : suf[len])
			puts(i.c_str());
	}
	ll ans = 0;
	for (int len = 1; len < m; len++)
	{
		ans += pre[len].size() * 1ll * suf[m - len].size();
	}
	printf("%I64d", ans);
}
