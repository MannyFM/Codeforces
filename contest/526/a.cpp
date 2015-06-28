
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
#define mp make_pair
#define pb push_back
//#define fn "a"
#define F first
#define S second

int n;
bool can[120];
char x[120];

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d", &n);
	scanf("%s", x);
	for (int i = 0; i < n; i++)
		can[i] = x[i] == '*';
	for (int len = 1; len <= n; len++)
	{
		for (int i = 0; i < n; i++)
		{
			bool good = 1;
			for (int j = i; j <= i + len * 4; j += len)
				if (!can[j] || j >= n)
					good = 0;
			if (good)
			{
				puts("yes");
				return 0;
			}
		}
	}
	puts("no");
}
