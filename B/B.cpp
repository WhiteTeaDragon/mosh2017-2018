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

int main()
{
	FILE* in = fopen("b2.txt", "r");
	FILE* out = fopen("b2myans.txt", "w");
	long long n, k, max_k = -1;
	fscanf(in, "%I64d", &n);
	fprintf(out, "%I64d\n", n);
	for (int i = 0; i < n; ++i)
	{
		fprintf(out, "\n");
		fscanf(in, "%I64d", &k);
		fprintf(out, "%I64d\n", k);
		vector<long long> a(k);
		for (int j = 0; j < k; ++j)
			fscanf(in, "%I64d", &a[j]);
		sort(a.begin(), a.end());
		for (int j = 1; j < k; ++j)
			fprintf(out, "%I64d ", a[j]);
		fprintf(out, "%I64d\n", a[0]);
	}
	//system("pause");
	return 0;
}