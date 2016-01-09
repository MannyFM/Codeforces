
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

int n, m;
string s, t;
char x;
int sum[maxn];
ll ans;


inline int get(int l, int r)
{
	//printf("[%d %d]", l, r);
	return sum[r] - (l > 0 ? sum[l - 1] : 0);
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	cin >> s >> t;
	n = int(s.size()), m = int(t.size());
	sum[0] = t[0] == '1';
	for (int i = 0; i < m; i++)
		sum[i] = sum[i - 1] + (t[i] == '1');
	int len = m - n + 1;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '0')
			ans += get(i, i + len - 1);
		else
			ans += len - get(i, i + len - 1);
		//printf(I64 " ", ans);
	}
	printf(I64, ans);
}

