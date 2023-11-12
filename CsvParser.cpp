#include "CsvParser.h"
#include <iostream>
#include <fstream>
#include <sstream>

CsvParser::CsvParser(std::string parseFile) : file(parseFile) {}

std::vector<std::string> CsvParser::splitCsvString(std::string str) {
    std::stringstream stream {str};
    std::string segment {};
    std::vector<std::string> output {};

    while (std::getline(stream, segment, ',')) {
        output.push_back(segment);
    }
    return output;
}

std::vector<std::string> CsvParser::getHeaders() {
    std::ifstream dataInputStream;
    dataInputStream.open(this->file);

    std::vector<std::string> parsedHeaders {};

    if (dataInputStream.is_open()) {
        std::string input {};
        std::getline(dataInputStream, input);
        parsedHeaders = splitCsvString(input);
    }

    dataInputStream.close();
    return parsedHeaders;
}

std::vector<std::vector<std::string>> CsvParser::getData() {
    std::ifstream dataInputStream;
    dataInputStream.open(this->file);

    std::vector<std::vector<std::string>> parsedRows {};
    if (dataInputStream.is_open()) {

        std::string line {};
        std::getline(dataInputStream, line); //apply getline once to avoid including headers

        while (std::getline(dataInputStream, line)) {
            parsedRows.push_back(
                splitCsvString(line)
            );
        }
    }
    return parsedRows;
};

std::map<std::string, std::vector<std::string>> CsvParser::parseAttributes() {
    std::vector<std::string> headers = getHeaders();
    std::vector<std::vector<std::string>> data = getData();
    std::map<std::string, std::vector<std::string>> output {};

    for (int index = 0; index < headers.size(); index++) {
        std::vector<std::string> relatedValues {};

        for (std::vector<std::string> row : data) {
            relatedValues.push_back(
                row.at(index)
            );
        }
        output[headers.at(index)] = relatedValues;
    }
    return output;
}