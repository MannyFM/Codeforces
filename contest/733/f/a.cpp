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

int const maxn = int(2e5 + 12);
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
#define rank MyLittleRank
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
//#define fn ""

template <typename T> bool umax(T &a, T b) { return a < b ? (a = b, 1) : 0; }

template <typename T> bool umin(T &a, T b) { return a > b ? (a = b, 1) : 0; }

struct edge {
	int a, b, id;
};

int n, m;
int w[maxn], c[maxn];
bool is[maxn];
vector <edge> E;
vector <pii> g[maxn];
int boss[maxn], rank[maxn];

int who(int x) {
	if (x == boss[x])
		return x;
	return boss[x] = who(boss[x]);
}

bool merge(int x, int y) {
	x = who(x);
	y = who(y);
	if (x == y)
		return 0;
	if (rank[x] > rank[y])
		swap(x, y);
	boss[x] = y;
	if (rank[x] == rank[y])
		rank[y]++;
	return 1;
}

bool cmp(const edge & a, const edge & b) {
	return w[a.id] < w[b.id];
}

const int mx_k = 20;
int pr[mx_k][maxn];
int mx[mx_k][maxn];
int lvl[maxn];

void dfs(int v, int p = -1) {
	for (int k = 1; k < mx_k; k++) {
		pr[k][v] = pr[k - 1][pr[k - 1][v]];
		mx[k][v] = max(mx[k - 1][v], mx[k - 1][pr[k - 1][v]]);
	}
	for (pii x : g[v]) {
		if (x.F == p)
			continue;
		mx[0][x.F] = x.S;
		pr[0][x.F] = x.F;
		lvl[x.F] = lvl[v] + 1;
		dfs(x.F, v);
	}
}

int lca(int v, int u) {
	if (lvl[v] < lvl[u])
		swap(v, u);
	int ans = -inf;
	for (int k = mx_k - 1; k >= 0; k--) 
		if (lvl[pr[k][v]] >= lvl[u]) {
			umax(ans, mx[k][v]);
			v = pr[k][v];
		}
	for (int k = mx_k - 1; k >= 0; k--)
		if (pr[k][v] != pr[k][u]) {
			umax(ans, mx[k][v]);
			umax(ans, mx[k][u]);
			v = pr[k][v];
			u = pr[k][u];
		}
	if (v == u)
		return ans;
	umax(ans, mx[0][v]);
	umax(ans, mx[0][u]);
	return ans;
}

int main() {
#ifdef fn
  freopen(fn ".in", "r", stdin);
  freopen(fn ".out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		boss[i] = i;
	for (int i = 1; i <= m; i++)
		scanf("%d", w + i);
	for (int i = 1; i <= m; i++)
		scanf("%d", c + i);
	int S;
	for (int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		E.pb({x, y, i});
	}
	scanf("%d", &S);
	sort(E.begin(), E.end(), cmp);
	ll all = 0;
	for (edge e : E) {
		if (merge(e.a, e.b)) {
			all += w[e.id];
			is[e.id] = 1;
			g[e.a].pb({e.b, w[e.id]});
			g[e.b].pb({e.a, w[e.id]});
//			printf("%d->%d %d\n", e.a, e.b, e.id);
		}
	}
	int root = 1;
	for (int k = 0; k < 19; k++)
		for (int i = 1; i <= n; i++) {
			pr[k][i] = root;
			mx[k][i] = -inf;
		}
	dfs(root);
	ll ans = all;
	int j = -1;
	int x = -1, y = -1;
	for (edge e : E) {
		ll now = all;
		if (is[e.id]) {
			now = all - (S / c[e.id]);
		} else {
			int L = lca(e.a, e.b);
			now = all - L + w[e.id] - (S / c[e.id]);
		}
//		printf("%d <-> %d = %d\n", e.a, e.b, now);
		if (umin(ans, now)) {
			j = e.id;
			x = e.a;
			y = e.b;
		}
	}
	printf(I64 "\n", ans);
	if (j == -1) {
		for (edge e : E)
			if (is[e.id])
				printf("%d %d\n", e.id, w[e.id]);
		return 0;
	}
	memset(is, 0, sizeof(is));
	for (int i = 1; i <= n; i++)
		rank[i] = 0, boss[i] = i;
	printf("%d %d\n", j, w[j] - (S / c[j]));
	merge(x, y);
	for (edge e : E) {
		if (merge(e.a, e.b))
			printf("%d %d\n", e.id, w[e.id]);
	}
}


times in msec
 clock   self+sourced   self:  sourced script
 clock   elapsed:              other lines

000.013  000.013: --- VIM STARTING ---
000.115  000.102: Allocated generic buffers
000.275  000.160: locale set
000.279  000.004: clipboard setup
000.291  000.012: window checked
013.570  013.279: inits 1
013.579  000.009: parsing arguments
013.581  000.002: expanding arguments
016.750  003.169: shell init
017.267  000.517: Termcap init
017.291  000.024: inits 2
017.438  000.147: init highlight
018.356  000.463  000.463: sourcing /Users/manny/.vim/autoload/pathogen.vim
020.806  000.218  000.218: sourcing /usr/local/share/vim/vim74/syntax/syncolor.vim
020.925  000.447  000.229: sourcing /usr/local/share/vim/vim74/syntax/synload.vim
044.167  000.099  000.099: sourcing /Users/manny/.vim/bundle/swift/ftdetect/swift.vim
044.400  023.375  023.276: sourcing /usr/local/share/vim/vim74/filetype.vim
044.459  024.093  000.271: sourcing /usr/local/share/vim/vim74/syntax/syntax.vim
044.588  000.017  000.017: sourcing /usr/local/share/vim/vim74/filetype.vim
044.757  000.060  000.060: sourcing /usr/local/share/vim/vim74/ftplugin.vim
044.937  000.070  000.070: sourcing /usr/local/share/vim/vim74/indent.vim
045.770  000.270  000.270: sourcing /usr/local/share/vim/vim74/syntax/syncolor.vim
046.275  000.255  000.255: sourcing /usr/local/share/vim/vim74/syntax/syncolor.vim
053.251  008.187  007.662: sourcing /Users/manny/.vim/bundle/base16-vim/colors/base16-default.vim
053.856  000.210  000.210: sourcing /usr/local/share/vim/vim74/syntax/syncolor.vim
054.239  000.202  000.202: sourcing /usr/local/share/vim/vim74/syntax/syncolor.vim
060.570  007.234  006.822: sourcing /Users/manny/.vim/bundle/base16-vim/colors/base16-default.vim
060.852  043.157  003.033: sourcing $HOME/.vimrc
060.860  000.265: sourcing vimrc file(s)
061.080  000.024  000.024: sourcing /Users/manny/.vim/bundle/swift/plugin/swift.vim
061.600  000.017  000.017: sourcing /Users/manny/.vim/bundle/syntastic/plugin/syntastic/autoloclist.vim
061.649  000.015  000.015: sourcing /Users/manny/.vim/bundle/syntastic/plugin/syntastic/balloons.vim
061.700  000.018  000.018: sourcing /Users/manny/.vim/bundle/syntastic/plugin/syntastic/checker.vim
061.747  000.015  000.015: sourcing /Users/manny/.vim/bundle/syntastic/plugin/syntastic/cursor.vim
061.794  000.015  000.015: sourcing /Users/manny/.vim/bundle/syntastic/plugin/syntastic/highlighting.vim
061.842  000.016  000.016: sourcing /Users/manny/.vim/bundle/syntastic/plugin/syntastic/loclist.vim
061.889  000.016  000.016: sourcing /Users/manny/.vim/bundle/syntastic/plugin/syntastic/modemap.vim
061.936  000.016  000.016: sourcing /Users/manny/.vim/bundle/syntastic/plugin/syntastic/notifiers.vim
061.985  000.017  000.017: sourcing /Users/manny/.vim/bundle/syntastic/plugin/syntastic/registry.vim
062.035  000.018  000.018: sourcing /Users/manny/.vim/bundle/syntastic/plugin/syntastic/signs.vim
062.827  000.543  000.543: sourcing /Users/manny/.vim/bundle/syntastic/autoload/syntastic/util.vim
088.564  000.101  000.101: sourcing /Users/manny/.vim/bundle/syntastic/plugin/syntastic/autoloclist.vim
088.686  000.073  000.073: sourcing /Users/manny/.vim/bundle/syntastic/plugin/syntastic/balloons.vim
088.967  000.244  000.244: sourcing /Users/manny/.vim/bundle/syntastic/plugin/syntastic/checker.vim
089.125  000.120  000.120: sourcing /Users/manny/.vim/bundle/syntastic/plugin/syntastic/cursor.vim
089.265  000.104  000.104: sourcing /Users/manny/.vim/bundle/syntastic/plugin/syntastic/highlighting.vim
089.699  000.398  000.398: sourcing /Users/manny/.vim/bundle/syntastic/plugin/syntastic/loclist.vim
089.875  000.135  000.135: sourcing /Users/manny/.vim/bundle/syntastic/plugin/syntastic/modemap.vim
090.007  000.096  000.096: sourcing /Users/manny/.vim/bundle/syntastic/plugin/syntastic/notifiers.vim
090.449  000.406  000.406: sourcing /Users/manny/.vim/bundle/syntastic/plugin/syntastic/registry.vim
090.608  000.120  000.120: sourcing /Users/manny/.vim/bundle/syntastic/plugin/syntastic/signs.vim
091.661  029.594  027.254: sourcing /Users/manny/.vim/bundle/syntastic/plugin/syntastic.vim
092.200  000.192  000.192: sourcing /Users/manny/.vim/bundle/vim-airline/autoload/airline.vim
092.474  000.108  000.108: sourcing /Users/manny/.vim/bundle/vim-airline/autoload/airline/init.vim
092.943  000.117  000.117: sourcing /Users/manny/.vim/bundle/vim-airline/autoload/airline/parts.vim
093.615  001.761  001.344: sourcing /Users/manny/.vim/bundle/vim-airline/plugin/airline.vim
093.781  000.027  000.027: sourcing /Users/manny/.vim/bundle/vim-airline-themes/plugin/airline-themes.vim
094.400  000.088  000.088: sourcing /usr/local/share/vim/vim74/plugin/getscriptPlugin.vim
094.675  000.238  000.238: sourcing /usr/local/share/vim/vim74/plugin/gzip.vim
094.998  000.285  000.285: sourcing /usr/local/share/vim/vim74/plugin/logiPat.vim
095.056  000.021  000.021: sourcing /usr/local/share/vim/vim74/plugin/manpager.vim
095.304  000.213  000.213: sourcing /usr/local/share/vim/vim74/plugin/matchparen.vim
095.921  000.579  000.579: sourcing /usr/local/share/vim/vim74/plugin/netrwPlugin.vim
096.039  000.034  000.034: sourcing /usr/local/share/vim/vim74/plugin/rrhelper.vim
096.139  000.042  000.042: sourcing /usr/local/share/vim/vim74/plugin/spellfile.vim
096.388  000.191  000.191: sourcing /usr/local/share/vim/vim74/plugin/tarPlugin.vim
096.552  000.114  000.114: sourcing /usr/local/share/vim/vim74/plugin/tohtml.vim
096.792  000.196  000.196: sourcing /usr/local/share/vim/vim74/plugin/vimballPlugin.vim
097.090  000.234  000.234: sourcing /usr/local/share/vim/vim74/plugin/zipPlugin.vim
097.133  002.469: loading plugins
097.287  000.154: loading packages
097.298  000.011: inits 3
097.727  000.429: reading viminfo
097.772  000.045: setting raw mode
097.780  000.008: start termcap
097.920  000.140: clearing screen
098.832  000.474  000.474: sourcing /Users/manny/.vim/bundle/vim-airline/autoload/airline/extensions.vim
099.145  000.109  000.109: sourcing /Users/manny/.vim/bundle/vim-airline/autoload/airline/extensions/quickfix.vim
099.672  000.086  000.086: sourcing /Users/manny/.vim/bundle/vim-airline/autoload/airline/extensions/netrw.vim
100.106  000.073  000.073: sourcing /Users/manny/.vim/bundle/vim-airline/autoload/airline/extensions/syntastic.vim
100.621  000.298  000.298: sourcing /Users/manny/.vim/bundle/vim-airline/autoload/airline/extensions/whitespace.vim
101.073  000.088  000.088: sourcing /Users/manny/.vim/bundle/vim-airline/autoload/airline/extensions/po.vim
101.379  000.107  000.107: sourcing /Users/manny/.vim/bundle/vim-airline/autoload/airline/extensions/wordcount.vim
101.911  000.298  000.298: sourcing /Users/manny/.vim/bundle/vim-airline/autoload/airline/extensions/tabline.vim
102.249  000.125  000.125: sourcing /Users/manny/.vim/bundle/vim-airline/autoload/airline/extensions/tabline/autoshow.vim
102.731  000.218  000.218: sourcing /Users/manny/.vim/bundle/vim-airline/autoload/airline/extensions/tabline/tabs.vim
103.275  000.333  000.333: sourcing /Users/manny/.vim/bundle/vim-airline/autoload/airline/extensions/tabline/buffers.vim
103.758  000.261  000.261: sourcing /Users/manny/.vim/bundle/vim-airline/autoload/airline/extensions/tabline/ctrlspace.vim
106.670  000.149  000.149: sourcing /Users/manny/.vim/bundle/vim-airline/autoload/airline/section.vim
107.263  000.318  000.318: sourcing /Users/manny/.vim/bundle/vim-airline/autoload/airline/highlighter.vim
110.466  000.104  000.104: sourcing /Users/manny/.vim/bundle/vim-airline/autoload/airline/themes.vim
112.309  002.283  002.179: sourcing /Users/manny/.vim/bundle/vim-airline-themes/autoload/airline/themes/base16.vim
127.486  000.201  000.201: sourcing /Users/manny/.vim/bundle/vim-airline/autoload/airline/util.vim
130.662  000.218  000.218: sourcing /Users/manny/.vim/bundle/vim-airline/autoload/airline/builder.vim
131.168  000.142  000.142: sourcing /Users/manny/.vim/bundle/vim-airline/autoload/airline/extensions/default.vim
152.201  048.500: opening buffers
152.628  000.294  000.294: sourcing /Users/manny/.vim/bundle/syntastic/autoload/syntastic/log.vim
153.530  001.035: BufEnter autocommands
153.536  000.006: editing files in windows
153.724  000.188: VimEnter autocommands
153.758  000.034: before starting main loop
154.580  000.092  000.092: sourcing /Users/manny/.vim/bundle/vim-airline/autoload/airline/extensions/tabline/buflist.vim
154.862  000.067  000.067: sourcing /Users/manny/.vim/bundle/vim-airline/autoload/airline/extensions/tabline/formatters/unique_tail.vim
160.147  006.230: first screen update
160.150  000.003: --- VIM STARTED ---


times in msec
 clock   self+sourced   self:  sourced script
 clock   elapsed:              other lines

000.013  000.013: --- VIM STARTING ---
000.112  000.099: Allocated generic buffers
000.265  000.153: locale set
000.269  000.004: clipboard setup
000.280  000.011: window checked
016.061  015.781: inits 1
016.070  000.009: parsing arguments
016.072  000.002: expanding arguments
019.228  003.156: shell init
019.624  000.396: Termcap init
019.643  000.019: inits 2
019.782  000.139: init highlight
020.624  000.423  000.423: sourcing /Users/manny/.vim/autoload/pathogen.vim
023.527  000.401  000.401: sourcing /usr/local/share/vim/vim74/syntax/syncolor.vim
023.740  000.799  000.398: sourcing /usr/local/share/vim/vim74/syntax/synload.vim
046.272  000.107  000.107: sourcing /Users/manny/.vim/bundle/swift/ftdetect/swift.vim
046.515  022.598  022.491: sourcing /usr/local/share/vim/vim74/filetype.vim
046.579  023.784  000.387: sourcing /usr/local/share/vim/vim74/syntax/syntax.vim
046.724  000.019  000.019: sourcing /usr/local/share/vim/vim74/filetype.vim
046.921  000.070  000.070: sourcing /usr/local/share/vim/vim74/ftplugin.vim
047.107  000.060  000.060: sourcing /usr/local/share/vim/vim74/indent.vim
047.869  000.272  000.272: sourcing /usr/local/share/vim/vim74/syntax/syncolor.vim
048.319  000.212  000.212: sourcing /usr/local/share/vim/vim74/syntax/syncolor.vim
055.297  008.100  007.616: sourcing /Users/manny/.vim/bundle/base16-vim/colors/base16-default.vim
055.857  000.199  000.199: sourcing /usr/local/share/vim/vim74/syntax/syncolor.vim
056.227  000.197  000.197: sourcing /usr/local/share/vim/vim74/syntax/syncolor.vim
062.818  007.456  007.060: sourcing /Users/manny/.vim/bundle/base16-vim/colors/base16-default.vim
063.130  043.113  003.201: sourcing $HOME/.vimrc
063.138  000.243: sourcing vimrc file(s)
063.348  000.025  000.025: sourcing /Users/manny/.vim/bundle/swift/plugin/swift.vim
063.885  000.017  000.017: sourcing /Users/manny/.vim/bundle/syntastic/plugin/syntastic/autoloclist.vim
063.936  000.016  000.016: sourcing /Users/manny/.vim/bundle/syntastic/plugin/syntastic/balloons.vim
063.983  000.014  000.014: sourcing /Users/manny/.vim/bundle/syntastic/plugin/syntastic/checker.vim
064.030  000.015  000.015: sourcing /Users/manny/.vim/bundle/syntastic/plugin/syntastic/cursor.vim
064.077  000.015  000.015: sourcing /Users/manny/.vim/bundle/syntastic/plugin/syntastic/highlighting.vim
064.125  000.016  000.016: sourcing /Users/manny/.vim/bundle/syntastic/plugin/syntastic/loclist.vim
064.172  000.015  000.015: sourcing /Users/manny/.vim/bundle/syntastic/plugin/syntastic/modemap.vim
064.224  000.020  000.020: sourcing /Users/manny/.vim/bundle/syntastic/plugin/syntastic/notifiers.vim
064.274  000.017  000.017: sourcing /Users/manny/.vim/bundle/syntastic/plugin/syntastic/registry.vim
064.325  000.019  000.019: sourcing /Users/manny/.vim/bundle/syntastic/plugin/syntastic/signs.vim
065.139  000.603  000.603: sourcing /Users/manny/.vim/bundle/syntastic/autoload/syntastic/util.vim
092.306  000.108  000.108: sourcing /Users/manny/.vim/bundle/syntastic/plugin/syntastic/autoloclist.vim
092.494  000.126  000.126: sourcing /Users/manny/.vim/bundle/syntastic/plugin/syntastic/balloons.vim
092.890  000.339  000.339: sourcing /Users/manny/.vim/bundle/syntastic/plugin/syntastic/checker.vim
093.064  000.133  000.133: sourcing /Users/manny/.vim/bundle/syntastic/plugin/syntastic/cursor.vim
093.203  000.102  000.102: sourcing /Users/manny/.vim/bundle/syntastic/plugin/syntastic/highlighting.vim
093.668  000.429  000.429: sourcing /Users/manny/.vim/bundle/syntastic/plugin/syntastic/loclist.vim
093.900  000.149  000.149: sourcing /Users/manny/.vim/bundle/syntastic/plugin/syntastic/modemap.vim
094.045  000.104  000.104: sourcing /Users/manny/.vim/bundle/syntastic/plugin/syntastic/notifiers.vim
094.512  000.429  000.429: sourcing /Users/manny/.vim/bundle/syntastic/plugin/syntastic/registry.vim
094.787  000.233  000.233: sourcing /Users/manny/.vim/bundle/syntastic/plugin/syntastic/signs.vim
096.119  031.763  029.008: sourcing /Users/manny/.vim/bundle/syntastic/plugin/syntastic.vim
096.803  000.197  000.197: sourcing /Users/manny/.vim/bundle/vim-airline/autoload/airline.vim
097.086  000.122  000.122: sourcing /Users/manny/.vim/bundle/vim-airline/autoload/airline/init.vim
097.708  000.146  000.146: sourcing /Users/manny/.vim/bundle/vim-airline/autoload/airline/parts.vim
098.457  002.043  001.578: sourcing /Users/manny/.vim/bundle/vim-airline/plugin/airline.vim
098.658  000.027  000.027: sourcing /Users/manny/.vim/bundle/vim-airline-themes/plugin/airline-themes.vim
099.306  000.091  000.091: sourcing /usr/local/share/vim/vim74/plugin/getscriptPlugin.vim
099.606  000.261  000.261: sourcing /usr/local/share/vim/vim74/plugin/gzip.vim
099.950  000.304  000.304: sourcing /usr/local/share/vim/vim74/plugin/logiPat.vim
100.012  000.022  000.022: sourcing /usr/local/share/vim/vim74/plugin/manpager.vim
100.276  000.228  000.228: sourcing /usr/local/share/vim/vim74/plugin/matchparen.vim
100.941  000.626  000.626: sourcing /usr/local/share/vim/vim74/plugin/netrwPlugin.vim
101.029  000.026  000.026: sourcing /usr/local/share/vim/vim74/plugin/rrhelper.vim
101.135  000.054  000.054: sourcing /usr/local/share/vim/vim74/plugin/spellfile.vim
101.361  000.183  000.183: sourcing /usr/local/share/vim/vim74/plugin/tarPlugin.vim
101.530  000.117  000.117: sourcing /usr/local/share/vim/vim74/plugin/tohtml.vim
101.771  000.197  000.197: sourcing /usr/local/share/vim/vim74/plugin/vimballPlugin.vim
102.106  000.279  000.279: sourcing /usr/local/share/vim/vim74/plugin/zipPlugin.vim
102.154  002.606: loading plugins
102.334  000.180: loading packages
102.346  000.012: inits 3
102.792  000.446: reading viminfo
102.840  000.048: setting raw mode
102.848  000.008: start termcap
102.923  000.075: clearing screen
103.638  000.367  000.367: sourcing /Users/manny/.vim/bundle/vim-airline/autoload/airline/extensions.vim
103.884  000.079  000.079: sourcing /Users/manny/.vim/bundle/vim-airline/autoload/airline/extensions/quickfix.vim
104.143  000.064  000.064: sourcing /Users/manny/.vim/bundle/vim-airline/autoload/airline/extensions/netrw.vim
104.619  000.128  000.128: sourcing /Users/manny/.vim/bundle/vim-airline/autoload/airline/extensions/syntastic.vim
105.291  000.362  000.362: sourcing /Users/manny/.vim/bundle/vim-airline/autoload/airline/extensions/whitespace.vim
105.937  000.074  000.074: sourcing /Users/manny/.vim/bundle/vim-airline/autoload/airline/extensions/po.vim
106.193  000.104  000.104: sourcing /Users/manny/.vim/bundle/vim-airline/autoload/airline/extensions/wordcount.vim
106.873  000.349  000.349: sourcing /Users/manny/.vim/bundle/vim-airline/autoload/airline/extensions/tabline.vim
107.231  000.181  000.181: sourcing /Users/manny/.vim/bundle/vim-airline/autoload/airline/extensions/tabline/autoshow.vim
108.121  000.267  000.267: sourcing /Users/manny/.vim/bundle/vim-airline/autoload/airline/extensions/tabline/tabs.vim
108.745  000.265  000.265: sourcing /Users/manny/.vim/bundle/vim-airline/autoload/airline/extensions/tabline/buffers.vim
109.149  000.197  000.197: sourcing /Users/manny/.vim/bundle/vim-airline/autoload/airline/extensions/tabline/ctrlspace.vim
111.516  000.118  000.118: sourcing /Users/manny/.vim/bundle/vim-airline/autoload/airline/section.vim
111.963  000.232  000.232: sourcing /Users/manny/.vim/bundle/vim-airline/autoload/airline/highlighter.vim
114.726  000.097  000.097: sourcing /Users/manny/.vim/bundle/vim-airline/autoload/airline/themes.vim
116.346  002.056  001.959: sourcing /Users/manny/.vim/bundle/vim-airline-themes/autoload/airline/themes/base16.vim
129.315  000.127  000.127: sourcing /Users/manny/.vim/bundle/vim-airline/autoload/airline/util.vim
132.115  000.203  000.203: sourcing /Users/manny/.vim/bundle/vim-airline/autoload/airline/builder.vim
132.577  000.134  000.134: sourcing /Users/manny/.vim/bundle/vim-airline/autoload/airline/extensions/default.vim
157.167  048.937: opening buffers
157.607  000.294  000.294: sourcing /Users/manny/.vim/bundle/syntastic/autoload/syntastic/log.vim
158.509  001.048: BufEnter autocommands
158.514  000.005: editing files in windows
158.749  000.235: VimEnter autocommands
158.792  000.043: before starting main loop
159.425  000.086  000.086: sourcing /Users/manny/.vim/bundle/vim-airline/autoload/airline/extensions/tabline/buflist.vim
159.696  000.065  000.065: sourcing /Users/manny/.vim/bundle/vim-airline/autoload/airline/extensions/tabline/formatters/unique_tail.vim
164.114  005.171: first screen update
164.116  000.002: --- VIM STARTED ---
