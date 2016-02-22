
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = int(1e6 + 12);
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

char s[maxn];
int n;
stack <char> st;

string o = "({[<", c = ")}]>";

bool isPair(char a, char b)
{
	return (o.find(a) == c.find(b));
}

#define NO {puts("Impossible"); return 0;}
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
		if (s[i] == '(' || s[i] == '[' || s[i] == '{' || s[i] == '<')
			st.push(s[i]);
		else
		{
			if (st.empty())
				NO;
			if (!isPair(st.top(), s[i]))
				ans++;
			st.pop();
		}
	}
	if (!st.empty())
		NO;
	printf("%d", ans);
}

