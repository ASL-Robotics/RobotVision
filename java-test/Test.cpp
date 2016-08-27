#include <iostream>
#include <cstdlib>

using namespace std;

int main(void) {
    srand(time(NULL));

    cout << rand() % 5 << endl;
}