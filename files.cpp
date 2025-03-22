#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>
using namespace std;

int main() {
    vector<ofstream> files;
    int filesToOpen = 100000;
    for (int i = 0; i < filesToOpen; ++i) {
        string filename = "file_" + to_string(i) + ".txt";
        files.push_back(ofstream(filename));

        if (!files.back()) {
            cerr << "Error opening file: " << filename << endl;
            return 1;
        }

        if (i % 1000 == 0) {
            this_thread::sleep_for(chrono::seconds(1));
        }
    }
    this_thread::sleep_for(chrono::seconds(100));

    return 0;
}
