#include <iterator>

template <typename T>
void printVector(const std::vector<T> & vec) {
    std::copy(vec.begin(),vec.end(),std::ostream_iterator<T>(std::cout," "));
    std::cout << std::endl;
}

