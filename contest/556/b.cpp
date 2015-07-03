
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
#ifdef WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif
#define mp make_pair
#define pb push_back
#define F first
#define S second
//#define fn ""

int n;
int a[1010];

bool check()
{
	for (int i = 0; i < n; i++)
		if (a[i] != i)
			return 0;
	return 1;
}

void upd()
{
	for (int i = 0; i < n; i++)
		if (i & 1)
			a[i] = (a[i] - 1 + n) % n;
		else
			a[i] = (a[i] + 1 + n) % n;
}

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", a + i);
	for (int step = 0; step < n; step++)
	{
		if (check())
		{
			puts("Yes");
			return 0;
		}
		upd();
		/*
		for (int i = 0; i < n; i++)
			printf("%d ", a[i]);
		puts("");
		*/
	}
	puts("No");
}

