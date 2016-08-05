
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = int(1e5 + 12);
int const maxb = int(1e6 + 12);
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
//#define all(x) x.begin(), x.end()
#define ex(x) {puts(x); exit(0);}
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

int n, k;
int c[maxb];
int lp[maxb];
vector <int> pr;
map<int, int> K, all;

map<int, int> f(int x) {
	map <int, int> ans;
	while (x > 1) {
		ans[lp[x]]++;
		x /= lp[x];
	}
	return ans;
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", c + i);
	for (int i = 2; i < maxb; i++) {
		if (!lp[i]) {
			lp[i] = i;
			pr.pb(i);
		}
		for (int j = 0; j < (int)pr.size() && i * 1ll * pr[j] < maxb && pr[j] <= lp[i]; j++)
			lp[i * pr[j]] = pr[j];
	}
	for (int i = 1; i <= n; i++) {
		auto tmp = f(c[i]);
		for (auto x : tmp)
			umax(all[x.F], x.S);
	}
	K = f(k);
	for (auto x : K) {
		if (all[x.F] < x.S)
			ex("NO");
	}
	puts("YES");
}

