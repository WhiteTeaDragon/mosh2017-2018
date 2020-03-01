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

FILE* in = fopen("input.txt", "r");
FILE* out = fopen("output.txt", "w");

//ifstream in("input.txt");
//ofstream out("output.txt");

int main()
{
	int n, m, k;
	fscanf(in, "%d %d %d", &n, &m, &k);
	int ans = m - 1, x;
	for (int i = 0; i < k; ++i)
	{
		fscanf(in, "%d", &x);
		x %= n;
		if (x == ans)
			ans = 0;
		else if (x > ans)
			++ans;
	}
	fprintf(out, "%d\n", ans + 1);
	return 0;
}