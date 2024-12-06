#include "PmergeMe.hpp"

static void binaryInsert(std::vector<int> &sorted, int value) {
    int left = 0;
    int right = (int)sorted.size();
    while (left < right) {
        int mid = (left + right) / 2;
        if (value < sorted[mid]) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    sorted.insert(sorted.begin() + left, value);
}

// Recursively apply Merge-Insertion sort
static void mergeInsertionSort(std::vector<int> &arr) {
    size_t n = arr.size();
    if (n < 2) return;

    std::vector< std::pair<int,int> > pairs;
    pairs.reserve((n+1)/2);
    for (size_t i = 0; i < n; i += 2) {
        if (i + 1 < n) {
            if (arr[i] > arr[i+1]) 
                pairs.push_back(std::make_pair(arr[i+1], arr[i]));
            else
                pairs.push_back(std::make_pair(arr[i], arr[i+1]));
        } else {
            pairs.push_back(std::make_pair(arr[i], arr[i]));
        }
    }

    std::vector<int> firsts;
    firsts.reserve(pairs.size());
    for (std::vector< std::pair<int,int> >::iterator it = pairs.begin(); it != pairs.end(); ++it) {
        firsts.push_back(it->first);
    }

    mergeInsertionSort(firsts);

    for (size_t i = 0; i < pairs.size(); ++i) {
        if (pairs[i].first == pairs[i].second && (2*i+1 >= n)) {
            continue;
        }
        binaryInsert(firsts, pairs[i].second);
    }

    arr = firsts;
}

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) {
    this->vec = other.vec;
    this->deq = other.deq;
    this->unsortedVec = other.unsortedVec;
    this->unsortedDeq = other.unsortedDeq;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
    if (this != &other) {
        this->vec = other.vec;
        this->deq = other.deq;
        this->unsortedVec = other.unsortedVec;
        this->unsortedDeq = other.unsortedDeq;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::fordJohnsonSort(std::vector<int> &container) {
    mergeInsertionSort(container);
}

void PmergeMe::fordJohnsonSort(std::deque<int> &container) {
    std::vector<int> temp(container.begin(), container.end());
    mergeInsertionSort(temp);
    for (size_t i = 0; i < temp.size(); ++i) {
        container[i] = temp[i];
    }
}

bool PmergeMe::parseInput(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Error: No input numbers provided." << std::endl;
        return false;
    }

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        for (size_t j = 0; j < arg.length(); ++j) {
            if (!std::isdigit((unsigned char)arg[j])) {
                std::cerr << "Error: Invalid number '" << arg << "'." << std::endl;
                return false;
            }
        }
        long num = std::atol(arg.c_str());
        if (num <= 0 || num > 2147483647L) {
            std::cerr << "Error: Number out of range '" << arg << "'." << std::endl;
            return false;
        }
        int number = (int)num;
        vec.push_back(number);
        deq.push_back(number);
        unsortedVec.push_back(number);
        unsortedDeq.push_back(number);
    }
    return true;
}

void PmergeMe::sortContainers() {
    clock_t startVec = clock();
    fordJohnsonSort(vec);
    clock_t endVec = clock();
    double timeVec = (double)(endVec - startVec) / CLOCKS_PER_SEC * 1000.0; // us

    clock_t startDeq = clock();
    fordJohnsonSort(deq);
    clock_t endDeq = clock();
    double timeDeq = (double)(endDeq - startDeq) / CLOCKS_PER_SEC * 1000.0; // us

    std::cout << "Before: ";
    for (size_t i = 0; i < unsortedVec.size(); ++i) {
        std::cout << unsortedVec[i] << ((i != unsortedVec.size() - 1) ? " " : "\n");
    }

    std::cout << "After: ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << ((i != vec.size() - 1) ? " " : "\n");
    }

    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : ";
    std::cout << std::fixed << std::setprecision(5) << timeVec << " us" << std::endl;

    std::cout << "Time to process a range of " << deq.size() << " elements with std::deque : ";
    std::cout << std::fixed << std::setprecision(5) << timeDeq << " us" << std::endl;
}
