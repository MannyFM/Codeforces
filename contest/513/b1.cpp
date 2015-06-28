
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
#define fn "b"
#define f first
#define s second

template<typename T>
T min(T a, T b, T c)
{
	return min(a, min(b, c));
}

template<typename T>
T max(T a, T b, T c)
{
	return max(a, max(b, c));
}

vector <int> v;
multimap <ll, vector <int>> s;
int n, m;

ll get()
{
	ll ans = 0ll;
	for (int l = 0; l < n; l++)
		for (int r = l; r < n; r++)
		{
			ll now = v[l];
			for (int k = l; k <= r; k++)
				now = min(now, ll(v[k]));
			ans += now;
		}
	return ans;
}

int main()
{
	#ifdef LOCAL
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		v.pb(i);
	ll maxx = -inf;
	do
	{
		ll ans = get();
		maxx = max(maxx, ans);
		s.insert(mp(ans, v));
	} while(next_permutation(v.begin(), v.end()));
	/*
	for (auto i = s.lower_bound(maxx); i != end(s); i++)
	{
		vector <int> t = i -> s;
		for (int i = 0; i < n; i++)
			printf("%d ", t[i]);
		puts("");
	}
	*/
	auto it = s.lower_bound(maxx);
	int t = 1;
	for (; it != end(s) && t < m; it++, t++);
	v = it -> s;
	for (int i = 0; i < n; i++)
		printf("%d ", v[i]);
}