#include <string>
#include <vector>
#include <map>

class CsvParser {
    public:
        CsvParser(std::string parseFile);
        std::vector<std::string> getHeaders();
        std::vector<std::vector<std::string>> getData();
        std::map<std::string, std::vector<std::string>> parseAttributes();
        bool validTarget(std::string target);

    private:
        std::string file;
        std::vector<std::string> splitCsvString(std::string str);
};