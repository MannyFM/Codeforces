
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define maxn 100000 + 12
#define maxb int(2e6 + 12)
#define inf int(1e9 + 7)
#define linf ll(1e18 + 12)
#define eps 1e-7
#define mp make_pair
#define pb push_back
#define fn "rvq"
#define F first
#define S second

int n, a[maxn];
int len;
vector <pii> s;
//min max

int get(int l, int r)
{
	int x = inf, y = -inf;
	for (int i = l; i <= r;)
		if (i % len == 0 && i + len - 1 <= r)
		{
			x = min(x, s[i / len].F);
			y = max(y, s[i / len].S);
			i += len;
		}
		else
		{
			x = min(x, a[i]);
			y = max(y, a[i]);
			i++;
		}
	return abs(y - x);
}

void upd(int p, int x)
{
	a[p] = x;
	int k = p / len;
	s[k].F = inf;
	s[k].S = -inf;
	for (int i = k * len; i < (k + 1) * len; i++)
	{
		s[k].F = min(s[k].F, a[i]);
		s[k].S = max(s[k].S, a[i]);
	}
}

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	n = int(1e5);
	for (int i = 1; i <= n; i++)
		a[i - 1] = int((i * 1ll * i) % 12345 + (i * 1ll * i * i) % 23456);
	len = int(sqrt(n + .0) + 1);
	s.assign(len, mp(inf, -inf));
	for (int i = 0; i < n; i++)
	{
		s[i / len].F = min(s[i / len].F, a[i]);
		s[i / len].S = max(s[i / len].S, a[i]);
	}
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
		if (l < 0)
		{
			l = -l;
			upd(l - 1, r);
		}
		else
			printf("%d\n", get(l - 1, r - 1));
	}
}
