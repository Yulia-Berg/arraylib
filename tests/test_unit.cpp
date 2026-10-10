#include "arraylib.h"

#include <cassert>
#include <cmath>
#include <cstddef>
#include <iostream>

static bool close(double a, double b, double eps = 1e-9) {
    return std::fabs(a - b) < eps;
}

int main() {
    // Массив с положительными, отрицательными элементами и нулём.
    int a[] = {-5, 0, 3, 3, 8, -2};
    const std::size_t n = sizeof(a) / sizeof(a[0]);

    assert(arr_sum(a, n) == 7);
    assert(arr_max(a, n) == 8);
    assert(arr_min(a, n) == -5);

    assert(arr_count_positive(a, n) == 3);
    assert(arr_count_negative(a, n) == 2);
    assert(arr_count_zero(a, n) == 1);

    assert(arr_product(a, n) == 0);
    assert(close(arr_average(a, n), 7.0 / 6.0));

    // Медиана массива чётного размера.
    int b[] = {7, 1, 9, 3};
    assert(close(arr_median(b, 4), 5.0));

    // Медиана массива нечётного размера.
    int c[] = {5, 1, 3};
    assert(close(arr_median(c, 3), 3.0));

    // Медиана не должна изменять исходный массив.
    int source[] = {7, 1, 9, 3};
    int source_copy[] = {7, 1, 9, 3};

    arr_median(source, 4);

    for (std::size_t i = 0; i < 4; ++i) {
        assert(source[i] == source_copy[i]);
    }

    // Произведение без переполнения.
    int d[] = {1, 2, 3, 4};
    assert(arr_product(d, 4) == 24);

    std::cout << "[unit] All tests passed\n";

    return 0;
}