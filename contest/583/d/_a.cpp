#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;

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
//#define fn ""

template <typename T> bool umax(T &a, T b) { return a < b ? (a = b, 1) : 0; }

template <typename T> bool umin(T &a, T b) { return a > b ? (a = b, 1) : 0; }

vi calc(vi const & v) {
	int N = (int)v.size() - 1;
	vector <int> dp(N + 1, 500), ans(N + 1);
	dp[0] = -1;
	for (int i = 1; i <= N; i++) {
		ans[i] = upper_bound(dp.begin(), dp.end(), v[i]) - dp.begin();
		dp[ans[i]] = v[i];
	}
	return ans;
}

int n, a[maxn], T;

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &T);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	if (2 * n >= T) {
		int nn = n * T;
		vector <int> v(nn + 1);
		for (int i = 1; i <= nn; i++)
			v[i] = i <= n ? a[i] : v[i - n];
		vi vv = calc(v);
		int ans = 0;
		for (int i = 1; i <= nn; i++)
			umax(ans, vv[i]);
		printf("%d\n", ans);
		return 0;
	}
	int nn = n * n;
	vector <int> v(nn + 1);
	for (int i = 1; i <= nn; i++)
		v[i] = i <= n ? a[i] : v[i - n];
	vi inc = calc(v);
//	for (int i = 1; i <= nn; i++)
//		printf("%d ", v[i]);
//	puts("");
//	for (int i = 1; i <= nn; i++)
//		printf("%d ", inc[i]);
//	puts("");
	for (int i = 1; i <= nn; i++)
		v[i] = 350 - v[i];
	reverse(v.begin() + 1, v.end());
	vi dec = calc(v);
	reverse(v.begin() + 1, v.end());
	reverse(dec.begin() + 1, dec.end());
//	for (int i = 1; i <= nn; i++)
//		printf("%d ", v[i]);
//	puts("");
//	for (int i = 1; i <= nn; i++)
//		printf("%d ", dec[i]);
//	puts("");
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++)
			cnt += a[i] == a[j];
		for (int j = 1; j <= n; j++) {
			if (a[i] > a[j])
				continue;
			umax(ans, inc[(n - 1) * n + i] + cnt * (T - 2 * n) + dec[j]);
		}
	}
	printf("%d\n", ans);
}
