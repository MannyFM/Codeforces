
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
#define fn "oddoreven"

bool ok, x, y;

bool F(char s)
{
	if (s == 'x')
		return x;
	if (s == 'y')
		return y;
	return (s - '0') & 1;
}

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	string s, t;
	cin >> s;
	cin >> t, x = t[0] == 'O';
	cin >> t, y = t[0] == 'O';
	//cout << x << " " << y << '\n';
	s.pb('+');
	char T = '0';
	int n = int(s.length());
	vector <char> bol, op;
	for (int i = 0; i < n; i++)
		if (s[i] == '+' || s[i] == '-' || s[i] == '*')
			bol.pb(F(T)), op.pb(s[i]);
		else
			T = s[i];
	for (int i = 0; i < int(bol.size()); i++)
	{
		//cerr << i << " ";
		bool cur = bol[i];
		while (i < int(bol.size()) && op[i] == '*')
			cur &= bol[++i];
		ok ^= cur;
	}
	puts(ok ? "Odd" : "Even");
}
