#include <iostream>
#include "ConversionLibrary.h"
#include <sstream>
#include <string>

using namespace std;

int main()
{
    binary bnum1, bnum2;
    decimal dnum1, dnum2;
    hexadecimal hnum1, hnum2;
    cin >> bnum1;
    dnum1 = bnum1;
    hnum1 = dnum1;
    dnum2 = hnum1;
    hnum2 = dnum2;
    bnum2 = hnum2;
    cout << bnum2;

    return 0;
}
