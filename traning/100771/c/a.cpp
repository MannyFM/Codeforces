
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

int a[maxn], sz;
int x, cnt;

void fill(int j)
{
	int cnt = 0;
	for (int i = j + 1; i <= sz; i++)
		cnt += a[i];
	a[j] = 1, cnt--;
	for (int i = j + 1; i <= sz - cnt; i++)
		a[i] = 0;
	for (int i = sz - cnt + 1; i <= sz; i++)
		a[i] = 1;
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d", &x);
	while (x > 0)
	{
		a[++sz] = x & 1;
		cnt += x & 1;
		x >>= 1;
	}
	sz++;
	reverse(a + 1, a + sz + 1);
//	for (int i = 1; i <= sz; i++)
//		printf("%d", a[i]);
//	puts("");
	int k = -1;
	for (int i = sz; i > 0; i--)
		if (k == -1 && a[i + 1] && !a[i])
			k = i;
	if (k == -1)
	{
		sz++;
		fill(1);
	}
	else
		fill(k);
//	for (int i = 1; i <= sz; i++)
//		printf("%d", a[i]);
//	puts("");
	ll ans = 0, p = 1;
	for (int i = sz; i > 0; i--)
	{
		ans += a[i] * p;
		p *= 2ll;
	}
	printf(I64, ans);
}

