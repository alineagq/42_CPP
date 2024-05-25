#include "FileReplacer.hpp"
#include <fstream>
#include <iostream>

bool FileReplacer::replaceInFile(const std::string& filename, const std::string& s1, const std::string& s2) {
    std::ifstream inFile(filename.c_str());
    if (!inFile) {
        std::cerr << "Error: Could not open input file." << std::endl;
        return false;
    }

    std::string outFilename = filename + ".replace";
    std::ofstream outFile(outFilename.c_str());
    if (!outFile) {
        std::cerr << "Error: Could not create output file." << std::endl;
        inFile.close();
        return false;
    }

    std::string line;
    while (std::getline(inFile, line)) {
        size_t pos;
        while ((pos = line.find(s1)) != std::string::npos) {
            line.erase(pos, s1.length());
            line.insert(pos, s2);
        }
        outFile << line << std::endl;
    }

    inFile.close();
    outFile.close();
    return true;
}
