
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
#define fn "frog"

int n, pos = 0;
map <int, int> cnt;

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		cnt[x]++;
	}
	ll E = 0;
	while (!cnt.empty())
	{
		auto it = cnt.end();
		it--;
		E += max(0, (it -> F - pos)) * 1ll * it -> S;
		pos += it -> S;
		cnt.erase(it);
	}
	printf(I64, E);
}
