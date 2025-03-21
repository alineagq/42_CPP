#include <iostream>
#include "MutantStack.hpp"

int main() {
    MutantStack<int> mstack;

    // Testing basic stack operations
    mstack.push(5);
    mstack.push(17);
    std::cout << "Top element: " << mstack.top() << std::endl;

    mstack.pop();
    std::cout << "Size after pop: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    // Testing iterator functionality
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;

    std::cout << "Stack contents:" << std::endl;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }

    // Copying to std::stack
    std::stack<int> s(mstack);

    return 0;
}
