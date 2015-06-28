
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define maxn int(2e6 + 12)
#define maxb int(2e6 + 12)
#define inf int(1e9 + 7)
#define linf ll(1e18 + 12)
#define eps 1e-7
#define mp make_pair
#define pb push_back
//#define fn "a"
#define F first
#define S second

int n, a[5], b[5], c[5], d[5];
int ans;

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d", &n);
	int i = 1;
	scanf("%d%d%d%d", a + i, b + i, c + i, d + i), i++;
	scanf("%d%d%d%d", a + i, b + i, c + i, d + i), i++;
	scanf("%d%d%d%d", a + i, b + i, c + i, d + i), i++;
	scanf("%d%d%d%d", a + i, b + i, c + i, d + i), i++;
	i--;
	while (i > 0)
	{
		int A = min(a[i], b[i]);
		int B = min(c[i], d[i]);
		if (A + B > n)
		{
			i--;
			continue;
		}
		printf("%d %d %d", i, A, n - A);
		return 0;
	};
	puts("-1");
}
