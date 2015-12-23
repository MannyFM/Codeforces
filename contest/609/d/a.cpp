
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
#define fn "gadget"

template <typename T>
bool umin(T & a, const T & b)
{
	if (a > b)
	{
		a = b;
		return true;
	}
	return false;
}

int n, m, K;
ll s;
int a[maxn], b[maxn];
pii A[maxn], B[maxn];

vector <pii> x[3];
vector <pii> y;

bool f(int k)
{
	int d = A[k].F, p = B[k].F;
	int D = A[k].S, P = B[k].S;
	int i = 0, j = 0;
	ll S = 0;
	y.clear();
	//printf("k:%d D:(%d %d$) P:(%d %d$)\n", k, D, d, P, p);
	while ((int)y.size() < K && (i < (int)x[1].size() || j < (int)x[2].size()))
	{
		//printf(I64 " vs " I64, x[1][i].F * 1ll * d, x[2][j].F * 1ll * p);
		if (j == int(x[2].size()) ||( i < int(x[1].size()) && x[1][i].F * 1ll * d < x[2][j].F * 1ll * p))
		{
			S += x[1][i].F * 1ll * d;
			y.pb(mp(x[1][i++].S, D));
		}
		else
		{
			S += x[2][j].F * 1ll * p;
			y.pb(mp(x[2][j++].S, P));
		}
		//printf("(%d %d)\n", y.back().F, y.back().S);
		if (S > s)
		{
			//puts("-");
			return 0;
		}
		if ((int)y.size() >= K)
		{
			//puts("+");
			return 1;
		}
	}
	//puts("-");
	return 0;
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d%d%d" I64, &n, &m, &K, &s);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	for (int i = 1; i <= n; i++)
		scanf("%d", b + i);
	for (int i = 1; i <= m; i++)
	{
		int t, q;
		scanf("%d%d", &t, &q);
		x[t].pb(mp(q, i));
	}
	sort(x[1].begin(), x[1].end());
	sort(x[2].begin(), x[2].end());
//	for (pii q : x[1])
//		printf("[%d %d] ", q.F, q.S);
//	puts("");
//	for (pii q : x[2])
//		printf("[%d %d] ", q.F, q.S);
//	puts("");
	A[0] = B[0] = mp(inf, 0);
	for (int i = 1; i <= n; i++)
	{
		A[i] = min(A[i - 1], mp(a[i], i));
		B[i] = min(B[i - 1], mp(b[i], i));
	}
	int l = 0, r = n + 1;
	while (r - l > 1)
	{
		int m = (l + r) >> 1;
		if (f(m))
			r = m;
		else
			l = m;
	}
	if (r == n + 1 || !f(r))
	{
		puts("-1");
		return 0;
	}
	printf("%d\n", r);
	for (pii x : y)
		printf("%d %d\n", x.F, x.S);
}

