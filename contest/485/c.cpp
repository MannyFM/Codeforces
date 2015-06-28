
#include <bits/stdc++.h>

using namespace std;

#define ll long long

int n;
ll l, r;

ll get(ll l, ll r)
{
	if (l == r)
		return l;
	ll now = 1ll;
	while (now  - 1 <= (ll)r)
		now *= 2;
	now /= 2;
	if (now <= l)
		return now + get(l - now, r - now);
	if (now * 2 - 1 <= r)
		return now * 2 - 1;
	return now - 1;
}

int main()
{
	scanf("%d", &n);
	while(n--)
	{
		scanf("%I64d%I64d", &l, &r);
		printf("%I64d\n", get(l, r));
	}
}