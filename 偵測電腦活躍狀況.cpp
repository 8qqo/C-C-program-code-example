#include <iostream>
#include <windows.h>

void displayBinary(DWORD value) {
    for (int i = 31; i >= 0; --i) {
        std::cout << ((value >> i) & 1);
    }
}

int main() {
    while (true) {
        // ���CPU�ϥβv
        PDH_HQUERY query;
        PDH_HCOUNTER counter;
        PdhOpenQuery(NULL, 0, &query);
        PdhAddCounter(query, "\\Processor(_Total)\\% Processor Time", 0, &counter);
        PdhCollectQueryData(query);
        Sleep(1000);
        PdhCollectQueryData(query);
        PDH_FMT_COUNTERVALUE value;
        PdhGetFormattedCounterValue(counter, PDH_FMT_LONG, NULL, &value);

        // ���CPU�ϥβv
        std::cout << "CPU �ϥβv: ";
        displayBinary(static_cast<DWORD>(value.longValue));
        std::cout << std::endl << std::endl;

        // ���CPU�֤߼�
        SYSTEM_INFO sysInfo;
        GetSystemInfo(&sysInfo);

        // ���CPU�֤߼�
        std::cout << "CPU �֤߼�: ";
        displayBinary(static_cast<DWORD>(sysInfo.dwNumberOfProcessors));
        std::cout << std::endl << std::endl;
    }

    return 0;
}

