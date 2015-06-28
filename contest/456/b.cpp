
#include <bits/stdc++.h>

using namespace std;

typedef vector <int> big;
const int base = (int)(1e9);

big read()
{
	big a;
	string input;
	cin >> input;
	int n = (int)(input.size());
	for (int i = n; i > 0; i -= 9)
	{
		if (i < 9)
			a.push_back(atoi(input.substr(0, i).c_str()));
		else
			a.push_back(atoi(input.substr(i - 9, 9).c_str()));
	}
	return a;
}	

pair <big, int> divide(big a, int b)
{
	int carry = 0;
	for (int i = (int)(a.size()) - 1; i >= 0; i--)
	{
		long long cur = a[i] + carry * 1ll * base;
		a[i] = int(cur / b);
		carry = int(cur % b);
	}
	while (a.size() > 1 && a.back() == 0)
		a.pop_back();
	return make_pair(a, carry);
}

int mod(big a, int b)
{
	auto ans = divide(a, b);
	return ans.second;
}

void output(big a)
{
	printf("%d", a.empty() ? 0 : a.back());
	for (int i = (int)(a.size()) - 2; i >= 0; i--)
		printf("%09d", a[i]);
}

int f[] = {0, 1, 1, 1, 1};

int main()
{
	big a = read();
	int k = mod(a, 4);
	for (int i = 0; i < k; i++)
		for (int j = 1; j <= 4; j++)
			f[j] = (f[j] * j) % 5;
	for (int i = 1; i <= 4; i++)
		f[0] = (f[0] + f[i]) % 5;
	printf("%d", f[0]);
}