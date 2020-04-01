#include "WordSearch.h"


bool WordSearch::dfs(std::vector<std::vector<char>>& board, std::shared_ptr<TrieNode> node, std::string word, const size_t x, const size_t y, std::unordered_set<std::string>& res) {
	if ((x < 0) || (x >= board.size()) || (y < 0) || (y >= board[0].size()) || board[x][y] == '{') {
		return false;
	}
	char c(board[x][y]);
	if (node->next_letters[c - 'a'] != nullptr) {
		word.push_back(c);
		std::shared_ptr<TrieNode> node_cp = node;
		node = node->next_letters[c - 'a'];
		bool ans(false);
		if (node->end_word) {
			res.insert(word);
		}
		board[x][y] = '{';
		ans = (dfs(board, node, word, x + 1, y, res) ||
			dfs(board, node, word, x - 1, y, res) ||
			dfs(board, node, word, x, y + 1, res) ||
			dfs(board, node, word, x, y - 1, res));
		board[x][y] = c;
		node = node_cp;
		return ans;
	}
	else {
		return false;
	}
}

std::vector<std::string> WordSearch::findWords(std::vector<std::vector<char>>& board, std::vector<std::string>& words) {
	std::unordered_set<std::string> res = {};
	std::shared_ptr<TrieNode> root(build_trie(words));
	for (size_t i(0); i < board.size(); i++) {
		for (size_t j(0); j < board[0].size(); j++) {
			dfs(board, root, "", i, j, res);
		}
	}
	std::vector<std::string> found_words;
	for (const std::string& w : res) {
		found_words.push_back(w);
	}
	return found_words;
}