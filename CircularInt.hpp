/**
*hidden file of class CircularInt
*Authors Alexey Titov and Shir Bentabou
*Version 2.0
**/
#pragma once
//libraries
#include <iostream>
using namespace std;
//our class
class CircularInt{
    private:
        int min; //always set to 1 - constructor wise too
        int max; //always set to 12 - constructor wise too
        int pos; //its current position
        // std::exception runtime_error;
    public:
        //constructor with minimal and maximal values
        CircularInt(int MIN,int MAX){
            if (MIN>MAX){
                cout << "MIN larger than MAX!" << endl;
                exit(1);
            }
            min=MIN;
            max=MAX;
            pos=MIN;
        }
        
        //plus function - a general function that will help us with all addition operators
        int plus(int min, int max, int pos, int x);
        //minus function - a general function that will help us with all subtraction operators
        int minus(int min, int max, int pos, int x);
        //multiply function - a general function that will help us with all multiplying operators
        int multiply(int min, int max, int pos, int by_x);
        //division function - a general function that will help us with all dividing operators
        int divide(int min, int max, int pos, int by_x);
        //modulo function - a general function that will help us with all modulo operators
        int modulo(int min, int max, int pos, int mod);
        //normaliztion function - this function normalizes a number to the relevant range
        //helpful especially for bitwise operations in our code
        int normalization(int min, int max, int num);
        
        //Overloading for bitwise not '~' operator for hour type. Note that we don't change the value of the original
        //object sent to the function.
        const CircularInt operator~();
        
        //Overloading for '&=' operator for hour type! (using & function)
        CircularInt& operator&=(const int& other);

        //Overloading for '&=' operator for hour type! (using & function) (CircularInt)
        CircularInt& CircularInt::operator&=(const CircularInt& other);

        //Overloading for '|=' operator for hour type! (using | function)
        CircularInt& operator|=(const int& other);

        //Overloading for '|=' operator for hour type! (using | function) (CircularInt)
        CircularInt& operator|=(const CircularInt& other);

        //Overloading for '^=' operator for hour type! (using ^ function)
        CircularInt& operator^=(const int& other);

        //Overloading for '^=' operator for hour type! (using ^ function) (CircularInt)
        CircularInt& CircularInt::operator^=(const CircularInt& other);

        //Overloading for '<<=' operator for hour type! (using << function)
        CircularInt& operator<<=(const int& other);

        //Overloading for '<<=' operator for hour type! (using << function) (CircularInt)
        CircularInt& operator<<=(const CircularInt& other);

        //Overloading for '>>=' operator for hour type! (using >> function)
        CircularInt& operator>>=(const int& other);

        //Overloading for '>>=' operator for hour type! (using >> function) (CircularInt)
        CircularInt& operator>>=(const CircularInt& other);

        //Overloading for '+=' operator for hour type!
        CircularInt& operator+=(const int& other);

        //Overloading for '+=' operator for hour type! (using plus/minus functions) (CircularInt)
        CircularInt& operator+=(const CircularInt& other);

        //Overloading for '-=' operator for hour type!
        CircularInt& operator-=(const int& other);
        
        //Overloading for '-=' operator for hour type! (using plus/minus functions) (CircularInt)
        CircularInt& operator-=(const CircularInt& other);

        //Overloading for '*=' operator for hour type!
        CircularInt& operator*=(const int& mult);

        //Overloading for '*=' operator for hour type!(CircularInt)
        CircularInt& operator*=(const CircularInt& mult);

        //Overloading for '/=' operator for hour type!
        CircularInt& operator/=(const int& div);

        //Overloading for '/=' operator for hour type! (CircularInt)
        CircularInt& operator/=(const CircularInt& div);

        //Overloading for '%=' operator for hour type!
        CircularInt& operator%=(const int& mod);

        //Overloading for '%=' operator for hour type! (CircularInt)
        CircularInt& operator%=(const CircularInt& mod);

        //Overloading for 'var++' operator for hour type!
        int operator++(int);

        //Overloading for '++var' operator for hour type!
        CircularInt& operator++();

        //Overloading for 'var--' operator for hour type!
        int operator--(int);

        //Overloading for '--var' operator for hour type!
        CircularInt& operator--();

        //Overloading - operator for complementary action
        int operator-();

        //Overloading for '=' operator for hour type!
        CircularInt& operator =(const CircularInt& other);

        //Overloading '=' operator between hour object and int.
        CircularInt& operator =(const int& other);
        
        //----------------------------------
        // friend global IO operators
        //----------------------------------
        friend ostream& operator<< (ostream& os, const CircularInt& c);
        friend istream& operator>> (istream& is,CircularInt& c);
        //-------------------------------------
        // friend global binary operators
        //-------------------------------------
        friend const CircularInt operator - (const int a,const CircularInt& other);
        friend const CircularInt operator + (const int a,const CircularInt& other);
        friend const CircularInt operator - (const CircularInt& other,const int a);
        friend const CircularInt operator + (const CircularInt& other,const int a);
        friend const CircularInt operator + (const CircularInt& a, const CircularInt& b);
        friend const CircularInt operator - (const CircularInt& a, const CircularInt& b);
        friend const CircularInt operator * (const CircularInt& a, const CircularInt& b);
        friend const CircularInt operator * (const int& a, const CircularInt& b);
        friend const CircularInt operator * (const CircularInt& b, const int& a);
        friend const CircularInt operator / (const CircularInt& a, const CircularInt& b);
        friend const CircularInt operator / (const int& div, const CircularInt& b);
        friend const CircularInt operator / (const CircularInt& a,const int& div);
        friend bool operator == (const CircularInt& a, const CircularInt& b);
        friend bool operator == (const int& b, const CircularInt& a);
        friend bool operator == (const CircularInt& a, const int& b);
        friend bool operator != (const CircularInt& a, const CircularInt& b);
        friend bool operator != (const CircularInt& a, const int& b);
        friend bool operator != (const int& a, const CircularInt& b);
        friend bool operator > (const CircularInt& a, const CircularInt& b);
        friend bool operator > (const CircularInt& a, const int& b);
        friend bool operator > (const int& b, const CircularInt& a);
        friend bool operator < (const CircularInt& a, const CircularInt& b);
        friend bool operator < (const CircularInt& a, const int& b);
        friend bool operator < (const int& b, const CircularInt& a);
        friend bool operator >= (const CircularInt& a, const CircularInt& b);
        friend bool operator >= (const CircularInt& a, const int& b);
        friend bool operator >= (const int& b, const CircularInt& a);
        friend bool operator <= (const CircularInt& a, const CircularInt& b);
        friend bool operator <= (const CircularInt& a, const int& b);
        friend bool operator <= (const int& b, const CircularInt& a);
        friend const CircularInt operator%(const CircularInt& a, const int& mod);
        friend const CircularInt operator%(const int& mod, const CircularInt& a);
        friend const CircularInt operator%(const CircularInt& a, const CircularInt& b);
        friend const CircularInt operator&(const CircularInt& a, const CircularInt& b);
        friend const CircularInt operator&(const int& a, const CircularInt& b);
        friend const CircularInt operator&(const CircularInt& a, const int& b);
        friend const CircularInt operator|(const CircularInt& a, const CircularInt& b);
        friend const CircularInt operator|(const int& a, const CircularInt& b);
        friend const CircularInt operator|(const CircularInt& a, const int& b);
        friend const CircularInt operator^(const CircularInt& a, const CircularInt& b);
        friend const CircularInt operator^(const int& a, const CircularInt& b);
        friend const CircularInt operator^(const CircularInt& a, const int& b);
        friend const CircularInt operator<<(const CircularInt& a, const CircularInt& b);
        friend const CircularInt operator<<(const int& a, const CircularInt& b);
        friend const CircularInt operator<<(const CircularInt& a, const int& b);
        friend const CircularInt operator>>(const CircularInt& a, const CircularInt& b);
        friend const CircularInt operator>>(const int& a, const CircularInt& b);
        friend const CircularInt operator>>(const CircularInt& a, const int& b);


        
};
//----------------------------------------
// friend global IO operators
//----------------------------------------
ostream& operator<< (ostream& os, const CircularInt& c);
istream& operator>> (istream& is,CircularInt& c);
//-------------------------------------
// friend global binary operators
//-------------------------------------
//Overloading for '-' operator for hour type! (int and CircularInt)
const CircularInt operator - (const int a,const CircularInt& other);

//Overloading for '-' operator for hour type! (CircularInt and int)
const CircularInt operator - (const CircularInt& other,const int a);

//Overloading for '+' operator for hour type! (int and CircularInt)
const CircularInt operator+(const int a,const CircularInt& other);

//Overloading for '+' operator for hour type! (CircularInt and int)
const CircularInt operator+(const CircularInt& other,const int a);

//Overloading for '+' operator for hour type! (CircularInt and CircularInt)
const CircularInt operator + (const CircularInt& a, const CircularInt& b);

//Overloading for '-' operator for hour type! (CircularInt and CircularInt)
const CircularInt operator - (const CircularInt& a, const CircularInt& b);

//Overloading for '*' operator for hour type! (CircularInt and CircularInt)
const CircularInt operator*(const CircularInt& a, const CircularInt& b);

//Overloading for '*' operator for hour type! (int and CircularInt)
const CircularInt operator*(const int& a, const CircularInt& b);

//Overloading for '*' operator for hour type! (CircularInt and int)
const CircularInt operator*(const CircularInt& b, const int& a);

//Overloading for '/' operator for hour type! (CircularInt and CircularInt)
const CircularInt operator/(const CircularInt& a, const CircularInt& b);

//Overloading for '/' operator for hour type! (int and CircularInt)
const CircularInt operator/(const int& div, const CircularInt& b);

//Overloading for '/' operator for hour type! (CircularInt and int)
const CircularInt operator / (const CircularInt& a,const int& div);

//Overloading for '==' operator for hour type! (Two CircularInt types)
bool operator == (const CircularInt& a, const CircularInt& b);

//Overloading for '==' operator for hour type! (CircularInt and int)
bool operator == (const CircularInt& a, const int& b);

//Overloading for '==' operator for hour type! (int and CircularInt)
bool operator == (const int& b, const CircularInt& a);

//Overloading for '!=' operator for hour type! (Two CircularInt types)
bool operator != (const CircularInt& a, const CircularInt& b);

//Overloading for '!=' operator for hour type! (CircularInt and int)
bool operator != (const CircularInt& a, const int& b);

//Overloading for '!=' operator for hour type! (Int and CircularInt )
bool operator != (const int& a, const CircularInt& b);

//Overloading for '>' operator for hour type! (Two CircularInt types)
bool operator > (const CircularInt& a, const CircularInt& b);

//Overloading for '>' operator for hour type! (CircularInt and int)
bool operator > (const CircularInt& a, const int& b);

//Overloading for '>' operator for hour type! (int and CircularInt)
bool operator > (const int& b, const CircularInt& a);

//Overloading for '<' operator for hour type! (Two CircularInt types)
bool operator < (const CircularInt& a, const CircularInt& b);

//Overloading for '<' operator for hour type! (CircularInt and int)
bool operator < (const CircularInt& a, const int& b);

//Overloading for '<' operator for hour type! (Int and CircularInt)
bool operator < (const int& b, const CircularInt& a);

//Overloading for '>=' operator for hour type! (Two CircularInt types)
bool operator >= (const CircularInt& a, const CircularInt& b);

//Overloading for '>=' operator for hour type! (CircularInt and int)
bool operator >= (const CircularInt& a, const int& b);

//Overloading for '>=' operator for hour type! (Int and CircularInt)
bool operator >= (const int& b, const CircularInt& a);


//Overloading for '<=' operator for hour type! (Two CircularInt types)
bool operator <= (const CircularInt& a, const CircularInt& b);

//Overloading for '<=' operator for hour type! (CircularInt and int)
bool operator <= (const CircularInt& a, const int& b);

//Overloading for '<=' operator for hour type! (Int and CircularInt)
bool operator <= (const int& b, const CircularInt& a);

//Overloading for '%' operator for hour type!
const CircularInt operator%(const CircularInt& a, const int& mod);

//Overloading for '%' operator for hour type! (int and CircularInt)
const CircularInt operator%(const int& mod, const CircularInt& a);

//Overloading for '%' operator for hour type! (Two CircularInts)
const CircularInt operator%(const CircularInt& a, const CircularInt& b);

//Overloading for bitwise '&' operator for hour type! (Two CircularInts)
const CircularInt operator&(const CircularInt& a, const CircularInt& b);

//Overloading for bitwise '&' operator for hour type! (int and CircularInt)
const CircularInt operator&(const int& a, const CircularInt& b);

//Overloading for bitwise '&' operator for hour type! (CircularInt and int)
const CircularInt operator&(const CircularInt& a, const int& b);

//Overloading for bitwise '|' operator for hour type! (Two CircularInts)
const CircularInt operator|(const CircularInt& a, const CircularInt& b);

//Overloading for bitwise '|' operator for hour type! (int and CircularInt)
const CircularInt operator|(const int& a, const CircularInt& b);

//Overloading for bitwise '|' operator for hour type! (CircularInt and int)
const CircularInt operator|(const CircularInt& a, const int& b);

//Overloading for bitwise '^' operator for hour type! (Two CircularInts)
const CircularInt operator^(const CircularInt& a, const CircularInt& b);

//Overloading for bitwise '^' operator for hour type! (int and CircularInt)
const CircularInt operator^(const int& a, const CircularInt& b);

//Overloading for bitwise '^' operator for hour type! (CircularInt and int)
const CircularInt operator^(const CircularInt& a, const int& b);

//Overloading for bitwise '<<' operator for hour type! (Two CircularInts)
const CircularInt operator<<(const CircularInt& a, const CircularInt& b);

//Overloading for bitwise '<<' operator for hour type! (int and CircularInt)
const CircularInt operator<<(const int& a, const CircularInt& b);

//Overloading for bitwise '<<' operator for hour type! (CircularInt and int)
const CircularInt operator<<(const CircularInt& a, const int& b);

//Overloading for bitwise '>>' operator for hour type! (Two CircularInts)
const CircularInt operator>>(const CircularInt& a, const CircularInt& b);

//Overloading for bitwise '>>' operator for hour type! (int and CircularInt)
const CircularInt operator>>(const int& a, const CircularInt& b);

//Overloading for bitwise '>>' operator for hour type! (CircularInt and int)
const CircularInt operator>>(const CircularInt& a, const int& b);