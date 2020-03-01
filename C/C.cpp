#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<string>
#include<stack>
#include<cmath>
#include<map>
#include<set>
#include<deque>
#include<climits>
#include<sstream>
//#pragma comment(linker, "/STACK:5000000000")

using namespace std;

struct card
{
	int i, limit;
	long double percent;
};

bool comp1(const card &a, const card &b)
{
	return a.percent < b.percent;
}

bool comp2(const card &a, const card &b)
{
	return a.limit * a.percent < b.limit * a.percent;
}

const long double eps = 1e-5;

int main(int argc, char *argv[])
{
	char *in_filename = argv[1];
	char *out_filename = argv[2];
	FILE* in = fopen(in_filename, "r");
	int n, k, m;
	fscanf(in, "%d", &n);
	for (int i = 0; i < n; ++i)
	{
		fscanf(in, "%d", &k);
		vector<card> a(k), copy;
		for (int j = 0; j < k; ++j)
		{
			fscanf(in, "%d %lf", &a[j].limit, &a[j].percent);
			a[j].i = j + 1;
		}
		fscanf(in, "%d", &m);
		vector<pair<int, int> > prod(m);
		for (int j = 0; j < m; ++j)
		{
			fscanf(in, "%d", &prod[j].first);
			prod[j].second = j;
		}
		copy = a;
		sort(copy.rbegin(), copy.rend(), comp1);
		sort(a.rbegin(), a.rend(), comp2);
		vector<int> ans(m), maxim, example(m);
		long double max_ans = 0.0;
		for (;;) 
		{
			vector<card> tmp = a;
			long double curr_ans = 0.;
			random_shuffle(prod.begin(), prod.end());
			int c = 0;
			for (int b = 0; b < k; ++b)
			{
				while (c < m && tmp[b].limit > 0)
				{
					curr_ans += min(prod[c].first, tmp[b].limit) * tmp[b].percent / 100.;
					tmp[b].limit -= prod[c].first;
					ans[prod[c].second] = tmp[b].i;
					++c;
				}
			}
			for (c; c < m; ++c)
				ans[prod[c].second] = 1;
			if (curr_ans > max_ans + eps)
			{
				FILE* out = fopen(out_filename, "a");
				fprintf(out, "%.15lf", curr_ans);
				max_ans = curr_ans;
				maxim = ans;
				for (int jj = 0; jj < m; ++jj)
					fprintf(out, "%d ", maxim[jj]);
				fprintf(out, "\n");
				fclose(out);
			}
			tmp = copy;
			curr_ans = 0;
			c = 0;
			ans = example;
			for (int b = 0; b < k; ++b)
			{
				while (c < m && tmp[b].limit > 0)
				{
					curr_ans += min(prod[c].first, tmp[b].limit) * tmp[b].percent / 100.;
					tmp[b].limit -= prod[c].first;
					ans[prod[c].second] = tmp[b].i;
					++c;
				}
			}
			for (c; c < m; ++c) 
				ans[prod[c].second] = 1;
			if (curr_ans > max_ans + eps)
			{
				FILE* out = fopen(out_filename, "a");
				fprintf(out, "%.15f", curr_ans);
				max_ans = curr_ans;
				maxim = ans;
				for (int jj = 0; jj < m; ++jj)
					fprintf(out, "%d ", maxim[jj]);
				fprintf(out, "\n");
				fclose(out);
			}
			tmp = copy;
			curr_ans = 0;
			c = 0;
			ans = example;
		}
		//cerr << i << "\n";
	}
	//system("pause");
	return 0;
}