
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = int(5e5 + 12);
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

int n, a[maxn];
ll l[maxn], r[maxn];
map <ll, ll> cnt;
ll ans;

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	for (int i = 1; i <= n; i++)
		l[i] = l[i - 1] + a[i];
	for (int i = n; i > 0; i--)
		r[i] = r[i + 1] + a[i];
	for (int i = 1; i < n; i++)
	{
		if ((l[i] & 1) || (l[i] != r[i + 1] * 2))
		{
			cnt[l[i]]++;
			continue;
		}
//		printf("(%d " I64 ")", i, cnt[l[i] / 2]);
		ans += cnt[l[i] / 2];
		cnt[l[i]]++;
	}
	printf(I64, ans);
}

