# ThreadPool

C++17 Thread Pool implementation.

Basic usage:
```c++
// Initialize with 4 worker threads
ThreadPool pool(4);

// Enqueue a task that returns a value
auto future = pool.enqueue([](int a, int b) {
    return a + b;
}, 10, 20);

// .get() will block until the result is ready
int result = future.get();
std::cout << "The result is: " << result << std::endl;
```
