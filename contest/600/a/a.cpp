
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

string s, cur;
char buf[maxn];
int pos, n;
vector <string> a, b;

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	gets(buf);
	s = string(buf);
	if (s.back() == ';' || s.back() == ',')
		s.pb(s.back());
	n = int(s.length());
	while (pos < n)
	{
		bool f1 = 0, f2 = 0;
		cur = "";
		while (pos < n && s[pos] != ',' && s[pos] != ';')
		{
			if (('a' <= s[pos] && s[pos] <= 'z') || ('A' <= s[pos] && s[pos] <= 'Z'))
				f1 = 1;
			if (s[pos] == '.')
				f2 = 1;
			cur.pb(s[pos++]);
		}
		pos++;
		if (cur.empty() || (cur[0] == '0' && cur.size() > 1) || f1 || f2)
			b.pb(cur);
		else
			a.pb(cur);
	}
	if (a.empty())
		puts("-");
	else
	{
		putchar(34);
		for (size_t i = 0; i < a.size(); i++)
		{
			printf("%s", a[i].c_str());
			if (i + 1 != a.size())
				putchar(44);
		}
		printf("%c\n", 34);
	}
	if (b.empty())
		puts("-");
	else
	{
		putchar(34);
		for (size_t i = 0; i < b.size(); i++)
		{
			printf("%s", b[i].c_str());
			if (i + 1 != b.size())
				putchar(44);
		}
		printf("%c\n", 34);
	}
}
