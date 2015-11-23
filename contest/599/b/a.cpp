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

int n, m;
int pos[maxn], a[maxn], f[maxn], b[maxn];
int cnt[maxn];

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", f + i), cnt[f[i]]++, pos[f[i]] = i;
	for (int i = 1; i <= m; i++)
		scanf("%d", b + i);
	bool f1 = 0;
	for (int i = 1; i <= m; i++)
	{
		if (!cnt[b[i]])
		{
			puts("Impossible");
			return 0;
		}
		if (cnt[b[i]] > 1)
			f1 = 1;
		a[i] = pos[b[i]];
	}
	if (f1)
	{
		puts("Ambiguity");
		return 0;
	}
	puts("Possible");
	for (int i = 1; i <= m; i++)
		printf("%d ", a[i]);
}
