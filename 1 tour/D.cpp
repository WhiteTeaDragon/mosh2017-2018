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
	long long k, n, x;
	fscanf(in, "%I64d %I64d", &k, &n);
	vector<pair<long long, long long> > a;
	for (int i = 0; i < n; ++i)
	{
		fscanf(in, "%I64d", &x);
		if (x != 0)
			a.push_back(mp(x, i + 1));
	}
	reverse(a.begin(), a.end());
	long long ans = 0, sum;
	for (int i = 0; i < a.size();)
	{
		ans += ((a[i].first + k - 1) / k) * a[i].second * 2;
		a[i].first %= k;
		if (a[i].first == 0)
			++i;
		else
		{
			sum = a[i].first;
			while (i < a.size() && sum < k)
			{
				++i;
				sum += a[i].first;
			}
			if (i >= a.size())
			{
				fprintf(out, "%d\n", ans);
				return 0;
			}
			if (sum == k)
				++i;
			else if (sum > k)
			{
				sum -= a[i].first;
				a[i].first -= (k - sum);
			}
		}
	}
	fprintf(out, "%I64d\n", ans);
	return 0;
}