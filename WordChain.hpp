#pragma once

#include <string>
#include <unordered_map>
#include <vector>

class WordChain {
private:
    // 마지막 글자 → 그 글자로 시작하는 단어들
    std::unordered_map<std::string, std::vector<std::string>> words;

public:
    void learn(const std::string& word);

    std::string findNext(const std::string& word) const;

    bool knows(const std::string& word) const;
};