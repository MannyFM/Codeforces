
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
#define fn "freecell"
#define YES {printf("Case #%d: Possible\n", c); continue;}
#define NO {printf("Case #%d: Broken\n", c); continue;}

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	int C;
	scanf("%d", &C);
	for (int c = 1; c <= C; c++)
	{
		ll N, pg, pd;
		scanf(I64 I64 I64, &N, &pd, &pg);
		if (pg == 0 || pg == 100)
		{
			if (pg != pd)
				NO
			else
				YES
		}
		ll x = 1;
		if (pd == 0 || pd == 100)
			x = 0;
		else
			for (;; x++)
			{
				if ((x * pd) % 100 == 0 && (x * (100 - pd) % 100 == 0))
					break;
			}
		//cerr << N << " " << x << "\n";
		if (x <= N)
			YES
		else
			NO;
	}
}
