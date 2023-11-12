#include <iostream>
#include <string>
#include "CsvParser.h"

int main(int argc, char *argv[])
{
    //provide 2 argument 
    //1.) link to dataset 
    //2.) target variable for decision tree

    CsvParser myParser("testData.csv");
    std::vector<std::string> headers = myParser.getHeaders();
    std::map<std::string, std::vector<std::string>> fixedData = myParser.parseAttributes();


    for (std::string att : headers) {
        std::cout << att << " ==> ";
        for (int i = 0; i < fixedData[att].size(); i++) {
            std::cout << fixedData[att].at(i) << ", ";
        }
        std::cout << '\n';
    }
    return 0;
};