#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <vector>

class PmergeMe {
public:
    PmergeMe(const std::vector<int>& nums);

    void sortContainer1();
    void sortContainer2();

    const std::vector<int>& getSortedContainer1() const;

private:
    std::vector<int> numbers;
    std::vector<int> sortedContainer1;
    std::vector<int> sortedContainer2;

    void mergeSort(std::vector<int>& arr);
    void insertSort(std::vector<int>& arr);
};

#endif // PMERGE_ME_HPP
