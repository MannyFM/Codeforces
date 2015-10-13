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
//#define fn ""

int n, k, a;
set <pii> s;

inline int f(int l, int r)
{
	return (r - l + 2) / (a + 1);
}

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d%d", &n, &k, &a);
	int m, x, cur;
	scanf("%d", &m);
	s.insert(mp(n, 1));
	cur = f(1, n);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d", &x);
		auto it = s.lower_bound(mp(x, -1));
		int l = it -> S, r = it -> F;
		s.erase(it);
		//printf("%d [%d %d]\n", x, l, r);
		cur -= f(l, r);
		if (l <= x - 1)
		{
			cur += f(l, x - 1);
			s.insert(mp(x - 1, l));
		}
		if (x + 1 <= r)
		{
			cur += f(x + 1, r);
			s.insert(mp(r, x + 1));
		}
		if (cur < k)
		{
			printf("%d", i);
			return 0;
		}
		/*
		for (pii x : s)
			printf("(%d %d) ", x.F, x.S);
		puts("");
		*/
	}
	puts("-1");
}
