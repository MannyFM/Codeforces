
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
#define fn "a"
#define f first
#define s second

ll a1, b1, a2, b2;
mii d1, d2;

void calc(ll x, mii &d)
{
	for (int i = 2; i * 1ll * i <= x; i++)
		while (x % i == 0)
			d[i]++, x /= i;
	if (x > 1)
		d[x]++;
}

void change(ll & a, ll & b, ll d)
{
	ll g = __gcd(a, d);
	a /= g;
	d /= g;
	g = __gcd(b, d);
	b /= g;
	d /= g;
}

void ch(ll & a, ll & b, ll d)
{
	while (d && a % 3 == 0)
		a /= 3, a *= 2, d--;
	while (d && b % 3 == 0)
		b /= 3, b *= 2, d--;
}

int main()
{
	#ifdef LOCAL
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%I64d%I64d%I64d%I64d", &a1, &b1, &a2, &b2);
	calc(a1, d1);
	calc(b1, d1);
	calc(a2, d2);
	calc(b2, d2);

	for (auto it = begin(d1); it != end(d1); it++)
	{
		if (it -> f != 2 && it -> f != 3)
		{
			int k = it -> f;
			if (d2.find(k) == end(d2) || d2[k] != it -> s)
			{
				puts("-1");
				return 0;
			}
		}
	}
	for (auto it = begin(d2); it != end(d2); it++)
	{
		if (it -> f != 2 && it -> f != 3)
		{
			int k = it -> f;
			if (d1.find(k) == end(d1) || d1[k] != it -> s)
			{
				puts("-1");
				return 0;
			}
		}
	}

	ll delta1 = 0, delta2 = 0;
	if (d2[3] > d1[3])
	{
		delta1 = d2[3] - d1[3];
		d2[3] -= delta1;
		d2[2] += delta1;
		ch(a2, b2, delta1);
	}
	else
	{
		delta1 = d1[3] - d2[3];
		d1[3] -= delta1;
		d1[2] += delta1;
		ch(a1, b1, delta1);
	}
	if (d2[2] > d1[2])
	{
		delta2 = d2[2] - d1[2];
		d2[2] -= delta2;
		change(a2, b2, pow(2, delta2));
	}
	else
	{
		delta2 = d1[2] - d2[2];
		d1[2] -= delta2;
		change(a1, b1, pow(2, delta2));
	}
	printf("%I64d\n", delta1 + delta2);
	printf("%I64d %I64d\n%I64d %I64d", a1, b1, a2, b2);
}
