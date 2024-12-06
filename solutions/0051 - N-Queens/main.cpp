#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout, std::endl, std::abs;


class Board {
public:
	int size;
	std::vector<int> squares; // 0 for empty, 1 for queen or attacked by queen
	std::vector<std::pair<int, int>> queens;
  Board(int size) {
		this->size = size;
		squares.resize(size*size);
		std::fill(squares.begin(), squares.end(), 0);
	}
	void set_queen(int x, int y) {
		queens.push_back({x, y});
		for (int i=0; i<size*size; i++) {
			int board_x = i%size;
			int board_y = i/size;
			// cout << board_x << "," << board_y << endl;
			// cout << (board_x - x) << " : " << (board_y -y) << endl;
			if (abs(board_x - x) == abs(board_y - y)) { // diagonal
				squares[i] = 1;
			}
			if (board_x == x)
				squares[i] = 1; // horizontal
			if (board_y == y)
				squares[i] = 1; // vertical
		}
	}
};

// overloading printing of the Board class
std::ostream& operator<<(std::ostream &out, Board const& data) {
	for (int y=0; y<data.size; y++) {
		for (int x=0; x<data.size ; x++) {
			if (data.squares[data.size*y + x] == 1)
				out << '#';
			if (data.squares[data.size*y + x] == 0)
				out << '.';
		}
		out << std::endl;
	}
	return out;
}

std::vector<std::string> queens_to_str(std::vector<std::pair<int, int>> queens, int n) {
	std::vector<int> queenboard(n*n, 0);
	for (std::pair<int, int> q : queens) {
		queenboard[q.second*n + q.first] = 1;
	}
	std::vector<std::string> output;
	for (int y=0; y<n; y++) {
		std::string line;
		for (int x=0; x<n ; x++) {
			if (queenboard[n*y + x] == 1)
				line.append("Q");
			if (queenboard[n*y + x] == 0)
				line.append(".");
		}
		output.push_back(line);
	}
	return output;
}

std::vector<std::vector<std::string>> found; // no hashing function for pairs

void print_queens(std::vector<std::pair<int, int>> queens, int n) {
	std::vector<int> queenboard(n*n, 0);
	for (std::pair<int, int> q : queens) {
		queenboard[q.second*n + q.first] = 1;
	}
	for (int y=0; y<n; y++) {
		for (int x=0; x<n ; x++) {
			if (queenboard[n*y + x] == 1)
				std::cout << '#';
			if (queenboard[n*y + x] == 0)
				std::cout << '.';
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void solve(Board board, int n, int y) {
	cout << y << endl;
	// cout << board << endl;
	if (board.queens.size() == n) {
		for (std::vector<std::string> s : found) {
			if (s == queens_to_str(board.queens, n)) 
				return;
		}
		print_queens(board.queens, n);
		found.push_back(queens_to_str(board.queens, n));
	}
	if (y+1>n)
		return;
	for (int x=0; x<n; x++) {
		if (board.squares[n*y + x] == 0) {
			Board newboard = board;
			newboard.set_queen(x, y);
			solve(newboard, n, y+1);
		}
	}
  return;
}

int main() {
	int size = 4;
	Board board(size);
	solve(board, size, 0);
	cout << found.size() << endl;
	// for (std::vector<std::string> b : found) {
	// 	for (std::string s : b) {
	// 		cout << s << endl;
	// 	}
	// 	cout << endl;
	// }
	return 0;
}

/**
	 Initial solution.
	 Quite rough, certainly more for loops iterating through data structures than necessary.
	 Better solution is probably to just work on a vector with no classes, too much fiddling
	 around with data structures outside the realm of the problem.
	 I'll come back to this.
 **/
