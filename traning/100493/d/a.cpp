
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = 350;
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
#define fn "problem"

int n;
pii v[maxn];
bool us[maxn];
ll ans = linf;

ll dist(pii a, pii b)
{
	return (a.F - b.F + 0ll) * (a.F - b.F) + (a.S - b.S + 0ll) * (a.S - b.S);
}

void go(int u)
{
	memset(us, 0, sizeof(us));
	ll cur = 0ll;
	us[u] = 1;
	for (int cnt = 1; cnt < n; cnt++)
	{
		//printf("%d -> ", u);
		int j = -1;
		for (int i = 1; i <= n; i++)
		{
			if (us[i])
				continue;
			if (j == -1 || dist(v[u], v[j]) > dist(v[u], v[i]))
				j = i;
		}
		cur += dist(v[u], v[j]);
		us[j] = 1;
		u = j;
	}
	//printf(I64 "\n", cur);
	ans = min(ans, cur);
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
		int x, y;
		scanf("%d%d", &x, &y);
		v[i] = mp(x, y);
	}
	//sort(v + 1, v + 1 + n);
	for (int i = 1; i <= n; i++)
		go(i);
	printf(I64, ans);
}
