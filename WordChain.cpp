#include "WordChain.hpp"

std::string firstUtf8Char(const std::string& str) {
    if (str.empty()) {
        return {};
    }

    unsigned char c = str[0];

    size_t length;

    if ((c & 0x80) == 0) {
        length = 1;       // ASCII
    } else if ((c & 0xE0) == 0xC0) {
        length = 2;
    } else if ((c & 0xF0) == 0xE0) {
        length = 3;
    } else if ((c & 0xF8) == 0xF0) {
        length = 4;
    } else {
        return {};
    }

    return str.substr(0, length);
}

std::string lastUtf8Char(const std::string& str) {
    if (str.empty()) {
        return {};
    }

    size_t i = str.size() - 1;

    // UTF-8 continuation byte:
    // 10xxxxxx
    while (i > 0 && (static_cast<unsigned char>(str[i]) & 0xC0) == 0x80) {
        --i;
    }

    return str.substr(i);
}

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

// stub
std::string WordChain::findNext(const std::string& word) const {
    if (word.empty()) {
        return {};
    }

    // 임시 구현
    auto it = words.find(word.back());

    if (it == words.end() || it->second.empty()) {
        return {};
    }

    return it->second.front();
}