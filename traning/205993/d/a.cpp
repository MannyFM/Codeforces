
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

template <typename T>
bool umax(T & a, T b)
{
	return a < b ? (a = b, 1) : 0;
}

template <typename T>
bool umin(T & a, T b)
{
	return a > b ? (a = b, 1) : 0;
}

typedef vector <int> vi;

vi parse(ll x)
{
	vi v;
	while (x > 0)
		v.pb(x & 1), x >>= 1;
//	for (int i = 0; i < (int)v.size(); i++)
//		printf("%d ", v[(int)v.size() - i - 1]);
//	puts("");
	return v;
}

ll calc(const vi & v)
{
	ll p = 1, ans = 0;
	for (int i = (int)v.size() - 1; i >= 0; i--)
		ans += v[i] * p, p <<= 1;
	return ans;
}

bool better(ll & a, ll & b)
{
	int pa = __builtin_popcountll(a), pb = __builtin_popcountll(b);
	if (pa < pb || (pa == pb && a > b))
	{
		a = b;
		return 1;
	}
	return 0;
}

ll solve(ll L, ll R)
{
	auto l = parse(L), r = parse(R);
	while (l.size() < r.size())
		l.pb(0);
	while (l.size() > r.size())
		r.pb(0);
	reverse(all(l));
	reverse(all(r));
	int n = (int)l.size();
	ll p = 0;
	ll ans = L;
	better(ans, R);
	for (int i = 0; i < n; i++)
	{
		ll cur = p | ((1ll << (n - i - 1)) - 1);
//		printf(I64 " ", p);
//		printf(I64 ":\n", cur);
//		parse(cur);
		if (L <= cur && cur <= R)
			better(ans, cur);
		if (r[i])
			p |= (1ll << (n - i - 1));
//		puts("");
	}
//	ll t = 1;
//	while (t <= R)
//	{
//		if (L <= t)
//			better(ans, t);
//		t = (t << 1) | 1;
//	}
	return ans;
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	int T;
	ll l, r;
	scanf("%d", &T);
	while (T--)
	{
		scanf(I64 I64, &l, &r);
		printf(I64 "\n", solve(l, r));
	}
}

