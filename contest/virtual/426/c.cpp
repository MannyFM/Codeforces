
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
#define all(v) begin(v), end(v)
#define mp make_pair
#define pb push_back
#define fn "c"
#define f first
#define s second
#define sz(v) int(v.size())

template<typename T>
T min(T a, T b, T c)
{
	return min(a, min(b, c));
}

bool cmp(int a, int b)
{
	return a > b;
}

int n, K, a[300];
ll sum[300];

ll calc(int l, int r)
{
	vector <int> v[3];
	for (int i = 1; i < l; i++)
		v[0].pb(a[i]);
	for (int i = l; i <= r; i++)
		v[1].pb(a[i]);
	for (int i = r + 1; i <= n; i++)
		v[2].pb(a[i]);
	sort(all(v[0]), cmp);
	sort(all(v[1]));
	sort(all(v[2]), cmp);
	/*
	for (int i = 0; i < int(v[0].size()); i++)
		printf("%d ", v[0][i]);
	puts("");
	for (int i = 0; i < int(v[1].size()); i++)
		printf("%d ", v[1][i]);
	puts("");
	for (int i = 0; i < int(v[2].size()); i++)
		printf("%d ", v[2][i]);
	puts("");
	*/
	int i = 0, j = 0, cnt = 0;
	for (int k = 0; k < int(v[1].size()); k++)
	{
		int mx = -inf, fl = 0;
		if ((i >= sz(v[0]) && j >= sz(v[2])) || cnt >= K)
			break;
		if (i >= sz(v[0]) || j >= sz(v[2]))
		{
			if (i < sz(v[0]))
				mx = v[0][i], fl = 1;
			else
				mx = v[2][j], fl = 2;
		}
		else
		{
			if (v[0][i] > v[2][j])
				mx = v[0][i], fl = 1;
			else
				mx = v[2][j], fl = 2;
		}
		if (mx <= v[1][k])
			break;
		v[1][k] = mx;
		if (fl == 1)
			i++;
		else
			j++;
		cnt++;
	}
	/*
	for (int i = 0; i < int(v[1].size()); i++)
		printf("%d ", v[1][i]);
	puts("");
	*/
	ll now = 0ll;
	for (int i = 0; i < sz(v[1]); i++)
		now += v[1][i];
	return now;
}

int main()
{
	#ifdef LOCAL
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &K);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i), sum[i] = sum[i - 1] + a[i];	
	ll ans = a[1] + 0ll;	
	for (int l = 1; l <= n; l++)
		for (int r = l; r <= n; r++)
		{
			//printf("%d %d:\n", l, r);
			ll now = calc(l, r);
			ans = max(ans, now);
			//printf("!%I64d\n", now);
		}
	printf("%I64d", ans);
}
