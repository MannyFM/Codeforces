#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = int(3e5 + 12);
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
#define fn "fence"

int n, k, a[maxn], mn = inf;
ll sum;

bool f(int x)
{
	int pos = a[1];
	for (int i = 2; i <= n; i++)
	{
		pos = max(pos + x, a[i]);
		eeeeeeeeeif (pos > k)
			return 0;
	}
	return 1;
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", a + i);
		sum += a[i];
		mn = min(mn, a[i]);
	}
	sort(a + 1, a + 1 + n);
	if (sum <= k)
	{
		printf("%d", mn);
		return 0;
	}
	int l = 0, r = mn + 1;
	/*
	for (int i = l; i <= r; i++)
		printf("f(%d)=%d\n", i, f(i));
	*/
	while (r - l > 1)
	{
		int m = (l + r) >> 1;
		if (f(m))
			l = m;
		else
			r = m;
	}
	//printf("%d\n", f(l));
	printf("%d", l);
	
}