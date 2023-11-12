#include <iostream>
#include <string>
#include <filesystem>
#include "CsvParser.h"

int main(int argc, char *argv[])
{
    if (argc < 2) {
        std::cout << "MISSING ARGUMENT(S): expected 2, found " << (argc - 1) << '\n';
        return 1;
    }

    std::string filePath = argv[1];
    if (!std::filesystem::exists(filePath)) {
        std::cout << "No file found at: " << filePath << std::endl;
        return 1;
    }

    CsvParser parser(filePath);
    std::string targetAttribute = argv[2];
    if (parser.validTarget(targetAttribute)) {
        std::cout << "INVALID TARGET: target attribute not part of headers. " << (argc - 1) << '\n';
        return 1;
    }

    return 0;
};