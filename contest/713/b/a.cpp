
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

int n, m;
int x1, x2, y1, y2;
bool isX;
map <pair <pii, pii>, int> MAP;
int cnt;

int Write(int x1, int y1, int x2, int y2) {
	pair <pii, pii> pr = {{x1, y1}, {x2, y2}};
	if (MAP.count(pr) > 0)
		return MAP[pr];
	cnt++;
	assert(cnt <= 200);
	printf("? %d %d %d %d\n", x1, y1, x2, y2);
	fflush(stdout);
	int res;
	scanf("%d", &res);
	MAP[pr] = res;
	return res;
}

int GetRes(int l, int r) {
	if (isX)
		return Write(l, 1, r, n);
	else
		return Write(1, l, n, r);
}

int xR1, xL1, yR1, yL1;
int xR2, xL2, yR2, yL2;
//[xL1; xR2] [xL2; xR2]

int searchR(int L, int R, int x) {
	int l = L - 1, r = R + 1;
	while(r - l > 1) {
		int m = (l + r) >> 1;
		if (GetRes(L, m) < x)
			l = m;
		else
			r = m;
	}
//	printf("[%d %d] %d = {%d %d}\n", L, R, x, l, r);
	return r;
}

int searchL(int L, int R, int x) {
	int l = L - 1, r = R + 1;
	while (r - l > 1) {
		int m = (l + r) >> 1;
		if (GetRes(m, R) < x)
			r = m;
		else
			l = m;
	}
//	printf("[%d %d] %d = {%d %d}\n", L, R, x, l, r);
	return l;
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d", &n);
	pair <pii, pii> pr = {{1, 1}, {n, n}};
	MAP[pr] = 2;
	isX = 1;
	xL1 = searchL(1, n, 2);
	xL2 = searchL(1, n, 1);
	xR1 = searchR(1, n, 1);
	xR2 = searchR(1, n, 2);

//	printf("[%d %d] [%d %d]\n", xL1, xR1, xL2, xR2);
	
	isX = 0;
	yL1 = searchL(1, n, 2);
	yL2 = searchL(1, n, 1);
	yR1 = searchR(1, n, 1);
	yR2 = searchR(1, n, 2);
	
//	printf("[%d %d] [%d %d]\n", yL1, yR1, yL2, yR2);
	assert(xL1 <= xR1 && yL1 <= yR1);
	assert(xL2 <= xR2 && yL2 <= yR2);
	printf("! %d %d %d %d", xL1, yL1, xR1, yR1);
	printf(" %d %d %d %d\n", xL2, yL2, xR2, yR2);
	fflush(stdout);
	
}

