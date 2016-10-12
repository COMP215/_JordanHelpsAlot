/*
 * Jordan Hamilton
 * ConversionLibrary.cpp
 *
 * Description: A Library for the declaration and conversion of numbers
                in 3 unique bases (binary, decimal, and hexadecimal).
 * Input      : User must create their own main() and design their own
                input. Values may be assigned to number objects with the
                overloaded ">>" operator defined in the library.
 * Output     : Output will vary by user main(). The contents of number
                objects may be displayed with the overloaded "<<"
                operator defined in the library.
 *
 */

#include "ConversionLibrary.h"
#include <sstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <stack>
#include <stdlib.h>
#include <math.h>
using namespace std;


 //--------------------------------------------
//-- Class: Number ---------------------------

number::number()
/*--Description: basic ctor for number object
    PRE: NA
    POST: number object created -- */
{
        base = "";
        decimal_value = 0;
        rawEntry = "";
}

number::number(const number& compared_number)
/*--Description: copy ctor for number object
    PRE: compared_number exists and contains desired values
    POST: number object created -- */
{
        base = compared_number.base;
        decimal_value = compared_number.decimal_value;
        rawEntry = compared_number.rawEntry;
}

number::operator=(number& otherNumber)
/*--Description: Overloaded assignment operator for number
        objects. Assigns decimal value from otherNumber to
        working number object. Additionally modifies
        rawEntry string to match the new decimal value in
        the desired base.
    PRE: Working number object as well as otherNumber both
         exist.
    POST: Values modified in working number object -- */
{
    decimal_value = otherNumber.decimal_value;
    if (base == "binary")
    {
        rawEntry = decimal_to_binary(decimal_value);
    }
    else if (base == "hexadecimal")
    {
        rawEntry = decimal_to_hexadecimal(decimal_value);
    }
    else if (base == "decimal")
    {
        rawEntry = decimal_to_string(decimal_value);
    }
    // Determines base of number object being compared and
    // converts internal decimal value into appropriate base
    // which is stored in rawEntry.
}

istream& operator>> (istream& inStream, number& object_x)
/*--Description: Overloaded operator for input stream.
    PRE: Number object must exist.
    POST: Number object's rawEntry and decimal_value
          are reassigned -- */
{
    string rawEntry = "";
    inStream >> rawEntry;
    object_x.rawEntry = rawEntry;

    if (object_x.base == "binary"){
        object_x.decimal_value = binary_to_decimal(rawEntry);
    }
    else if (object_x.base == "decimal"){
        object_x.decimal_value = string_to_decimal(rawEntry);
    }
    else if (object_x.base == "hexadecimal"){
        object_x.decimal_value = hexadecimal_to_decimal(rawEntry);
    }
    return inStream;
}

ostream &operator<<(ostream &newOutStream, number &number)
/*--Description: Overloaded operator for output stream.
    PRE: Number object must exist.
    POST: Outputs to console rawEntry value for number
          object. -- */
{
    newOutStream << number.rawEntry;
    return newOutStream;
}


 //--------------------------------------------
//-- Non-Member Functions --------------------

string decimal_to_string(double decimal)
/* -- Description: Converts decimal value to decimal string -- */
{
    string result; // stores the converted string to return
    ostringstream convert;
    convert << decimal;
    result = convert.str();
    return result;
}

string decimal_to_binary(int decimal)
/* -- Description: Converts decimal value to binary string -- */
{
      int remainder_int = 0,    // int form of remainder in binary conversion calculations
                counter = 0;    // counter for while loop
    char remainder_char = '0';  // char version of remainder_int, used for creating string
          string binary = "";   // string to contain finished result
    stack<char> binary_stack;   // stack for reversing the order of binary characters

    while (decimal > 0)         // While loop for binary calculations
    {
        if (decimal % 2 == 0){
            remainder_char = '0';
            decimal = decimal / 2;
        }
        else{
            remainder_char = '1';
            decimal = (decimal)/2;
        }
        counter++;
        binary_stack.push(remainder_char);
    }

    for (short i=0; i<counter; i++)
    {
        binary += binary_stack.top();
        binary_stack.pop();
    }
    return binary;
}

string decimal_to_hexadecimal(int decimal)
/* -- Description: Converts decimal value to hexadecimal string -- */
{
    stringstream send_dec;
    send_dec << std::hex << decimal;
    std::string result( send_dec.str() );
    return result;
}

double string_to_decimal(string input_string)
/* -- Description: Converts decimal string to decimal value -- */
{
     double decimal;
     stringstream make_double(input_string); //turn the string into a stream
     make_double >> decimal; //convert
     return decimal;
}

double binary_to_decimal(string rawEntry)
/* -- Description: Converts binary string to decimal value -- */
{
    stack<char> digit_queue;

    double sum_of_terms = 0,
           binary_digit_double = 0;

    char binary_digit_char = 'a';

    for (short i=0; i < rawEntry.length(); i++)
    {
        digit_queue.push(rawEntry[i]);
    }
    for (short i=0; i < rawEntry.length(); i++)
    {
        binary_digit_char = digit_queue.top();
        binary_digit_double = (double)binary_digit_char-48;
        digit_queue.pop();
        sum_of_terms += (binary_digit_double)*pow(2,i) ;
    }
    return sum_of_terms;

}

double hexadecimal_to_decimal(string rawEntry)
/* -- Description: Converts hexadecimal string to decimal value -- */
{
    int dec_value_int;
    stringstream send_hex(rawEntry);
    send_hex >> std::hex >> dec_value_int;
    return (double)dec_value_int;
}


 //--------------------------------------------
//-- Class: Binary ---------------------------

binary::binary()
/*--Description: basic ctor for binary object
    PRE: NA
    POST: binary object created -- */
{
    rawEntry = "";
    base = "binary";
    decimal_value = 0;
}


 //--------------------------------------------
//-- Class: Decimal --------------------------

decimal::decimal()
/*--Description: basic ctor for decimal object
    PRE: NA
    POST: decimal object created -- */
{
    rawEntry = "";
    base = "decimal";
    decimal_value = 0;
}


 //--------------------------------------------
//-- Class: Hexadecimal ----------------------

hexadecimal::hexadecimal()
/*--Description: basic ctor for hexadecimal object
    PRE: NA
    POST: hexadecimal object created -- */
{
    rawEntry = "";
    base = "hexadecimal";
    decimal_value = 0;
}

