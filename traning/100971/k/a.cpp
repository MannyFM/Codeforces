
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

int n;
char s[maxn];
bool eq[maxn], cen[maxn];
int cnt;

void pre() {
	memset(eq, 0, sizeof(eq));
	memset(cen, 0, sizeof(cen));
	eq[0] = 1;
	for (int i = 1; i <= n; i++) {
		if (s[i] == s[n - i + 1])
			eq[i] = 1;
		else
			break;
//		printf("%d ", i);
	}
//	puts("");
	cnt = n / 2;
	cen[0] = 1;
	if (n & 1) {
		for (int i = 1; cnt - i + 1 > 0 && cnt + i <= n; i++) {
			if (s[cnt - i + 1] == s[cnt + i])
				cen[i] = 1;
			else
				break;
//			printf("%d ", i);
		}
	} else {
		for (int i = 1; cnt - i > 0 && cnt + i <= n; i++) {
			if (s[cnt - i] == s[cnt + i])
				cen[i] = 1;
			else
				break;
//			printf("%d ", i);
		}
	}
//	puts("");
}
bool check() {
	int N = n - 1;
	for (int i = 1; i <= N; i++)
		if (s[i] != s[N - i + 1])
			return false;
	return true;
}
int solve() {
	if (check())
		return n;
	pre();
	int ln = n / 2;
	if (n & 1) {
		for (int i = cnt + 1; i < n; i++) {
			int dist = i - cnt - 1;
//			printf("i:%d dist:%d e:%d c:%d\n", i, dist, eq[ln - dist], cen[dist]);
			if (eq[ln - dist] && cen[dist])
				return i;
		}
	} else {
		ln--;
		for (int i = cnt + 1; i < n; i++) {
			int dist = i - cnt - 1;
//			printf("i:%d dist:%d e:%d c:%d\n", i, dist, eq[ln - dist], cen[dist]);
			if (eq[ln - dist] && cen[dist])
				return i;
		}
	}
	return -1;
}
int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%s", s + 1);
	n = strlen(s + 1);
	int ans = solve();
	if (ans != -1) {
		printf("YES\n%d", ans);
		return 0;
	}
	reverse(s + 1, s + 1 + n);
	ans = solve();
	if (ans == -1)
		rt("NO");
	ans = n - ans + 1;
	printf("YES\n%d", ans);
}

