#include <stdio.h>
#include <thread>
#include <mutex>
#include <chrono>
#include "ticker/ticker.hpp"

int main() {
    constexpr std::chrono::seconds mainDelay{2};   // Delay for the main function

    std::mutex mtx;
    int sharedCount = 0;  

    const int maxTick = 5;
    auto ticker = Ticker::create(sharedCount, mtx, maxTick);
    ticker->start();

    while (true) {
        {
            std::lock_guard<std::mutex> lock(mtx);
            sharedCount++;
            printf("Main: Shared Count = %d\n", sharedCount);
        }
        std::this_thread::sleep_for(mainDelay);
    }

    ticker->join();

    return 0;
}

extern "C" void app_main() {
    main();
}