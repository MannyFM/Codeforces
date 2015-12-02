
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = int(3e5 + 12);
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
#define fn "numbers"

int n, m, k;
char _S[15];

map <int, set <int> > dic;

string s;

int i, g, op;

bool get3()
{
	if (i == int(s.size()) || s[i] == '0')
		return 1;
	s = s.substr(i, s.size());
	if (s.size() < 3 || s.size() > 7)
		return 1;
	//printf("%d:%s\n", s.size(), s.c_str());
	printf("+%d(%d)", g, op);
	if (s.size() == 3)
	{
		printf("%03d", (s[0] - '0') * 100 + (s[1] - '0') * 10 + (s[2] - '0'));
	}
	if (s.size() == 4)
	{
		printf("%02d-", (s[0] - '0') * 10 + s[1] - '0');
		printf("%02d", (s[2] - '0') * 10 + s[3] - '0');
	}
	if (s.size() == 5)
	{
		printf("%03d-", (s[0] - '0') * 100 + (s[1] - '0') * 10 + (s[2] - '0'));
		printf("%02d", (s[3] - '0') * 10 + s[4] - '0');
	}
	if (s.size() == 6)
	{
		printf("%02d-", (s[0] - '0') * 10 + s[1] - '0');
		printf("%02d-", (s[2] - '0') * 10 + s[3] - '0');
		printf("%02d", (s[4] - '0') * 10 + s[5] - '0');
	}
	if (s.size() == 7)
	{
		printf("%03d-", (s[0] - '0') * 100 + (s[1] - '0') * 10 + (s[2] - '0'));
		printf("%02d-", (s[3] - '0') * 10 + s[4] - '0');
		printf("%02d", (s[5] - '0') * 10 + s[6] - '0');
	}
	return 0;
}

bool get2()
{
	if (i == int(s.size()) || s[i] == '0')
		return 1;
	set <int> & se = dic[g];
	op = 0;
	for (; i < int(s.size()); i++)
	{
		op = op * 10 + s[i] - '0';
		if (se.count(op))
		{
			int was = i++;
			if (!get3())
				return 0;
			i = was;
		}
	}
	return 1;
}

bool get()
{
	scanf("%s", _S);
	s = string(_S);
	i = g = 0;
	if (s[0] == '0')
		return 1;
	for (; i < int(s.size()); i++)
	{
		g = g * 10 + s[i] - '0';
		if (dic.count(g))
		{
			int was = i++;
			if (!get2())
				return 0;
			i = was;
		}
	}
	return 1;
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int g, op;
		set <int> se;
		scanf("%d%d", &g, &m);
		for (int i = 1; i <= m; i++)
		{
			scanf("%d", &op);
			se.insert(op);
		}
		dic[g] = se;
	}
	scanf("%d", &k);
	for (int i = 1; i <= k; i++)
	{
		if (get())
		{
			puts("Incorrect");
			continue;
		}
		puts("");
	}
}
