
#include <bits/stdc++.h>

using namespace std;

#define maxn (int)(1e6 + 123)
#define inf (int)(1e9 + 7)

int c[maxn], a, b, n;
int dex[20], suf[maxn], pre[maxn];
string s;

int main()
{
	cin >> s >> a >> b;
	n = (int)(s.size());
	for (int i = 1; i <= n; i++)
		c[i] = (int)(s[i - 1] - '0');
	for (int i = 1; i <= n; i++)
	{
		pre[i] = (pre[i - 1] * 10 + c[i]) % a;
	}
	int p = 1;
	for (int i = n; i > 0; i--)
	{
		suf[i - 1] = (suf[i] + c[i] * p) % b;
		p = (p * 10) % b;
	}
	for (int i = 1; i < n; i++)
	{
		if (!pre[i] && !suf[i] && (c[i + 1] != 0))
		{
			cout << "YES\n" << s.substr(0, i) << '\n' << s.substr(i, ((int)(s.size() - i)));
			return 0;
		}
	}
	puts("NO");
}