#include "answer.h"
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

// MarbleDecoration
// http://community.topcoder.com/stat?c=problem_statement&pm=11287

// for Debug
void show_vector(vector<int> &a) {
	for (unsigned int i = 0; i < a.size(); i++) {
		cout << a[i] << ",";
	}
	cout << endl;
}

void swap(int &a, int &b) {
	int tmp;

	tmp = a;
	a = b;
	b = tmp;
}

// return index
int findl(vector<int> &a, int fromindex, int endindex, int pip) {
	int i;
	for (i = fromindex; i < endindex; i++) {
		if (a[i] >= pip) break;
	}
	return i;
}

// return index
int findr(vector<int> &a, int fromindex, int startindex, int pip) {
	int i;
	for (i = fromindex; i >= startindex; i--) {
		if (a[i] < pip) break;
	}
	return i;
}

vector<int> QuickSort::sort(vector<int> a) {
	int pip;
	unsigned int i, j;

	pip = a[a.size() / 2 - 1];

	cout << "pip=" << pip << endl;
	show_vector(a);

	i = 0;
	j = a.size() - 1;

	do {
		i = findl(a, i, a.size(), pip);
		j = findr(a, j, 0, pip);

		cout << i << "<=>" << j << endl;
		if (i > j) break;

		swap(a[i], a[j]);
		show_vector(a);
	} while (i < j);

	return a;
}
