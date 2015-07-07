
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
#ifdef WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif
#define mp make_pair
#define pb push_back
#define F first
#define S second
//#define fn ""

int n, l, r, x;
int c[16], ans;
vector <int> v;

void rec(int i)
{
	if (i == n)
	{
		int sum = 0, mn = inf, mx = -inf;
		for (int i = 0; i < int(v.size()); i++)
		{
			sum += v[i];
			mx = max(mx, v[i]);
			mn = min(mn, v[i]);
		}
		ans += l <= sum && sum <= r && mx - mn >= x && int(v.size()) > 1;
		return;
	}
	rec(i + 1);
	v.push_back(c[i]);
	rec(i + 1);
	v.pop_back();
}

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d%d%d", &n, &l, &r, &x);
	for (int i = 0; i < n; i++)
		scanf("%d", c + i);
	rec(0);
	printf("%d", ans);
}
