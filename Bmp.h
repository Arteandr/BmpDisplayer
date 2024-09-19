#pragma once

#include "IBmpFileReader.h"
#include "IBmpFileDisplayer.h"
#include <memory>
#include <string>

class BmpImage {
private:
    std::unique_ptr<IBmpFileReader> reader;
    std::unique_ptr<IBmpDisplayer> displayer;

public:
    BmpImage(std::unique_ptr<IBmpFileReader> r, std::unique_ptr<IBmpDisplayer> d);
    void openBMP(const std::string& fileName);
    void displayBMP();
    void closeBMP();
};
