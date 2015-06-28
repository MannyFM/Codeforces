
#include <bits/stdc++.h>

using namespace std;

string a, b;

int delta;

string get(string a)
{
	string b;
	for (int i = 0; i < int(a.size()); i++)
	{
		b.push_back((a[i] - delta + 256) % 256);
	}
	return b;
}

int main()
{
	while (getline(cin, a))
	{
		delta = 7;
		cout << get(a) << '\n';
	}
}

