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

struct edge
{
	int a, b, c, t, id;
	edge(){ a = b = c = t = id = 0;}
	edge(int c, int t, int id) : a(0), b(0), c(c), t(t), id(id){};
};


bool cmp(edge a, edge b)
{
	if (a.t == b.t)
		return a.c < b.c;
	return a.t > b.t;
}

bool cmp2(edge a, edge b)
{
	return a.id < b.id;
}

int n, m;
int mx[maxn];
int a[maxn], b[maxn];
edge e[maxn];
set <pii> se;
set <int> g[maxn];

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d", a + i, b + i);
		e[i] = edge(a[i], b[i], i);
	}
	for (int i = 1; i <= n; i++)
		mx[i] = inf;
	sort(e + 1, e + 1 + m, cmp);
	int last = 1;
	//puts("");
	for (int i = 1; i <= m; i++)
	{
		//printf("%d %d\n", e[i].c, e[i].t);
		if (e[i].t)
		{
			e[i].a = 1;
			e[i].b = ++last;
			g[1].insert(last);
			g[last].insert(1);
			mx[1] = e[i].c;
			mx[last] = e[i].c;
			se.insert(mp(mx[last], last));
			//printf("%d -> %d = %d\n", 1, last, e[i].c);
		}
	}
	//puts("");
	for (int i = 1; i <= m; i++)
	{
		if (!e[i].t)
		{
			auto itt = se.begin();
			int a = -1, b = -1;
			while (itt != se.end())
			{
				a = itt -> S;
				auto it = itt;
				it++;
				while (it != se.end() && g[a].count(it -> S))
					it++;
				if (it != se.end())
				{
					b = it -> S;
					se.erase(itt);
					se.erase(it);
					break;
				}
				itt++;
			}
			if (itt == se.end())
			{
				puts("-1");
				return 0;
			}
			if (mx[b] > e[i].c)
			{
				puts("-1");
				return 0;
			}
			g[a].insert(b);
			g[b].insert(a);
			e[i].a = a;
			e[i].b = b;
			mx[a] = max(mx[a], e[i].c);
			mx[b] = max(mx[b], e[i].c);
			if (int(g[a].size()) != n - 1)
				se.insert(mp(mx[a], a));
			if (int(g[b].size()) != n - 1)
				se.insert(mp(mx[b], b));
			//printf("%d -> %d = %d\n", a, b, e[i].c);
		}
	}
	sort(e + 1, e + 1 + m, cmp2);
	for (int i = 1; i <= m; i++)
		printf("%d %d\n", e[i].a, e[i].b);
}
