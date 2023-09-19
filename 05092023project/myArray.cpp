#include <iostream>

#define M int**

using namespace std;

M init(int m , int n) {
	M tmp = new int* [m];
	for (int i = 0; i < m; ++i)
		tmp[i] = new int[n];
	return tmp;
}

void clear(M tmp, int m) {
	for (int i = 0 ; i < m; ++i)
		delete[] tmp[i];
	delete[] tmp;
}

void print(M tmp, int m, int n) {
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << tmp[i][j] << ' ';
		}
		cout << '\n';
	}
}

M sum(M first, M second, int m, int n) {
	M result = init(m, n);
	for (int i = 0; i < m; ++i) 
		for (int j = 0; j < n; ++j) 
			result[i][j] = first[i][j] + second[i][j];
	return result;
}

M transpose(M tmp, int m, int n) {
	M tmp_copy = init(n, m);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			tmp_copy[i][j] = tmp[j][i];
	return tmp_copy;
}


void scalarate(M tmp, int alpha, int m, int n) {
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			tmp[i][j] *= alpha;
}
