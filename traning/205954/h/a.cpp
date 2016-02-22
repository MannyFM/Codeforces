
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

int n, a[maxn];
int ans[maxn];
int l[maxn], r[maxn];
int st[maxn], h;
vector <pii> v;

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	for (int i = 1; i <= n; i++)
	{
		while (h && a[st[h - 1]] > a[i])
		{
			r[st[h - 1]] = i;
			h--;
		}
		st[h++]= i;
		r[i] = n + 1;
	}
	h = 0;
	for (int i = n; i > 0; i--)
	{
		while (h && a[st[h - 1]] > a[i])
		{
			l[st[h - 1]] = i;
			h--;
		}
		st[h++] = i;
	}
//	for (int i = 1; i <= n; i++)
//		printf("%d ", l[i]);
//	puts("");
//	for (int i = 1; i <= n; i++)
//		printf("%d ", r[i]);
//	puts("");
	for (int i = 1; i <= n; i++)
	{
//		printf("%d: %d(%d - %d - 1)\n", a[i], r[i] - l[i] - 1, r[i], l[i]);
		v.pb({a[i], r[i] - l[i] - 1});
	}
	sort(all(v));
	for (int i = 0; i < n; i++)
		umax(ans[v[i].S], v[i].F);
	for (int i = n; i > 0; i--)
		umax(ans[i], ans[i + 1]);
	for (int i = 1; i <= n; i++)
		printf("%d ", ans[i]);
}

