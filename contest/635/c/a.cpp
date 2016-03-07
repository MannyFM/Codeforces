
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

ll s, x;

typedef vector <int> vi;

vi parse(ll x)
{
	vi ans;
	while(x > 0)
	{
		ans.pb(x & 1);
		x >>= 1;
	}
	return ans;
}

ll solve(ll s, ll x)
{
	auto S = parse(s), X = parse(x);
	while (X.size() < S.size())
		X.pb(0);
	while (X.size() > S.size())
		S.pb(0);
	reverse(all(X));
	reverse(all(S));
//	for (int i = 0; i < (int)X.size(); i++)
//		printf("%d", X[i]);
//	puts("");
//	for (int i = 0; i < (int)S.size(); i++)
//		printf("%d", S[i]);
//	puts("");
	int bal = 0, n = (int)X.size(), ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (bal)
		{
			if (S[i] && !X[i])
				continue;
			if (S[i] && X[i])
				return 0ll;
			if (!X[i])
			{
				bal--;
				continue;
			}
			if (X[i])
				ans++;
		}
		else
		{
			if (S[i])
			{
				if (X[i])
					ans++;
				if (!X[i])
					bal++;
				continue;
			}
			if (X[i])
				return 0ll;
			if (!X[i])
				continue;
		}
	}
	if (bal != 0)
		return 0ll;
	return (1ll << ans) + (x == s ? -2 : 0);
}

#define NO {puts("0"); exit(0);}
int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf(I64 I64, &s, &x);
//	ll test = 0;
//	for (ll a = 1; a < s; a++)
//	{
//		ll b = s - a;
////		if (b < a)
////			break;
//		if (b != (a ^ x))
//			continue;
//		test++;
////		printf("(" I64 " " I64 ")\n", a, b);
//	}
	ll ans = solve(s, x);
//	if (ans != test)
//	{
//		printf(I64 "!=", test);
//	}
	printf(I64, ans);
}

