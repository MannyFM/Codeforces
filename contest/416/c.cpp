
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <ll, ll> pll;

#define maxn int(1e3 + 12)
#define maxb int(2e6 + 12)
#define inf int(1e9 + 7)
#define linf ll(1e18 + 12)
#define eps 1e-7
#define mp make_pair
#define pb push_back
#define fn "c"
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

struct pii
{
	int f, s;
	int i;
	pii() {};
	pii(int f, int s, int i) : f(f), s(s), i(i) {};
};

int n, c[maxn], p[maxn];
int k, r[maxn];
vector <pii> v;
vector <pair<int, int>> ans;
ll res;

bool cmp(pii a, pii b)
{
	if (a.f != b.f)
		return a.f > b.f;
	return a.s < b.s;
}

int main()
{
	#ifdef LOCAL
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", c + i, p + i);
		pii now = pii(p[i], c[i], i);
		v.pb(now);
	}
	multimap <int, int> R;
	scanf("%d", &k);
	sort(begin(v), end(v), cmp);
	for (int i = 1; i <= k; i++)
		scanf("%d", r + i), R.insert(mp(r[i], i));
	for (int i = 0; i < int(v.size()); i++)
		printf("%d %d\n", v[i].f, v[i].s);
	for (int i = 0; i < int(v.size()); i++)
	{
		auto it = R.lower_bound(v[i].s);
		if (it == end(R))
			continue;
		ans.pb(mp(v[i].i, it -> s));
		R.erase(it);
		res += v[i].f;
	}
	printf("%d %I64d\n", int(ans.size()), res);
	for (int i = 0; i < int(ans.size()); i++)
		printf("%d %d\n", ans[i].f, ans[i].s);
}