
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = int(1e5 + 12);
int const maxlen = 5 * 1000 * 1000 + 13;
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
#define fn "f"

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

int n;
int lp[maxlen];
vector <int> pr;

ll bp(ll a, ll b)
{
	ll ans = 1ll;
	while (b)
	{
		if (b & 1)
			ans *= a;
		a *= a;
		b >>= 1;
	}
	return ans;
}

mii a[maxlen];

ll solve(int x, int y)
{
	mii cur;
	for (pii f : a[x])
	{
		printf("+(%d %d) ", f.F, f.S);
		cur[f.F] += f.S;
	}
	for (pii f : a[y])
	{
		printf("-(%d %d) ", f.F, f.S);
		cur[f.F] -= f.S;
	}
	ll ans = 1ll;
	for (pii f : cur)
	{
		printf("(%d %d) ", f.F, f.S);
		ans += f.S;
	}
	return ans;
}

void pre()
{
	int N = 5 * 100;
	lp[0] = lp[1] = 1;
	for (int i = 2; i <= N; i++)
	{
		if (!lp[i])
		{
			lp[i] = i;
			pr.pb(i);
		}
		for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && pr[j] * 1ll * i <= N; j++)
			lp[i * pr[j]] = pr[j];
	}
	for (int i = 1; i <= N; i++)
		printf("lp[%d]=%d\n", i, lp[i]);
	puts("");
	for (int i = 1; i <= N; i++)
	{
		if (i % 1000 == 0)
			cerr << i << "\n";
		int x = i;
		a[i] = a[i - 1];
		while (x > 1)
		{
			a[i][lp[x]]++;
			x /= lp[x];
		}
	}
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	pre();
	int t, x, y;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &x, &y);
		printf(I64 "\n", solve(x, y));
	}
}

