
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef map<int, int> mii;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int const maxn = int(1e5 + 12);
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
#define rt(x)                                                                  \
  {                                                                            \
    puts(x);                                                                   \
    exit(0);                                                                   \
  }
//#define fn ""

template <typename T> bool umax(T &a, T b) { return a < b ? (a = b, 1) : 0; }

template <typename T> bool umin(T &a, T b) { return a > b ? (a = b, 1) : 0; }

int n, m, k;
bool us[60][60];
bool a[60][60];
char s[60][60];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

vector <pair<int, pii>> v;

#define ok(x, y) (1 <= (x) && (x) <= (y))

int dfs(int x, int y) {
	if (us[x][y])
		return 0;
	us[x][y] = 1;
	int ans = 1;
	for (int i = 0; i < 4; i++) {
		if (!ok(x + dx[i], n) || !ok(y + dy[i], m))
			continue;
		ans += dfs(x + dx[i], y + dy[i]);
	}
	return ans;
}

int main() {
#ifdef fn
  freopen(fn ".in", "r", stdin);
  freopen(fn ".out", "w", stdout);
#endif
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
		scanf("%s", s[i] + 1);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			a[i][j] = us[i][j] = s[i][j] == '*';
		}
	for (int i = 1; i <= n; i++)
		dfs(i, 1), dfs(i, m);
	for (int j = 1; j <= m; j++)
		dfs(1, j), dfs(n, j);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			if (a[i][j] || us[i][j])
				continue;
			int cnt = dfs(i, j);
			v.pb({cnt, {i, j}});
//			printf("%d : %d %d\n", cnt, i, j);
		}
	sort(all(v)); 
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			us[i][j] = s[i][j] == '*';
		}
	int ans = 0;
	for (int i = 0; i < int(v.size()) - k; i++) {
//		printf("%d- %d %d\n", v[i].F, v[i].S.F, v[i].S.S);
		ans += dfs(v[i].S.F, v[i].S.S);
	}
	printf("%d\n", ans);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			printf("%c", us[i][j] ? '*' : '.');
		}
		puts("");
	}
}
