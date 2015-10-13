
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
//#define fn ""

int T, n, k;
char s[3][110];
int dp[3][110];

bool can(int i, int j)
{
	for (int k = 0; k < 3; k++)
		if (s[i][j + k] != '.')
			return 0;
	return 1;
}

bool rec(int i, int j)
{
	if (j >= n - 1)
		return true;
	if (dp[i][j] != -1)
		return dp[i][j];
	int & ans = dp[i][j] = 0;
	//printf("%d %d %c %c\n", i, j, s[i][j], s[i][j + 1]);
	if (s[i][j + 1] != '.')
		return ans = false;
	for (int k = max(0, i - 1); k <= min(2, i + 1); k++)
		if (can(k, j + 1) && rec(k, j + 3))
			return ans = true;
	return false;
}

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &k);
		memset(dp, -1, sizeof(dp));
		for (int i = 0; i < 3; i++)
			scanf("%s", s[i]);
		bool ok = 0;
		
		//int k = 0;
		for (int i = 0; i < 3; i++)
			if (s[i][0] == 's')
				ok = rec(i, 0);
		/*
		for (int i = max(0, k - 1); i <= min(2, k + 1); i++)
			ok |= rec(i, 1);
		
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < n; j++)
				printf("%d ", dp[i][j] > 0 ? dp[i][j] : 0);
			puts("");
		}
		*/
		puts(ok ? "YES" : "NO");
	}
}
