
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

int n = 3;
pii a[4];
char c[4];

void check()
{
	int b = a[0].F;
	bool ok = true;
	int sum = a[0].S;
	for (int i = 1; i < n; i++)
	{
		if (a[i].F != b)
			ok = false;
		sum += a[i].S;
	}
	//printf("%d %d %d\n", ok, sum, b);
	if (ok && sum == b)
	{
		printf("%d\n", b);
		for (int i = 0; i < b; i++)
		{
			for (int k = 0; k < n; k++)
				for (int j = 0; j < a[k].S; j++)
					printf("%c", c[k]);
			puts("");
		}
		exit(0);
	}
	b = a[2].S;
	ok = (a[0].F == a[1].F) && (a[0].S + a[1].S == b) && (a[0].F + a[2].F == b);
	if (ok)
	{
		printf("%d\n", b);
		for (int i = 0; i < a[0].F; i++)
		{
			for (int j = 0; j < a[0].S; j++)
				printf("%c", c[0]);
			for (int j = 0; j < a[1].S; j++)
				printf("%c", c[1]);
			puts("");
		}
		for (int i = 0; i < a[2].F; i++)
		{
			for (int j = 0; j < b; j++)
				printf("%c", c[2]);
			puts("");
		}
		exit(0);
	}
	b = a[0].F;
	ok = (a[1].F == a[2].F) && (a[0].S + a[1].S == b) && (a[1].F + a[2].F == b);
	if (ok)
	{
		printf("%d\n", b);
		for (int i = 0; i < a[1].F; i++)
		{
			for (int j = 0; j < a[0].F; j++)
				printf("%c", c[0]);
			for (int j = 0; j < a[1].F; j++)
				printf("%c", c[1]);
		}
		for (int i = 0; i < a[2].F; i++)
		{
			for (int j = 0; j < a[0].F; j++)
				printf("%c", c[0]);
			for (int j = 0; j < a[2].F; j++)
				printf("%c", c[2]);
		}
		exit(0);
	}
}

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	for (int i = 0; i < n; i++)
		scanf("%d%d", &a[i].F, &a[i].S), c[i] = 'A' + i;
	
	int C = a[0].F * a[0].S + a[1].F * a[1].S + a[2].F * a[2].S;
	int Q = int(sqrt(C));
	if (Q * Q != C)
	{
		puts("-1");
		return 0;
	}

	for (int mask = 0; mask < (1 << n); mask++)
	{
		for (int i = 0; i < n; i++)
			if (mask & (1 << i))
				swap(a[i].F, a[i].S);
		check();
		for (int i = 0; i < n; i++)
			if (mask & (1 << i))
				swap(a[i].F, a[i].S);
	}
	
	do
	{
		for (int mask = 0; mask < (1 << n); mask++)
		{
			for (int i = 0; i < n; i++)
				if (mask & (1 << i))
					swap(a[i].F, a[i].S);
			check();
			for (int i = 0; i < n; i++)
				if (mask & (1 << i))
					swap(a[i].F, a[i].S);
		}
	} while (next_permutation(a, a + n) && next_permutation(c, c + n));
	puts("-1");
}
