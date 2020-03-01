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

int main()
{
	long long a, b, c;
	in >> a >> b >> c;
	long long first = (a + c - 1) / c;
	long long second = b / c;
	out << max(0LL, second - first + 1) << "\n";
	//system("pause");
	return 0;
}