
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
//#define fn

ll a, b, ans;
int n, p[10];

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf(I64 I64 "%d", &a, &b, &n);
	for (int i = 0; i < n; i++)
		scanf("%d", p + i);
	for (; a <= b; a++)
	{
		bool ok = 1;
		for (int i = 0; i < n; i++)
			if (a % p[i] == 0)
				ok = 0;
		ans += ok;
		if (ok)
			printf(I64 " ", a);
	}
	printf(I64 "\n", ans);
}
