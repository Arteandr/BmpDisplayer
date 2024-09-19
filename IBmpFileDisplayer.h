#pragma once

#include <vector>

class IBmpDisplayer {
public:
    virtual void displayBMP(const std::vector<std::vector<bool>>& pixels) = 0;
    virtual ~IBmpDisplayer() = default;
};
