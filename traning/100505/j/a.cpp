
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
#define fn "dominoes"

typedef vector <int> vi;
map <int, pair <int, vi>> head, tail, nhead, ntail;

void add(int a, int b)
{
	nhead.clear(), ntail.clear();
	int len = tail[a].F;
	vi v = tail[a].S;
	for (int c : v)
	{
		auto it = nhead[c];
		if (it.F < len + 1)
		{
			it.F = len + 1;
			it.S.clear();
		}
		if (it.F == len + 1)
			it.S.pb(b);
	}
	auto it = ntail.find(a);
	if (it == ntail.end())
		ntail[a] = mp(1, vi(1, b));
	else
		if (it -> S.F == 1)
			it -> S.S.pb(b);
	
	len = head[b].F;
	v = head[b].S;
	for (int c : v)
	{
		auto it = ntail[c];
		if (it.F != len + 1)
		{
			it.F = len = 1;
			it.S.clear();
		}
		if (it.F == len + 1)
			it.S.pb(a);
	}
	it = nhead.find(b);
	if (it == nhead.end())
		nhead[b] = mp(1, vi(1, a));
	else
		if (it -> S.F == 1)
			it -> S.S.pb(a);
	
	for (auto x : nhead)
	{
		printf("nhead[%d]= (%d, [", x.F, x.S.F);
		for (int y : x.S.S)
			printf("%d,", y);
		puts("])");
	}
	for (auto x : ntail)
	{
		printf("ntail[%d]= (%d, [", x.F, x.S.F);
		for (int y : x.S.S)
			printf("%d,", y);
		puts("])");
	}
	for (auto x : head)
	{
		auto &y = nhead[x.F];
		if (x.S.F > y.F)
		{
			y = x.S;
			continue;
		}
		if (x.S.F == y.F)
		{
			merge(all(y.S), all(y.S), y.S.begin());
			continue;
		}
	}
	for (auto x : tail)
	{
		auto &y = ntail[x.F];
		if (x.S.F > y.F)
		{
			y = x.S;
			continue;
		}
		if (x.S.F == y.F)
		{
			merge(all(y.S), all(y.S), y.S.begin());
			continue;
		}
	}
	for (auto x : nhead)
	{
		printf("head[%d]= (%d, [", x.F, x.S.F);
		for (int y : x.S.S)
			printf("%d,", y);
		puts("])");
	}
	for (auto x : ntail)
	{
		printf("tail[%d]= (%d, [", x.F, x.S.F);
		for (int y : x.S.S)
			printf("%d,", y);
		puts("])");
	}
	puts("");
	head = nhead;
	tail = ntail;
}

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	int n, x, y;
	scanf("%d%d%d", &n, &x, &y);
	head[x] = mp(1, vi(1, y));
	tail[y] = mp(1, vi(1, x));
	for (auto x : head)
	{
		printf("head[%d]= (%d, [", x.F, x.S.F);
		for (int y : x.S.S)
			printf("%d,", y);
		puts("])");
	}
	for (auto x : tail)
	{
		printf("tail[%d]= (%d, [", x.F, x.S.F);
		for (int y : x.S.S)
			printf("%d,", y);
		puts("])");
	}
	puts("");
	for (int i = 2; i <= n; i++)
	{
		scanf("%d%d", &x, &y);
		add(x, y);
	}
}
