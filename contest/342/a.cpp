
#include <bits/stdc++.h>

using namespace std;

int n, cnt[8];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int _int;
		scanf("%d", &_int);
		cnt[_int]++;
		if (_int == 5 || _int == 7)
		{
			puts("-1");
			return 0;
		}
	}
	vector <string> s;
	for (int i = 1; i <= n / 3; i++)
	{
		if (cnt[1] && cnt[2] && cnt[4])
		{
			s.push_back("1 2 4");
			cnt[1]--, cnt[2]--, cnt[4]--;
			continue;
		}
		if (cnt[1] && cnt[2] && cnt[6])
		{
			s.push_back("1 2 6");
			cnt[1]--, cnt[2]--, cnt[6]--;
			continue;
		}
		if (cnt[1] && cnt[3] && cnt[6])
		{
			s.push_back("1 3 6");
			cnt[1]--, cnt[3]--, cnt[6]--;
			continue;
		}
		puts("-1");
		return 0;
	}
	for (int i = 0; i < n / 3; i++)
		cout << s[i] << '\n';
}