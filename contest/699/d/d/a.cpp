
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = int(2e5 + 12);
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

template <typename T>
bool umax(T & a, T b)
{
	return a < b ? (a = b, 1) : 0;
}

template <typename T>
bool umin(T & a, T b)
{
	return a > b ? (a = b, 1) : 0;
}

int us[maxn];
int n, m, pr[maxn];
int ans[maxn];
set <int> cyc;

void dfs(int v) {
	if (us[v] == 1) {
		cyc.insert(v);
		//printf("%d ", v);
	}
	if (us[v])
		return;
	us[v] = 1;
	dfs(pr[v]);
	us[v] = 2;
}

void CLR(int st) {
	int v = pr[st];
	while (v != st) {
		cyc.erase(v);
		v = pr[v];
	}
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", pr + i);
	for (int i = 1; i <= n; i++)
		if (!us[i]) {
			dfs(i);
			//puts("");
		}
	int st = -1;
	for (int x : cyc) {
		CLR(x);
		if (pr[x] == x)
			st = x;
	}
	for (int i = 1; i <= n; i++)
		ans[i] = pr[i];
	int cnt = 0;
	if (st == -1) {
		st = *cyc.begin();
		ans[st] = st;
		cnt++;
	}
	for (int x : cyc) {
		if (x == st) continue;
		ans[x] = st;
		cnt++;
	}
	printf("%d\n", cnt);
	for (int i = 1; i <= n; i++)
		printf("%d ", ans[i]);
}

