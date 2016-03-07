
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

int n, cnt[12];
int ans[12];
vector <int> now, best;

bool better()
{
	int a = 0, b = 0;
	for (int x : now)
		a += x;
	for (int x : best)
		b += x;
	if (a != b)
		return a > b;
	for (int i = 9; i >= 0; i--)
		if (now[i] != best[i])
			return now[i] > best[i];
	return 0;
}

void rec(int cur, int bal)
{
	bal %= 3;
	if (cur == 0)
	{
		if (bal % 3)
			return;
//		for (int i = 0; i < 10; i++)
//			for (int y = 0; y < now[i]; y++)
//				printf("%d", i);
//		puts("");
		if (better())
			best = now;
		return;
	}
	for (int x = 0; x <= cnt[cur]; x++)
	{
		now[cur] = x;
		rec(cur - 1, bal + cur * x);
	}
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
		int x;
		scanf("%d", &x);
		cnt[x]++;
	}
	if (!cnt[0])
	{
		puts("-1");
		return 0;
	}
	for (int i = 0; i < 10; i++)
	{
		if (i % 3)
		{
			int last = cnt[i] % 3;
			ans[i] = cnt[i] - last;
			cnt[i] = last;
		}
		else
		{
			ans[i] = cnt[i];
			cnt[i] = 0;
		}
	}
//	for (int i = 9; i >= 0; i--)
//	{
//		for (int x = 0; x < ans[i]; x++)
//			printf("%d", i);
//	}
//	puts("");
	best.assign(10, 0);
	now.assign(10, 0);
	rec(9, 0);
	for (int i = 0; i < 10; i++)
		ans[i] += best[i];
	int ok = 0;
	for (int i = 9; i > 0; i--)
	{
		for (int x = 0; x < ans[i]; x++)
		{
			if (i)
				ok = 1;
			printf("%d", i);
		}
	}
	if (!ok)
		ans[0] = 1;
	for (int i = 0; i < ans[0]; i++)
		printf("0");
}

