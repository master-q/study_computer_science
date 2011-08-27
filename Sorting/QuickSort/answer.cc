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
	for (i = fromindex; i <= endindex; i++) {
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

void sort_internal(vector<int> &a, int startindex, int endindex) {
	int i = startindex;
	int j = endindex;

	cout << "sort " << i << ".." << j << endl;
	if (j - i < 1) return;

	int pip = a[(j - i) / 2];

	cout << "pip=" << pip << endl;

	do {
		i = findl(a, i, endindex, pip);
		j = findr(a, j, 0, pip);

		cout << i << "<=>" << j << endl;
		if (i > j) break;

		cout << "swap!" << endl;
		swap(a[i], a[j]);
		show_vector(a);
	} while (i < j);

	sort_internal(a, startindex, i - 1);
	sort_internal(a, i + 1, endindex);
	// xxx
}

vector<int> QuickSort::sort(vector<int> a) {
	show_vector(a);
	sort_internal(a, 0, a.size() - 1);

	return a;
}
