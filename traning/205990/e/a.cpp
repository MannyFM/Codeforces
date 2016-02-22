
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

int n, k, a[maxn];
map <int, int> cnt;
set <int> se;

void solve()
{
//	printf("%d:", (int)se.size());
//	for (int x : se)
//		printf("%d ", x);
//	puts("");
	if (se.empty())
		puts("Nothing");
	else
	{
		auto it = se.end();
		it--;
		printf("%d\n", *it);
	}
}

void check(int x)
{
	if (cnt[x] == 1)
		se.insert(x);
	else
		se.erase(x);
}
int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	for (int i = 1; i <= k; i++)
	{
		cnt[a[i]]++;
		check(a[i]);
	}
	solve();
	for (int i = k + 1; i <= n; i++)
	{
		cnt[a[i - k]]--;
		cnt[a[i]]++;
		check(a[i - k]);
		check(a[i]);
		solve();
	}
}

