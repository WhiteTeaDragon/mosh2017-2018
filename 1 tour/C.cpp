#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<string>
#include<set>
#include<sstream>
#include<climits>
#include<limits.h>
#include<cstdio>
//#pragma comment(linker, "/STACK:10000000")
#define mp make_pair

using namespace std;

//FILE* in = fopen("input.txt", "r");
//FILE* out = fopen("output.txt", "w");

ifstream in("input.txt");
ofstream out("output.txt");

const int SinM = 60, SinH = 60 * 60, SinD = 60 * 60 * 24;

int time(string &a)
{
	int hh = (a[0] - '0') * 10 + (a[1] - '0');
	int mm = (a[3] - '0') * 10 + (a[4] - '0');
	int ss = (a[6] - '0') * 10 + (a[7] - '0');
	return ss + mm * SinM + hh * SinH;
}

void print(int sec)
{
	int hh = sec / SinH;
	sec %= SinH;
	int mm = sec / SinM;
	sec %= SinM;
	int ss = sec;
	string ans = "  :  :  ";
	ans[0] = (hh / 10) + '0';
	ans[1] = (hh % 10) + '0';
	ans[3] = (mm / 10) + '0';
	ans[4] = (mm % 10) + '0';
	ans[6] = (ss / 10) + '0';
	ans[7] = (ss % 10) + '0';
	out << ans;
}

int main()
{
	string a, b, c;
	in >> a >> b >> c;
	int a_sec = time(a), b_sec = time(b), c_sec = time(c);
	int time_2way, time_way;
	if (c_sec < a_sec)
		time_2way = c_sec + SinD - a_sec;
	else
		time_2way = c_sec - a_sec;
	time_way = (time_2way + 1) / 2;
	int ans = b_sec + time_way;
	ans %= SinD;
	print(ans);
	return 0;
}