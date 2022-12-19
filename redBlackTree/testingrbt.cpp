
#include <iostream>
using namespace std;


void printoutdata(int dataContent) {
    cout << dataContent << "\n";
}

int main() {
// Dummy Data
    int dumpData[10] = {13, 7, 16, 19, 9, 22, 10, 14, 17};


    for(int dataContent : dumpData) {
        printoutdata(dataContent);
    }

    return 0;
}