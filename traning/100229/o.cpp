
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
#define fn "road"
#define LOCAL
#define F first
#define S second

int n;
char a[2][60];

int main()
{
	#ifdef LOCAL
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d", &n);
	scanf("%s\n%s", a[0], a[1]);
	for (int i = 1; i < n - 1; i++)
		if (a[0][i] == 'W' && a[1][i] == 'W')
		{
			puts("NO");
			return 0;
		}
	puts("YES");
}