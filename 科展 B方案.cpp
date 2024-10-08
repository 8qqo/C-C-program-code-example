/*----------------------------------------------------------------------- 
Detect laptop IP ADDRESS & RAM
Completion Date:2024/01/15 
Completion timer:11:43 a.m. 
----------------------------------------------------------------------- */ 
#include <iostream>
/*資料流輸入輸出函式庫中的大部分類別都是模板類別，可以適用於不同的字元型別或操作函數（如字元比較）。常用的一些字元型別的資料流輸入輸出已經用typedef定義了相應的模板特化實例。
例如，basic_fstream<CharT,Traits>是檔案資料流輸入輸出的實作的模板類別。它的一個特化實例：fstream是basic_fstream<char,char_traits<char>>的型別別名，換句話說，
這是basic_fstream的字元型別為char使用預設字元操作集的特化實例。資料流輸入輸出函式庫中的類別可分為兩類。一是定義了介面的抽象，適用於任何流型別，無論是檔案流、
記憶體快取區流或者網路socket流。二是對具體資料來源與資料槽（sink）的流的實作。C++標準函式庫僅實作了檔案流與記憶體緩衝區流。
資料流輸入輸出函式庫中的類別依據是否實作底層或高層操作可分為兩類別。實作了底層操作的類別稱作流緩衝區（stream buffer），處理沒有任何格式化功能的字元。
這些類別極少被程式設計師直接使用。實作高層操作的類別稱作流，並提供了不同的格式化能力，是建構於流緩衝區之上的。*/
#include <windows.h>
/*windows.h是在可在C和C++中使用的僅用於Windows的頭文件，其中包含所有Windows API中函數的聲明、程式設計師常用的Windows宏和各種函數所要使用到的數據類型和子系統。
它定義了大量可在C和C++中使用的適用於Windows的特定函數。在源文件中添加windows.h頭文件並將其連結到對應的lib中，就可以將Win32 API包含到項目裡邊。
假如你要使用***.dll中所包含的函數，那麼你就應該將程序連結到***.lib中（在MinGW中，這個擴展將會變為***.dll.a）。一些頭文件不會與.dll 關聯，而與靜態庫關聯
（例如scrnsave.h 需要scrnsave.lib）。*/
#include <psapi.h>
/*psapi.h 標頭會將 EnumPageFiles 定義為別名，根據 UNICODE 預處理器常數的定義，自動選取此函式的 ANSI 或 Unicode 版本。 混合使用編碼中性別名與非編碼中性的程式碼，
可能會導致編譯或執行時間錯誤不符。*/
#include <conio.h>
/*conio.h是一個C標頭檔，用於MS-DOS C編譯器裡。此標頭檔宣告了數個有用的函數，提供程式設計者主控台的輸出入操作介面。
大部份MS-DOS、Windows 3.x、Phar Lap、DOSX、OS/2或Win32的C編譯器都預設此標頭檔，並提供相關的函數。
用於UNIX及Linux的編譯器並不支援conio.h，因為它不屬於C標準函式庫（C Standard library）或POSIX的一部分。*/
#include <tlhelp32.h>
/*具體來說，<tlhelp32.h>通常與工具幫助庫 ( ) 結合使用Kernel32.lib來執行與進程枚舉和操作相關的任務。例如，您可以使用它來檢索系統上執行的進程的快照、瀏覽進程清單並收集有關每個進程的資訊。*/
#include <cstdio>

using namespace std;

void printBinary(unsigned long long value) {
    for (int i = 63; i >= 0; --i) {
        std::cout << ((value >> i) & 1);
        if (i % 8 == 0) std::cout << ' ';
    }
    	cout << std::endl;
}

void setColor(WORD color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}//color's fuction

void PC_ALL_IP_DATA_TAKING() {

			//background color 
			system("color E4");
			
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
        	cout << std::endl<< std::endl<< std::endl;
    	}
    
}

void RAM_USE_SPACE_EXPRESSION(){
	while (true) {
		
        MEMORYSTATUSEX memoryStatus;
        memoryStatus.dwLength = sizeof(memoryStatus);

        if (GlobalMemoryStatusEx(&memoryStatus)) {
        	//totalram & treeram ,their using for %  operation
        	
        	
            unsigned long long totalRAM = memoryStatus.ullTotalPhys;
            double allPercentage = (static_cast<double>( totalRAM) / totalRAM) * 100.0;
            
            
            unsigned long long  usedRAM= memoryStatus.ullAvailPhys;
            double usagePercentage = (static_cast<double>(usedRAM) / totalRAM) * 100.0;
            
            
            unsigned long long freeRAM = totalRAM - usedRAM;
            double freePercentage = (static_cast<double>(freeRAM) / totalRAM) * 100.0;
            
            
            system("cls"); 
            // reset for displayer
            
            setColor(FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            cout << "------------------------------------------------------------------------------------------" << std::endl;

			setColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY); // green
            cout << "Total RAM: " << totalRAM << " bytes(" <<   allPercentage  << "%)" << std::endl;
            printBinary(totalRAM);
            //output Total RAM using for %  operation

			setColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY); // blue
            cout << "\nUsed RAM: " << usedRAM << " bytes (" << freePercentage << "%)" << std::endl;
            printBinary(usedRAM);
            //output Used RAM using for %  operation

			setColor(FOREGROUND_RED | FOREGROUND_INTENSITY); // red
            cout << "\nFree RAM: " << freeRAM << " bytes (" <<   usagePercentage << "%)" << std::endl;
            printBinary(freeRAM);
            
            //output Free RAM using for %  operation
            setColor(FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            
            cout << "------------------------------------------------------------------------------------------" << std::endl;
            if (_kbhit()){
            	system("color 0F");
            	system("cls");
            	break;
			}
			//determine whether the keyboard is pressed
			
        	} else {
        	
            std::cerr << "Failed to retrieve memory information." << std::endl;
            
        			}
        
        Sleep(1000); // deley time (one sence)
    
    }
} 

void CPU_USE_SPACE_EXPRESSION(){
	FILETIME idleTime, kernelTime, userTime;
    ULARGE_INTEGER lastIdleTime, lastTotalTime;
    
    // ?取初始??
    GetSystemTimes(&idleTime, &kernelTime, &userTime);
    lastIdleTime.LowPart = idleTime.dwLowDateTime;
    lastIdleTime.HighPart = idleTime.dwHighDateTime;

    lastTotalTime.LowPart = kernelTime.dwLowDateTime + userTime.dwLowDateTime;
    lastTotalTime.HighPart = kernelTime.dwHighDateTime + userTime.dwHighDateTime;

    while (true) {
        // 等待1秒
        Sleep(1000);
		system("cls");
        // ?取?前??
        GetSystemTimes(&idleTime, &kernelTime, &userTime);

        ULARGE_INTEGER currentIdleTime, currentTotalTime;
        currentIdleTime.LowPart = idleTime.dwLowDateTime;
        currentIdleTime.HighPart = idleTime.dwHighDateTime;

        currentTotalTime.LowPart = kernelTime.dwLowDateTime + userTime.dwLowDateTime;
        currentTotalTime.HighPart = kernelTime.dwHighDateTime + userTime.dwHighDateTime;

        // ?算CPU使用率和剩余CPU
        ULONGLONG idleTicks = currentIdleTime.QuadPart - lastIdleTime.QuadPart;
        ULONGLONG totalTicks = currentTotalTime.QuadPart - lastTotalTime.QuadPart;
		
        double cpuUsage = 100.0 - (idleTicks * 100.0 / totalTicks);
        double remainingCpu = 100.0 - cpuUsage;

        // 更新上一次的??
        lastIdleTime = currentIdleTime;
        lastTotalTime = currentTotalTime;

        // ?出?果
        std::cout << "CPU TOTAL: " << "100" << "%\n";
        std::cout << "CPU Usage: " << cpuUsage << "%\n";
        std::cout << "Remaining CPU: " << remainingCpu << "%\n";
        if (_kbhit()){
            	system("color 0F");
            	system("cls");
            	break;
			}
    }
}

void background_program(){
	while(true){
	system("color E4");
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    PROCESSENTRY32 pe32;
    pe32.dwSize = sizeof(PROCESSENTRY32);

    if (Process32First(hSnapshot, &pe32)) {
        do {
            std::cout << "Process ID: " << pe32.th32ProcessID << " | Process Name: " << pe32.szExeFile << std::endl;
        } while (Process32Next(hSnapshot, &pe32));
    }

    CloseHandle(hSnapshot);
    Sleep(1000);
    system("cls");
    if (_kbhit()){
            	system("color 0F");
            	system("cls");
            	break;
			}
	}
}

void os_leave(){
			system("color E4");
			
			OSVERSIONINFO osvi;
    		osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
    		SYSTEM_INFO sysInfo;
    		GetSystemInfo(&sysInfo);
    		
		if (GetVersionEx(&osvi)) {
	        cout << "Operating System Version: " << osvi.dwMajorVersion << "." << osvi.dwMinorVersion << std::endl;
	        cout << "Build Number: " << osvi.dwBuildNumber << std::endl;
	        cout << "Platform ID: " << osvi.dwPlatformId << std::endl;
	        cout << "Processor Architecture: " << sysInfo.wProcessorArchitecture << std::endl;
		    cout << "Number of Processors: " << sysInfo.dwNumberOfProcessors << std::endl;
		    cout << "Page Size: " << sysInfo.dwPageSize << std::endl;
		    cout << "Processor Type: " << sysInfo.dwProcessorType << std::endl;
		    cout << std::endl<< std::endl<< std::endl;
		    
	        if (_kbhit()){
	        	
	            	system("color 0F");
	            	system("cls");
	            	
				}
				
	    } else {
	    	
	        cerr << "Error getting operating system version." << std::endl;
	    }
	}   

int main() {
	
	a1:
	int taking_type;
	cout << "Taking type:"             << std::endl
			  <<"1.PC ALL IP DATATAKING"   << std::endl
			  <<"2.RAM USE SPACE EXPRESSION"<< std::endl 
			  <<"3.CPU USE SPACE EXPRESSION"<< std::endl 
			  <<"4.Background program"<< std::endl
			  <<"5.Os Version"<< std::endl
			  <<"6.End Program"<< std::endl;
	cin>>taking_type;
	
	if (taking_type){
            system("cls");
			}
	
	switch(taking_type){
		
	case 1:
	PC_ALL_IP_DATA_TAKING(); 
	goto a1;
	break;
	
	case 2:
	RAM_USE_SPACE_EXPRESSION();
	goto a1;
	break;
	
	case 3:
	CPU_USE_SPACE_EXPRESSION();
	goto a1;
	break;
	
	case 4:
	background_program();
	goto a1;
	break;
	
	case 5:
	os_leave();
	goto a1;
	break;
	
	case 6:
	break;
	}

	return 0;
	
}
