
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
#define fn "b"
#define F first
#define S second

int v, d;
int b[maxn], len, a[10];

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d", &v);
	for (int i = 1; i <= 9; i++)
		scanf("%d", a + i);
	d = 1;
	for (int i = 2; i <= 9; i++)
		if (a[i] <= a[d])
			d = i;
	len = v / a[d];
	v = v - a[d] * len;
	if (!len)
	{
		puts("-1");
		return 0;
	}
	for (int i = 0; i < len; i++)
		b[i] = d;
	for (int i = 1; i <= 9; i++)
		a[i] -= i != d ? a[d] : 0;
	a[d] = 0;
	for (int i = 0; i < len; i++)
	for (int j = 9; j > d; j--)
	{
		if (a[j] <= v)
		{
			v -= a[j];
			b[i] = j;
			break;
		}
	}
	for (int i = 0; i < len; i++)
		printf("%d", b[i]);
}