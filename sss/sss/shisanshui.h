#pragma once
#define mp make_pair
#define fi first
#define se second
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#define pi pair <int ,int >
using namespace std;
struct P {
	int number;
	pair <int ,int > p1, p2, p3;
	int x, y, z;
	P() {}
	P(int num, pi _p1, pi _p2, pi _p3,int _x,int _y,int _z) {
		number = num;
		x = _x;	y = _y;	z = _z;
		p1 = _p1;
		p2 = _p2;
		p3 = _p3;
	}
	bool operator < (const P&a) const{
		return number < a.number;
	}
};
class sss {
public:
	string ori;
	pair <int, int > s[14];
	int n;
	sss() {}
	sss(string str) {
		n = 0;
		for (int i = 0; i < (int)str.size(); i += 3) {
			s[n].second = fc_to_number(str[i]);
			s[n].first = num_to_number(str[i + 1]);
			if (str[i + 1] == '1') i++;
			n++;
		}
		sort(s, s + n);
	}
	void doit();
	void dfs(int, int,int);
//	void dfs1(int, int);
	void check(int, int, int);
	int pk(int, int);
	void prin(int );
	void ans(int, int, int);
	pi fen(int);
	int fc_to_number(char );
	int num_to_number(char);
	char number_to_num(int);
	char number_to_fc(int);
};