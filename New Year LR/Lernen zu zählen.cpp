#include <iostream>
#include <vector>
#include <string>
using namespace std;



// Преобразование чисел до 19
string UnderTwenty(int number) {
    const vector<string> words = {"","ein","zwei","drei", "vier", "funf", "sechs", "sieben", "acht", "neun", "zehn", "elf", "zwolf", "dreizehn", "vierzehn", "funfzehn", "sechzehn", "siebzehn", "achtzehn", "neunzehn"};
    return words[number];
}


string Tens(int number) {
    const vector<string> tens = { "", "zehn", "zwanzig", "dreissig", "vierzig", "funfzig", "sechzig", "siebzig", "achtzig", "neunzig"};
    
    if (number < 20)
        return UnderTwenty(number);
        
    int ten = number / 10;
    int ost = number % 10;
    
    if (ost == 0)
        return tens[ten];
        
    return UnderTwenty(ost) + "und" + tens[ten];
}

string Hundreds(int number) {
    if (number < 100)
        return Tens(number);
        
    int hundreds = number / 100;
    int ost = number % 100;
    return UnderTwenty(hundreds) + "hundert" + Tens(ost);
}


string Thousands(int number) {
    if (number < 1000) 
        return Hundreds(number);
        
    int thousands = number / 1000;
    int ost = number % 1000;
    
    if (thousands == 1)
        return "eintausend" + Hundreds(ost);
    return Hundreds(thousands) + "tausend" + Hundreds(ost);
}


string Millions(int number) {
    if (number < 1000000)
        return Thousands(number);
    
    int millions = number / 1000000;
    int ost = number % 1000000;
    
    if (millions == 1) 
        return "einMillion" + Thousands(ost);
    
    return Hundreds(millions) + "Millionen" + Thousands(ost);
}


string German(int number) {
    if (number == 0) return "null";
    return Millions(number);
}

int main() {
    int num;
    cin >> num;
    cout  <<German(num);
    return 0;
}
