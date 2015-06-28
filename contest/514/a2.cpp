#include <bits/stdc++.h>

using namespace std;

string a, b;

int main()
{
	cin >> a;
	for (int i = 0; i < int(a.size()); i++)
	{
		if (a[i] == '9' && !i)
			b.push_back('9');
		else
		{
			int t = a[i] - '0';
			t = min(t, 9 - t);
			b.push_back('0' + t);
		}

	}
	cout << b;
	return 0;
}