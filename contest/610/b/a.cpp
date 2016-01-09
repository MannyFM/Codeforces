
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

int n, a[maxn], j = 1;
ll ans;

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d", &n);
	int mn = inf;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", a + i);
		if (a[i] < a[j])
		{
			j = i;
		}
	}
	mn = a[j];
	for (int i = 1; i <= n; i++)
		a[i + n] = a[i];
	int mx = 0, l = -1;
	for (int i = 1; i <= 2 * n; i++)
	{
		if (a[i] > mn)
		{
			if (l == -1)
				l = i;
		}
		else
		{
			if (l != -1)
			{
				mx = max(i - l, mx);
				l = -1;
			}
		}
	}
	printf(I64, mx + n * 1ll * mn);
}

