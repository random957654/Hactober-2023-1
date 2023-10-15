#include <iostream>
#include <thread>
#include <vector>
#include <cmath>
#include <mutex>

std::mutex printMutex;

void generatePrimes(int start, int end, std::vector<int>& primes) {
    for (int i = start; i <= end; ++i) {
        bool isPrime = true;
        for (int j = 2; j <= std::sqrt(i); ++j) {
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            std::lock_guard<std::mutex> lock(printMutex);
            primes.push_back(i);
        }
    }
}

int main() {
    const int numThreads = 4;
    const int rangeStart = 1;
    const int rangeEnd = 1000;

    std::vector<int> primes;
    std::vector<std::thread> threads;

    int step = (rangeEnd - rangeStart + 1) / numThreads;

    for (int i = 0; i < numThreads; ++i) {
        int start = rangeStart + i * step;
        int end = (i == numThreads - 1) ? rangeEnd : start + step - 1;
        threads.emplace_back(generatePrimes, start, end, std::ref(primes));
    }

    for (auto& thread : threads) {
        thread.join();
    }

    std::cout << "Prime numbers between " << rangeStart << " and " << rangeEnd << " are: ";
    for (const auto& prime : primes) {
        std::cout << prime << " ";
    }
    std::cout << std::endl;

    return 0;
}
