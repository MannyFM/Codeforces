
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

char s[maxb];
int n;
int cnt[4];
string t = "({[<)}]>";

int type(char x)
{
	return t.find(x);
}

int st[maxb], h;

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%s", s + 1);
	n = strlen(s + 1);
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int x = type(s[i]);
		if (x < 4)
			st[h++] = x;
		else
		{
			x -= 4;
			if (!h)
			{
				puts("Impossible");
				return 0;
			}
			ans += st[h - 1] != x;
			h--;
		}
	}
	if (h)
		puts("Impossible");
	else
		printf("%d", ans);
}

