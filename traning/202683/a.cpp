
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
#define fn "stupid_rmq"
#define F first
#define S second

int n, a[maxn];
int len;
vector <int> s;

int get(int l, int r)
{
	int ans = inf;
	for (int i = l; i <= r;)
		if (i % len == 0 && i + len - 1 <= r)
		{
			ans = min(ans, s[i / len]);
			i += len;
		}
		else
		{
			ans = min(ans, a[i]);
			i++;
		}
	return ans;
		
}

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", a + i);
	len = int(sqrt(n + .0) + 1);
	s.assign(len, inf);
	for (int i = 0; i < n; i++)
		s[i / len] = min(s[i / len], a[i]);
	/*
	printf("%d\n", len);
	for (auto i : s)
		printf("%d ", i);
	puts("");
	*/
	int m, l, r;
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &l, &r);
		printf("%d\n", get(l - 1, r - 1));
	}
}
