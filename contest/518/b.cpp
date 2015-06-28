
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define maxn int(2e5 + 12)
#define inf int(1e9 + 7)
#define linf ll(1e18 + 12)
#define eps 1e-7
#define mp make_pair
#define pb push_back
#define F first
#define S second

const int sz = 'z' + 'a' + 1;

char s[maxn], t[maxn], us[maxn];
int cnt[300];
int a, b, n, m;

char ch(char x)
{
	if ('a' <= x && x <= 'z')
		return x - 'a' + 'A';
	return x - 'A' + 'a';

}

int main()
{
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	scanf("%s\n%s", s, t);
	n = strlen(s);
	m = strlen(t);
	for (int i = 0; i < m; i++)
		cnt[t[i]]++;
	
	for (int i = 0; i < n; i++)
	{
		if (cnt[s[i]] == 0)
			continue;
		cnt[s[i]]--;
		a++;
		us[i] = 1;
	}
	for (int i = 0; i < n; i++)
	{
		if (us[i] || cnt[ch(s[i])] == 0)
			continue;
		cnt[ch(s[i])]--;
		b++;
	}
	printf("%d %d", a, b);
}
