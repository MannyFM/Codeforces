
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = 2500;
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
#define next MyLittleNext
//#define end MyLittleEnd
#define all(x) x.begin(), x.end()
//#define fn ""
#define cmb(i) mp(abs(pos[s[i]] - i), mp(pos[s[i]], i))

set <pair <int, pii>> se;
int n, s[maxn], t[maxn], pos[maxn];

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", s + i);
	for (int i = 1; i <= n; i++)
		scanf("%d", t + i), pos[t[i]] = i;
	for (int i = 1; i <= n; i++)
	{
		if (pos[s[i]] != i)
		{
			se.insert(cmb(i));
			//se.insert(mp(abs(pos[s[i]] - i), mp(pos[s[i]], i)));
		}
	}
	ll ans = 0ll;
	vector <pii> path;
	while (!se.empty())
	{
		int pts = se.begin() -> F;
		int to = se.begin() -> S.F;
		int from = se.begin() -> S.S;
		se.erase(se.begin());
		if (!pts)
			continue;
		se.erase(cmb(to));
		ans += pts;
		swap(s[from], s[to]);
		se.insert(cmb(to));
		path.pb(mp(from, to));
	}
	printf(I64 "\n%d\n", ans, path.size());
	for (pii x: path)
		printf("%d %d\n", x.F, x.S);
}
