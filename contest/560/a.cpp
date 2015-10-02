
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
#define WA {puts("NO"); exit(0);}
#define OK {puts("YES"); exit(0);}

int n, m;
int x, y, a, b;

bool in(int a, int b, int n, int m)
{
	if (a > b)
		swap(a, b);
	if (n > m)
		swap(n, m);
	if (a > n)
		return false;
	if (b > m)
		return false;
	return true;
}

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	scanf("%d%d", &x, &y);
	scanf("%d%d", &a, &b);
	if ((x + a <= n && max(y, b) <= m) || (x + a <= m && max(y, b) <= n))
		OK;
	if ((y + b <= n && max(x, a) <= m) || (y + b <= m && max(x, a) <= n))
		OK;
	swap(a, b);
	if ((x + a <= n && max(y, b) <= m) || (x + a <= m && max(y, b) <= n))
		OK;
	if ((y + b <= n && max(x, a) <= m) || (y + b <= m && max(x, a) <= n))
		OK;
	WA;
}
