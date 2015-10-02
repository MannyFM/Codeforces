
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = 2 * 450;
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

int n;
int us[maxn];
vector <pair<int, pii>> v;

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 1; i <= 2 * n; i++)
		for (int j = 1; j < i; j++)
		{
			int x;
			scanf("%d", &x);
			v.pb(mp(x, mp(j, i)));
		}
	sort(all(v), greater <pair<int, pii>>());

	for (int i = 0; i < int(v.size()); i++)
	{
		if (us[v[i].S.F] || us[v[i].S.S])
			continue;
		us[v[i].S.F] = v[i].S.S;
		us[v[i].S.S] = v[i].S.F;
	}
	for (int i = 1; i <= 2 * n; i++)
		printf("%d ", us[i]);
}
