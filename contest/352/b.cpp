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

int n, a[maxn];
map <int, vector <int> > pos;
vector <pii> ans;

void check(int x)
{
	vector <int> v = pos[x];
	if (int(v.size()) == 1)
	{
		ans.pb(mp(x, 0));
		return;
	}
	int dx = v[1] - v[0];
	for (int i = 2; i < int(v.size()); i++)
		if (v[i] - v[i - 1] != dx)
			return;
	ans.pb(mp(x, dx));
}

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		pos[a[i]].pb(i);
	}
	for (auto i : pos)
		check(i.F);
	/*
	for (auto i : pos)
	{
		printf("%d %d: ", i.F, i.S.size());
		for (int j = 0; j < int(i.S.size()); j++)
			printf("%d ", i.S[j]);
		puts("");
	}
	puts("");
	*/
	printf("%d\n", ans.size());
	for (auto i : ans)
		printf("%d %d\n", i.F, i.S);
}
