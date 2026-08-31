#include "WordChain.hpp"

void WordChain::learn(const std::string& word) {
    if (word.empty()) {
        return;
    }

    words[word[0]].push_back(word);
}