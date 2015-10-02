
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
#ifdef _WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define next MyLittleNext
//#define end MyLittleEnd
#define all(x) x.begin(), x.end()
//#define fn ""

char s[250][250], c[4];
pii a[4];
ll b;
int n = 3;

bool free(int x, int y, int k)
{
	for (int i = x; i < x + a[k].F; i++)
		for (int j = y; j < y + a[k].S; j++)
			if (s[i][j])
				return false;
	for (int i = x; i < x + a[k].F; i++)
		for (int j = y; j < y + a[k].S; j++)
			s[i][j] = c[k];
	return true;
}

bool rec(int cnt)
{
	if (cnt == n)
		return true;
	for (int i = 0; i < b; i++)
		for (int j = 0; j < b; j++)
			if (free(i, j, cnt) && rec(cnt + 1))
				return true;
	return false;
}

bool check()
{
	memset(s, 0, sizeof(s));
	if (!rec(0))
		return false;
	for (int i = 0; i < b; i++)
		for (int j = 0; j < b; j++)
			if (!s[i][j])
				return false;
	return true;
}

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	ll sum = 0ll;
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &a[i].F, &a[i].S);
		sum += a[i].F * 1ll * a[i].S;
		c[i] = 'A' + i;
	}
	b = sqrt(sum);
	if (b * b != sum)
	{
		puts("-1");
		return 0;
	}
	do
	{
		for (int mask = 0; mask < (1 << n); mask++)
		{
			for (int i = 0; i < n; i++)
				if (mask & (1 << i))
					swap(a[i].F, a[i].S);
			if (check())
			{
				printf(I64 "\n", b);
				return 0;
				for (int i = 0; i < b; i++)
				{
					for (int j = 0; j < b; j++)
						printf("%c", s[i][j]);
					puts("");
				}
				return 0;
			}
			for (int i = 0; i < n; i++)
				if (mask & (1 << i))
					swap(a[i].F, a[i].S);
		}
	}
	while (next_permutation(a, a + n) && next_permutation(c, c + n));
	puts("-1");
	return 0;
}
