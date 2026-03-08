// 猜数字游戏
// 需求详见 docs/需求.txt
// 作者：GitHub Copilot
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <limits>

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // 初始化随机数种子
    char playAgain = 'y';
    while (playAgain == 'y' || playAgain == 'Y') {
        int target = std::rand() % 100 + 1; // 生成1到100的目标数字
        int guessCount = 0;
        std::cout << "Welcome to the Guess Number Game!\n";
        std::cout << "I have chosen a number between 1 and 100. Try to guess it!" << std::endl;
        bool guessed = false;
        while (!guessed) {
            std::cout << "Please enter your guess (1-100): ";
            std::string input;
            std::cin >> input;
            // 检查输入是否为数字
            bool isNumber = true;
            for (char c : input) {
                if (!isdigit(c)) {
                    isNumber = false;
                    break;
                }
            }
            if (!isNumber) {
                std::cout << "Invalid input, please enter a number." << std::endl;
                continue;
            }
            int guess = std::stoi(input);
            if (guess < 1 || guess > 100) {
                std::cout << "Please enter a number between 1 and 100." << std::endl;
                continue;
            }
            guessCount++;
            if (guess > target) {
                std::cout << "Too high!" << std::endl;
            } else if (guess < target) {
                std::cout << "Too low!" << std::endl;
            } else {
                std::cout << "Congratulations, you guessed it!" << std::endl;
                std::cout << "You used " << guessCount << " attempts." << std::endl;
                guessed = true;
            }
        }
        std::cout << "Play again? (y/Y to continue, any other key to exit): ";
        std::cin >> playAgain;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cout << "Thanks for playing, see you next time!" << std::endl;
    return 0;
}
