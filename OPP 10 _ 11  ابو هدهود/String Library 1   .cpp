                        // String Library Project (Requirements)  

/*

//ProgrammingAdvices.com
//Mohammed Abu-Hadhoud

#include <iostream>
#include "clsString.h"

using namespace std;


int main()

{
    clsString String1;
    clsString String2("Mohammed");

    String1.Value = "ali Ahmed keroles Fadi";

    cout << "String1 = " << String1.Value << endl;
    cout << "String2 = " << String2.Value << endl;

    cout << "Number of words: " << String1.CountWords() << endl;

    cout << "Number of words: " << String1.CountWords("Fadi ahmed rateb omer") << endl;

    cout << "Number of words: " <<
        clsString::CountWords("Mohammed Saqer Abu-Hadhoud");

    cout << String1.CountWords("Keroles Mezre akfj botros alngar");

    cout << "\n\nPrint First Letter Of Each Word?"; 
    String1.PrintFirstLetterOfEachWord("Keroles  Mezare Khames");


    cout << "\n\nPrint First Letter Of Each Word?";
    clsString::PrintFirstLetterOfEachWord(String1.Value);


    cout << "\n\nPrint Upper First Letter Of Each Word?\n" <<
        clsString::UpperFirstLetterOfEachWord(String1.Value);


       cout << "\n\nPrint Lowwer First Letter Of Each Word?\n" <<
        clsString::LowwerFirstLetterOfEachWord(String1.Value);


    system("pause>0");
    return 0;
};



*/

