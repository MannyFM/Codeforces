
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

int a, b, k;
int npr[maxb];
int cnt[maxb];

bool f(int l)
{
	for (int x = a; x + l - 1 <= b; x++)
		if (cnt[x + l - 1] - cnt[x - 1] < k)
			return 0;
	return 1;
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d%d%d", &a, &b, &k);
	npr[0] = npr[1] = 1;
	for (int i = 2; i <= b; i++)
	{
		if (!npr[i] && i * 1ll * i <= b)
			for (int j = i * i; j <= b; j += i)
				npr[j] = 1;
		cnt[i] = cnt[i - 1] + !npr[i];
	}
//	for (int i = 1; i <= b; i++)
//		printf("%d ", cnt[i]);
//	puts("");
	if (cnt[b] - cnt[a - 1] < k)
	{
		puts("-1");
		return 0;
	}
	int l = 0, r = b - a + 2;
	while (r - l > 1)
	{
		int m = l + ((r - l) >> 1);
		if (f(m))
			r = m;
		else
			l = m;
	}
	printf("%d", r);
}

