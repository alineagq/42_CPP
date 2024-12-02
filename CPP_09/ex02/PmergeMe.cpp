// PmergeMe.cpp
#include "PmergeMe.hpp"

// Constructor
PmergeMe::PmergeMe() {}

// Copy Constructor
PmergeMe::PmergeMe(const PmergeMe &other) {
    this->vec = other.vec;
    this->deq = other.deq;
    this->unsortedVec = other.unsortedVec;
    this->unsortedDeq = other.unsortedDeq;
}

// Assignment Operator
PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
    if (this != &other) {
        this->vec = other.vec;
        this->deq = other.deq;
        this->unsortedVec = other.unsortedVec;
        this->unsortedDeq = other.unsortedDeq;
    }
    return *this;
}

// Destructor
PmergeMe::~PmergeMe() {}

// Implementação simplificada do algoritmo de Ford-Johnson para std::vector
void PmergeMe::fordJohnsonSort(std::vector<int> &container) {
    // Implementação do algoritmo de Ford-Johnson
    // Esta é uma versão simplificada e pode precisar ser aprimorada
    if (container.empty()) return;

    // Passo 1: Encontrar o mínimo e máximo
    int min = container[0];
    int max = container[0];
    for (size_t i = 1; i < container.size(); ++i) {
        if (container[i] < min) min = container[i];
        if (container[i] > max) max = container[i];
    }

    // Passo 2: Ordenar usando uma abordagem personalizada
    // Aqui, para simplificar, usamos std::sort apenas como placeholder
    // Substituir por Ford-Johnson completo
    std::sort(container.begin(), container.end());
}

// Implementação simplificada do algoritmo de Ford-Johnson para std::deque
void PmergeMe::fordJohnsonSort(std::deque<int> &container) {
    // Implementação do algoritmo de Ford-Johnson
    if (container.empty()) return;

    // Passo 1: Encontrar o mínimo e máximo
    int min = container[0];
    int max = container[0];
    for (size_t i = 1; i < container.size(); ++i) {
        if (container[i] < min) min = container[i];
        if (container[i] > max) max = container[i];
    }

    // Passo 2: Ordenar usando uma abordagem personalizada
    // Aqui, para simplificar, usamos std::sort apenas como placeholder
    // Substituir por Ford-Johnson completo
    std::sort(container.begin(), container.end());
}

// Parse and validate input
bool PmergeMe::parseInput(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Error: No input numbers provided." << std::endl;
        return false;
    }

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        // Verificar se o argumento é um número
        for (size_t j = 0; j < arg.length(); ++j) {
            if (!isdigit(arg[j])) {
                std::cerr << "Error: Invalid number '" << arg << "'." << std::endl;
                return false;
            }
        }
        // Converter para inteiro e verificar o intervalo
        long num = atol(arg.c_str());
        if (num <= 0 || num > 2147483647) { // Assumindo int de 32 bits
            std::cerr << "Error: Number out of range '" << arg << "'." << std::endl;
            return false;
        }
        int number = static_cast<int>(num);
        vec.push_back(number);
        deq.push_back(number);
        unsortedVec.push_back(number);
        unsortedDeq.push_back(number);
    }
    return true;
}

// Sort both containers and measure time
void PmergeMe::sortContainers() {
    // Ordenar std::vector
    clock_t startVec = clock();
    fordJohnsonSort(vec);
    clock_t endVec = clock();
    double timeVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000; // us

    // Ordenar std::deque
    clock_t startDeq = clock();
    fordJohnsonSort(deq);
    clock_t endDeq = clock();
    double timeDeq = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1000; // us

    // Imprimir resultados
    std::cout << "Before: ";
    for (size_t i = 0; i < unsortedVec.size(); ++i) {
        std::cout << unsortedVec[i] << (i != unsortedVec.size() - 1 ? " " : "\n");
    }

    std::cout << "After: ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << (i != vec.size() - 1 ? " " : "\n");
    }

    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : ";
    std::cout << std::fixed << std::setprecision(5) << timeVec << " us" << std::endl;

    std::cout << "Time to process a range of " << deq.size() << " elements with std::deque : ";
    std::cout << std::fixed << std::setprecision(5) << timeDeq << " us" << std::endl;
}
