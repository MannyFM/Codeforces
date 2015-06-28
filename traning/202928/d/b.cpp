
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = int(1e5 + 12);
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

int n, w, r;
int a[maxn], len;
vector <pii> s;
vector <int> add;

void push(int k)
{
	if (!add[k])
		return;
	int k1 = len * (k + 1);
	for (int i = len * k; i < k1; i++)
		a[i] += add[k];
	add[k] = 0;
}

void calc(int k)
{
	push(k);
	s[k] = mp(inf, inf);
	for (int i = 0; i < len; i++)
		s[k] = min(s[k], mp(a[k * len + i], k * len + i));
}

void pre()
{
	len = int(sqrt(n + .0)) + 1;
	s.assign(len, mp(inf, inf));
	add.assign(len, 0);
	for (int i = 0; i < n; i++)
		s[i / len] = min(s[i / len], mp(a[i], i));
}

pii get(int l, int r)
{
	push(l / len);
	push(r / len);
	pii ans = mp(inf, inf);
	for (int i = l; i <= r; )
	{
		if (i % len == 0 && i + len <= r + 1)
		{
			ans = min(ans, s[i / len]);
			i += len;
		}
		else
		{
			ans = min(ans, mp(a[i], i));
			i++;
        }
	}
	return ans;
}

void upd(int l, int r)
{
	push(l / len);
	push(r / len);
	for (int i = l; i <= r; )
	{
		if (i % len == 0 && i + len <= r + 1)
		{
			s[i / len].F++;
			add[i / len]++;
			i += len;
		}
		else
		{
			a[i]++;
			i++;
		}
	}
	calc(l / len);
	calc(r / len);
}

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	int m, w;
	scanf("%d%d%d", &n, &m, &w);
	for (int i = 0; i < n; i++)
		scanf("%d", a + i);
	pre();
	for (int i = 1; i <= m; i++)
	{
		pii g = get(0, n - 1);
		int p = g.S;
		p = min(p, n - w);
		upd(p, p + w - 1);
	}
	printf("%d", get(0, n - 1).F);
}
