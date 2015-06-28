
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = int(1e6 + 12);
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

int A, B, n;
int a[maxn];
int s[25][maxn];
int lg[maxn];

void pre()
{
	for (int i = 2; i <= n; i++)
		lg[i] = lg[i / 2] + 1;
	for (int i = 1; i <= n; i++)
		s[0][i] = a[i];
	for (int i = 1; i <= n; 
}

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
}
