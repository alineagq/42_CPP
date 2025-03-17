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
#include <sys/time.h>

class PmergeMe {
public:
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    bool parseInput(int argc, char **argv);
    void sortContainers();

private:
    std::vector<int> vec;
    std::deque<int> deq;
    std::vector<int> unsortedVec;
    std::deque<int> unsortedDeq;

    void fordJohnsonSort(std::vector<int> &container);
    void fordJohnsonSort(std::deque<int> &container);
    void mergeInsertionSort(std::vector<int> &arr);
    void mergeInsertionSortDeque(std::deque<int> &arr);
    void binaryInsert(std::vector<int> &sorted, int value);
    void binaryInsertDeque(std::deque<int> &sorted, int value);
};

#endif