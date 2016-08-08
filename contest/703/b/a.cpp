
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

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

int n, k;
bool cap[maxn];
ll c[maxn], all, ans;

ll cost(int i, int j) {
	return c[i] * c[j];
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf(I64, c + i);
		all += c[i];
	}
	for (int i = 1; i <= k; i++) {
		int x;
		scanf("%d", &x);
		cap[x] = 1;
	}
	c[0] = c[n];
	cap[0] = cap[n];
	c[n + 1] = c[1];
	cap[n + 1] = cap[1];
//	for (int i = 0; i < n; i++) {
//		if (capital[i]) {
//			all -= c[i];
//			ans += all * c[i];
//		} else 
//			ans += cost(i, i + 1);
//	}
	for (int i = 1; i <= n; i++) {
		if (cap[i]) {
			all -= c[i];
			ans += all * c[i];
		}
		else {
//			if (!cap[i - 1])
//				ans += cost(i - 1, i);
			if (!cap[i + 1])
				ans += cost(i, i + 1);
		}
	}
	printf(I64, ans);
}

