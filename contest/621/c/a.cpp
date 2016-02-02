
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
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
#define fn "a"

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

int n, P, l[maxn], r[maxn];
ll p[maxn], neg[maxn], bol[maxn], all[maxn];
ld ans;

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &P);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", l + i, r + i);
	l[n + 1] = l[1], r[n + 1] = r[1];
	for (int i = 0; i <= n + 1; i++)
	{
		p[i] = (r[i] / P) - ((l[i] - 1) / P);
		neg[i] = r[i] - l[i] + 1 - p[i];
		all[i] = (r[i] - l[i] + 1);
	}
//	for (int i = 1; i <= n; i++)
//		printf(I64 " ", neg[i]);
//	puts("");
//	for (int i = 1; i <= n; i++)
//		printf(I64 " ", p[i]);
//	puts("");
	for (int i = 1; i <= n; i++)
	{
//		printf("1 - (" I64 " * " I64 ") / (" I64 " * " I64 ") = %.9f\n", neg[i], neg[i + 1], all[i], all[i + 1], 1 - (neg[i] * 1ll * neg[i + 1] + .0) / (all[i] * 1ll * all[i + 1]));
		ans += 1 - (neg[i] * 1ll * neg[i + 1] + .0) / (all[i] * 1ll * all[i + 1]);
	}
//	puts("");
//	printf("2000 * %.9f=", (double)ans);
	printf("%.9f", 2000 * double(ans));
}

