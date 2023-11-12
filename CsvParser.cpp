#include "CsvParser.h"
#include <iostream>
#include <fstream>
#include <sstream>

CsvParser::CsvParser(std::string parseFile) : file(parseFile) {}

std::vector<std::string> CsvParser::getHeaders() {
    std::vector<std::string> parsedVectors;
    std::ifstream dataInputStream;
    dataInputStream.open(this->file);

    if (dataInputStream.is_open()) {
        std::string input;
        std::getline(dataInputStream, input);

        std::stringstream headerStream(input);
        std::string segment;
        while (std::getline(headerStream, segment, ',')) {
            parsedVectors.push_back(segment);
        }
    }

    return parsedVectors;
}