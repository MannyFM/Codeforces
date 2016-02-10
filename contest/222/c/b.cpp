
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = int(1e5 + 12);
int const maxb = int(1e7 + 12);
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

int n, m, a[maxn], b[maxn];
int A[maxn], B[maxn];
int lp[maxb];
mii cnt[2];
vector <int> pr;

void parse(int x, int f)
{
	while (x > 1)
	{
		cnt[f][lp[x]]++;
		x /= lp[x];
	}
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	for (int i = 2; i < maxb; i++)
	{
		if (!lp[i])
		{
			lp[i] = i;
			pr.pb(i);
		}
		for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * 1ll * pr[j] < maxb; j++)
			lp[i * pr[j]] = pr[j];
	}
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	for (int i = 1; i <= m; i++)
		scanf("%d", b + i);
	for (int i = 1; i <= n; i++)
		parse(a[i], 0);
	for (int i = 1; i <= m; i++)
		parse(b[i], 1);
	for (int i = 1; i <= n; i++)
	{
		cnt[2].clear();
		parse(a[i], 2);
		for (pii f : cnt[2])
		{
			int need = min(cnt[1][f.F], cnt[0][f.F]);
		}
	}
}

