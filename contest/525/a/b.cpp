
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
#define mp make_pair
#define pb push_back
//#define fn "a"
#define F first
#define S second

char s[maxn];
int n, x, y[maxn];

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%s", s + 1);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &x), y[x]++;
	int m = strlen(s + 1), now = 0;
	for (int i = 1; i <= m / 2; i++)
	{
		now += y[i];
		if (now & 1)
			swap(s[i], s[m - i + 1]);
		//printf("%d ", now);
	}
	printf("%s", s + 1);
}
