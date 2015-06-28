
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define maxn 100000 + 12
#define linf ll(1e18 + 12)
#define mp make_pair
#define pb push_back
#define fn "sum"
#define F first
#define S second

int n, m;
ll a[maxn];
vector <ll> s;
vector <ll> add;
int len;

void push(int k)
{
	if (add[k] == linf)
		return;
	s[k] = 0ll;
	for (int i = k * len; i < (k + 1) * len; i++)
	{
		a[i] = add[k];
		s[k] += a[i];
	}
	add[k] = linf;
}

ll get(int l, int r)
{
	ll ans = 0ll;
	for (int i = l; i <= r; )
	{
		if (i % len == 0 && i + len - 1 <= r)
		{
			ans += s[i / len];
			i += len;
		}
		else
		{
			push(i / len);
			ans += a[i];
			i++;
		}
	}
	//printf("%I64d\n", ans);
	return ans;
}

void upd(int l, int r, int x)
{
	for (int i = l; i <= r; )
	{
		if (i % len == 0 && i + len - 1 <= r)
		{
			add[i / len] = x + 0ll;
			s[i / len] = len * 1ll * x;
			i += len;
		}
		else
		{
			push(i / len);
			s[i / len] -= a[i];
			a[i] = x;
			s[i / len] += a[i];
			i++;
		}
	}
}

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	len = int(sqrt(n)) + 1;
	s.assign(len, 0ll);
	add.assign(len, linf);
	/*
	printf("%d\n", len);
	for (auto i : s)
		printf("%d ", i);
	puts("");
	*/
	int l, r, x;
	char q;
	while(m--)
	{
		scanf("\n%c%d%d", &q, &l, &r);
		if (q == 'A')
		{
			scanf("%d", &x);
			upd(l - 1, r - 1, x);
		}
		else
		{
			printf("%I64d\n", get(l - 1, r - 1));
		}
	}
}
