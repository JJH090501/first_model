#include <iostream>
#include <string>

std::string firstUtf8Char(const std::string& str);
std::string lastUtf8Char(const std::string& str);

int main() {
    std::string word;

    std::cout << "단어 입력: ";
    std::cin >> word;

    std::cout << "입력: " << word << '\n';
    std::cout << "바이트 수: " << word.size() << '\n';
    std::cout << "첫 글자: " << firstUtf8Char(word) << '\n';
    std::cout << "마지막 글자: " << lastUtf8Char(word) << '\n';

    return 0;
}