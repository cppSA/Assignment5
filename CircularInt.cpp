/**
*cpp file of class CircularInt
*Authors Alexey Titov and Shir Bentabou
*Version 3.0
**/
//libraries
#include "CircularInt.hpp"
#include <string>
using namespace std;


//plus function - a general function that will help us with all addition operators
int CircularInt::plus(int min, int max, int pos, int x){
    pos = pos + x;
    if (pos > max){
        while (pos>max){
            pos = pos - max;
            pos = pos + min -1;
        }
    }
    return pos; 
}

//minus function - a general function that will help us with all subtraction operators
int CircularInt::minus(int min, int max, int pos, int x){
    pos = pos - x;
    if (pos < min){
        while (pos < min){
            pos = pos - min;
            pos = max + pos +1;
        }
    }
    return pos;
}

//multiply function - a general function that will help us with all multiplying operators
int CircularInt::multiply(int min, int max, int pos, int by_x){
    pos = pos * by_x;
    if (pos > max){
        while (pos>max){
            pos = pos - max;
            pos = pos + min -1;
        }
    }
    return pos; 
}

//division function - a general function that will help us with all dividing operators
int CircularInt::divide(int min, int max, int pos, int by_x){
    if (by_x!=0)
        for(int i=min; i<=max; i++){
            if (i*by_x==pos){
                return i;
            }
        }
    string ans;
    if (by_x==0){
        ans = "Dividing by zero!";
    }
    else{
        ans = "There is no number x in {" + std::to_string(min) + "," + std::to_string(max)+"} such that x*"+std::to_string(pos)+"=10";
    }
    throw ans; 
}

//modulo function - a general function that will help us with all modulo operators
int CircularInt::modulo(int min, int max, int pos, int mod){
    if (mod!=0){
        if (mod > pos){
            return pos;
        }
        if ((pos % mod)>=min && (pos % mod)<=max){
            return pos % mod;
        }
    }
    string ans;
    if (mod==0){
        ans = "Cannot mod by 0!";
    }
    else{
        ans = "There is no number in range that equals to position modulo the int given";
    }
    throw ans; 
}

//normaliztion function - this function normalizes a number to the relevant range
//helpful especially for bitwise operations in our code
int CircularInt::normalization(int min, int max, int num){
    if (num > max){
        while (num>max){
            num = num - max;
            num = num + min -1;
        }
        return num;  
    }
    if (num < min){
        while (num < min){
            num = num - min;
            num = max + num + 1;
        }
    }
    return num;
}

//Overloading for bitwise not '~' operator for hour type. Note that we don't change the value of the original
//object sent to the function.
const CircularInt CircularInt::operator~(){
    int tmp=this->pos;
    CircularInt circ_new{this->min, this->max};
    tmp=normalization(this->min,this->max,~(tmp));
    circ_new.pos = tmp;
    return circ_new;
}

//Overloading for '&=' operator for hour type! (using & function)
CircularInt& CircularInt::operator&=(const int& other) {
    CircularInt temp = *this&other;
    this->pos = temp.pos;
    return (*this);
}

//Overloading for '&=' operator for hour type! (using & function) (CircularInt)
CircularInt& CircularInt::operator&=(const CircularInt& other) {
    CircularInt temp = *this&other.pos;
    this->pos = temp.pos;
    return (*this);
}

//Overloading for '|=' operator for hour type! (using | function)
CircularInt& CircularInt::operator|=(const int& other) {
    CircularInt temp = *this|other;
    this->pos = temp.pos;
    return (*this);
}

//Overloading for '|=' operator for hour type! (using | function) (CircularInt)
CircularInt& CircularInt::operator|=(const CircularInt& other) {
    CircularInt temp = *this|other.pos;
    this->pos = temp.pos;
    return (*this);
}

//Overloading for '^=' operator for hour type! (using ^ function)
CircularInt& CircularInt::operator^=(const int& other) {
    CircularInt temp = *this^other;
    this->pos = temp.pos;
    return (*this);
}

//Overloading for '^=' operator for hour type! (using ^ function) (CircularInt)
CircularInt& CircularInt::operator^=(const CircularInt& other) {
    CircularInt temp = *this^other.pos;
    this->pos = temp.pos;
    return (*this);
}

//Overloading for '<<=' operator for hour type! (using << function)
CircularInt& CircularInt::operator<<=(const int& other) {
    CircularInt temp = *this<<other;
    this->pos = temp.pos;
    return (*this);
}

//Overloading for '<<=' operator for hour type! (using << function) (CircularInt)
CircularInt& CircularInt::operator<<=(const CircularInt& other) {
    CircularInt temp = *this<<other.pos;
    this->pos = temp.pos;
    return (*this);
}

//Overloading for '>>=' operator for hour type! (using >> function)
CircularInt& CircularInt::operator>>=(const int& other) {
    CircularInt temp = *this>>other;
    this->pos = temp.pos;
    return (*this);
}

//Overloading for '>>=' operator for hour type! (using >> function) (CircularInt)
CircularInt& CircularInt::operator>>=(const CircularInt& other) {
    CircularInt temp = *this>>other.pos;
    this->pos = temp.pos;
    return (*this);
}

//Overloading for '+=' operator for hour type! (using plus/minus functions)
CircularInt& CircularInt::operator+=(const int& other) {
    if (other>=0)
        this->pos=plus(this->min, this->max, this->pos, other);
    else{
        int tmp=other*(-1);
        this->pos=minus(this->min, this->max, this->pos, tmp);
    }
    return (*this);
}

//Overloading for '+=' operator for hour type! (using plus/minus functions) (CircularInt)
CircularInt& CircularInt::operator+=(const CircularInt& other) {
    if (other.pos>=0)
        this->pos=plus(this->min, this->max, this->pos, other.pos);
    else{
        int tmp=other.pos*(-1);
        this->pos=minus(this->min, this->max, this->pos, tmp);
    }
    return (*this);
}

//Overloading for '-=' operator for hour type! (using plus/minus functions)
CircularInt& CircularInt::operator-=(const int& other) {
    if (other < 0){
        this->pos=plus(this->min, this->max, this->pos, other*(-1));
    }
    else{
        this->pos=minus(this->min, this->max, this->pos, other);
    }
    return (*this);
}

//Overloading for '-=' operator for hour type! (using plus/minus functions) (CircularInt)
CircularInt& CircularInt::operator-=(const CircularInt& other) {
    if (other.pos < 0){
        this->pos=plus(this->min, this->max, this->pos, other.pos*(-1));
    }
    else{
        this->pos=minus(this->min, this->max, this->pos, other.pos);
    }
    return (*this);
}

//Overloading for 'var++' operator for hour type!
int CircularInt::operator++(int){
    int tmp = this->pos;
    this->pos=plus(this->min, this->max, this->pos, 1);
    return (tmp);
}

//Overloading for '++var' operator for hour type!
CircularInt& CircularInt::operator++(){
    this->pos=plus(this->min, this->max, this->pos, 1);
    return (*this);
}

//Overloading for 'var--' operator for hour type!
int CircularInt::operator--(int){
    int tmp = this->pos;
    this->pos=minus(this->min, this->max, this->pos, 1);
    return (tmp);
}

//Overloading for '--var' operator for hour type!
CircularInt& CircularInt::operator--(){
    this->pos=minus(this->min, this->max, this->pos, 1);
    return (*this);
}

//Overloading - operator for complementary action
int CircularInt::operator-() {
    int tmp=minus(this->min, this->max, this->max, this->pos);
    return tmp;
}

//Overloading for '=' operator for hour type!
CircularInt& CircularInt::operator =(const CircularInt& other){
    this->min = other.min;
    this->max = other.max;
    this->pos = other.pos;
    return *this;
}

//Overloading for '=' operator for hour type!
CircularInt& CircularInt::operator =(const int& other){
    if (other>=this->min && other<=this->max){
        this->pos = other;
    }else{
        this->pos=this->normalization(this->min,this->max,other);
    }
    return *this;
}

//Overloading for '*=' operator for hour type!(int)
CircularInt& CircularInt::operator*=(const int& mult) {
    int tmp;
    if (mult < 0){
        tmp=multiply(this->min, this->max, this->pos, mult*(-1));
        this->pos=tmp;
        this->pos=this->operator-();
    }
    else{
        tmp=this->normalization(this->min, this->max, this->pos*mult);
        //tmp=multiply(this->min, this->max, this->pos, mult);
        this->pos=tmp;
    }
    return (*this);
}

//Overloading for '*=' operator for hour type!(CircularInt)
CircularInt& CircularInt::operator*=(const CircularInt& mult) {
    int tmp;
    if (mult.pos < 0){
        tmp=multiply(this->min, this->max, this->pos, mult.pos*(-1));
        this->pos=tmp;
        this->pos=this->operator-();
    }
    else{
        tmp=this->normalization(this->min, this->max, this->pos*mult.pos);
        //tmp=multiply(this->min, this->max, this->pos, mult.pos);
        this->pos=tmp;
    }
    return (*this);
}

//Overloading for '/=' operator for hour type! (int)
CircularInt& CircularInt::operator/=(const int& div) {
    CircularInt tmp{this->min,this->max};
    if (div > 0){
        this->pos=tmp.divide(this->min, this->max, this->pos, div);
    }
    else{
        this->pos=tmp.divide(this->min, this->max, this->pos, div*(-1));
        this->pos=this->operator-();
    }
    return (*this);
}

//Overloading for '/=' operator for hour type! (CircularInt)
CircularInt& CircularInt::operator/=(const CircularInt& div) {
    CircularInt tmp{this->min,this->max};
    if (div.pos > 0){
        this->pos=tmp.divide(this->min, this->max, this->pos, div.pos);
    }
    else{
        this->pos=tmp.divide(this->min, this->max, this->pos, div.pos*(-1));
        this->pos=this->operator-();
    }
    return (*this);
}

//Overloading for '%=' operator for hour type! (int)
CircularInt& CircularInt::operator%=(const int& mod) {
    this->pos=modulo(this->min, this->max, this->pos, mod);
    return (*this);
}

//Overloading for '%=' operator for hour type! (CircularInt)
CircularInt& CircularInt::operator%=(const CircularInt& mod) {
    this->pos=modulo(this->min, this->max, this->pos, mod.pos);
    return (*this);
}

//----------------------------------------
// friend global IO operators
//----------------------------------------
ostream& operator<< (ostream& os, const CircularInt& c) {
    os << c.pos;
    return os;
}
istream& operator>> (istream& is,CircularInt& c) {
    int tmp;
    is>>tmp;
    if (tmp>=c.min && tmp<=c.max){
        c.pos=tmp;
        return is;
    }else{
        c.pos=c.normalization(c.min,c.max,tmp);
        return is;
    }
    // string ans = "New pos larger than MAX! or new pos smaller than MIN!";
    // throw ans; 
}
//-------------------------------------
// friend global binary operators
//-------------------------------------
//Overloading for '-' operator for hour type! (int and CircularInt)
const CircularInt operator - (const int a, const CircularInt& other){
    CircularInt tmp{other.min,other.max};
    tmp.pos=other.pos;
    int res;
    if (a>0){
        tmp.pos=tmp.minus(tmp.min, tmp.max, tmp.pos, a);
        res=-tmp;
        tmp.pos=res;
    }
    else{
        tmp.pos=tmp.plus(tmp.min, tmp.max, tmp.pos, a*(-1));
        res=-tmp;
        tmp.pos=res;
    }
    return tmp;
}

//Overloading for '-' operator for hour type! (CircularInt and int)
const CircularInt operator - (const CircularInt& other,const int a){
    CircularInt tmp{other.min,other.max};
    tmp.pos=other.pos;
    if (a>0){
        tmp.pos=tmp.minus(tmp.min, tmp.max, tmp.pos, a);
    }
    else{
        tmp.pos=tmp.plus(tmp.min, tmp.max, tmp.pos, a*(-1));
    }
    return tmp;
}

//Overloading for '-' operator for hour type! (CircularInt and CircularInt)
const CircularInt operator - (const CircularInt& a, const CircularInt& b){
	CircularInt tmp{a.min,a.max};
    if (b.pos>0){
        tmp.pos=tmp.minus(tmp.min, tmp.max, a.pos, b.pos);
    }
    else{
        tmp.pos=tmp.plus(tmp.min, tmp.max, a.pos, b.pos*(-1));
    }
    return tmp;
}

//Overloading for '+' operator for hour type! (int and CircularInt)
const CircularInt operator+(const int a,const CircularInt& other){
    CircularInt tmp{other.min,other.max};
    tmp.pos=other.pos;
    if (a>0){
        tmp.pos=tmp.plus(tmp.min, tmp.max, tmp.pos, a);
    }
    else{
        tmp.pos=tmp.minus(tmp.min, tmp.max, tmp.pos, a*(-1));
    }
    return tmp;
}

//Overloading for '+' operator for hour type! (CircularInt and int)
const CircularInt operator+(const CircularInt& other,const int a){
    CircularInt tmp{other.min,other.max};
    tmp.pos=other.pos;
    if (a>0){
        tmp.pos=tmp.plus(tmp.min, tmp.max, tmp.pos, a);
    }
    else{
        tmp.pos=tmp.minus(tmp.min, tmp.max, tmp.pos, a*(-1));
    }
    return tmp;
}

//Overloading for '+' operator for hour type! (CircularInt and CircularInt)
const CircularInt operator + (const CircularInt& a, const CircularInt& b){
	CircularInt tmp{a.min,a.max};
    if (b.pos>0){
        tmp.pos=tmp.plus(tmp.min, tmp.max, a.pos, b.pos);
    }
    else{
        tmp.pos=tmp.minus(tmp.min, tmp.max, a.pos, b.pos*(-1));
    }
    return tmp;
}

//Overloading for '*' operator for hour type! (CircularInt and CircularInt)
const CircularInt operator*(const CircularInt& a, const CircularInt& b){
	CircularInt tmp{a.min,a.max};
    if (b.pos>0){
        tmp.pos=tmp.multiply(tmp.min, tmp.max, a.pos, b.pos);
    }
    else{
        tmp.pos=tmp.normalization(tmp.min,tmp.max,a.pos*b.pos);
        // tmp.pos=tmp.multiply(tmp.min, tmp.max, a.pos, b.pos*(-1));
        // tmp=tmp.operator-();
    }
    return tmp;
}

//Overloading for '*' operator for hour type! (int and CircularInt)
const CircularInt operator*(const int& a, const CircularInt& b){
	CircularInt tmp{b.min,b.max};
    if (a > 0){
        tmp.pos=tmp.multiply(tmp.min, tmp.max, b.pos, a);
    }
    else{
        tmp.pos=tmp.normalization(tmp.min,tmp.max,a*b.pos);
        // tmp.pos=tmp.multiply(tmp.min, tmp.max, b.pos, a*(-1));
        // tmp=tmp.operator-();
    }
    return tmp;
}

//Overloading for '*' operator for hour type! (CircularInt and int)
const CircularInt operator*(const CircularInt& b, const int& a){
	CircularInt tmp{b.min,b.max};
    if (a > 0){
        tmp.pos=tmp.multiply(tmp.min, tmp.max, b.pos, a);
    }
    else{
        tmp.pos=tmp.normalization(tmp.min,tmp.max,a*b.pos);
        // tmp.pos=tmp.multiply(tmp.min, tmp.max, b.pos, a*(-1));
        // tmp=tmp.operator-();
    }
    return tmp;
}

//Overloading for '/' operator for hour type! (CircularInt and CircularInt)
const CircularInt operator/(const CircularInt& a, const CircularInt& b){
	CircularInt tmp{a.min,a.max};
    if (b.pos > 0){
        tmp.pos=tmp.divide(tmp.min, tmp.max, a.pos, b.pos);
    }
    else{
        tmp.pos=tmp.divide(tmp.min, tmp.max, a.pos, b.pos*(-1));
        tmp=tmp.operator-();
    }
    return tmp;
}

//Overloading for '/' operator for hour type! (int and CircularInt)
const CircularInt operator/(const int& div, const CircularInt& b){
	CircularInt tmp{b.min,b.max};
    if (div > 0){
        tmp.pos=tmp.divide(tmp.min, tmp.max, b.pos, div);
    }
    else{
        tmp.pos=tmp.divide(tmp.min, tmp.max, b.pos, div*(-1));
        tmp=tmp.operator-();
    }
    return tmp;
}

//Overloading for '/' operator for hour type! (CircularInt and int)
const CircularInt operator / (const CircularInt& a,const int& div){
    CircularInt tmp{a.min,a.max};
    if (div > 0){
        tmp.pos=tmp.divide(tmp.min, tmp.max, a.pos, div);
    }
    else{
        tmp.pos=tmp.divide(tmp.min, tmp.max, a.pos, div*(-1));
        tmp=tmp.operator-();
    }
    return tmp;
}

//Overloading for '==' operator for hour type! (Two CircularInt types)
bool operator == (const CircularInt& a, const CircularInt& b){
    if (a.max==b.max && a.min==b.min && a.pos==b.pos){
        return true;
    }
    else{
        return false;
    }
}

//Overloading for '==' operator for hour type! (CircularInt and int)
bool operator == (const CircularInt& a, const int& b){
    if (a.pos==b){
        return true;
    }
    else{
        return false;
    }
}

//Overloading for '==' operator for hour type! (int and CircularInt)
bool operator == (const int& b, const CircularInt& a){
    if (a.pos==b){
        return true;
    }
    else{
        return false;
    }
}

//Overloading for '!=' operator for hour type! (Two CircularInt types)
bool operator != (const CircularInt& a, const CircularInt& b){
    return !(a==b);
}

//Overloading for '!=' operator for hour type! (CircularInt and int)
bool operator != (const CircularInt& a, const int& b){
    return !(a==b);
}

//Overloading for '!=' operator for hour type! (Int and CircularInt )
bool operator != (const int& a, const CircularInt& b){
    return !(a==b);
}

//Overloading for '>' operator for hour type! (Two CircularInt types)
bool operator > (const CircularInt& a, const CircularInt& b){
    if (a.max==b.max && a.min==b.min && a.pos>b.pos){ //we have decided that it is not relevant to compare two types
        return true;                                   //that are not within the same range
    }
    else{
        if (a.max==b.max && a.min==b.min && a.pos<=b.pos)
            return false;
        return false;
        // string ans = "The objects are not from the same range!";
        // throw ans;
    }

}

//Overloading for '>' operator for hour type! (CircularInt and int)
bool operator > (const CircularInt& a, const int& b){
    if (a.pos>b){                          
        return true;                                   
    }
    else
        return false;
}

//Overloading for '>' operator for hour type! (int and CircularInt)
bool operator > (const int& b, const CircularInt& a){
    if (a.pos<b){                          
        return true;                                   
    }
    else
        return false;
}

//Overloading for '<' operator for hour type! (Two CircularInt types)
bool operator < (const CircularInt& a, const CircularInt& b){
     if (a.max==b.max && a.min==b.min && a.pos<b.pos){ //we have decided that it is not relevant to compare two types
        return true;                                   //that are not within the same range
    }
    else{
        if (a.max==b.max && a.min==b.min && a.pos>=b.pos)
            return false;
        return false;
        // string ans = "The objects are not from the same range!";
        // throw ans;
    }
}

//Overloading for '<' operator for hour type! (CircularInt and int)
bool operator < (const CircularInt& a, const int& b){
     if (a.pos<b){
        return true;                                   
    }
    else{
        return false;
    }
}

//Overloading for '<' operator for hour type! (Int and CircularInt)
bool operator < (const int& b, const CircularInt& a){
     if (b<a.pos){
        return true;                                   
    }
    else{
        return false;
    }
}

//Overloading for '>=' operator for hour type! (Two CircularInt types)
bool operator >= (const CircularInt& a, const CircularInt& b){
     return (a>b || a==b);
}

//Overloading for '>=' operator for hour type! (CircularInt and int)
bool operator >= (const CircularInt& a, const int& b){
     return (a>b || a==b);
}

//Overloading for '>=' operator for hour type! (Int and CircularInt)
bool operator >= (const int& b, const CircularInt& a){
     return (b>a || b==a);
}

//Overloading for '<=' operator for hour type! (Two CircularInt types)
bool operator <= (const CircularInt& a, const CircularInt& b){
     return (a<b || a==b);
}

//Overloading for '<=' operator for hour type! (CircularInt and int)
bool operator <= (const CircularInt& a, const int& b){
     return (a<b || a==b);
}

//Overloading for '<=' operator for hour type! (Int and CircularInt)
bool operator <= (const int& b, const CircularInt& a){
     return (b<a || b==a);
}

//Overloading for '%' operator for hour type! (CircularInt and int)
const CircularInt operator%(const CircularInt& a, const int& mod) {
    CircularInt tmp{a.min,a.max};
    tmp.pos=tmp.modulo(a.min, a.max, a.pos, mod);
    return tmp;  
}

//Overloading for '%' operator for hour type! (Two CircularInts)
const CircularInt operator%(const CircularInt& a, const CircularInt& b) {
    CircularInt tmp{a.min,a.max};
    tmp.pos=tmp.modulo(a.min, a.max, a.pos, b.pos);
    return tmp;  
}

//Overloading for bitwise '&' operator for hour type! (Two CircularInts)
const CircularInt operator&(const CircularInt& a, const CircularInt& b) {
    CircularInt tmp{a.min,a.max};
    int first = a.pos;
    int second = b.pos;
    tmp.pos=tmp.normalization(a.min,a.max,first&second);
    return tmp;  
}

//Overloading for bitwise '&' operator for hour type! (int and CircularInt)
const CircularInt operator&(const int& a, const CircularInt& b) {
    CircularInt tmp{b.min,b.max};
    int second = b.pos;
    tmp.pos=tmp.normalization(b.min,b.max,a&second);
    return tmp;  
}

//Overloading for bitwise '&' operator for hour type! (CircularInt and int)
const CircularInt operator&(const CircularInt& a, const int& b) {
    CircularInt tmp{a.min,a.max};
    int first = a.pos;
    tmp.pos=tmp.normalization(a.min,a.max,first&b);
    return tmp;  
}

//Overloading for bitwise '|' operator for hour type! (Two CircularInts)
const CircularInt operator|(const CircularInt& a, const CircularInt& b) {
    CircularInt tmp{a.min,a.max};
    int first = a.pos;
    int second = b.pos;
    tmp.pos=tmp.normalization(a.min,a.max,first|second);
    return tmp;  
}

//Overloading for bitwise '|' operator for hour type! (int and CircularInt)
const CircularInt operator|(const int& a, const CircularInt& b) {
    CircularInt tmp{b.min,b.max};
    int second = b.pos;
    tmp.pos=tmp.normalization(b.min,b.max,a|second);
    return tmp;  
}

//Overloading for bitwise '|' operator for hour type! (CircularInt and int)
const CircularInt operator|(const CircularInt& a, const int& b) {
    CircularInt tmp{a.min,a.max};
    int first = a.pos;
    tmp.pos=tmp.normalization(a.min,a.max,first|b);
    return tmp;  
}

//Overloading for bitwise '^' operator for hour type! (Two CircularInts)
const CircularInt operator^(const CircularInt& a, const CircularInt& b) {
    CircularInt tmp{a.min,a.max};
    int first = a.pos;
    int second = b.pos;
    tmp.pos=tmp.normalization(a.min,a.max,first^second);
    return tmp;  
}

//Overloading for bitwise '^' operator for hour type! (int and CircularInt)
const CircularInt operator^(const int& a, const CircularInt& b) {
    CircularInt tmp{b.min,b.max};
    int second = b.pos;
    tmp.pos=tmp.normalization(b.min,b.max,a^second);
    return tmp;  
}

//Overloading for bitwise '^' operator for hour type! (CircularInt and int)
const CircularInt operator^(const CircularInt& a, const int& b) {
    CircularInt tmp{a.min,a.max};
    int first = a.pos;
    tmp.pos=tmp.normalization(a.min,a.max,first^b);
    return tmp;  
}

//Overloading for bitwise '<<' operator for hour type! (Two CircularInts)
const CircularInt operator<<(const CircularInt& a, const CircularInt& b) {
    CircularInt tmp{a.min,a.max};
    int first = a.pos;
    int second = b.pos;
    tmp.pos=tmp.normalization(a.min,a.max,first<<second);
    return tmp;  
}

//Overloading for bitwise '<<' operator for hour type! (int and CircularInt)
const CircularInt operator<<(const int& a, const CircularInt& b) {
    CircularInt tmp{b.min,b.max};
    int second = b.pos;
    tmp.pos=tmp.normalization(b.min,b.max,a<<second);
    return tmp;  
}

//Overloading for bitwise '<<' operator for hour type! (CircularInt and int)
const CircularInt operator<<(const CircularInt& a, const int& b) {
    CircularInt tmp{a.min,a.max};
    int first = a.pos;
    tmp.pos=tmp.normalization(a.min,a.max,first<<b);
    return tmp;  
}

//Overloading for bitwise '>>' operator for hour type! (Two CircularInts)
const CircularInt operator>>(const CircularInt& a, const CircularInt& b) {
    CircularInt tmp{a.min,a.max};
    int first = a.pos;
    int second = b.pos;
    tmp.pos=tmp.normalization(a.min,a.max,first>>second);
    return tmp;  
}

//Overloading for bitwise '>>' operator for hour type! (int and CircularInt)
const CircularInt operator>>(const int& a, const CircularInt& b) {
    CircularInt tmp{b.min,b.max};
    int second = b.pos;
    tmp.pos=tmp.normalization(b.min,b.max,a>>second);
    return tmp;  
}

//Overloading for bitwise '>>' operator for hour type! (CircularInt and int)
const CircularInt operator>>(const CircularInt& a, const int& b) {
    CircularInt tmp{a.min,a.max};
    int first = a.pos;
    tmp.pos=tmp.normalization(a.min,a.max,first>>b);
    return tmp;  
}