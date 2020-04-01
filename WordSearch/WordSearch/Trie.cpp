#include "Trie.h"
#include <string>
#include <iostream>	


std::shared_ptr<TrieNode> build_trie(const std::vector<std::string>& words) {
	std::shared_ptr<TrieNode> root(new TrieNode);
	std::shared_ptr<TrieNode> node(root);
	for (const auto& word : words) {
		node = root;
		for (const auto& c : word) {
			if (node->next_letters[c - 'a'] == nullptr) {
				node->next_letters[c - 'a'] = std::make_shared<TrieNode>();
			}
			node = node->next_letters[c - 'a'];
		}
		node->end_word = true;
	}
	return root;
}

void print_trie(std::shared_ptr<TrieNode> root) {
	for (const auto& l : root->next_letters) {
		if (l == nullptr) {
			std::cout << "nullptr" << std::endl;
		}
		else {
			if (l->end_word == true) {
				std::cout << l << std::endl;
				std::cout << "end word" << std::endl;
				break;
			}
			else {
				std::cout << l << std::endl << std::endl;
				print_trie(l);
			}
			std::cout << std::endl;
		}
	}
}