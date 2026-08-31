#include <iostream>
#include "WordChain.hpp"

int main() {
    WordChain ai;

    std::cout << "끝말잇기 AI\n";
    std::cout << "단어를 입력하세요. /quit으로 종료\n\n";

    std::string word;

    while (true) {
        std::cout << "You: ";
        std::cin >> word;

        if (word == "/quit") {
            break;
        }

        if (!ai.knows(word)) {
            std::cout << "AI: 나는 아직 \"" << word << "\"를 몰라.\n";
            std::cout << "AI에게 이 단어를 가르쳐 주세요.\n";
            ai.learn(word);
            continue;
        }

        std::cout << "AI: 배운 단어야!\n";
    }
}