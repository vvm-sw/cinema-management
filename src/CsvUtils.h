#ifndef _CSVU_TILS_H
#define _CSV_UTILS_H
#include <string>
#include <algorithm>
#include <fstream>
class CsvUtils {
public:
    static std::string escapeCSV(const std::string& s) {
        std::string r = s;
        std::replace(r.begin(), r.end(), ',', ';');
        return r;
    }
    static int getNextId(const std::string& filepath) {
       std::ifstream in(filepath);
       std::ofstream out(filepath);
       std::string idStr;
       std::getline(in, idStr);
       int id = std::stoi(idStr);
       out << id+1;
       return id;
    }

    static bool validaFilepath(const std::string& filepath) {
        return false;
    }
};
#endif