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
//#define fn ""

int a[3], b[3];

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	for (int i = 0; i < 3; i++)
		scanf("%d", a + i);
	for (int i = 0; i < 3; i++)
		scanf("%d", b + i);
	int delta = 0;
	for (int i = 0; i < 3; i++)
		if (a[i] > b[i])
			delta += (a[i] - b[i]) / 2;
	for (int i = 0; i < 3; i++)
		if (b[i] > a[i])
			delta -= b[i] - a[i];
	puts(delta >= 0 ? "Yes" : "No");
}
