
#include <bits/stdc++.h>

using namespace std;

int k, pts, w[30];
string s;
long long ans = 0;

int main()
{
	cin >> s >> k;
	int n = (int)s.length();
	for (int i = 0; i < 26; i++)
		cin >> w[i], pts = max(pts, w[i]);
	for (int i = 1; i <= n; i++)
		ans += w[s[i - 1] - 'a'] * i;
	for (int i = n + 1; i <= n + k; i++)
		ans += pts * (i);
	printf("%I64d", ans);
}
