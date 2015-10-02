
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

int n, a[maxn], cnt[12];
int k;
ll ans = 0ll;

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", a + i);
	//sort(a, a + n);
	for (int i = 0; i < n; i++)
		ans += a[i] / 10;
	for (int i = 0; i < n; i++)
	{
		int cur = min((100 - a[i]) / 10, k / 10);
		//printf("%d %d %d -> ", a[i], k, cnt);
		a[i] += cnt * 10;
		k -= cur * 10;
		ans += cur;
		cnt[a[i] % 10]++;
		//printf("%d %d\n", a[i], k);
	}
	for (int i = 9; i; i--)
	{
		int cur = min(k / (10 - i), cnt[i]);
		ans += cur;
		k -= cur * (10 - i);
	}
	printf(I64, ans);
}
