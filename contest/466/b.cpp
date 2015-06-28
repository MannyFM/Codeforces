
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
#define fn "b"
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

ll n, a, b, fl;

int main()
{
	#ifdef LOCAL
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%I64d%I64d%I64d", &n, &a, &b);
	if (a * b >= 6 * n)
	{
		printf("%I64d\n%I64d %I64d", a * b, a, b);
		return 0;
	}
	if (a > b)
	{
		fl = 1;
		swap(a, b);
	}
	ll A = a, B = b, C = linf;
	ll maxx = ll(sqrt(6 * n)) + 123ll;
	ll old_a = a, old_b = b;
	for (a = old_a; a <= maxx; a++)
	{
		b = (6 * n + a - 1) / a;
		if (a * b < C && b >= old_b)
		{
			A = a;
			B = b;
			C = A * B;
		}
	}
	if (fl)
		swap(A, B);
	printf("%I64d\n%I64d %I64d", C, A, B);
}