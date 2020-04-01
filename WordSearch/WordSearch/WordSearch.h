#pragma once
#include "Trie.h"
#include <vector>
#include <unordered_set>


class WordSearch {
private:
	bool dfs(std::vector<std::vector<char>>& board, std::shared_ptr<TrieNode> node, std::string word, const size_t x, const size_t y, std::unordered_set<std::string>& res);
public:
	std::vector<std::string> findWords(std::vector<std::vector<char>>& board, std::vector<std::string>& words);
};

