
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

int n, m;
int d[maxn], s[maxn];
vector <int> g[maxn];
int st[maxn], head;

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", d + i, s + i);
		if (d[i] == 1)
			st[head++] = i;
	}
	while (head)
	{
		int v = st[--head], to = s[v];
		if (!d[v])
			continue;
		g[v].pb(to);
		m++;
		s[to] ^= v;
		d[to]--;
		if (d[to] == 1)
			st[head++] = to;
	}
	printf("%d\n", m);
	for (int i = 0; i < n; i++)
		for (int to : g[i])
			printf("%d %d\n", i, to);
}

