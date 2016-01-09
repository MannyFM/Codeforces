
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
//#define fn ""

struct ev
{
	int x, open;
	ev() : x(0), open(0) {};
	ev(int x, int o) : x(x), open(o) {};
};

int n, k;
vector <pii> ans;
vector <ev> a;

bool operator < (const ev & a, const ev & b)
{
	return a.x != b.x ? a.x < b.x : a.open && !b.open;
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		a.pb(ev(l, 1));
		a.pb(ev(r, 0));
	}
	sort(a.begin(), a.end());
	int cur = 0, L = -inf;
	for (auto & i : a)
	{
		if (i.open)
		{
			cur++;
			if (cur >= k && L == -inf)
				L = i.x;
		}
		else
		{
			if (cur == k)
			{
				ans.pb(mp(L, i.x));
				L = -inf;
			}
			cur--;
		}
		//printf("x:%d o:%d c:%d\n", i.x, i.open, cur);
	}
	if (L != -inf)
		ans.pb(mp(L, a.back().x));
	printf("%d\n", (int)ans.size());
	for (pii x : ans)
		printf("%d %d\n", x.F, x.S);
}

