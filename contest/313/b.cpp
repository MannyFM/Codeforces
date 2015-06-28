
#include <bits/stdc++.h>

using namespace std;

#define maxn (int)(1e5 + 12)

int a[maxn], b[maxn], l, r, n, m;
string s;

int main()
{
	cin >> s;
	n = (int)(s.size());
	for (int i = 0; i < n - 1; i++)
		a[i] = (s[i] == s[i + 1]);
	for (int i = 0; i < n; i++)
		b[i] = b[i - 1] + a[i];
	
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> l >> r;
		l--, r -= 2;
		cout << b[r] - b[l - 1] << '\n';
	}
}