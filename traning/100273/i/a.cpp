//
// Created by Manny, Alibek Manabayev
// Alibek.manabayev@gmail.com, Alibek.manabayev@nu.edu.kz
// Copyright 2016 A-3. All rights reserved.
//   ________                                             __  ___                       
//  /_  __/ /_  ___  ________     _      ______ ______   /  |/  /___ _____  ____  __  __
//   / / / __ \/ _ \/ ___/ _ \   | | /| / / __ `/ ___/  / /|_/ / __ `/ __ \/ __ \/ / / /
//  / / / / / /  __/ /  /  __/   | |/ |/ / /_/ (__  )  / /  / / /_/ / / / / / / / /_/ / 
// /_/ /_/ /_/\___/_/   \___/    |__/|__/\__,_/____/  /_/  /_/\__,_/_/ /_/_/ /_/\__, /  
//                                                                             /____/   

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef map<int, int> mii;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int const maxn = int(1e5 + 12);
int const maxlen = int(2e6 + 12);
int const inf = int(1e9 + 7);
ll const linf = ll(1e18 + 12);
ld const eps = 1e-7;
ld const pi = 3.1415926535897932384626433832795l;

#ifdef _WIN32
#define I64 "%I64d"
#else
#define I64 "%lld"
#endif
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define next MyLittleNext
//#define end MyLittleEnd
#define all(x) x.begin(), x.end()
#define x1 MyLittleX1
#define y1 MyLittleY1
#define x2 MyLittleX2
#define y2 MyLittleY2
#define rt(x)                                                                  \
  {                                                                            \
    puts(x);                                                                   \
    exit(0);                                                                   \
  }
#define fn "i18n"

template <typename T> bool umax(T &a, T b) { return a < b ? (a = b, 1) : 0; }

template <typename T> bool umin(T &a, T b) { return a > b ? (a = b, 1) : 0; }

typedef pair <pair <char, char>, int> abr;

abr f(const string & s) {
	int F = s[0];
	int S = s.back();
	if ('A' <= F && F <= 'Z')
		F = 'a' + (F - 'A');
	if ('A' <= S && S <= 'Z')
		S = 'a' + (S - 'A');
	return {{F, S}, (int)s.length() - 2};
}

map <abr, string> id;

string itoa(int x) {
	string str = "";
	while (x > 0) {
		str += (x % 10) + '0';
		x /= 10;
	}
	reverse(all(str));
	return str;
}

void add(const string & s) {
	auto pt = f(s);
	if (id.count(pt) && id[pt] != s)
		id[pt] = pt.F.F + itoa(pt.S) + pt.F.S;
	else
		id[pt] = s;
}

void get(string str) {
	if (str.length() < 3 || !('0' <= str[1] && str[1] <= '9')) {
		add(str);
		cout << str;
		return;
	}
	int x = 0;
	for (int i = 1; i + 1 < (int)str.length(); i++)
		x = x * 10 + (str[i] - '0');
	char F = str[0];
	char S = str.back();
	bool ff = false, ss = false;
	if ('A' <= F && F <= 'Z') {
		ff = true;
		F = 'a' + (F - 'A');
	}
	if ('A' <= S && S <= 'Z') {
		ss = true;
		S = 'a' + (S - 'A');
	}
	abr pt = {{F, S}, x};
	string ans = "";
	string out = "";
	if (id.count(pt))
		ans = id[pt];
	else
		ans = str;
	if (ff)
		out += toupper(ans[0]);
	else
		out += tolower(ans[0]);
	for (int i = 1; i < (int)ans.size(); i++)
		if (ss)
			out += toupper(ans[i]);
		else
			out += tolower(ans[i]);
	cout << out;
}

bool cor(char x) {
	return ('a' <= x && x <= 'z') || ('A' <= x && x <= 'Z') || ('0' <= x && x <= '9');
}

int main() {
#ifdef fn
  freopen(fn ".in", "r", stdin);
  freopen(fn ".out", "w", stdout);
#endif
	string buf = "";
	char c;
	while (scanf("%c", &c) == 1) {
		if (cor(c))
			buf += c;
		else {
			if (buf != "")
				get(buf);
			buf = "";
			printf("%c", c);
		}
	}
}
