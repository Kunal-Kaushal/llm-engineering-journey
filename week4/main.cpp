
#include <iostream>
#include <vector>
#include <thread>
#include <iomanip>
#include <chrono>
#include <algorithm>

// Worker function for each thread.
// It calculates a partial sum over a given range of iterations.
// The formula is an algebraic simplification of the original loop's operations
// to reduce the number of floating-point operations, especially divisions.
// Original: result += 1.0 / (i*p1 + p2) - 1.0 / (i*p1 - p2)
// Simplified: result += -2.0*p2 / ((i*p1)^2 - p2^2)
double calculate_partial_sum(long long start_iter, long long end_iter, double param1, double param2) {
    double partial_sum = 0.0;
    const double p1_sq = param1 * param1;
    const double p2_sq = param2 * param2;
    const double numerator = -2.0 * param2;

    for (long long i = start_iter; i <= end_iter; ++i) {
        double i_d = static_cast<double>(i);
        partial_sum += numerator / (p1_sq * i_d * i_d - p2_sq);
    }
    return partial_sum;
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);

    // Constants from the Python code
    constexpr long long iterations = 200'000'000;
    constexpr double param1 = 4.0;
    constexpr double param2 = 1.0;

    auto start_time = std::chrono::high_resolution_clock::now();

    // Determine the number of threads to use, defaults to 1 if not available
    const unsigned int num_threads = std::max(1u, std::thread::hardware_concurrency());
    std::vector<std::thread> threads;
    threads.reserve(num_threads);
    std::vector<double> partial_results(num_threads);

    const long long chunk_size = iterations / num_threads;

    // Launch threads to compute partial sums in parallel
    for (unsigned int i = 0; i < num_threads; ++i) {
        const long long start = i * chunk_size + 1;
        const long long end = (i == num_threads - 1) ? iterations : (i + 1) * chunk_size;

        threads.emplace_back([&partial_results, i, start, end, param1, param2]() {
            if (start <= end) {
                partial_results[i] = calculate_partial_sum(start, end, param1, param2);
            } else {
                partial_results[i] = 0.0;
            }
        });
    }

    // jthreads will automatically join at the end of this scope.

    // Aggregate the results from all threads
    double result = 1.0;
    for(double partial : partial_results) {
        result += partial;
    }
    result *= 4.0;

    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end_time - start_time;

    // Print the final result and execution time, matching Python's output format
    std::cout << "Result: " << std::fixed << std::setprecision(12) << result << '\n';
    std::cout << "Execution Time: " << std::fixed << std::setprecision(6) << diff.count() << " seconds\n";

    return 0;
}
