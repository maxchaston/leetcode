#include <vector>
#include <string>
#include <iostream>

using std::cout, std::endl;

void print_board(std::vector<std::string> board) {
	for (std::string row : board) {
		cout << row << endl;
	}
	cout << endl;
}

bool is_valid(int x, int y, std::vector<std::string> &board, int n) {
	// check column, only need to check "behind"
	for (int i=y; i>=0; i--) {
		if (board[i][x] == 'Q')
			return false;
	}

	// check north-west diagonal
	for (int i=y; i>=0; i--) {
		if (x-(y-i) >= 0) {
			if (board[i][x-(y-i)] == 'Q')
				return false;
		}
	}


	// check north-east diagonal
	for (int i=y; i>=0; i--) {
		if (x+(y-i) < n) {
			if (board[i][x+(y-i)] == 'Q')
				return false;
		}
	}
	return true;
}

void solve_recurse(std::vector<std::string> board, int y, int n, std::vector<std::vector<std::string>> &solved_boards) { // don't want passing by reference as we use the copy to manipulate
	for (int i=0; i<n; i++) {
		if (is_valid(i, y, board, n)) {
			board[y][i] = 'Q';
			if (y==n-1) {
				solved_boards.push_back(board);
			} else {
				solve_recurse(board, y+1, n, solved_boards);
			}
			board[y][i] = '.';
		}
	}
}

std::vector<std::vector<std::string>> solve(int n) {
	std::vector<std::vector<std::string>> solved_boards;
	std::vector<std::string> initial_board(n);
	std::fill(initial_board.begin(), initial_board.end(), std::string(n, '.'));
	solve_recurse(initial_board, 0, n, solved_boards);
	return solved_boards;
}

int main() {
	std::vector<std::vector<std::string>> solved_boards = solve(6);
	for (std::vector<std::string> board : solved_boards) {
		print_board(board);
	}
	cout << solved_boards.size() << endl;
	return 0;
}

/**
	 Much better overall solution.
	 Main improvements are removing looking ahead and only checking
	 backwards, as well as a lot less faffing around with data
	 structure formatting.
 **/
