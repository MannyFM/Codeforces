
#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair

string s, u;
int n, m;

int get(string now)
{
	int ans = 0;
	for (int i = 0; i < m; i++)
		ans += now[i] != u[i] || i >= int(now.size());
	return ans;
}

int main()
{
	cin >> s >> u;
	
	for (int i = 0; i < 2000; i++)
		s = '#' + s;
	for (int i = 0; i < 2000; i++)
		s = s + '#';
	
	n = int(s.size()), m = int(u.size());
	int ans = m;
	for (int i = 0; i <= n - m; i++)
		ans = min(ans, get(s.substr(i, m)));
	printf("%d", ans);
}