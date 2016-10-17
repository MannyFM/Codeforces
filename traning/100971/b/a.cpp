
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

int n, a[maxn];
int cnt, buf;
set <int> se;

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		if (a[i] == i)
			se.insert(i);
		else
			buf = i;
	}
	cnt = se.size();
	printf("%d\n", (cnt + 1) / 2);
	while (se.size() > 1) {
		int x = *se.begin(); se.erase(se.begin());
		int y = *se.begin(); se.erase(se.begin());
		printf("%d %d\n", x, y);
		buf = x;
	}
	if (se.size() > 0) {
		int x = *se.begin(); se.erase(se.begin());
		printf("%d %d\n", x, buf);
	}
}

