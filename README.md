# ThreadPool (C++17)

A lightweight, high-performance, and header-only **ThreadPool** implementation written in modern C++17. This library allows you to easily manage a pool of worker threads to execute tasks asynchronously, retrieve results via `std::future`, and ensure system stability with built-in exception safety.


## 🚀 Features

* **C++17 Standards**: Uses `std::invoke_result_t`, variadic templates, and perfect forwarding for type-safe and efficient task dispatching.
* **Future-Based Results**: The `enqueue` method returns a `std::future`, enabling the caller to retrieve return values or wait for task completion.
* **Thread Safety**: Internal synchronization is handled via `std::mutex` and `std::condition_variable`. The `std::mutex` specifically protects the `std::queue`, ensuring that concurrent `enqueue` and worker `pop` operations are thread-safe.
* **Exception Safety**: A robust `try-catch` block inside the worker loop prevents an unhandled exception in a single task from terminating the worker thread.
* **Graceful Shutdown**: The destructor handles the cleanup process by setting a stop flag, waking all threads, and joining them only after the remaining tasks in the queue are completed.

## 🛠 Dependencies

* **Compiler**: A C++17 compliant compiler (GCC 7+, Clang 5+, or MSVC 19.14+).
* **Library**: Requires the `pthread` library on Linux/Unix systems (link with `-pthread`).

## 💻 Usage Example

### 1. Basic Task with Return Value
You can pass any callable (lambdas, functions, or member functions) with any number of arguments.

```cpp
#include "ThreadPool.h"
#include <iostream>

int main() {
    ThreadPool pool(4); // Create a pool with 4 worker threads

    auto future = pool.enqueue([](int a, int b) {
        return a + b;
    }, 10, 20);

    // Retrieve result
    std::cout << "Result: " << future.get() << std::endl;

    return 0;
}
