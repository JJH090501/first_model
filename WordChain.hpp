#pragma once

#include <string>
#include <unordered_map>
#include <vector>

class WordChain {
private:
    std::unordered_map<std::string, std::vector<std::string>> words;

public:
    void learn(const std::string& word);

    std::string findNext(const std::string& word) const;

    bool knows(const std::string& word) const;

    void load(const std::string& filename);

    void save(const std::string& filename) const;
};