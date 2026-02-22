#include <iostream>
#include <string>

#include "ThreadPool.h"

int main() {
    ThreadPool pool(4); // Create a thread pool with 4 threads

    std::vector<std::future<void>> results;
    for (int i = 0; i < 10; ++i) {
        results.emplace_back(
            pool.enqueue([i](int a, int b) {
            if (i % 2 == 0)
                throw std::runtime_error("Even error!");
            std::cout << "Task executed: " << std::to_string(i + a + b) << std::endl;
        }, 10, 20)
        );
    }

    // Check results later
    for (auto& fut : results) {
        try {
            fut.get();
        } catch (const std::exception& e) {
            std::cerr << "Batch check caught: " << e.what() << std::endl;
        }
    }

    // The destructor of ThreadPool will handle joining threads
    return 0;
}