
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
//#define fn

ll a, b, ans;
int n, p[10];

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf(I64 I64 "%d", &a, &b, &n);
	for (int i = 0; i < n; i++)
		scanf("%d", p + i);
	for (int mask = 1; mask < (1 << n); mask++)
	{
		ll cur = 1;
		for (int i = 0; i < n; i++)
			if (mask & (1 << i))
				cur *= p[i];
		if (__builtin_popcount(mask) & 1)
		{
			//printf("%d " I64 "+" I64 "\n", mask, cur, b / cur - (a - 1) / cur);
			ans += b / cur - (a - 1) / cur;
		}
		else
		{
			//printf("%d " I64 "+" I64 "\n", mask, cur, b / cur - (a - 1) / cur);
			ans -= b / cur - (a - 1) / cur;
		}
	}
	//printf(I64 "\n", ans);
	printf(I64, b - a + 1 - ans);
}
