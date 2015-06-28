
#include <bits/stdc++.h>

using namespace std;

int cnt[10], n, a;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a), cnt[a]++;
	int fl = 0;
	string s = "";
	for (int i = 0; i < cnt[5] / 9; i++)
		s += "555555555";
	if (!cnt[0])
	{
		puts("-1");
		return 0;
	}
	if (s.empty())
	{
		puts("0");
		return 0;
	}
	for (int i = 0; i < cnt[0]; i++)
		s += '0';
	cout << s;
}