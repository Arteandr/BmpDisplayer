#include "BmpFileReader.h"

#include <stdexcept>

void BmpFileReader::openBMP(const std::string& fileName) {
	file.open(fileName, std::ios::binary);
	if (!file)
		throw std::runtime_error("Не удалось открыть файл");

	file.read(reinterpret_cast<char*>(&fileHeader), sizeof(fileHeader));
	file.read(reinterpret_cast<char*>(&infoHeader), sizeof(infoHeader));

	if (infoHeader.biBitCount != 24 && infoHeader.biBitCount != 32)
		throw std::runtime_error("Поддерживаются только 24 и 32-битные BMP");

	int width = infoHeader.biWidth;
	int height = abs(infoHeader.biHeight);
	pixels.resize(height, std::vector<bool>(width, false));

	int padding = (4 - (width * (infoHeader.biBitCount / 8)) % 4) % 4;
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			unsigned char color[4] = { 0 };
			file.read(reinterpret_cast<char*>(color), infoHeader.biBitCount / 8);
			bool isBlack = color[0] == 0 && color[1] == 0 && color[2] == 0;
			pixels[height - i - 1][j] = isBlack;
		}
		file.ignore(padding);
	}
}

std::vector<std::vector<bool>> BmpFileReader::getPixelData() {
	return pixels;
}

void BmpFileReader::closeBMP() {
	if (file.is_open())
		file.close();
}
