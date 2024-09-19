#include "Bmp.h"
#include "BmpFileReader.h"
#include "ConsoleBmpDisplayer.h"
#include <iostream>
#include <memory>

int main(int argc, char* argv[]) {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	if (argc != 2) {
		std::cerr << "�������������: bmp-drawer.exe <����_�_BMP_�����>" << std::endl;
		return 1;
	}

	std::string fileName = argv[1];
	
	try {
		auto reader = std::make_unique<BmpFileReader>();
		auto displayer = std::make_unique<ConsoleBmpDisplayer>();
		BmpImage bmpImage(std::move(reader), std::move(displayer));

		bmpImage.openBMP(fileName);
		bmpImage.displayBMP();
		bmpImage.closeBMP();

	}
	catch (const std::exception& e) {
		std::cerr << "������: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}