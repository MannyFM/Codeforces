
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = 55;
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
#define mt make_tuple
#define pb push_back
#define F first
#define S second
#define next MyLittleNext
//#define end MyLittleEnd
#define all(x) x.begin(), x.end()
#define fn ""

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

int n, m, A, B, C;
int a[maxn][maxn], x[maxn], y[maxn];
int X[maxn], Y[maxn], ans;
set <tuple <int, int, int> > xx, yy;

void sort(int & a, int &b, int & c)
{
	int x[] = {a, b, c};
	sort(x, x + 3);
	a = x[0], b = x[1], c = x[2];
}

bool check(int a, int b, int c)
{
	sort(a, b, c);
	return (a == A && b == B && c == C);
}

int main()
{
	#ifdef fn
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);
	scanf("%d%d%d", &A, &B, &C);
	sort(A, B, C);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			x[i] += a[i][j];
			y[j] += a[i][j];
		}
	for (int i = 1; i <= n; i++)
		X[i] = X[i - 1] + x[i];
	for (int i = 1; i <= m; i++)
		Y[i] = Y[i - 1] + y[i];
//	for (int i = 1; i <= n; i++)
//		printf("%d ", x[i]);
//	puts("");
//	for (int i = 1; i <= m; i++)
//		printf("%d ", y[i]);
//	puts("");
	
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j < n; j++)
		{
			int q = X[i], w = X[j] - X[i], e = X[n] - X[j];
			if (check(q, w, e))
				ans++;
		}
	for (int i = 1; i <= m; i++)
		for (int j = i + 1; j < m; j++)
		{
			int q = Y[i], w = Y[j] - Y[i], e = Y[m] - Y[j];
			if (check(q, w, e))
				ans++;
		}
	printf("%d", ans);
}

