
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
#define mp make_pair
#define pb push_back
//#define fn "a"
#define F first
#define S second

int v1, v2;
int t, d;
int r[120], l[120], ans;

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d%d%d", &v1, &v2, &t, &d);
	r[1] = v1;
	l[t] = v2;
	ans = l[t];
	for (int i = 2; i <= t; i++)
		r[i] = r[i - 1] + d;
	for (int i = t - 1; i > 0; i--)
	{
		l[i] = min(l[i + 1] + d, r[i]);
		ans += l[i];
	}
	printf("%d ", ans);
}
