#include <iostream>
#include <string>
#include "CsvParser.h"

int main(int argc, char *argv[])
{
    //provide 2 argument 
    //1.) link to dataset 
    //2.) target variable for decision tree

    CsvParser myParser("testData.csv");
    myParser.getHeaders();



    return 0;
};