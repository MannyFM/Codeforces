
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = int(3e5 + 12);
int const maxb = int(3e5 + 12);
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
#define CNT {printf("%d\n", cnt); continue;}

int n, m;
char s[maxn];
int cnt;

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d %s ", &n, &m, (s + 1));
	for (int i = 2; i <= n; i++)
		if (s[i] == '.' && s[i - 1] == '.')
			cnt++;
	for (int i = 0; i < m; i++)
	{
		int x;
		char c;
		scanf("%d %c", &x, &c);
		if (s[x] == c)
			CNT;
		if (c == '.')
		{
			if (s[x - 1] == '.')
				cnt++;
			if (s[x + 1] == '.')
				cnt++;
		}
		else
		{
			if (s[x] != '.')
				CNT;
			if (s[x - 1] == '.')
				cnt--;
			if (s[x + 1] == '.')
				cnt--;
		}
		s[x] = c;
		CNT;
	}
}
