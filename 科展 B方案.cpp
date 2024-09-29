/*----------------------------------------------------------------------- 
Detect laptop IP ADDRESS & RAM
Completion Date:2024/01/15 
Completion timer:11:43 a.m. 
----------------------------------------------------------------------- */ 
#include <iostream>
/*��Ƭy��J��X�禡�w�����j�������O���O�ҪO���O�A�i�H�A�Ω󤣦P���r�����O�ξާ@��ơ]�p�r������^�C�`�Ϊ��@�Ǧr�����O����Ƭy��J��X�w�g��typedef�w�q�F�������ҪO�S�ƹ�ҡC
�Ҧp�Abasic_fstream<CharT,Traits>�O�ɮ׸�Ƭy��J��X����@���ҪO���O�C�����@�ӯS�ƹ�ҡGfstream�Obasic_fstream<char,char_traits<char>>�����O�O�W�A���y�ܻ��A
�o�Obasic_fstream���r�����O��char�ϥιw�]�r���ާ@�����S�ƹ�ҡC��Ƭy��J��X�禡�w�������O�i���������C�@�O�w�q�F��������H�A�A�Ω����y���O�A�L�׬O�ɮ׬y�B
�O����֨��Ϭy�Ϊ̺���socket�y�C�G�O������ƨӷ��P��Ƽѡ]sink�^���y����@�CC++�зǨ禡�w�ȹ�@�F�ɮ׬y�P�O����w�İϬy�C
��Ƭy��J��X�禡�w�������O�̾ڬO�_��@���h�ΰ��h�ާ@�i���������O�C��@�F���h�ާ@�����O�٧@�y�w�İϡ]stream buffer�^�A�B�z�S������榡�ƥ\�઺�r���C
�o�����O���ֳQ�{���]�p�v�����ϥΡC��@���h�ާ@�����O�٧@�y�A�ô��ѤF���P���榡�Ư�O�A�O�غc��y�w�İϤ��W���C*/
#include <windows.h>
/*windows.h�O�b�i�bC�MC++���ϥΪ��ȥΩ�Windows���Y���A�䤤�]�t�Ҧ�Windows API����ƪ��n���B�{���]�p�v�`�Ϊ�Windows���M�U�ب�Ʃҭn�ϥΨ쪺�ƾ������M�l�t�ΡC
���w�q�F�j�q�i�bC�MC++���ϥΪ��A�Ω�Windows���S�w��ơC�b����󤤲K�[windows.h�Y���ñN��s���������lib���A�N�i�H�NWin32 API�]�t�춵�ظ���C
���p�A�n�ϥ�***.dll���ҥ]�t����ơA����A�N���ӱN�{�ǳs����***.lib���]�bMinGW���A�o���X�i�N�|�ܬ�***.dll.a�^�C�@���Y��󤣷|�P.dll ���p�A�ӻP�R�A�w���p
�]�Ҧpscrnsave.h �ݭnscrnsave.lib�^�C*/
#include <psapi.h>
/*psapi.h ���Y�|�N EnumPageFiles �w�q���O�W�A�ھ� UNICODE �w�B�z���`�ƪ��w�q�A�۰ʿ�����禡�� ANSI �� Unicode �����C �V�X�ϥνs�X���ʧO�W�P�D�s�X���ʪ��{���X�A
�i��|�ɭP�sĶ�ΰ���ɶ����~���šC*/
#include <conio.h>
/*conio.h�O�@��C���Y�ɡA�Ω�MS-DOS C�sĶ���̡C�����Y�ɫŧi�F�ƭӦ��Ϊ���ơA���ѵ{���]�p�̥D���x����X�J�ާ@�����C
�j����MS-DOS�BWindows 3.x�BPhar Lap�BDOSX�BOS/2��Win32��C�sĶ�����w�]�����Y�ɡA�ô��Ѭ�������ơC
�Ω�UNIX��Linux���sĶ���ä��䴩conio.h�A�]�������ݩ�C�зǨ禡�w�]C Standard library�^��POSIX���@�����C*/
#include <tlhelp32.h>
/*����ӻ��A<tlhelp32.h>�q�`�P�u�����U�w ( ) ���X�ϥ�Kernel32.lib�Ӱ���P�i�{�T�|�M�ާ@���������ȡC�Ҧp�A�z�i�H�ϥΥ����˯��t�ΤW���檺�i�{���ַӡB�s���i�{�M��æ��������C�Ӷi�{����T�C*/
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
    
    // ?����l??
    GetSystemTimes(&idleTime, &kernelTime, &userTime);
    lastIdleTime.LowPart = idleTime.dwLowDateTime;
    lastIdleTime.HighPart = idleTime.dwHighDateTime;

    lastTotalTime.LowPart = kernelTime.dwLowDateTime + userTime.dwLowDateTime;
    lastTotalTime.HighPart = kernelTime.dwHighDateTime + userTime.dwHighDateTime;

    while (true) {
        // ����1��
        Sleep(1000);
		system("cls");
        // ?��?�e??
        GetSystemTimes(&idleTime, &kernelTime, &userTime);

        ULARGE_INTEGER currentIdleTime, currentTotalTime;
        currentIdleTime.LowPart = idleTime.dwLowDateTime;
        currentIdleTime.HighPart = idleTime.dwHighDateTime;

        currentTotalTime.LowPart = kernelTime.dwLowDateTime + userTime.dwLowDateTime;
        currentTotalTime.HighPart = kernelTime.dwHighDateTime + userTime.dwHighDateTime;

        // ?��CPU�ϥβv�M�ѧECPU
        ULONGLONG idleTicks = currentIdleTime.QuadPart - lastIdleTime.QuadPart;
        ULONGLONG totalTicks = currentTotalTime.QuadPart - lastTotalTime.QuadPart;
		
        double cpuUsage = 100.0 - (idleTicks * 100.0 / totalTicks);
        double remainingCpu = 100.0 - cpuUsage;

        // ��s�W�@����??
        lastIdleTime = currentIdleTime;
        lastTotalTime = currentTotalTime;

        // ?�X?�G
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
