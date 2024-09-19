#include "ConsoleBmpDisplayer.h"
#include <iostream>

void ConsoleBmpDisplayer::displayBMP(const std::vector<std::vector<bool>>& pixels) {
    for (const auto& row : pixels) {
        for (bool isBlack : row) {
            std::cout << (isBlack ? '#' : ' ');
        }
        std::cout << std::endl;
    }
}