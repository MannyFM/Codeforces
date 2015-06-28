
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define maxn 4040
//#define fn "a"

int us[maxn];
int n, q, a, b, x;

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d", &x, &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &q);
		if (q == 1)
		{
			scanf("%d%d", &a, &b);
			us[a] = 1;
			us[b] = 1;
		}
		if (q == 2)
		{
			scanf("%d", &a);
			us[a] = 1;
		}
	}
	int mn = 0, mx = 0;
	int last = -1;
	us[x] = 1;
	for (int i = 1; i <= x; i++)
	{
		if (us[i])
		{
			if (last != -1)
			{
				//printf("%d %d\n", last, i);
				mx += i - last;
				mn += (i - last + 1) / 2;
				last = -1;
			}
		}
		else
		{
			if (last == -1)
				last = i;
		}
	}
	printf("%d %d", mn, mx);
}