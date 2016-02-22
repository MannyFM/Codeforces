
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = int(1e6 + 12);
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
//#define fn "f"

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

int lp[maxb];
int n, a[maxn], N;
ll cnt[maxb];
vector <int> v;

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", a + i), umax(N, a[i]);
	}
	lp[1] = lp[0] = 1;
	for (int i = 2; i <= N; i++)
	{
		if (!lp[i])
		{
			lp[i] = i;
			v.pb(i);
		}
		for (int j = 0; j < (int)v.size() && v[j] <= lp[i] && i * v[j] <= N; j++)
			lp[i * v[j]] = v[j];
	}
	for (int i = 1; i <= n; i++)
	{
		int x = a[i], last = -1;
//		printf("%d %d: ", i, x);
		while (x > 1)
		{
//			printf("%d ", lp[x]);
			if (last != lp[x])
				cnt[lp[x]]++;
			last = lp[x];
			x /= lp[x];
		}
//		puts("");
	}
	for (int i = 1; i <= N; i++)
	{
//		if (cnt[i])
//			printf("(%d " I64 ") ", i, cnt[i]);
		cnt[i] += cnt[i - 1];
	}
	int m, l, r;
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &l, &r);
		ll ans = 0;
		if (r > N)
			r = N;
		if (l <= N)
			ans = cnt[r] - cnt[l - 1];
		printf(I64 "\n", ans);
	}
}

