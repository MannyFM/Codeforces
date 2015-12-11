
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

int n, m, k;
int a[maxn];
int is[maxn], cnt;

bool f(int x)
{
	memset(is, 0, sizeof(is));
	int mn = x;
	for (int y = max(x - k + 1, 1); y <= x; y++)
		is[y] = 1, cnt++;
	mn = max(x - k + 1, 1);
	/**/printf("[%d %d]:\n", mn, x);
	for (int i = n; i > 0; i--)
	{
		
		for (int j = 1; j <= m; j++)
			if (is[j])
				printf("%d ", j);
		puts("");
		
		if (is[a[i]])
		{
			is[a[i]]--;
			if (mn != 1)
				is[--mn]++;
			else
				cnt--;
		}
		if (!cnt)
		{
			/**/printf("+\n");
			return 1;
		}
	}
	/**/printf("%c\n", !cnt ? '+' : '-');
	return !cnt;
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	int T;
	scanf("%d", &T);
	for (int step = 1; step <= T; step++)
	{
		scanf("%d%d%d", &n, &m, &k);
		for (int i = 1; i <= n; i++)
			scanf("%d", a + i);
		int l = 0, r = m + 1;
		while (r - l > 1)
		{
			int m = (l + r) >> 1;
			if (f(m))
				l = m;
			else
				r = m;
		}
		/**/puts("");
		printf("%d\n", l);
	}
}
