
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

vector <int> kmp(const string & s)
{
	vector <int> p(s.length());
	for (int i = 1; i < (int)p.size(); i++)
	{
		int j = p[i - 1];
		while (j && s[j] != s[i])
			j = p[j - 1];
		if (s[j] == s[i])
			j++;
		p[i] = j++;
	}
	puts(s.c_str());
	for (int i : v)
		printf("%d ", i);
	return p;
}

char s[maxn], t[maxn];
int p[maxn], n, m;

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%s\n%s", s, t);
	auto v = kmp(string(s) + "#" + string(t));
}

