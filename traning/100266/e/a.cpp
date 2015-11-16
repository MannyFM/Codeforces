
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
#define fn "division"

int n;
set <int> x, y;

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		x.insert(a);
		y.insert(b);
	}
	printf("%d\n", x.size() + y.size() - 2);
	auto it = x.begin(); it++;
	for (; it != x.end(); it++)
		printf("x %d\n", *(it));
	it = y.begin(); it++;
	for (; it != y.end(); it++)
		printf("y %d\n", *(it));
}
