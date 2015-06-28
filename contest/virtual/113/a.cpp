
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

int n, p[maxn], t[maxn], k;
map <pii, int> cnt;
vector <pii> v;

int main()
{
	#ifdef LOCAL
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", p + i, t + i);
		p[i] *= -1;
		cnt[mp(p[i], t[i])]++;
		v.pb(mp(p[i], t[i]));
	}
	sort(begin(v), end(v));
	printf("%d", cnt[v[k - 1]]);
}