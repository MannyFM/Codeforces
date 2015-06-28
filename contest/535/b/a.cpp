
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

vector <int> v;

void gen(int len)
{
	for (int mask = 0; mask < (1 << len); mask++)
	{
		ll now = 0;
		for (int j = 0; j < len; j++)
		{
			now *= 10;
			if (mask & (1 << j))
				now += 4;
			else
				now += 7;
		}
		v.pb(now);
	}
}

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	int n;
	scanf("%d", &n);
	for (int i = 1; i < 10; i++)
		gen(i);
	sort(v.begin(), v.end());
	int i = 0;
	while (v[i] != n)
		i++;
	printf("%d", i + 1);
}
