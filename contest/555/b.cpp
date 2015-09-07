
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

int n, m;
ll l[maxn], r[maxn];
ll a[maxn];
multimap <ll, int> bridges;
vector <int> ans;

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf(I64 I64, l + i, r + i);
	for (int i = 1; i <= m; i++)
		scanf(I64, a + i),
		bridges.insert(mp(a[i], i));
	for (int i = 1; i < n; i++)
	{
		auto it = bridges.lower_bound(l[i + 1] - r[i]);
		if (it == bridges.end() || it -> F > r[i + 1] - l[i])
		{
			for (int i = 0; i < int(ans.size()); i++)
				printf("%d ", ans[i]);
			printf("%d\n", it == bridges.end() ? -1 : it -> F);
			puts("No");
			return 0;
		}
		ans.pb(it -> S);
		bridges.erase(it);
	}
	puts("Yes");
	for (int i = 0; i < int(ans.size()); i++)
		printf("%d ", ans[i]);
}
