
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = int(2e5 + 12);
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

#define rt(x) {puts(x); exit(0);}
int n, d, m;
pii x[maxn];
int can[maxn];
set <pii> se;

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d%d%d", &d, &n, &m);
	for (int i = 1; i <= m; i++)
		scanf("%d%d", &x[i].F, &x[i].S);
	sort(x + 1, x + 1 + m);
	x[m + 1] = {d, 0};
	ll ans = 0ll;
	se.insert({0, 0});
	int i = 1, pos = n;
	for (; i <= m && x[i].F <= n; i++)
		se.insert({x[i].S, x[i].F + n});
	for (; i <= m + 1; i++)
	{
//		printf("p:%d i:%d\n", pos, i);
//		for (pii x : se)
//			printf("(%d %d) ", x.F, x.S);
//		puts("");
		while (!se.empty() && x[i].F > se.begin() -> S)
		{
			if (se.begin() -> S > pos)
			{
				ans += (se.begin() -> S - pos + 0ll) * se.begin() -> F;
				pos = se.begin() -> S;
			}
			se.erase(se.begin());
		}
//		printf("p:%d i:%d\n", pos, i);
//		for (pii x : se)
//			printf("(%d %d) ", x.F, x.S);
//		puts("\n");
		if (se.empty())
			rt("-1")
		ans += (x[i].F - pos + 0ll) * se.begin() -> F;
		pos = x[i].F;
		se.insert({x[i].S, x[i].F + n});
	}
	if (pos < d)
		ans = -1;
	printf(I64, ans);
}

