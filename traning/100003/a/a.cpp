
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
#define fn "aisle"
#define NO {puts("-1"); exit(0);}

int n, l, w, x, y, a;

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d%d%d%d%d%d", &n, &l, &w, &x, &y, &a);
	if (l < x || w < a || w < y)
		NO;

	int L = l / x;
	int C = (n + L - 1) / L;
	if (C * y + a > w)
		NO;
	printf("%d", min(L * min((w - C * y) / a * 2, C), n));
}
