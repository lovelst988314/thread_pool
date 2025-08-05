#include <iostream>
#include <vector>
#include <chrono>

#include "ThreadPool.h"

int main()
{
    
    ThreadPool pool(4);
    std::vector< std::future<int> > results;

    for(int i = 0; i < 8; ++i) {
        results.emplace_back(
            pool.enqueue([i] {
                std::cout << "hello " << i << std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(1));
                std::cout << "world " << i << std::endl;
                return i*i;
            })
        );
    }

    for(auto && result: results)
        std::cout << result.get() << ' ';  // 可以拿到线程执行函数后的结果
        // future<int> myf = async(myfun,10,20)  async(myfun,10,20)就是一个异步进程 返回一个future对象
    std::cout << std::endl;
    
    return 0;
}


// 函数名就是函数的地址  因此函数名可以隐式转换成函数指针   对于普通函数可以对函数名取地址也可以不取地址
// 但是对于成员函数语法上是需要取地址的
