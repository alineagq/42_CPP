#ifndef FILEREPLACER_HPP
#define FILEREPLACER_HPP

#include <string>

class FileReplacer {
public:
    static bool replaceInFile(const std::string& filename, const std::string& s1, const std::string& s2);
};

#endif
