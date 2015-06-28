
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <char, int> pii;
typedef pair <ll, ll> pll;

#define maxn int(2e5 + 12)
#define maxb int(2e6 + 12)
#define inf int(1e9 + 7)
#define linf ll(1e18 + 12)
#define eps 1e-7
#define mp make_pair
#define pb push_back
//#define fn "a"
#define F first
#define S second

char s[maxn];
int n;
stack <char> st, ans;

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%s", s);
	n = int(strlen(s));
	for (int i = 0; i < n; i++)
		if (st.empty() || st.top() != s[i])
			st.push(s[i]);
		else
			st.pop();
	while (!st.empty())
	{
		ans.push(st.top());
		st.pop();
	}
	while (!ans.empty())
	{
		putchar(ans.top());
		ans.pop();
	}
}