#include "WordChain.hpp"

#include <string>

std::string firstUtf8Char(const std::string& str) {
    if (str.empty()) {
        return {};
    }

    unsigned char c = str[0];

    size_t length;

    if ((c & 0x80) == 0) {
        length = 1;
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

    while (
        i > 0 &&
        (static_cast<unsigned char>(str[i]) & 0xC0) == 0x80
    ) {
        --i;
    }

    return str.substr(i);
}

void WordChain::learn(const std::string& word) {
    if (word.empty()) {
        return;
    }

    std::string first = firstUtf8Char(word);

    words[first].push_back(word);
}

bool WordChain::knows(const std::string& word) const {
    std::string first = firstUtf8Char(word);

    auto it = words.find(first);

    if (it == words.end()) {
        return false;
    }

    for (const auto& known : it->second) {
        if (known == word) {
            return true;
        }
    }

    return false;
}

std::string WordChain::findNext(const std::string& word) const {
    std::string last = lastUtf8Char(word);

    auto it = words.find(last);

    if (it == words.end()) {
        return {};
    }

    if (it->second.empty()) {
        return {};
    }

    return it->second.front();
}