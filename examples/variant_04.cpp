#include "arraylib.h"

#include <cstddef>
#include <iomanip>
#include <iostream>

int main() {
    int times[] = {
        248, 261, 239, 275, 252,
        244, 268, 231, 257, 249
    };

    const std::size_t n = sizeof(times) / sizeof(times[0]);

    int faster_than_250 = 0;

    for (std::size_t i = 0; i < n; ++i) {
        if (times[i] < 250) {
            ++faster_than_250;
        }
    }

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "Лучшее время: "
              << arr_min(times, n) << " с\n";

    std::cout << "Худшее время: "
              << arr_max(times, n) << " с\n";

    std::cout << "Среднее время: "
              << arr_average(times, n) << " с\n";

    std::cout << "Медиана времени: "
              << arr_median(times, n) << " с\n";

    std::cout << "Результатов быстрее 250 секунд: "
              << faster_than_250 << '\n';

    return 0;
}