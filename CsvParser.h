#include <string>
#include <vector>

class CsvParser {
    public:
        CsvParser(std::string parseFile);
        std::vector<std::string> getHeaders();
    private:
        std::string file;
};