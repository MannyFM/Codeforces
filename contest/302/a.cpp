
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define maxn int(2e5 + 12)
//#define fn "a"

int n, cnt[2];
int a[maxn];

bool f(int sz)
{
	if (sz & 1)
		return 0;
	int c = min(cnt[0], cnt[1]) * 2;
	return (c >= sz);
}

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	int m, l, r;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i), cnt[a[i] == 1]++;
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d", &l, &r);
		printf("%d\n", f(r - l + 1));
	}
}
