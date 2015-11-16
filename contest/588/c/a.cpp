#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = int(1e6 + 12);
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
#define all(x) x.begin(), x.end()
//#define fn ""

int n, w[maxn], ans;
map <int, int> cnt;
vector <int> v;

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", w + i);
		cnt[w[i]]++;
		v.pb(w[i]);
	}
	sort(w, w + n);
	for (auto x : cnt)
	{
		int c = x.S / 2;
		if (c)
		{
			cnt[x.F] -= c * 2;
			cnt[x.F + 1] += c;
		}
		ans += cnt[x.F];
	}
	printf("%d", ans);
}
