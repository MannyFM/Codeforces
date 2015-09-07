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
#define all(x) x.begin(), x.end()
//#define fn ""

int n;
ll x, a, ans;
vector <pll> l, r;

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf(I64 I64, &x, &a);
		if (x > 0)
			r.pb(mp(x, a));
		else
			l.pb(mp(x, a));	
	}
	sort(all(l));
	reverse(all(l));
	sort(all(r));
	for (int i = 0; i < int(l.size()) &&  i < int(r.size()); i++)
	{
		ans += l[i].S + r[i].S;
		//printf(I64 " " I64 "  " I64 " " I64 "\n", l[i].F, l[i].S, r[i].F, r[i].S);
	}
	if (l.size() > r.size())
		ans += l[r.size()].S;
	if (l.size() < r.size())
		ans += r[l.size()].S;
	printf(I64, ans);
}
