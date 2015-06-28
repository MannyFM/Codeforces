
#include <bits/stdc++.h>

using namespace std;

string get(int x)
{
	string ans = "";
	if (x < 5)
		ans = "O-|";
	else
		ans = "-O|";
	if (x >= 5)
		x -= 5;
	for (int i = 0; i < x; i++)
		ans += 'O';
	ans += '-';
	for (int i = x; i < 4; i++)
		ans += 'O';
	return ans;
}

int n;
vector <string> v;

int main()
{
	scanf("%d", &n);
	if (n == 0)
		v.push_back(get(0));
	while (n > 0)
	{
		v.push_back(get(n % 10));
		n /= 10;
	}
	for (auto i : v)
		cout << i << '\n';
}