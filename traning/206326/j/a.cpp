
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

struct pt
{
	int x, y;
	pt() {x = y = 0;}
	pt(int)
	{
		scanf("%d%d", &x, &y);
	}
	pt(int x, int y) : x(x), y(y) {}
	pt operator + (const pt & p)
	{
		return pt(x + p.x, y + p.y);
	}
	pt operator - (const pt & p)
	{
		return pt(x - p.x, y - p.y);
	}
	bool operator == (const pt & p)
	{
		return x == p.x && y == p.y;
	}
};

pt p;
pt a[maxn];
char s[maxn];
int n;
string dir = "UDLR";
pt d[] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

inline bool same(ll x, ll y)
{
	if (x == 0)
		return y == 0;
	if (x > 0)
		return y > 0;
	return y < 0;
}

bool check(pt cur)
{
	cur = p - cur;
//	printf("(%d %d) ", cur.x, cur.y);
//	printf("(%d %d)\n", a[n].x, a[n].y);
//	printf("%d %d\n", same(cur.x, a[n].x), same(cur.y, a[n].y));
	if (!same(cur.x, a[n].x) || !same(cur.y, a[n].y))
		return 0;
	if (!a[n].x)
	{
		return same(cur.y, a[n].y) && cur.y % a[n].y == 0;
//		return a[n].y % cur.y == 0;
	}
	if (!a[n].y)
	{
		return same(cur.y, a[n].y) && cur.x % a[n].x == 0;
//		return a[n].x % cur.x == 0; 
	}
	ll k = cur.x / a[n].x;
	return a[n].x * k == cur.x && a[n].y * k == cur.y;
}

#define rt(x) {puts(x); exit(0);}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	p = pt(1);
	if (!p.x && !p.y)
		rt("Yes");
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for (int i = 1; i <= n; i++)
	{
		a[i] = a[i - 1] + d[dir.find(s[i])];
		if (a[i] == p)
			rt("Yes");
//		printf("[%d %d]\n", a[i].x, a[i].y);
	}
	if (!a[n].x && !a[n].y)
		rt("No");
	for (int i = 1; i <= n; i++)
		if (check(a[i]))
			rt("Yes");
	rt("No");
}

