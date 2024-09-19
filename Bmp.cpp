#include "Bmp.h"


BmpImage::BmpImage(std::unique_ptr<IBmpFileReader> r, std::unique_ptr<IBmpDisplayer> d)
    : reader(std::move(r)), displayer(std::move(d)) {}

void BmpImage::openBMP(const std::string& fileName) {
    reader->openBMP(fileName);
}

void BmpImage::displayBMP() {
    auto pixels = reader->getPixelData();
    displayer->displayBMP(pixels);
}

void BmpImage::closeBMP() {
    reader->closeBMP();
}