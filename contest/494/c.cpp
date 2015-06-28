
#include <bits/stdc++.h>

using namespace std;

#define maxn (int)(1e5 + 7)
#define inf (int)(1e9 + 7)
#define pb push_back
#define ll long long
#define f first
#define s second
#define mp make_pair

string s;
int n, cnt, sharp, last, ans[maxn];

int main()
{
	cin >> s;
	n = (int)(s.size());
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '(')
			cnt++;
		if (s[i] == ')')
			cnt--;
		if (s[i] == '#')
		{
			sharp++;
			cnt--;
			ans[i] = 1;
			last = i;
		}
		if (cnt < 0)
		{
			puts("-1");
			return 0;
		}
	}
	ans[last] += cnt;
	if (cnt < 0)
	{
		puts("-1");
		return 0;
	}
	int pts = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '(')
			pts++;
		if (s[i] == ')')
			pts--;
		if (s[i] == '#')
		{
			pts -= ans[i];
		}
		if (pts < 0)
		{
			puts("-1");
			return 0;
		}
	}
	if (pts < 0)
	{
		puts("-1");
		return 0;
	}
	for (int i = 0; i < n; i++)
		if (s[i] == '#')
			printf("%d\n", ans[i]);
}