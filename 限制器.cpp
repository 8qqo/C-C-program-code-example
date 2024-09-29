#include <iostream>
#include <string>
#include <vector>
#include <conio.h> // For _getch() function
#include <windows.h>
#include <tlhelp32.h>

bool authenticate() {
    const std::string password = "10306108"; // ��惡�B���z�Q�n���K�X
    std::string inputPassword;
    
    std::cout << "Enter password to terminate the program: ";
    
    char ch;
    while ((ch = _getch()) != '\r') { // �v��Ū���r�šA������U Enter ��
        if (ch == '\b') { // �B�z�h����
            if (!inputPassword.empty()) {
                std::cout << "\b \b"; // �q����x�R���r��
                inputPassword.pop_back(); // �q�K�X�r�Ŧꤤ�R���̫�@�Ӧr��
            }
        } else {
            std::cout << '*'; // ���C�Ӧr�ť��L�P��
            inputPassword += ch; // �N�r�ŲK�[��K�X�r�Ŧ�
        }
    }
    std::cout << std::endl;

    return inputPassword == password;
}

bool isProcessRunning(const std::string& processName) {
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hSnapshot == INVALID_HANDLE_VALUE) {
        std::cerr << "CreateToolhelp32Snapshot failed, error " << GetLastError() << std::endl;
        return false;
    }

    PROCESSENTRY32 pe;
    pe.dwSize = sizeof(pe);
    if (!Process32First(hSnapshot, &pe)) {
        CloseHandle(hSnapshot);
        std::cerr << "Process32First failed, error " << GetLastError() << std::endl;
        return false;
    }

    do {
        if (processName == pe.szExeFile) {
            CloseHandle(hSnapshot);
            return true;
        }
    } while (Process32Next(hSnapshot, &pe));

    CloseHandle(hSnapshot);
    return false;
}

bool terminateProcessByName(const std::string& processName) {
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hSnapshot == INVALID_HANDLE_VALUE) {
        std::cerr << "CreateToolhelp32Snapshot failed, error " << GetLastError() << std::endl;
        return false;
    }

    PROCESSENTRY32 pe;
    pe.dwSize = sizeof(pe);
    if (!Process32First(hSnapshot, &pe)) {
        CloseHandle(hSnapshot);
        std::cerr << "Process32First failed, error " << GetLastError() << std::endl;
        return false;
    }

    bool terminated = false;
    do {
        if (processName == pe.szExeFile) {
            HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, FALSE, pe.th32ProcessID);
            if (hProcess == NULL) {
                std::cerr << "OpenProcess failed, error " << GetLastError() << std::endl;
                CloseHandle(hSnapshot);
                return false;
            }

            if (!TerminateProcess(hProcess, 0)) {
                std::cerr << "TerminateProcess failed, error " << GetLastError() << std::endl;
            } else {
                std::cout << "Terminated process: " << processName << " (PID: " << pe.th32ProcessID << ")" << std::endl;
                terminated = true;
            }

            CloseHandle(hProcess);
        }
    } while (Process32Next(hSnapshot, &pe));

    CloseHandle(hSnapshot);
    return terminated;
}

int main() {
    std::cout << "Program is running..." << std::endl;

    while (true) {
        if (authenticate()) {
            std::cout << "Correct password. Terminating the program..." << std::endl;
            break;
        } else {
            std::cout << "Incorrect password. Try again." << std::endl;
        }
    }

    // �b���B��m�z���{���޿�
    const std::vector<std::string> processesToCheck = { "chrome.exe", "msedge.exe" };

    while (true) {
        for (const auto& processName : processesToCheck) {
            if (isProcessRunning(processName)) {
                std::cout << processName << " is running. Terminating..." << std::endl;
                terminateProcessByName(processName);
            } else {
                std::cout << processName << " is not running." << std::endl;
            }
        }
        Sleep(1000); // ����1��A���ˬd
    }

    return 0;
}

