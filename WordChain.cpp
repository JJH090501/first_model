#include "WordChain.hpp"

void WordChain::learn(const std::string& word) {
    if (word.empty()) {
        return;
    }

    words[word[0]].push_back(word);
}

bool WordChain::knows(const std::string& word) const {
    for (const auto& [_, list] : words) {
        for (const auto& known : list) {
            if (known == word) {
                return true;
            }
        }
    }

    return false;
}