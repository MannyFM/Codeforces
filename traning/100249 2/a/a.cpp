
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
#define fn "sum"

int n;
ll T[4 * maxn];

void upd(int v, int tl, int tr, int pos, int x)
{
	if (tl == tr)
	{
		T[v] = x;
		return;
	}
	int tm = (tl + tr) >> 1;
	if (pos <= tm)
		upd(v + v, tl, tm, pos, x);
	else
		upd(v + v + 1, tm + 1, tr, pos, x);
	T[v] = T[v + v] + T[v + v + 1];
}

ll sum(int v, int tl, int tr, int l, int r)
{
	if (l > r || tr < l || r < tl)
		return 0ll;
	if (l <= tl && tr <= r)
		return T[v];
	int tm = (tl + tr) >> 1;
	return sum(v + v, tl, tm, l, r)
		+ sum(v + v + 1, tm + 1, tr, l, r);
}

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	int m;
	scanf("%d%d", &n, &m);
	char c;
	int x, y;
	for (int i = 1; i <= m; i++)
	{
		scanf(" %c%d%d", &c, &x, &y);
		if (c == 'A')
			upd(1, 1, n, x, y);
		else
			printf(I64 "\n", sum(1, 1, n, x, y));
	}
}
