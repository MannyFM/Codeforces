
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = int(2e5 + 12);
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

int n;
ll A;
ll d[maxn], l[maxn], r[maxn];
ll sum;

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%I64d", &n, &A);
	for (int i = 1; i <= n; i++)
	{
		scanf("%I64d", d + i);
		sum += d[i];
	}
	for (int i = 1; i <= n; i++)
		if (A - n + 1 >= 0)
			r[i] = min(A - n + 1, d[i]);
		else
			r[i] = d[i];
	for (int i = 1; i <= n; i++)
		if (sum - d[i] + 1 >= A)
			l[i] = 1;
		else
			l[i] = A - sum + d[i];
	/*
	for (int i = 1; i <= n; i++)
		printf("%d ", r[i]);
	puts("");
	for (int i = 1; i <= n; i++)
		printf("%d ", l[i]);
	puts("");
	*/
	for (int i = 1; i <= n; i++)
		printf("%I64d ", (d[i] - r[i]) + l[i] - 1);
}
