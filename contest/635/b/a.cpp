
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = int(2e5 + 12);
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

int n;
vector <int> a, b, c;
int pos[maxn];

bool check(int l1, int r1, int l2, int r2)
{
//	printf("[%d %d] [%d %d]\n", l1, r1, l2, r2);
	for (int i = l1, j = l2; i <= r1 && j <= r2; i++, j++)
		if (a[i] != b[j])
			return 0;
	return 1;
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d", &n);
	int x;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		if (x)
			a.pb(x);
	}
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		if (x)
		{
			pos[x] = (int)b.size();
			b.pb(x);
		}
	}
	n--;
//	for (int i = 0; i < n; i++)
//		printf("%d ", a[i]);
//	puts("");
//	for (int i = 0; i < n; i++)
//		printf("%d ", b[i]);
//	puts("");
	int l = pos[a[0]], r = n - 1;
	if (!check(0, r - l, l, r))
	{
		puts("NO");
		return 0;
	}
	if (!check(r - l + 1, n - 1, 0, l - 1))
	{
		puts("NO");
		return 0;
	}
	puts("YES");
}

