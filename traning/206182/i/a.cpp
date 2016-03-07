
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

char s[maxn];
int n, pr[maxn];
int a[maxn];
stack <int> st;

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for (int i = 1; i <= n; i++)
	{
		if (s[i] == '(' || s[i] == '[')
			st.push(i);
		if (s[i] == ')')
		{
			if (!st.empty() && s[st.top()] == '(')
			{
				pr[i] = st.top(), st.pop();
				pr[pr[i]] = i;
			}
			else
			{
				while (!st.empty())
					pr[st.top()] = -1, st.pop();
				pr[i] = -1;
			}
		}
		if (s[i] == ']')
		{
			if (!st.empty() && s[st.top()] == '[')
			{
				pr[i] = st.top(), st.pop();
				pr[pr[i]] = i;
			}
			else
			{
				while (!st.empty())
					pr[st.top()] = -1, st.pop();
				pr[i] = -1;
			}
		}
	}
	while (!st.empty())
		pr[st.top()] = -1, st.pop();
//	for (int i = 1; i <= n; i++)
//		printf("%d ", pr[i]);
//	puts("");
	for (int i = 1; i <= n; i++)
		a[i] = a[i - 1] + (s[i] == '[');
	int L = 0, R = -1, l = -1, r = -1, ans = 0;
	for (int i = 1; i <= n;)
	{
		if (pr[i] == -1)
		{
			if (l != -1 && umax(ans, a[r] - a[l - 1]))
				L = l, R = r;
			l = -1, r = -1;
			i++;
		}
		else
		{
			if (l == -1)
				l = i;
			r = pr[i];
			i = pr[i] + 1;
		}
	}
	if (l != -1 && umax(ans, a[r] - a[l - 1]))
		L = l, R = r;
	printf("%d\n", ans);
	for (int i = L; i <= R; i++)
		putchar(s[i]);
}

