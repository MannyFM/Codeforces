
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = int(1e3 + 12);
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
#define fn "fenwick"

int T[maxn][maxn];
int N, M;

void updx(int x, int y, int tl, int tr, int dx, int dy)
{
	if (tl == tr)
	{
		T[x][y]++;
		return;
	}
	int tm = (tl + tr) >> 1;
	if (dx <= tm)
		updx(x + x, y, tl, tm, dx, dy);
	else
		updx(x + x + 1, y, tm + 1, tr, dx, dy);
	T[x][y] = T[x + x][y] + T[x + x + 1][y];
}

void updy(int y, int tl, int tr, int dx, int dy)
{
	if (tl == tr)
	{
		updx(1, y, 1, N, dx, dy);
		return;
	}
	int tm = (tl + tr) >> 1;
	if (dy <= tm)
		updy(y + y, tl, tm, dx, dy);
	else
		updy(y + y + 1, tm + 1, tr, dx, dy);
}

int getx(int x, int y, int tl, int tr, int xl, int xr, int yl, int yr)
{
	if (xl > xr || tr < xl || xr < tl)
		return 0;
	if (xl <= tl && tr <= xr)
		return T[x][y];
	int tm = (tl + tr) >> 1;
	return getx(x + x, y, tl, tm, xl, xr, yl, yr)
		+ getx(x + x + 1, y, tm + 1, tr, xl, xr, yl, yr);
}

int gety(int y, int tl, int tr, int xl, int xr, int yl, int yr)
{
	if (yl > yr || tr < yl || yr < tl)
		return 0;
	if (yl <= tl && tr <= yr)
		return getx(1, y, 1, N, xl, xr, yl, yr);
	int tm = (tl + tr) >> 1;
	return gety(y + y, tl, tm, xl, xr, yl, yr)
		+ gety(y + y + 1, tm + 1, tr, xl, xr, yl, yr);
}

void upd(int x, int y)
{
	updy(1, 1, N, x, y);
}

int get(int xl, int xr, int yl, int yr)
{
	return gety(1, 1, N, xl, xr, yl, yr);
}

char s[5];

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; i++)
	{
		scanf("%s", s);
		if (s[0] == 'A')
		{
			int X, Y;
			scanf("%d%d", &X, &Y);
			upd(X, Y);
		}
		else
		{
			int xl, xr, yl, yr;
			scanf("%d%d%d%d", &xl, &yl, &xr, &yr);
			printf("%d\n", get(xl, xr, yl, yr));
		}
	}
}
