#include "shisanshui.h"
#define dd(x) cout << #x << " = " << x << " "
#define de(x) cout << #x << " = " << x << "\n"
char c[] = { "$&*#" };
vector <P> v;
int sss::fc_to_number(char x) {
	for (int i = 0; i < 4; i++)
		if (x == c[i]) return i;
	return 5;
}
int sss::num_to_number(char x) {
	if (x <= '9' && x >= '2') return x - (int)'0';
	if (x == '1') return 10;
	if (x == 'J') return 11;
	if (x == 'Q') return 12;
	if (x == 'K') return 13;
	if (x == 'A') return 14;
	return 0;
}
char sss::number_to_num(int x) {
	if (2 <= x && x <= 9) return (char)x + '0';
	if (x == 10) return '1';
	if (x == 11) return 'J';
	if (x == 12) return 'Q';
	if (x == 13) return 'K';
	if (x == 14) return 'A';
	return '0';
}
char sss::number_to_fc(int x) {
	return c[x];
}
pi q[6];
inline pi sss::fen(const int &x) {
	//vector <pi >q;
	int m = 0;
	for (int i = 0; i < n; i++)
		if (x >> i & 1) {
			q[m++] = s[i];
		}
	if (m == 3) {
		if (q[0].fi == q[1].fi && q[1].fi == q[2].fi) return mp(4, q[0].fi);
		if (q[0].fi == q[1].fi || q[1].fi == q[2].fi) return mp(1, q[1].fi);
		return mp(0, q[2].fi);
	}
	int f1 = 1, f2 = 1;
	for (int i = 0; i < m; i++)
		if (q[i].se != q[0].se) f1 = 0;
	for (int i = 0; i < m; i++)
		if (q[i].fi - q[0].fi != i) f2 = 0;
	if (f1 && f2) return mp(20, q[4].fi);
	if (f2) return mp(5, q[4].fi);
	if (f1) return mp(6, q[4].fi);
	int t = 0;
	for (int i = 0; i < m; i++) {
		int k = 0;
		for (int j = i; j < m; j++)
			if (q[j].fi == q[i].fi) k++;
			else break;
		t = max(t, k);
	}
	if (t == 4) return mp(19, q[3].fi);
	if (t == 3) {
		if (q[0].fi == q[1].fi && q[2].fi == q[3].fi && q[3].fi == q[4].fi ||
			q[0].fi == q[1].fi && q[1].fi == q[2].fi && q[3].fi == q[4].fi) return mp(7, q[2].fi);
		return mp(4, q[2].fi);
	}
	if (t == 1)
		return mp(0, q[4].fi);
	t = 0;
	int f[3];
	for (int i = 1; i < m; i++)
		if (q[i].fi == q[i - 1].fi) f[t++]=q[i].fi;
	if (t == 2) {
		if (f[0] == f[1] - 1) return mp(3, f[1]);
		return mp(2, f[1]);
	}
	return mp(1, f[0]);
}
inline void sss::check(const int &x,const int &y,const int &z) {
	//dd(x), dd(y), de(z);
	//de((x^y^z));
	pi x1 = fen(x);
	pi x2 = fen(y);
	pi x3 = fen(z);
	if (x1 > x2 || x2 > x3) return;
	v.push_back(P(x1.first+x2.first+x3.first, x1, x2 , x3, x, y, z));
}
int st[10];
void sss::dfs(int p, int t, int sta) {
	if (t > 5) {
		int m = 0;
		for (int i = 0; i < n; i++)
			if (!(sta >> i & 1)) st[m++] = i;
		for (int i = 0; i < m; i++)
			for (int j = i + 1; j < m; j++)
				for (int k = j + 1; k < m; k++){
					int x = (1 << st[i]) | (1 << st[j]) | (1 << st[k]);
					check(x, ((1 << 13) - 1) ^ sta^x, sta);
				}
		return;
	}
	for (int i = p; i < n; i++) {
		dfs(i + 1, t + 1, sta | (1 << i));
	}
}
int sss::pk(int x, int y) {
	int num = 0, t = 0;
	pi x1 = v[x].p1, x2 = v[y].p1;
	if (x1 > x2) num++, t++;
	else if (x1 < x2) num--, t--;
	x1 = v[x].p2, x2 = v[y].p2;
	int k = 0;
	if (x1 > x2) { t++; if (x1.fi == 19) k = 8; else if (x1.fi == 20) k = 10; else if (x1.fi == 7)k = 2; }
	else if (x1 < x2) { t--; if (x2.fi == 19) k = -8; else if (x2.fi == 20) k = -10; else if (x2.fi == 7) k = -2; }
	num += k;

	x1 = v[x].p3, x2 = v[y].p3;
	k = 0;
	if (x1 > x2) { t++;  if (x1.fi == 19) k = 4; else if (x1.fi == 20) k = 5; else k = 1; }
	else if (x1 < x2) {
		t--; if (x2.fi == 19) k = -4; else if (x2.fi == 20) k = -5; else k = -1;
	}
	num += k;
	if (t == 3 || t == -3 || t == 2 || t == -2) num *= 2;
	return num;
}
void sss::prin(int x) {
	vector < pi > v;
	for (int i = 0; i < n; i++)
		if (x >> i & 1) v.push_back(s[i]);
	for (int i = 0; i < (int)v.size(); i++) {
		if (i) printf(" ");
		printf("%c%c", number_to_fc(v[i].second), number_to_num(v[i].fi));
		if (v[i].fi == 10) printf("0");
	}
	printf("\n");
}
void sss::ans(int x,int y,int z) {
	prin(x);
	prin(y);
	prin(z);
//	system("pause");
}
void sss::doit() {
	v.clear();
	dfs(0, 1, 0);
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
//	de((int)v.size());
	int m = min(1000, (int)v.size());
	int num[1004] = { 0 };
	for (int i = 0; i < m; i++)
		for (int j = i + 1; j < m; j++) {
			int k = pk(i, j);
			num[i] += k;
			num[j] -= k;
		}
	int mx = 0;
	for (int i = 1; i < m; i++)
		if (num[i] > num[mx]) mx = i;

	ans(v[mx].x, v[mx].y, v[mx].z);
}