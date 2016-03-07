
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

int n, rm = 1;

int ln(int x)
{
	int ans = 0;
	while (x > 0)
		x /= 10, ans++;
	if (!ans)
		ans++;
	return ans;
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d", &n);
	if (n < 3)
		rt("-1");
	if (n == 3)
		rt("210");
	for (int i = 2; i < n; i++)
		rm = (rm * 10) % 7;
	rm = 7 - rm;
//	printf("%d\n", rm);
	for (int j = 2; ; j += 3)
		if (j % 7 == rm)
		{
//			printf("%d\n", j);
			int cnt = n - 2 - ln(j);
			printf("1");
			for (int i = 0; i < cnt; i++)
				printf("0");
			printf("%d0", j);
			break;
		}
}

