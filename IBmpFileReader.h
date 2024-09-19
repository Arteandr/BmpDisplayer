#pragma once

#include <string>
#include <vector>

class IBmpFileReader {
public:
    virtual void openBMP(const std::string& fileName) = 0;
    virtual std::vector<std::vector<bool>> getPixelData() = 0;
    virtual void closeBMP() = 0;
    virtual ~IBmpFileReader() = default;
};
