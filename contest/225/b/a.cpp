
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

vector <ll> v, ans;
ll f[maxn];
int n, k;

bool rec(ll x, int last)
{
	//printf(I64 " %d\n", x, last);
	if (!x)
	{
		ans.pb(0);
		return 1;
	}
	if (last < 0)
		return 0;
	for (int i = last; i >= 0; i--)
		if (v[i] <= x && rec(x - v[i], i - 1))
		{
			ans.pb(v[i]);
			return 1;
		}
	return 0;
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &k);
	if (k < 300)
	{
		f[k] = 1;
		for (int i = k + 1; ; i++)
		{
			for (int x = 1; x <= k; x++)
				f[i] += f[i - x];
			if (f[i] > n)
				break;
			v.pb(f[i]);
		}
	}
	else
	{
		v.pb(1);
		for (ll x = 2; x <= n + 0ll; x += x)
			v.pb(x);
	}
//	for (ll x : v)
//		printf(I64 " " , x);
//	puts("");
	rec(n, v.size() - 1);
	printf("%d\n", (int)ans.size());
	for (ll x : ans)
		printf(I64 " ", x);
}

