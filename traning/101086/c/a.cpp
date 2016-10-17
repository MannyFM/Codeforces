
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = int(5e5 + 12);
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
#define end MyLittleEnd
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

int sz[maxn], end[maxn], last;
int next[26][maxn];
int cnt[maxn], cur;

void add(const string & s, int id) {
	int n = s.length();
	int v = 0;
	for (int i = 0; i < n; i++) {
		int x = s[i] - 'a';
		int & to = next[x][v];
		if (!to)
			to = ++last;
		v = to;
	}
	end[v] = id;
}

void dfs1(int v) {
	for (int x = 0; x < 26; x++) {
		int & to = next[x][v];
		if (to) {
			dfs1(to);
			sz[v] += sz[to];
		}
	}
	if (end[v]) {
		cnt[end[v]] = ++cur;
		sz[v]++;
	}
}

int getans(const string & s, int id) {
	int v = 0;
	int n = s.length();
	int ans = inf;
	int order = cnt[id];
//	printf("%d\n", order);
//	puts(s.c_str());
	for (int i = 0; i < n; i++) {
		int x = s[i] - 'a';
		int & to = next[x][v];
//		printf("v:%d %c o:%d  ", v, s[i], order);
		if (umin(ans, i + order)) {
//			printf("%d ", ans);
		}
		if (umin(ans, i + sz[v] - order + 2)) {
//			printf("%d ", ans);
		}
		for (int j = 0; j < x; j++) {
				if (next[j][v])
					order -= sz[next[j][v]];
		}
//		puts("");
		v = to;
	}
	return ans;
}


void solve() {
	vector <string> all;
	int n;
	char s[maxn];
	memset(next, 0, sizeof(next));
	memset(cnt, 0, sizeof(cnt));
	memset(end, 0, sizeof(end));
	memset(sz, 0, sizeof(sz));
	last = cur = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%s", s + 1);
		all.pb(string(s + 1));
		add(all.back(), i);
	}
	dfs1(0);
	for (int i = 1; i <= n; i++) {
		printf("%d ", getans(all[i - 1], i));
	}
	puts("");
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	int T;
	scanf("%d", &T);
	while (T--) {
		solve();
	}
}

