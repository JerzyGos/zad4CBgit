// Jerzy Gos Zad 4 project
#include <iostream>
#include <fstream>
#include <ctime>
#include <bitset>
#include <tuple>
#include <chrono>
using namespace std;



void createLog(string message){
    fstream logFile;
    logFile.open("log.txt", ios::app);
    time_t t = time(0);
    string dt = ctime(&t);
    logFile << endl << dt.substr(0, dt.length()-1) << " : " << message;
    logFile.close();
}

tuple<int, int, float, long> makeComparison(fstream &file_A, fstream &file_B){

    int diff = 0, comparison = 0;
    long sizeInBytes = 0L;
    float ber = 0.;
    char a, b;
    string bitSetA, bitSetB;

    createLog("Analyzing bits sequences... [clock start]");
    auto start = chrono::high_resolution_clock::now();

    while(!file_A.eof()){

        a = file_A.get();
        b = file_B.get();
        sizeInBytes++;

        if(a != b){
            bitSetA = bitset<8>(a).to_string();
            bitSetB = bitset<8>(b).to_string();

            for(int i = 7; i >= 0; i--){
                if(bitSetA[i] != bitSetB[i]) diff++;
                comparison++;
            }
        }
    }

    sizeInBytes -= 1;
    ber = float(diff) / (sizeInBytes * 8.) * 100.;

    auto stop = chrono::high_resolution_clock::now();
    createLog("Analysis finished. [clock stop]");
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);

    tuple<int, int, float, long> results = make_tuple(comparison, diff, ber, duration.count());
    return results;
}




int main() {

    // test github  wersja 4


  cout << "Hello World!";



  return 0;
}
