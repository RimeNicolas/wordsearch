#include "BoardGenerator.h"
#include "WordSearch.h"
#include <iostream>

int main() {
	size_t x(10), y(x);

	std::vector<std::string> words = { "abc", "hum", "ko", "pure" };

	std::cout << "Words to search:\n";
	print_vector(words);
	std::cout << std::endl << std::endl;

	std::cout << "Board:";
	std::vector<std::vector<char>> board = generate_board(x, y);
	print_matrix(board);

	WordSearch wordsearch;
	std::vector<std::string> res = wordsearch.findWords(board, words);

	std::cout << "Found words:\n";
	print_vector(res);
	std::cout << std::endl;

	return 0;
}