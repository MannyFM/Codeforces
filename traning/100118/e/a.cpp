
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
#define fn "half"

set <int> v;
int dp[2550][2550];
int n, k;

void rec(int a, int f)
{
	//cerr << a << " " << f << '\n';
	if (dp[a][f])
		return;
	if (!f)
	{
		v.insert(a);
		dp[a][f] = 1;
		return;
	}
	if (a % 2 == 0)
		rec(a / 2, f - 1);
	if (a)
		rec(a - 1, f - 1);
	dp[a][f] = 1;
}

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &k);
	rec(2 * n, k);
	printf("%d\n", v.size());
	for (int x : v)
		printf("%d.%d ", x / 2, (x & 1) * 5);
}