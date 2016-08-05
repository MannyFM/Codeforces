
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

int x;

#define in(mask, x) (((1 << (x)) & (mask)) > 0)

int us[10];
int len1, len2;

bool check(int x, int y) {
	memset(us, 0, sizeof(us));
	for (int i = 0; i < len1; i++) {
		us[x % 7]++;
		x /= 7;
	}
	for (int i = 0; i < len2; i++) {
		us[y % 7]++;
		y /= 7;
	}
	for (int i = 0; i < 7; i++)
		if (us[i] > 1)
			return 0;
	return 1;
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	int n, m;
	scanf("%d%d", &n, &m);
	len1 = 1, len2 = 1;
	for (int x = 7; x < n; x *= 7)
		len1++;
	for (int y = 7; y < m; y *= 7)
		len2++;
	if (len1 + len2 > 7) {
		puts("0");
		return 0;
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) 
			ans += check(i, j);
	printf("%d", ans);
}

