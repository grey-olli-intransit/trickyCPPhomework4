#include <iostream>
#include <vector>
#include <numeric>
#include "printVector.h"

// Имеется отсортированный массив целых чисел. Необходимо разработать функцию insert_sorted,
// которая принимает вектор и новое число и вставляет новое число в определенную позицию в векторе,
// чтобы упорядоченность контейнера сохранялась.
// Реализуйте шаблонную функцию insert_sorted, которая сможет аналогично работать с любым контейнером,
// содержащим любой тип значения.
template <typename T>
void insert_sorted(std::vector<T> & sortedVector, const T & value ) {
      auto result = std::find_if(std::begin(sortedVector),
                               std::end(sortedVector),
                               [ &value](const T & val) {
        return val >= value;
    });
    if(result != std::end(sortedVector))
        sortedVector.insert(result,value);
    else
        sortedVector.template emplace_back(value);
}

// Сгенерируйте вектор a, состоящий из 100 вещественный чисел, представляющий собой значения
//  аналогового сигнала. На основе этого массива чисел создайте другой вектор целых чисел b,
//  представляющий цифровой сигнал, в котором будут откинуты дробные части чисел.
//  Выведите получившиеся массивы чисел. Посчитайте ошибку, которой обладает цифровой сигнал по
//  сравнению с аналоговым по формуле:
//Сумма от 0 до N-1 (ai-bi)^2 ,
//где:
//N - количество элементов в векторе,
//a - элемент вектора с дробными числами,
//b - элемент вектора с целыми числами.
//Постарайтесь воспользоваться алгоритмическими функциями, не используя циклы.

int main() {
    constexpr int size=100;
    std::vector<double> a(size), c(size);
    std::vector<int> b(size);
    generate (a.begin(), a.end(), [](){ return static_cast<double> (rand() % 100) / 10.0;});
    std::cout << "Аналоговый сигнал: ";
    printVector(a);
    std::transform(a.begin(),a.end(),b.begin(),[](double & var)->int {return static_cast<int>(var);});
    std::cout << "Цифровой сигнал:   ";
    printVector(b);
    std::transform(a.begin(),a.end(),b.begin(),c.begin(),
                   [](const double & var, const int & other)->double {
        return static_cast<double>((var-other)*(var-other));});
    std::cout << "Дельты:            ";
    printVector(c);
    double deltaError = std::accumulate(c.begin(),c.end(),0.0);
    std::cout << "суммарная ошибка (сумма квадратов дельт): " << deltaError << std::endl;

    std::vector<int> vec{1,2,3,4,5,6,7};
    std::cout << "Original vector: " << std::endl;
    printVector(vec);
    insert_sorted(vec,2);
    std::cout << "After 'insert_sorted(vec,2);':" << std::endl;
    printVector(vec);
    insert_sorted(vec,32);
    std::cout << "After 'insert_sorted(vec,32);':" << std::endl;
    printVector(vec);
    return 0;
}
