
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = 300000;
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
#define fn "balls"

ll f[502], g[502];
int cnt[maxn + 12], N;

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	f[1] = g[1] = 1;
	N = 1;
	for (int i = 2; ; i++)
	{
		f[i] = f[i - 1] + i;
		g[i] = g[i - 1] + f[i];
		N++;
		if (g[i] >= 300000)
			break;
	}
	for (int i = 1; i <= maxn; i++)
		cnt[i] = inf;
	cnt[0] = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= maxn; j++)
			if (j + g[i] <= maxn)
				cnt[j + g[i]] = min(cnt[j + g[i]], cnt[j] + 1);
	}
	int t, x;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &x);
		printf("%d\n", cnt[x]);
	}
}
