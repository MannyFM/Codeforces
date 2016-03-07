
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

template <typename T>
bool umax(T & a, T b)
{
	return a < b ? (a = b, 1) : 0;
}

template <typename T>
bool umin(T & a, T b)
{
	return a > b ? (a = b, 1) : 0;
}

int n, x, cnt[12], bal;
vector <int> one = {1, 4, 7}, two = {2, 5, 8};

bool del(int f)
{
	auto & v = f == 1 ? one : two;
	for (int x : v)
		if (cnt[x])
		{
			cnt[x]--;
			return 1;
		}
	return 0;
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		cnt[x]++;
		bal += x;
		bal %= 3;
	}
	if (!cnt[0])
	{
		puts("-1");
		return 0;
	}
	if (bal == 1)
	{
		if (!del(1))
		{
			del(2);
			del(2);
		}
	}
	if (bal == 2)
	{
		if (!del(2))
		{
			del(1);
			del(1);
		}
	}
	int ok = 0;
	for (int i = 9; i > 0; i--)
	{
		ok |= cnt[i];
		for (int k = 0; k < cnt[i]; k++)
			printf("%d", i);
	}
	if (!ok)
		cnt[0] = 1;
	for (int i = 0; i < cnt[0]; i++)
		printf("0");
}

