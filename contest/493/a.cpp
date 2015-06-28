
#include <bits/stdc++.h>

using namespace std;

struct item
{
	int team;
	int time;
	int number;
	item(int team, int time, int number) : team(team), time(time), number(number) {};
};

string teams[2];
map <int, int> m[2];
int n;
vector <item> v;

int main()
{
	cin >> teams[0] >> teams[1];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int t, nu, team;
		char te, card;
		cin >> t >> te >> nu >> card;
		team = (te == 'a');
		if (m[team][nu] == 2)
			continue;
		if (card == 'r')
		{
			m[team][nu] = 2;
			item now = item(team, t, nu);
			v.push_back(now);
		}
		if (card == 'y')
		{
			m[team][nu]++;
			if (m[team][nu] == 2)
			{
				m[team][nu] = 2;
				item now = item(team, t, nu);
				v.push_back(now);
			}
		}
	}
	for (auto i : v)
	{
		cout << teams[i.team] << " " << i.number << " " << i.time << '\n';
	}
}