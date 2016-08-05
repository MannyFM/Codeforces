
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

int x[2];
int cnt[2][7];

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d%d", x, x + 1);
	for (int i = 0; i < 2; i++) {
		cnt[i][0] = x[i] / 5;
		for (int j = 1; j < 5; j++)
			cnt[i][j] = cnt[i][0] + (j <= x[i] % 5);
	}
//	for (int i = 0; i < 2; i++) {
//		for (int j = 0; j < 5; j++)
//			printf("%d ", cnt[i][j]);
//		puts("");
//	}
	ll ans = 0;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			if ((i + j) % 5 == 0) {
				ans += cnt[0][i] * 1ll * cnt[1][j];
//				printf(I64 " ", cnt[0][i] * 1ll * cnt[1][j]);
			}
	printf(I64, ans);
}

