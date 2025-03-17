#include "PmergeMe.hpp"

int main(int argc, char **argv) {
    PmergeMe sorter;

    if (!sorter.parseInput(argc, argv))
        return 1;

    sorter.sortContainers();
    return 0;
}