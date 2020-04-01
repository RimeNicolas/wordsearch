#pragma once

#include <array>
#include <vector>

struct TrieNode {
	bool end_word = false;
	std::array<std::shared_ptr<TrieNode>, 26> next_letters = { nullptr };
};


std::shared_ptr<TrieNode> build_trie(const std::vector<std::string>& words);
void print_trie(std::shared_ptr<TrieNode> root);

