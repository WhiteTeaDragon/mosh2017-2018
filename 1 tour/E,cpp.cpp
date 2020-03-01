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

string next(string a)
{
	string ans = a;
	int n = a.size(), sum = 0;
	for (int i = 0; i < n; ++i)
		sum += (a[i] - '0');
	if (sum == 0)
		return "";
	if (n == 1)
	{
		ans = '1' + (a[0] - 1);
		return ans;
	}
	if (a[n - 1] != '0')
	{
		if (a[n - 2] != '9')
		{
			++a[n - 2];
			--a[n - 1];
		}
		else
		{
			a[n - 1] = '0';
			int i = n - 2;
			while (i >= 0 && a[i] == '9')
			{
				a[i] = '0';
				--i;
			}
			if (i < 0)
			{
				a = '0' + a;
				i = 0;
				n = a.size();
			}
			++a[i];
			--sum;
			i = n - 1;
			while (i >= 0 && sum >= 9)
			{
				a[i] = '9';
				sum -= 9;
				--i;
			}
			a[i] = sum + '0';
		}
	}
	else
	{
		int i = n - 1;
		while (i >= 0 && a[i] == '0')
			--i;
		if (i == 0)
		{
			--a[0];
			a = '1' + a;
			return a;
		}
		if (a[i - 1] != '9')
		{
			++a[i - 1];
			--a[i];
		}
		else
		{
			a[i] = '0';
			int j = i - 1;
			while (j >= 0 && a[j] == '9')
			{
				a[j] = '0';
				--j;
			}
			if (j < 0)
			{
				a = '0' + a;
				j = 0;
				++i;
				++n;
			}
			++a[j];
			--sum;
			i = n - 1;
			while (i >= 0 && sum >= 9)
			{
				a[i] = '9';
				sum -= 9;
				--i;
			}
			a[i] = sum + '0';
		}
	}
	return a;
}

int main()
{
	string s;
	in >> s;
	string first = s.substr(0, s.size() / 2), second = s.substr(s.size() / 2, s.size() / 2);
	string next_sec = next(second), next_f = next(first);
	int n = s.size() / 2;
	string next_zero(n, '0');
	int sum = 0;
	for (int i = 0; i < s.size() / 2; ++i)
	{
		sum += s[i] - '0';
	}
	int i = s.size() / 2 - 1;
	while (i >= 0 && sum >= 9)
	{
		next_zero[i] = '9';
		sum -= 9;
	}
	next_zero[i] = sum + '0';
	if (next_sec.size() == s.size() / 2)
		out << first + next_sec;
	else
	{
		if (next_f.size() == s.size() / 2)
			out << next_f + next_zero;
		else
			out << next_zero + next_zero;
	}
	return 0;
}