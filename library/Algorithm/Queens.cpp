/*
	Problem:
		Find a solution to put N queens on NxN chessboard
		so that none of them attacks each other.
	Solution:
		Backtracking
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

using namespace std;


const int MAX_N = 44;
const int MAX_M = 2*MAX_N;


int n, nQueen;
bool ok[MAX_N][MAX_N];
bool row_ok[MAX_N];
bool col_ok[MAX_N];
bool left_diagonal[2*MAX_M], right_diagonal[2*MAX_M];
int result[MAX_N][MAX_N];
bool found;



bool check(int x, int y) {
	return ok[x][y] && row_ok[x] && col_ok[y]
		&& left_diagonal[x-y + MAX_N] && right_diagonal[x+y + MAX_N];
}



void push_queen(int x, int y) {
	ok[x][y] = false;
	row_ok[x] = false;
	col_ok[y] = false;
	left_diagonal[x-y+MAX_N] = false;
	right_diagonal[x+y+MAX_N] = false;
}



void pop_queen(int x, int y) {
	ok[x][y] = true;
	row_ok[x] = true;
	col_ok[y] = true;
	left_diagonal[x-y+MAX_N] = true;
	right_diagonal[x+y+MAX_N] = true;
}



void tryf(int nQueen) {
	if (found)
		return;
	if (nQueen >= n) {
		found = true;
		return;
	}

	for (int i = 0; i < n; ++i)
		if (check(nQueen, i)) {
			result[nQueen][i] = nQueen+1;
			push_queen(nQueen, i);
			tryf(nQueen+1);
			if (found)
				return;
			pop_queen(nQueen, i);
			result[nQueen][i] = 0;
		}
}



int main(int argc, char** argv) {
	cout << "This program to find a solution to put N queens on NxN chessboard \
so that none of them attacks each other." << endl << endl;
	if (argc > 1)
		n = atoi(argv[1]);
	else {
		cout << "Enter N: ";
		cin >> n;
	}
	cout << endl << "With N = " << n << ": " << endl;


	clock_t start_time = clock();

	memset(ok, true, sizeof(ok));
	memset(row_ok, true, sizeof(ok));
	memset(col_ok, true, sizeof(ok));
	memset(left_diagonal, true, sizeof(ok));
	memset(right_diagonal, true, sizeof(ok));
	memset(result, 0, sizeof(ok));

	tryf(0);
	if (found) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j)
				cout << result[i][j] << " ";
			cout << endl;
		}
		// for (int i = 0; i < n; ++i)
		// 	for (int j = 0; j < n; ++j)
		// 		if (result[i][j])
		// 			cout << i+1 << " " << j+1 << endl;
	}
	else
		cout << "No solution!" << endl;

	clock_t end_time = clock();
	cout << endl << "Time: " << double(end_time - start_time)/CLOCKS_PER_SEC;

	cout << endl << "Done!" << endl;
	cin.get();
	cin.get();
	return 0;
}