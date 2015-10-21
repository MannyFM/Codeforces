
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
#define fn "dominoes"

int n;
pii a[maxn];
map <int, int> d;

bool cmp(pii a, pii b)
{
	return a.S == b.S ? a.F < b.F : a.S < b.S;
}

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &a[i].F, &a[i].S);
	sort(a + 1, a + 1 + n);
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		auto it = d.find(a[i].F);
		int x = it == d.end() ? 0 : (it -> S);
		d[a[i].S] = max(d[a[i].S], x + 1);
		ans = max(ans, d[a[i].S]);
	}
	printf("%d", ans);
}
