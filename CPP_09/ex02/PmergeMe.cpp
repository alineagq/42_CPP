#include "PmergeMe.hpp"
#include <algorithm>
#include <iostream>
#include <chrono>

PmergeMe::PmergeMe(const std::vector<int>& nums) : numbers(nums) {}

void PmergeMe::sortContainer1() {
    sortedContainer1 = numbers;
    mergeSort(sortedContainer1);
}

void PmergeMe::sortContainer2() {
    sortedContainer2 = numbers;
    insertSort(sortedContainer2);
}

const std::vector<int>& PmergeMe::getSortedContainer1() const {
    return sortedContainer1;
}

void PmergeMe::mergeSort(std::vector<int>& arr) {
    if (arr.size() < 2) return;

    int mid = arr.size() / 2;
    std::vector<int> left(arr.begin(), arr.begin() + mid);
    std::vector<int> right(arr.begin() + mid, arr.end());

    mergeSort(left);
    mergeSort(right);

    std::merge(left.begin(), left.end(), right.begin(), right.end(), arr.begin());
}

void PmergeMe::insertSort(std::vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }

        arr[j + 1] = key;
    }
}
