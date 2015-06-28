
#include <bits/stdc++.h>

using namespace std;

int cnt[2], x, y;

#define ll long long

bool ch(ll v)
{
	ll t[] = {v / x, v / y};
	ll b = v / (x * 1ll * y);
	ll other = v - t[0] - t[1] + b;
	t[0] -= b;
	t[1] -= b;
	ll f[] = {cnt[0] - t[1], cnt[1] - t[0]};
	if (f[0] < 0)
		f[0] = 0;
	if (f[1] < 0)
		f[1] = 0;
	return f[0] + f[1] <= other;
}

int main()
{
	scanf("%d%d%d%d", &cnt[0], &cnt[1], &x, &y);
	ll l = 0ll, r = (ll)(1e18 + 12);
	while (r - l > 1)
	{
		ll m = (r + l) >> 1;
		if (ch(m))
			r = m;
		else
			l = m;
	}
	//printf("%I64d %I64d  %d %d\n", l, r, ch(l), ch(r));
	printf("%I64d", r);
}