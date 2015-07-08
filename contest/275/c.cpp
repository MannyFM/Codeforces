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
//#define fn ""

int n;
ll a[maxn];
ll k, ans;
set <ll> s;

int chain(ll x)
{
	if (!s.count(x))
		return 0;
	//printf(I64 " ", x);
	int ans = chain(x * k);
	s.erase(x * k);
	return ans + 1;
}

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d" I64, &n, &k);
	for (int i = 1; i <= n; i++)
		scanf(I64, a + i),
		s.insert(a[i]);
	if (k == 1)
	{
		printf("%d", s.size());
		return 0;
	}
	sort(a + 1, a + 1 + n);	
	for (int i = 1; i <= n; i++)
		ans += (chain(a[i]) + 1) / 2;
	printf(I64, ans);
}
