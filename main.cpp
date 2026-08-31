#include <iostream>
#include <string>

#include "WordChain.hpp"

int main() {
    WordChain ai;

    ai.load("words.txt");

    std::string word;

    while (true) {
        std::cout << "You: ";
        std::cin >> word;

        if (word == "/quit") {
            ai.save("words.txt");
            break;
        }

        std::string next = ai.findNext(word);

        if (next.empty()) {
            std::cout << "AI: \"" << word
                      << "\" 다음 단어를 모르겠어.\n";

            std::cout << "AI에게 단어를 가르쳐 주세요: ";

            std::string learned;
            std::cin >> learned;

            ai.learn(learned);

            std::cout << "AI: \"" << learned
                      << "\"를 배웠어!\n";
        } else {
            std::cout << "AI: " << next << '\n';
        }
    }

    return 0;
}