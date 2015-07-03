
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair<list<int>, list<int> > pv;

int const maxn = int(1e5 + 12);
int const maxb = int(2e6 + 12);
int const inf = int(1e9 + 7);
ll const linf = ll(1e18 + 12);
double const eps = 1e-7;
double const pi = acos(-1);
#ifdef WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif
#define mp make_pair
#define pb push_back
#define F first
#define S second
//#define fn ""

int n;
list<int> l, r;
int k1, k2, x;

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d", &n);
	scanf("%d", &k1);
	for (int i = 0; i < k1; i++)
	{
		scanf("%d", &x);
		l.pb(x);
	}
	scanf("%d", &k2);
	for (int i = 0; i < k2; i++)
	{
		scanf("%d", &x);
		r.pb(x);
	}
	map <pv, int> us;
	queue <pv> Q;
	us[mp(l, r)] = 0;
	Q.push(mp(l, r));
	while (!Q.empty())
	{
		pv v = Q.front();
		int CurAns = us[v];
		Q.pop();
		int L = v.F.front();
		v.F.pop_front();
		int R = v.S.front();
		v.S.pop_front();
		if (L < R)
		{
			v.S.pb(L);
			v.S.pb(R);
		}
		if (L > R)
		{
			v.F.pb(R);
			v.F.pb(L);
		}
		if (us.count(v))
		{
			puts("-1");
			return 0;
		}
		us[v] = CurAns + 1;
		if (v.F.empty())
		{
			printf("%d %d", us[v], 2);
			return 0;
		}
		if (v.S.empty())
		{
			printf("%d %d", us[v], 1);
			return 0;
		}
		Q.push(v);
	}
}