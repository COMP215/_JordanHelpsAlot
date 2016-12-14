//-----------------------------------------------------------------------

#include <iostream>

using namespace std;


//-----------------------------------------------------------------------

class number
{
public:
    double decimal_value;   // Permanent container for decimal value of number
    string rawEntry,        // Container for number value in the correct base
           base;            // Numeric base for number object

    // Constructors (CTOR)
    number();                               // default ctor
    number(const number& compared_number);  // copy ctor

    operator=(number& otherNumber);
    friend ostream& operator<<(ostream& newOutStream, number& x);
    friend istream& operator>> (istream& inStream, number& object_x);
};

string decimal_to_string(double decimal);
string decimal_to_binary(int decimal);
string decimal_to_hexadecimal(int decimal);

double string_to_decimal(string input_string);
double binary_to_decimal(string rawEntry);
double hexadecimal_to_decimal(string rawEntry);


class binary: public number
{
public:
    binary();       // default ctor

    using number::operator=;
};

class decimal: public number
{
public:
    decimal();      // default ctor

    using number::operator=;
};

class hexadecimal: public number
{
public:
    hexadecimal();  // default ctor

    using number::operator=;
};
