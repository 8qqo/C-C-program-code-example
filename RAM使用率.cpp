#include <iostream>
#include <windows.h>
#include <psapi.h>

void printBinary(unsigned long long value) {
    for (int i = 63; i >= 0; --i) {
        std::cout << ((value >> i) & 1);
        if (i % 8 == 0) std::cout << ' ';
    }
    std::cout << std::endl;
}
// Binary conversion 

void setColor(WORD color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
//color's fuction

void CMD() {
    		// command to execute
    		LPCTSTR command = TEXT("ipconfig /all");

    		// start new process
    		STARTUPINFO si = {sizeof(STARTUPINFO)};
    		PROCESS_INFORMATION pi;

    		if (CreateProcess(NULL,   // Application name, NULL here
                      (LPTSTR)command,  // Command Line
                      NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
        	// Wait for process to end
        	WaitForSingleObject(pi.hProcess, INFINITE);

        	// Close process and thread handles
        	CloseHandle(pi.hProcess);
        	CloseHandle(pi.hThread);
    	}
}

int main() {

    while (true) {
    	
        MEMORYSTATUSEX memoryStatus;
        memoryStatus.dwLength = sizeof(memoryStatus);

        if (GlobalMemoryStatusEx(&memoryStatus)) {
        	//totalram & treeram ,their using for %  operation
            unsigned long long totalRAM = memoryStatus.ullTotalPhys;
            double allPercentage = (static_cast<double>( totalRAM) / totalRAM) * 100.0;
            
            unsigned long long freeRAM = memoryStatus.ullAvailPhys;
            double usagePercentage = (static_cast<double>(freeRAM) / totalRAM) * 100.0;
            
            unsigned long long usedRAM = totalRAM - freeRAM;
            double freePercentage = (static_cast<double>(usedRAM) / totalRAM) * 100.0;
            
            system("cls"); 
            // reset for displayer
            
            setColor(FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            std::cout << "------------------------------------------------------------------------------------------" << std::endl;

			setColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY); // green
            std::cout << "Total RAM: " << totalRAM << " bytes(" <<   allPercentage  << "%)" << std::endl;
            printBinary(totalRAM);
            //output Total RAM using for %  operation

			setColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY); // blue
            std::cout << "\nUsed RAM: " << usedRAM << " bytes (" << usagePercentage << "%)" << std::endl;
            printBinary(usedRAM);
            //output Used RAM using for %  operation

			setColor(FOREGROUND_RED | FOREGROUND_INTENSITY); // red
            std::cout << "\nFree RAM: " << usedRAM << " bytes (" <<  freePercentage  << "%)" << std::endl;
            printBinary(usedRAM);
            
            //output Free RAM using for %  operation
            setColor(FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            std::cout << "------------------------------------------------------------------------------------------" << std::endl;
            
            setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            CMD();
			//output CMD DATA
			
			setColor(FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            std::cout << "------------------------------------------------------------------------------------------" << std::endl;
           
        	} else {
        	
            std::cerr << "Failed to retrieve memory information." << std::endl;
            
        			}
        
        Sleep(1000); // deley time (one sence)
    
    }
      
    return 0;
}

