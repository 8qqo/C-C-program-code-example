#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// Function to split a string based on a delimiter
vector<string> split(const string& s, char delimiter) {
    vector<string> tokens;
    stringstream ss(s);
    string token;
    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

// Function to read and parse /proc/<pid>/stat file for CPU usage
float getCPUUsage(int pid) {
    ifstream file("/proc/" + to_string(pid) + "/stat");
    string line;
    if (file.is_open()) {
        getline(file, line);
        file.close();
        vector<string> fields = split(line, ' ');
        // Total time spent in user and kernel mode
        long utime = stol(fields[13]);
        long stime = stol(fields[14]);
        long cutime = stol(fields[15]);
        long cstime = stol(fields[16]);
        long total_time = utime + stime + cutime + cstime;
        // Get total elapsed time since process started
        long uptime = stol(fields[21]);
        // Get total clock ticks per second
        long clk_tck = sysconf(_SC_CLK_TCK);
        // Calculate CPU usage percentage
        float cpu_usage = 100.0 * total_time / clk_tck / uptime;
        return cpu_usage;
    }
    return -1.0; // Error
}

// Function to read and parse /proc/<pid>/status file for RAM usage
float getRAMUsage(int pid) {
    ifstream file("/proc/" + to_string(pid) + "/status");
    string line;
    if (file.is_open()) {
        string key, value;
        while (getline(file, line)) {
            istringstream iss(line);
            iss >> key >> value;
            if (key == "VmRSS:") {
                // 'VmRSS' field contains the resident set size in kilobytes
                float ram_usage_kb = stof(value);
                // Convert KB to MB
                float ram_usage_mb = ram_usage_kb / 1024.0;
                return ram_usage_mb;
            }
        }
        file.close();
    }
    return -1.0; // Error
}

int main() {
    // Open directory /proc to read process information
    ifstream proc_dir("/proc");
    string pid;
    cout << "PID\tCPU Usage (%)\tRAM Usage (MB)" << endl;
    if (proc_dir.is_open()) {
        // Iterate over each entry in /proc directory
        while (proc_dir >> pid) {
            // Check if entry is a directory and contains only digits (PID)
            if (isdigit(pid[0])) {
                int pid_val = stoi(pid);
                // Retrieve CPU and RAM usage for the process
                float cpu_usage = getCPUUsage(pid_val);
                float ram_usage = getRAMUsage(pid_val);
                // Print PID, CPU usage, and RAM usage
                if (cpu_usage >= 0 && ram_usage >= 0) {
                    cout << pid_val << "\t" << cpu_usage << "\t\t" << ram_usage << endl;
                }
            }
        }
        proc_dir.close();
    }
    return 0;
}

