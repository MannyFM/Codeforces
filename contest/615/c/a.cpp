
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = 2150;
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

template <typename T>
bool umax(T & a, T b)
{
	return a < b ? (a = b, 1) : 0;
}

template <typename T>
bool umin(T & a, T b)
{
	return a > b ? (a = b, 1) : 0;
}

char s[maxn], t[maxn], r[maxn];
int dp[maxn], n, m;
int pre[maxn][maxn], pr[maxn][maxn];
int mx[maxn], from[2][maxn];
pii wh[maxn];
string S;

vector <pii> ans;

bool rec(int i)
{
	if (i == m + 1)
		return 1;
	for (int x = mx[i]; x > 0; x--)
		if (rec(i + mx[i]))
		{
			//printf("i:%d f0:%d f1:%d m%d\n", i, from[0][i], from[1][i], mx[i]);
			if (from[0][i])
				ans.pb(mp(from[0][i], from[0][i] + mx[i] - 1));
			else
				ans.pb(mp(from[1][i], from[1][i] - mx[i] + 1));
			return 1;
		}
	return 0;
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%s\n%s", s + 1, t + 1);	
	n = strlen(s + 1), m = strlen(t + 1);
	dp[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		pre[i][m] = s[i] == t[m];
		r[i] = s[i];
	}
	reverse(r + 1, r + 1 + n);
	//puts(r + 1);
	for (int i = 1; i <= n; i++)
		pr[i][m] = r[i] == t[m];
	for (int i = 1; i <= m; i++)
	{
		pre[n][i] = s[n] == t[i];
		pr[n][i] = r[n] == t[i];
	}
	for (int i = n - 1; i > 0; i--)
		for (int j = m - 1; j > 0; j--)
			pre[i][j] = s[i] == t[j] ? pre[i + 1][j + 1] + 1 : 0;
	for (int i = n - 1; i > 0; i--)
		for (int j = m - 1; j > 0; j--)
			pr[i][j] = r[i] == t[j] ? pr[i + 1][j + 1] + 1 : 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (umax(mx[j], pre[i][j]))
				from[0][j] = i;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			if (umax(mx[j], pr[i][j]))
			{
				from[0][j] = 0;
				from[1][j] = n - i + 1;
				//printf("!%d", from[1][j]);
			}
		//	if (pr[i][j])
		//		printf("pr[%d][%d]=%d\n", i, j, pr[i][j]);
		}
	if (!mx[1] || !rec(1))
	{
		puts("-1");
		return 0;
	}
	reverse(all(ans));
	printf("%d\n", (int)ans.size());
	for (pii x : ans)
		printf("%d %d\n", x.F, x.S);
}

