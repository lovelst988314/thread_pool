#include <iostream>
#include <thread>
#include <future>
#include <chrono>

// 异步任务函数
void async_task(std::promise<int> prom) {
    // 模拟异步操作
    std::this_thread::sleep_for(std::chrono::seconds(1));
    prom.set_value(42); // 设置异步操作的结果
}

int main() {
    // 创建一个 promise 对象
    std::promise<int> prom;

    // 通过 promise 获取关联的 future 对象
    std::future<int> fut = prom.get_future();

    // 启动异步任务，并将 promise 传递给它
    std::thread t(async_task, std::move(prom));

    // 在主线程中等待异步操作完成并获取结果
    try {
        std::cout << "The result is " << fut.get() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    // 等待线程结束
    t.join();

    return 0;
}