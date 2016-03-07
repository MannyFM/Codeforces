
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

int n, a[maxn], L, R, sa, sk, k;

void fill(int l, int r, int sum)
{
	if (l > r)
		return;
	int rm = sum % (r - l + 1), dm = sum / (r - l + 1);
	for (int i = l; i <= r; i++)
		a[i] = dm + (rm > 0), rm--;
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d%d%d%d%d%d", &n, &k, &L, &R, &sa, &sk);
	fill(1, k, sk);
	fill(k + 1, n, sa - sk);
	for (int i = 1; i <= n; i++)
		printf("%d ", a[i]);
}

