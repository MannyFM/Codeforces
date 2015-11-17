
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
//#define fn

char s[maxn];
int n, p[maxn];

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%s", s);
	n = strlen(s);
	for (int i = 1; i < n; i++)
	{
		int j = p[i - 1];
		while (j > 0 && s[j] != s[i])
			j = p[j - 1];
		if (s[i] == s[j])
			j++;
		p[i] = j;
	}
	
	for (int i = 0; i < n; i++)
		printf("%d ", p[i]);
	puts("");
	
	for (int len = 1; len <= n; len++)
	{
		if (n % len)
			continue;
		
		printf("%d: ", len);
		for (int i = len - 1; i < n; i += len)
			printf("%d ", p[i]);
		puts("");
		
		bool ok = 1;
		for (int i = 2 * len - 1; i < n; i += len)
			if (p[i] != p[i - len] + len)
			{
				ok = 0;
				break;
			}
		if (ok)
		{
			printf("%d", len);
			return 0;
		}
	}
	printf("%d", n);
}
