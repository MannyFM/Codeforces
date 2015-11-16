
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
#define fn "tiv"

int n;
int a[11], N[11];
char s[11][11];

bool check()
{
	for (int i = 1; i < n; i++)
	{
		if (!a[s[i - 1][0] - 'a'])
			return 0;
		if (N[i - 1] < N[i])
			continue;
		if (N[i - 1] > N[i])
			return 0;
		bool ok = 1;
		for (int j = 0; j < N[i] - 1; j++)
		{
			if (a[s[i - 1][j] - 'a'] < a[s[i][j] - 'a'])
			{
				ok = 0;
				break;
			}
			if (a[s[i - 1][j] - 'a'] > a[s[i][j] - 'a'])
				return 0;
		}
		if (ok && a[s[i - 1][N[i - 1] - 1] - 'a'] >= a[s[i][N[i] - 1] - 'a'])
			return 0;
	}
	return 1;
}

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", s[i]);
		N[i] = strlen(s[i]);
	}
	for (int i = 1; i < n; i++)
		if (N[i - 1] > N[i])
		{
			puts("No");
			return 0;
		}
	for (int i = 0; i < 10; i++)
		a[i] = i;
	do
	{
		if (check())
		{
			puts("Yes");
			for (int i = 0; i < 10; i++)
				printf("%d ", a[i]);
			return 0;
		}
	} while (next_permutation(a, a + 10));
	puts("No");
}
