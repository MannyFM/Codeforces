
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define maxn int(2e6 + 12)
#define maxb int(2e6 + 12)
#define inf int(1e9 + 7)
#define linf ll(1e18 + 12)
#define eps 1e-7
#define mp make_pair
#define pb push_back
#define fn "c"
#define F first
#define S second

map <ll, ll> se;
int n, t;
ll p[maxn], k[maxn], c[maxn];
ll pts, cnt;
int uk = 1;

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%I64d%I64d", k + i, c + i);
		se[c[i]] += k[i];
	}
	scanf("%d", &t);
	for (int i = 1; i <= t; i++)
		scanf("%I64d", p + i);
	p[t + 1] = linf;
	while (!se.empty())
	{
		pll v = *se.begin();
		se.erase(se.begin());
		ll kill = min(v.S, p[uk] - cnt);
		//printf("%I64d %I64d %I64d u%d ", v.F, v.S, p[uk], uk);
		cnt += kill;
		pts += kill * v.F * uk;
		v.S -= kill;
		//printf("p%I64d\n", pts);
		if (uk <= t && cnt >= p[uk])
			uk++;
		if (v.S)
			se.insert(v);
	}
	printf("%I64d", pts);
}
