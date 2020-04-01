#pragma once

#include <iostream>
#include <vector>

std::vector<std::vector<char>> generate_board(size_t size_x, size_t size_y);

template<class T>
void print_vector(std::vector<T> v) {
	if (v.size() != 0) {
		std::cout << '(';
		for (size_t i(0); i < v.size() - 1; i++)
			std::cout << v[i] << ',';
		std::cout << v.back() << ')';
	}
	else {
		std::cout << "empty vector\n";
	}
}

template<class T>
void print_matrix(std::vector<std::vector<T>> m) {
	if (m.size() != 0) {
		for (size_t i(0); i < m.size(); i++) {
			print_vector(m[i]);
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
	else {
		std::cout << "empty matrix\n";
	}
}

