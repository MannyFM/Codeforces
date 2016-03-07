
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = 350;
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
#define fn "f"

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
int a[maxn][maxn];
int b[maxn], bal[maxn];
int ans[maxn], pos[maxn];

int solve(int j)
{
	int ans = inf, k = 1;
	int F = -1, S = -1;
	for (int i = 1; i <= n; i++)
		bal[a[j][i]] = i;
//	printf("%d:\n", j);
	for (int i = 1; i <= n; i++)
	{
		if (F == -1 || pos[i] < pos[F])
			S = F, F = i;
		else
		{
			if (S == -1 || pos[i] < pos[S])
				S = i;
		}
		if (F != -1 && F != j && umin(ans, bal[F]))
			k = F;
		if (F == j && S != -1 && S != j && umin(ans, bal[S]))
			k = S;
//		printf("%d %d  %d %d\n", F, S, ans, k);
	}
	return k;
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);
	for (int i = 1; i <= n; i++)
		scanf("%d", b + i), pos[b[i]] = i;
	for (int i = 1; i <= n; i++)
		ans[i] = solve(i);
	for (int i = 1; i <= n; i++)
	{
		printf("%d ", ans[i]);
	}
}

