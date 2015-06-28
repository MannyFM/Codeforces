
#include <bits/stdc++.h>

using namespace std;

int n, k, a[30];
string s, out;

int main()
{
	cin >> k >> s;
	n = (int)(s.size());
	if (n % k != 0)
	{
		printf("-1");
		return 0;
	}
	for (int i = 0; i < n; i++)
		a[(int)(s[i] - 'a')]++;
	for (int i = 0; i < 26; i++)
		if (a[i] % k == 0)
		{
			for (int j = 0; j < a[i] / k; j++)
				out += (char)(i + 'a');
		}
		else
		{
			puts("-1");
			return 0;
		}
	for (int i = 0; i < k; i++)
		cout << out;
}