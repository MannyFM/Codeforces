
#include <bits/stdc++.h>

using namespace std;

int cnt[10];
int a[5][5];

int main()
{
	char _char;
	int k;
	cin >> k;
	for (int i = 0; i < 4; i++)
	for (int j = 0; j < 4; j++)
	{
		cin >> _char;
		if (_char != '.')
		{
			a[i][j] = _char - '0';
			cnt[a[i][j]]++;
		}
	}
	int ok = 1;
	for (int i = 1; i < 10; i++)
		if (cnt[i] > 2 * k)
			ok = 0;
	puts(ok ? "YES" : "NO");
}
