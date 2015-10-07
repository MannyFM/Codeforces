
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
#define fn "repair"

int n, a[maxn];
ll k;
map <ll, int> cnt;

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d" I64, &n, &k);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", a + i);
		cnt[a[i]]++;
	}
	while (k && cnt.size() > 1)
	{
		auto it = cnt.begin();
		auto f = *(it++);
		ll to = it -> F;
		cerr << (to - f.F) * 1ll * f.S << '\n';
		if ((to - f.F) * 1ll * f.S > k)
			break;
		k -= (to - f.F) * 1ll * f.S;
		cnt.erase(cnt.begin());
		cnt[to] += f.S;
	}
	if (k >= cnt.begin() -> S)
	{
		int to = k / (cnt.begin() -> S);
		printf(I64, cnt.begin() -> F + to);
		return 0;
	}
	printf(I64, cnt.begin() -> F);
}
