
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

int r, g, b, ans = 0;

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d%d", &r, &g, &b);
	for (int mix = 0; mix < 3; mix++)
	{
		if (r < mix || g < mix || b < mix)
			break;
		int R = (r - mix) / 3;
		int G = (g - mix) / 3;
		int B = (b - mix) / 3;
		ans = max(ans, R + G + B + mix);
	}
	printf("%d", ans);
}
