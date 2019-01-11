/***** First Program ******/
//To read number of characters, numbers blank spaces etc. in a file

#include<bits/stdc++.h>
using namespace std;

int main() {
    fstream fout;
    int number_of_ints = 0, number_of_chars = 0, number_of_spaces = 0, special_chars = 0;
    fout.open("sampleFile.txt", ios::in);
    
    while(!fout.eof()){
        char ch;
        fout.get(ch);
        if( ch >= 48 && ch <= 57){
            if(fout.eof()) break;
            number_of_ints++;
        }

        else if((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122))
        {
            if(fout.eof()) break;            
            number_of_chars++;            
        }

        else if(ch == 32) {
            if(fout.eof()) break;
            number_of_spaces++;
        }

        else {
            if(fout.eof()) break;
            special_chars++;
        }
    }
    
    cout<<"Number of Digits present in the file: "<<number_of_ints<<endl;
    cout<<"Number of Characters present in the file: "<<number_of_chars<<endl;
    cout<<"Number of Spaces present in the file: "<<number_of_spaces<<endl;
    cout<<"Number of Special Characters present in the file: "<<special_chars<<endl;
    fout.close();
    return 0;
}