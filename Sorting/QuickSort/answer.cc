#include "answer.h"
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

// MarbleDecoration
// http://community.topcoder.com/stat?c=problem_statement&pm=11287

//#define DEBUG 1

void show_vector(vector<int> &a) {
#if DEBUG
	for (unsigned int i = 0; i < a.size(); i++) {
		cout << a[i] << ",";
	}
	cout << endl;
#endif
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

#if DEBUG
	cout << "#sort " << i << ".." << j << endl;
#endif
	if (j - i < 1) return;

	int pip = a[(j - i) / 2 + i];

#if DEBUG
	cout << "pip=" << pip << endl;
#endif

	do {
		i = findl(a, i, endindex, pip);
		j = findr(a, j, 0, pip);

#if DEBUG
		cout << i << "<=>" << j << endl;
#endif
		if (i > j) break;

#if DEBUG
		cout << "swap!" << endl;
#endif
		swap(a[i], a[j]);
		show_vector(a);
	} while (i < j);

	sort_internal(a, startindex, i - 1);
	sort_internal(a, i + 1, endindex);
}

vector<int> QuickSort::sort(vector<int> a) {
	show_vector(a);
	sort_internal(a, 0, a.size() - 1);

	return a;
}
