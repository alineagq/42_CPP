#include "PmergeMe.hpp"

void PmergeMe::binaryInsert(std::vector<int> &sorted, int value) {
    std::vector<int>::iterator it = std::lower_bound(sorted.begin(), sorted.end(), value);
    sorted.insert(it, value);
}

void PmergeMe::binaryInsertDeque(std::deque<int> &sorted, int value) {
    std::deque<int>::iterator it = std::lower_bound(sorted.begin(), sorted.end(), value);
    sorted.insert(it, value);
}

void PmergeMe::mergeInsertionSort(std::vector<int> &arr) {
    if (arr.size() <= 1) return;

    bool hasStraggler = (arr.size() % 2 != 0);
    int straggler = 0;
    if (hasStraggler) {
        straggler = arr.back();
        arr.pop_back();
    }

    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < arr.size(); i += 2) {
        int a = arr[i];
        int b = arr[i + 1];
        if (a > b) std::swap(a, b);
        pairs.push_back(std::make_pair(a, b));
    }

    std::vector<int> mains;
    for (size_t i = 0; i < pairs.size(); ++i)
        mains.push_back(pairs[i].second);

    mergeInsertionSort(mains);

    std::vector<int> pend;
    for (size_t i = 0; i < pairs.size(); ++i)
        pend.push_back(pairs[i].first);

    for (size_t i = 0; i < pend.size(); ++i)
        binaryInsert(mains, pend[i]);

    if (hasStraggler)
        binaryInsert(mains, straggler);

    arr = mains;
}

void PmergeMe::mergeInsertionSortDeque(std::deque<int> &arr) {
    if (arr.size() <= 1) return;

    bool hasStraggler = (arr.size() % 2 != 0);
    int straggler = 0;
    if (hasStraggler) {
        straggler = arr.back();
        arr.pop_back();
    }

    std::deque<std::pair<int, int> > pairs;
    for (size_t i = 0; i < arr.size(); i += 2) {
        int a = arr[i];
        int b = arr[i + 1];
        if (a > b) std::swap(a, b);
        pairs.push_back(std::make_pair(a, b));
    }

    std::deque<int> mains;
    for (size_t i = 0; i < pairs.size(); ++i)
        mains.push_back(pairs[i].second);

    mergeInsertionSortDeque(mains);

    std::deque<int> pend;
    for (size_t i = 0; i < pairs.size(); ++i)
        pend.push_back(pairs[i].first);

    for (size_t i = 0; i < pend.size(); ++i)
        binaryInsertDeque(mains, pend[i]);

    if (hasStraggler)
        binaryInsertDeque(mains, straggler);

    arr = mains;
}

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) {
    *this = other;
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
    mergeInsertionSortDeque(container);
}

bool PmergeMe::parseInput(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Error: No input numbers provided." << std::endl;
        return false;
    }

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg.empty()) {
            std::cerr << "Error: Empty argument." << std::endl;
            return false;
        }
        for (size_t j = 0; j < arg.length(); ++j) {
            if (!std::isdigit(arg[j])) {
                std::cerr << "Error: Invalid number '" << arg << "'." << std::endl;
                return false;
            }
        }
        long num = std::atol(arg.c_str());
        if (num <= 0 || num > 2147483647L) {
            std::cerr << "Error: Number out of range '" << arg << "'." << std::endl;
            return false;
        }
        vec.push_back(static_cast<int>(num));
        deq.push_back(static_cast<int>(num));
        unsortedVec.push_back(static_cast<int>(num));
        unsortedDeq.push_back(static_cast<int>(num));
    }
    return true;
}

long long getMicroseconds() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (long long)tv.tv_sec * 1000000 + tv.tv_usec;
}

void PmergeMe::sortContainers() {
    std::vector<int> vecCopy = unsortedVec;
    std::deque<int> deqCopy = unsortedDeq;

    long long startVec = getMicroseconds();
    fordJohnsonSort(vecCopy);
    long long timeVec = getMicroseconds() - startVec;

    deqCopy = unsortedDeq;
    
    long long startDeq = getMicroseconds();
    fordJohnsonSort(deqCopy);
    long long timeDeq = getMicroseconds() - startDeq;

    // Formatação ajustada para 5 casas decimais
    std::cout << "Time to process a range of " << vec.size() 
              << " elements with std::vector : "
              << std::fixed << std::setprecision(5) 
              << (timeVec / 1000000.0) << " s" << std::endl;
    
    std::cout << "Time to process a range of " << deq.size() 
              << " elements with std::deque : "
              << std::fixed << std::setprecision(5) 
              << (timeDeq / 1000000.0) << " s" << std::endl;
}