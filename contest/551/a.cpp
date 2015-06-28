
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = 2020;
int const maxb = int(2e6 + 12);
int const inf = int(1e9 + 7);
ll const linf = ll(1e18 + 12);
double const eps = 1e-7;
double const pi = acos(-1);
#define mp make_pair
#define pb push_back
#define F first
#define S second
//#define fn ""

int n;
pii a[maxn];
int ans[maxn];

bool cmp(pii a, pii b)
{
	if (a.F != b.F)
		return (a.F > b.F);
	else
		return a.S < b.S;
}

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d", &n);
	a[0] = {0, 0};
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		a[i] = mp(x, i);
	}
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; i++)
	{
		if (a[i].F == a[i - 1].F)
			ans[a[i].S] = ans[a[i - 1].S];
		else
			ans[a[i].S] = i;
	}
	for (int i = 1; i <= n; i++)
		printf("%d ", ans[i]);
}

