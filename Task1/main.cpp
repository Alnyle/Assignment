#include <iostream>
#include <map>
#include <cctype>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;


string cleanWord(string &word) {

    // the clean word;
    string nWord;

    // loop on word characters and clean it from any punctuation and non-alphanumeric
    for (int i = 0; i < word.size(); i++) {
        
        // check if the character not punctuation and if the character is punctuation check is '-' then add it
        if (isalpha(word[i]) || word[i] == '-')  {

            
                nWord += word[i];
            
        }
    }

    return nWord;
    
} 

void getFrequencyTable(ifstream &file,map<string, int>& freTable)  {

    // variable to store line of the file 
    string line;


    
    // loop on file lines
    while(getline(file, line)) {


        // to store words when loop on lines
        string word;

        // use stringStream to spilt line to words using stringStream 
        stringstream ss(line);
        
        // loop on line words word by word
        while(ss >> word) {
            
            // clean the word it from any punctuation and non-alphanumeric
            freTable[cleanWord(word)]++;     
        }
    }


}

int main() {
    // map to store frequency if each word
    map <string, int > freTable;

    // store file path in string (name)
    string path;
    ifstream file;

    cout << "this Program show the frequency of each words in your file \n";

    // let user Enter file path
    cout << "Enter file path: ";
    cin >> path; 


    // append .txt at the end of the path to make it read file from type txt
    path.append(".txt");

    // open the file
    file.open(path);

    getFrequencyTable(file, freTable);
    

    for (auto word:freTable) {
        cout << "Word: " << word.first << " " << "Frequency: " << word.second << '\n'; 
    }
    
    
    
    file.close();


}