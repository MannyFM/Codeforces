
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

int n;
ll pw[20];
map <ll, int> cnt;

ll f() {
	ll x;
	scanf(I64, &x);
//	printf("f(" I64 ")=", x);
	ll ans = 0;
	for (int i = 0; i < 18; i++) {
		ans += pw[i] * (x % 2);
		x /= 10;
	}
//	printf(I64 "\n", ans);
	return ans;
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	pw[0] = 1;
	for (int i = 1; i < 20; i++)
		pw[i] = pw[i - 1] * 10ll;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		char ch;
		scanf(" %c", &ch);
		if (ch == '+') {
			cnt[f()]++;
		}
		if (ch == '-') {
			cnt[f()]--;
		}
		if (ch == '?') {
			ll x;
			scanf(I64, &x);
			printf("%d\n", cnt[x]);
		}
	}
}

