#include <iostream>
#include <thread>
#include <vector>


// 线程函数
void thread_entry(int* count) {
    (*count)++;
    std::cout << "Thread ID: " << std::this_thread::get_id() << ", Count: " << *count << std::endl;
}

int main() {
    const int THREAD_COUNT = 5;  // 假设 THREAD_COUNT 为 5
    int count = 0;

    // 使用 std::vector 来存储线程对象
    std::vector<std::thread> threads;

    // 创建线程
    for (int i = 0; i < THREAD_COUNT; ++i) {
        threads.emplace_back(thread_entry, &count);
        //  threads.push_back(std::thread(thread_entry, &count));
        //  thread( Function&& f, Args&&... args );  
        //  Function&& f：这是一个可调用对象（如函数、lambda 表达式、函数对象等）。
        //  Args&&... args：这是传递给可调用对象 f 的参数。
    }

    // 等待所有线程完成
    for (auto& thread : threads) {
        if (thread.joinable()) {
            thread.join();
        }
    }
    // 始终在销毁 std::thread 对象前调用 join() 或 detach()，否则程序会崩溃。

    std::cout << "Final Count: " << count << std::endl;

    return 0;
}