#include <iostream>
#include <windows.h>
using namespace std;

void displayBinary(DWORD value) {
    for (int i = 31; i >= 0; --i) {
        std::cout << ((value >> i) & 1);
    }
}

int main() {
    while (true) {
        // 獲取CPU使用率
        PDH_HQUERY query;
        PDH_HCOUNTER counter;
        PdhOpenQuery(NULL, 0, &query);
        PdhAddCounter(query, "\\Processor(_Total)\\% Processor Time", 0, &counter);
        PdhCollectQueryData(query);
        Sleep(1000);
        PdhCollectQueryData(query);
        PDH_FMT_COUNTERVALUE value;
        PdhGetFormattedCounterValue(counter, PDH_FMT_LONG, NULL, &value);

        // 顯示CPU使用率
        cout << "CPU 使用率: ";
        displayBinary(static_cast<DWORD>(value.longValue));
        cout << std::endl << std::endl;

        // 獲取CPU核心數
        SYSTEM_INFO sysInfo;
        GetSystemInfo(&sysInfo);

        // 顯示CPU核心數
        cout << "CPU 核心數: ";
        displayBinary(static_cast<DWORD>(sysInfo.dwNumberOfProcessors));
         cout << std::endl << std::endl;
    }

    return 0;
}

