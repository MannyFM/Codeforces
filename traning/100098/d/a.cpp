
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = int(1e7 + 12);
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
#define rank MyLittleRank
//#define end MyLittleEnd
#define all(x) x.begin(), x.end()
#define fn "dsu"

int rank[maxn], boss[maxn];

int who(int v)
{
	return boss[v] = (boss[v] == v ? v : who(boss[v]));
}

bool same(int u, int v)
{
	return who(u) == who(v);
}

bool merge(int u, int v)
{
	u = who(u);
	v = who(v);
	if (u == v)
		return false;
	if (rank[u] < rank[v])
		swap(u, v);
	boss[v] = u;
	if (rank[u] == rank[v])
		rank[u]++;
	return true;
}

int n, k;

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		boss[i] = i;
	ll ans = 0ll;
	for (int t = 0; t < k; t++)
	{
		int u, v, c, du, dv, dc, m;
		scanf("%d%d%d%d%d%d%d", &u, &v, &c, &du, &dv, &dc, &m);
		for (int i = 0; i < m; i++)
		{
			//printf("%d %d %d\n", u, v, c);
			if (merge(u, v))
				ans += c;
			u = (u + du + n * 1ll * n) % n;
			v = (v + dv + n * 1ll * n) % n;
			c = (c + dc + ll(1e18)) % int(1e9);
		}
	}
	printf(I64, ans);
}
