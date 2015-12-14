
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

struct edge
{
	int a, b, c, t, i;
	edge() { a = b = c = t = i = 0;};
	edge(int c, int t, int id) : a(0), b(0), c(c), t(t), i(id) {};
};

bool operator < (edge a, edge b)
{
	if (a.c == b.c)
		return a.t > b.t;
	return a.c < b.c;
}

int n, m;
int from = 2, to = 3, last = 1;
int A[maxn], B[maxn];
edge e[maxn];

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		e[i] = (edge(a, b, i));
	}
	sort(e + 1, e + 1 + m);
	for (int i = 1; i <= m; i++)
	{
		if (e[i].t)
		{
			A[e[i].i] = 1;
			B[e[i].i] = ++last;
		}
		else
		{
			if (from == to)
				to++, from = 2;
			if (to > last)
			{
				//printf(":%d %d %d\n", i, to, last);
				puts("-1");
				return 0;
			}
			A[e[i].i] = from++;
			B[e[i].i] = to;
		}
		//printf(" %d %d %d %d  %d %d\n", e[i].c, e[i].t, A[e[i].i], B[e[i].i], from, to);
	}
	for (int i = 1; i <= m; i++)
		printf("%d %d\n", A[i], B[i]);
}

