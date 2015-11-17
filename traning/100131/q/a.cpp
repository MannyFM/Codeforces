
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
#define rank MyLittleRank
//#define end MyLittleEnd
#define all(x) x.begin(), x.end()
//#define fn

int boss[maxn];
int rank[maxn];

int who(int x)
{
	if (boss[x] == x)
		return x;
	return boss[x] = who(boss[x]);
}

bool merge(int x, int y)
{
	x = who(x);
	y = who(y);
	if (x == y)
		return 0;
	if (rank[x] < rank[y])
		swap(x, y);
	boss[y] = x;
	if (rank[x] == rank[y])
		rank[x]++;
	return 1;
}

struct edge
{
	int a, b, c;
	edge()
	{
		a = b = c = 0;
	}
	edge(int a, int b, int c) : a(a), b(b), c(c) {};
};

bool cmp(edge a, edge b)
{
	return a.c < b.c;
}

vector <edge> v;
int n, m;

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	v.resize(m);
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		v[i] = edge(a, b, c);
	}
	for (int i = 1; i <= n; i++)
		boss[i] = i;
	sort(all(v), cmp);
	ll ans = 0;
	for (int i = 0; i < m; i++)
	{
		if (merge(v[i].a, v[i].b))
			ans += v[i].c;
	}
	printf(I64, ans);
}
