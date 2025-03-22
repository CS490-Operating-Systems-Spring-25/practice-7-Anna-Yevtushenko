#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
using namespace std;

int main() {
    ofstream outfile("test.txt");
    if (!outfile.is_open()) {
        cerr << "Error opening file!" << endl;
        return 1;
    }
    for (int i = 1; i <= 1000; ++i) {
        outfile << "Iteration " << i << endl;
        outfile.flush();

        this_thread::sleep_for(chrono::seconds(1));
    }
    outfile.close();
    return 0;
}
