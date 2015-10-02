
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

int n, a[maxn];
int k;
ll ans = 0ll;

bool cmp(int a, int b)
{
	return (a % 10) > (b % 10);
}

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", a + i);
	sort(a, a + n, cmp);
	for (int i = 0; i < n; i++)
	{
		int add = 10 - (a[i] % 10);
		if (add <= k)
		{
			a[i] += add;
			k -= add;
		}
		ans += a[i] / 10;
	}
	ans += k / 10;
	printf(I64, min(ans, n * 10ll));
}
