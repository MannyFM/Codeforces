
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
#define fn "b2"
#define f first
#define s second

template<typename T>
T min(T a, T b, T c)
{
	return min(a, min(b, c));
}

template<typename T>
T max(T a, T b, T c)
{
	return max(a, max(b, c));
}

vector <int> v;
int n;
ll m;
int us[60];

void find(int i, ll pr, ll pos, int last, bool fl)
{
	if (i == n + 1)
	{
		for (int i = 0; i < n; i++)
			printf("%d ", v[i]);
		exit(0);
	}
	if (last == n || fl)
	{
		for (int k = last - 1; k > 0; k--)
			if (!us[k])
			{
				us[k] = 1;
				v.pb(k);
				find(i + 1, pr, pos, k, 1);
			}
	}
	/*
	for (int tt = 1; tt < i; tt++)
		putchar(' ');
	
	printf("%d:\n", i);
	*/
	ll now = pr;
	for (int k = last + 1; k <= n; k++)
	{
		now /= 2;
		if (now == 0)
			now = 1;
		if (pos < now)
		{
			v.pb(k);
			us[k] = 1;
			//printf("!%d n%I64d p%d i%d\n", k, now, pos, i);
			find(i + 1, now, pos, k, 0);
		}
		pos -= now;
	}
	for (int k = n; k > 0; k--)
		if (!us[k])
		{
			us[k] = 1;
			v.pb(k);
			find(i + 1, pr, pos, k, 1);
		}
}

int main()
{
	#ifdef LOCAL
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%I64d", &n, &m);
	find(1, (1ll << (n - 1)), m - 1, 0, 0);
}