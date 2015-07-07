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
int a[200];
int j = 1;

int main()
{
    #ifdef fn
        freopen(fn".in", "r", stdin);
        freopen(fn".out", "w", stdout);
    #endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    	scanf("%d", a + i);
    a[n + 1] = a[1];
    for (int i = 1; i <= n; i++)
    	if (abs(a[i] - a[i + 1]) < abs(a[j] - a[j + 1]))
    		j = i;
    printf("%d %d\n", j, j % n + 1);
}
