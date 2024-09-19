#pragma once

#include "IBmpFileReader.h"
#include <string>
#include <vector>
#include <fstream>
#include <windows.h>

class BmpFileReader : public IBmpFileReader {
private:
    std::ifstream file;
    BITMAPFILEHEADER fileHeader;
    BITMAPINFOHEADER infoHeader;
    std::vector<std::vector<bool>> pixels;

public:
    void openBMP(const std::string& fileName) override;
    std::vector<std::vector<bool>> getPixelData() override;
    void closeBMP() override;
};
