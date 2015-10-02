
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

ll H[2][maxn], p_pow[maxn];
char s[maxn], t[maxn];

ll const p = 31, mod = ll(1e9 + 17);
ll const mod2 = (mod * mod);

ll get_hash(int k, int l, int r)
{
	ll ans = H[k][r];
	if (l)
		ans = (ans - H[k][l - 1] * p_pow[r - l + 1] + mod2) % mod;
	return ans;
}

bool equal(int l1, int r1, int l2, int r2)
{
	if (l1 > r1 || l2 > r2)
		return false;
	if (r1 - l1 != r2 - l2)
		return false;
	if (get_hash(0, l1, r1) == get_hash(1, l2, r2))
		return true;
	//printf("%d %d %d %d\n", l1, r1, l2, r2);
	
	if (((r1 - l1 + 1) & 1) || ((r2 - l2 + 1)) & 1)
		return false;
	
	int m1 = (l1 + r1) >> 1;
	int m2 = (l2 + r2) >> 1;
	if (equal(l1, m1, m2 + 1, r2) && equal(m1 + 1, r1, l2, m2))
		return true;
	if (equal(l1, m1, l2, m2) && equal(m1 + 1, r1, m2 + 1, r2))
		return true;
	return false;
}

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%s %s", s, t);
	int n = strlen(s);
	H[0][0] = s[0] - 'a' + 1;
	H[1][0] = t[0] - 'a' + 1;
	p_pow[0] = 1;
	for (int i = 1; i < n; i++)
	{
		H[0][i] = (H[0][i - 1] * p + s[i] - 'a' + 1 + mod2) % mod;
		H[1][i] = (H[1][i - 1] * p + t[i] - 'a' + 1 + mod2) % mod;
		p_pow[i] = (p_pow[i - 1] * p + mod2) % mod;
	}
	puts(equal(0, n - 1, 0, n - 1) ? "YES" : "NO");
}
