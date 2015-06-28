
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define maxn int(1e5 + 12)
#define inf int(1e9 + 7)
#define linf ll(1e18 + 12)
#define eps 1e-7
#define mp make_pair
#define pb push_back
#define fn "a"

int n, x, a;
vector <int> v;

int main()
{
	#ifdef LOCAL
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &x);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a), v.pb(a);
	sort(begin(v), end(v));
	int mid = (int(v.size()) + 1) / 2;
	while (v[mid - 1] != x)
	{
		v.pb(x);
		sort(begin(v), end(v));
		mid = (int(v.size()) + 1) / 2;
	}
	printf("%d", int(v.size()) - n);
}