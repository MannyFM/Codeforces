
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

ll l, r;
int ans;

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf(I64 I64, &l, &r);
	ll mask = 1;
	for (int step = 1; step < 61; step++)
	{
		//printf(":%d " I64 "\n", step, mask);
		for (int i = 0; i + 1 < step; i++)
		{
			ll nmask = mask ^ (1ll << i);
			if (l <= nmask && nmask <= r)
			{
				ans++;
				//printf(I64 " ", nmask);
			}
		}
		//puts("");
		mask = (mask << 1) | 1ll;
	}
	printf("%d", ans);
}

