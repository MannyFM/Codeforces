#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = int(2e5 + 12);
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
#define all(x) x.begin(), x.end()
//#define fn ""

map <int, set <pii> > m;
int n, w[maxn];
pii a[maxn], last, ans[maxn];

bool cmp (pii a, pii b)
{
	return a.F <= b.F && a.S <= b.S;
}

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d", &n);
	int X = -inf, Y = -inf;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", &a[i].F, &a[i].S);
		X = max(X, a[i].F);
		Y = max(Y, a[i].S);
		m[a[i].S - a[i].F].insert(a[i]);
	}
	for (int i = 1; i <= n; i++)
		scanf("%d", w + i);
	for (int i = 0; i <= X; i++)
		m[-i].insert(mp(i, 0));
	for (int i = 0; i <= Y; i++)
		m[i].insert(mp(0, i));
	last = mp(-inf, -inf);
	for (int i = 1; i <= n; i++)
	{
		int W = w[i], & p = pos[W];
		vector <pii> & v = m[W];
		//printf("%d %d [%d %d]\n", W, p, v[p].F, v[p].S);
		if (p >= int(v.size()))
		{
			puts("NO");
			return 0;
		}
		while (p < int(v.size()) && !cmp(last, v[p]))
			p++;
		ans[i] = v[p++];
	}
	/*
	for (int i = 2; i <= n; i++)
		if (cmp(a[i], a[i - 1]))
		{
			puts("NO");
			return 0;
		}
	*/
	puts("YES");
	for (int i = 1; i <= n; i++)
		printf("%d %d\n", ans[i].F, ans[i].S);
}
