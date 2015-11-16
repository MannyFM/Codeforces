
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
#define fn "rebus"

string ans, s, cur;

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	while (cin >> s)
	{
		int i = 0;
		while (i < int(s.length()) && s[i] == 39)
			i++;
		int j = int(s.length()) - 1, cnt = 0;
		while (j >= 0 && s[j] == 39)
			j--, cnt++;
		for (int k = i + i ; k + cnt + cnt < int(s.length()); k++)
			putchar(s[k]);
		//putchar(' ');
	}
}
