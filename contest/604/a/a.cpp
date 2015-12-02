
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

int m[6], w[6], x[] = {0, 500, 1000, 1500, 2000, 2500};
int ac, de;
double ans;

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	for (int i = 1; i <= 5; i++)
		scanf("%d", m + i);
	for (int i = 1; i <= 5; i++)
		scanf("%d", w + i);
	scanf("%d%d", &ac, &de);
	for (int i = 1; i <= 5; i++)
		ans += max(0.3 * x[i], (250 - m[i]) * x[i] / 250.0 - 50.0 * w[i]);
	ans += 100.0 * ac - 50 * de;
	printf("%d", int(ans + eps));
}
