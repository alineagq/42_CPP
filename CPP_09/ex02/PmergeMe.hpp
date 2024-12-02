// PmergeMe.hpp
#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <sstream>
#include <algorithm> // Adicionado para std::sort

class PmergeMe {
private:
    std::vector<int> vec;
    std::deque<int> deq;
    std::vector<int> unsortedVec;
    std::deque<int> unsortedDeq;

    // Helper function for Ford-Johnson algorithm
    void fordJohnsonSort(std::vector<int> &container);
    void fordJohnsonSort(std::deque<int> &container);

    // Additional helper functions as needed

public:
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    bool parseInput(int argc, char **argv);
    void sortContainers();
    void printResults();
};

#endif // PMERGEME_HPP
