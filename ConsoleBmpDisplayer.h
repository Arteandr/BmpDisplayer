#pragma once

#include "IBmpFileDisplayer.h"
#include <vector>

class ConsoleBmpDisplayer : public IBmpDisplayer {
public:
    void displayBMP(const std::vector<std::vector<bool>>& pixels) override;
};
