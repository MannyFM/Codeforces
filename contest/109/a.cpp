
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

int a = -inf, b = -inf;

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	int n;
	scanf("%d", &n);
	for (int x = 0; x < maxn; x++)
	{
		if ((n - 7 * x) % 4 == 0 && n - 7 * x >= 0)
		{
			a = (n - 7 * x) / 4;
			b = x;
		}
	}
	if (a == -inf)
		puts("-1");
	else
	{
		while(a--)
			putchar('4');
		while(b--)
			putchar('7');
	}
}
