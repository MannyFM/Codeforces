
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = int(2e5 + 12);
int const maxlen = int(2e6 + 12);
int const inf = int(1e9 + 7);
ll const linf = ll(1e18 + 12);
ld const eps = 1e-7;
ld const pi = 3.1415926535897932384626433832795l;

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
#define x1 MyLittleX1
#define y1 MyLittleY1
#define x2 MyLittleX2
#define y2 MyLittleY2
#define rt(x) {puts(x); exit(0);}
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

int n, go[maxn];
int us[maxn];
ll pw[maxn];
ll ans;
vector <int> cycs;

void cycle(int v) {
	if (us[v] == 3)
		return;
	cycs.back()++;
	us[v] = 3;
	cycle(go[v]);
}

void dfs(int v) {
	us[v] = 1;
	if (us[go[v]] == 0)
		dfs(go[v]);
	else if (us[go[v]] == 1) {
		cycs.pb(0);
		cycle(v);
	}
	us[v] = 2;
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d", &n);
	pw[0] = 1;
	for (int i = 1; i <= n; i++)
		scanf("%d", go + i), pw[i] = (pw[i - 1] * 2ll) % inf;
	for (int i = 1; i <= n; i++)
		if (!us[i])
			dfs(i);
	ans = 1;
	int noncyc = n;
	for (int sz : cycs) {
		noncyc -= sz;
//		printf("%d++ = " I64 "\n", sz, ans);
		ans = (ans * (pw[sz] - 2 + inf)) % inf;
	}
	ans = (ans * pw[noncyc]) % inf;
	if (ans < 0)
		ans += inf;
	printf(I64, ans);
}

