
#include <bits/stdc++.h>

using namespace std;

string a, b = "nineteen";
int cnt[2][300], now = 1000;

int main()
{
	cin >> a;
	for (int i = 0; i < int(a.size()); i++)
		cnt[0][int(a[i])]++;
	for (int i = 0; i < int(b.size()); i++)
		cnt[1][int(b[i])]++;
	if (cnt[0][int('n')])
		cnt[0][int('n')]--;
	if (cnt[1][int('n')])
		cnt[1][int('n')]--;
	for (int i = 0; i < int(b.size()); i++)
	{
		now = min(now, cnt[0][int(b[i])] / cnt[1][int(b[i])]);
	}
	printf("%d", now);
}