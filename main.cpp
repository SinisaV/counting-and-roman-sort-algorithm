#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

typedef unsigned int uint;

bool BranjeStevil(vector<int> &A, const char *filename);
bool ZapisStevil(vector<int> &A, const char *filename);

vector<int> CountingSort(vector<int> A);
vector<int> RomanSort(vector<int> A);

int main(int argc, const char** argv) {

    if (argc != 3) {
        return 0;
    }

    vector<int> vectorA;
    BranjeStevil(vectorA, "vhod.txt");

    if (argv[1][0] == '0') {
        vector<int> sortedVector = CountingSort(vectorA);
        ZapisStevil(sortedVector, "out.txt");
        cout << "Counting sort\n";
    }
    else if (argv[1][0] == '1') {
        vector<int> sortedVector = RomanSort(vectorA);
        ZapisStevil(sortedVector, "out.txt");
        cout << "Roman sort\n";
    }
    else {
        return 0;
    }

    return 0;
}

bool BranjeStevil(vector<int> &A, const char *filename) {
    ifstream input(filename);
    int st;

    if (!input.is_open()) {
        return false;
    }

    while (!input.eof()) {
        input >> st;
        if (!input) break;
        A.push_back(st);
    }

    input.close();

    return true;
}

bool ZapisStevil(vector<int> &A, const char *filename) {
    ofstream output(filename);

    if (!output.is_open()) {
        return false;
    }

    for (uint i = 0; i<A.size(); i++)
        output << A[i] << ' ';

    output.close();

    return true;
}

vector<int> CountingSort(vector<int> A) {

    int minValue = *min_element(A.begin(), A.end());

    for (int myIt = 0; myIt < A.size(); myIt++) {
        A[myIt] = A[myIt] - minValue;
    }

    int maxValue = *max_element(A.begin(), A.end());

    vector<int> C(maxValue + 1);
    //cout << C.size() << endl;

    for (int myIt = 0; myIt < C.size(); myIt++) {
        C[myIt] = 0;
    }

    for (int myIt = 0; myIt < A.size(); myIt++) {
        C[A[myIt]] = C[A[myIt]] + 1;
    }

    for (int myIt = 0; myIt < C.size(); myIt++) {
        if (myIt > 0) {
            C[myIt] = C[myIt] + C[myIt - 1];
        }
    }

    vector<int> B(A.size());
    //cout << B.size() << endl;

    for (int myIt = 0; myIt < B.size(); myIt++) {
        B[myIt] = 0;
    }

    for (int myIt = A.size() - 1; myIt >= 0; myIt--) {
        B[C[A[myIt]] - 1] = A[myIt];
        C[A[myIt]] = C[A[myIt]] - 1;
    }

    for (int myIt = 0; myIt < B.size(); myIt++) {
        B[myIt] = B[myIt] + minValue;
    }
    return B;
}

vector<int> RomanSort(vector<int> A) {

    int minValue = *min_element(A.begin(), A.end());

    for (int myIt = 0; myIt < A.size(); myIt++) {
        A[myIt] = A[myIt] - minValue;
    }

    int maxValue = *max_element(A.begin(), A.end());
    vector<int> C(maxValue + 1);

    for (int myIt = 0; myIt < C.size(); myIt++) {
        C[myIt] = 0;
    }

    for (int myIt = 0; myIt < A.size(); myIt++) {
        C[A[myIt]] = C[A[myIt]] + 1;
    }

    /*cout << "C: ";
    for (int myIt = 0; myIt < C.size(); myIt++) {
        cout << C[myIt] << " ";
    }*/

    vector<int> B(A.size());

    for (int myIt = 0; myIt < B.size(); myIt++) {
        B[myIt] = 0;
    }

    /*for (int myIt = 0; myIt < B.size(); myIt++) {
        cout << B[myIt] << endl;
    }*/

    int i = 0;
    for (int myIt = 0; myIt < C.size(); myIt++) {
        if (C[myIt] != 0) {
            int tmp = C[myIt];
            for (int j = 0; j < tmp; j++) {
                B[i] = myIt;
                i++;
            }
        }
    }

    for (int myIt = 0; myIt < B.size(); myIt++) {
        B[myIt] = B[myIt] + minValue;
    }

    /*cout << endl << "B: ";
    for (int myIt = 0; myIt < B.size(); myIt++) {
        cout << B[myIt] << " ";
    }*/

    return B;
}
