
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
#define mp make_pair
#define pb push_back
//#define fn "a"
#define F first
#define S second

int n;
int us[maxn];

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d", &n);
	if (n < 3)
	{
		puts("1\n1");
		return 0;
	}
	if (n == 3)
	{
		puts("2\n1 3");
		return 0;
	}
	if (n == 4)
	{
		puts("4\n3 1 4 2");
		return 0;
	}
	printf("%d\n", n);
	for (int i = 1; i <= n; i += 2)
		printf("%d ", i);
	for (int i = 2; i <= n; i += 2)
		printf("%d ", i);
}
