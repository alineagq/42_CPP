#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include <cctype>

class PmergeMe {
public:
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    bool parseInput(int argc, char **argv);
    void sortContainers();
    void fordJohnsonSort(std::vector<int> &container);
    void fordJohnsonSort(std::deque<int> &container);

private:
    std::vector<int> vec;
    std::deque<int> deq;
    std::vector<int> unsortedVec;
    std::deque<int> unsortedDeq;
};

#endif
