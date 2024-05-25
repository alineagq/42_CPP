#include "FileReplacer.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (s1.empty()) {
        std::cerr << "Error: The string to be replaced cannot be empty." << std::endl;
        return 1;
    }

    if (!FileReplacer::replaceInFile(filename, s1, s2)) {
        return 1;
    }

    return 0;
}
