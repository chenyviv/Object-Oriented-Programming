#include<iostream>
#include<fstream>

#include<string>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<random>

using namespace std;

//------------------------PROTOTYPE-------------------------------------------
void promptFile(vector<string> &); 
void printVec(vector<string>);

int ranGen(int size);
bool readFile(string filename, vector<string> & vec);
void writeFile(string filename, vector<string> v0, vector<string> v1);

int main()
{
    vector<string> roster;
    vector<string> qBank;
    readFile("2310_F26_Rosters.csv", roster);
    readFile("Questions.csv", qBank);
    // printVec(roster);
    // printVec(qBank);

    // cout << "Size of roster: " << roster.size() << endl; 
    // cout << "Size of qBank: " << qBank.size() << endl;

    writeFile("Student_question_bank.csv",roster, qBank);

}

//------------------------DECLARATIONS-------------------------------------------
int ranGen(int size){
    //int randomNumber = rand() % size;  // 0 through size-1
    // return randomNumber;
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<int> dist(0, size - 1);
    return dist(gen);
}

/**
 * @brief reads contents of filename and populates into vec
 * 
 * @param filename :string 
 * @param vec: vector<string> &
 */

bool readFile(string filename, vector<string> & vec) {

   ifstream inputFile(filename);

    //error handling
    if (!inputFile.is_open()) {
        cerr << "Error: Could not open file\n";
        return false;
    }

    string line;

    while (getline(inputFile, line)) {
        vec.push_back(line);
    }

    inputFile.close();
    return true;
}
/**
 * @brief writes to filename with the first column from v0, second column from v1
 * 
 * @param filename: string
 * @param v0: vector<string> (for students names)
 * @param v1: vector<string> (for questions)
 * 
 * TO DO: 
 * ​​​Return a bool instead in order to indicate whether the operation
 * succeeded or not
 * 
 * TO DO:
 * ​​Use pass by const reference (const vector<string> & v0, const vector<string> & v1)
 * as opposed to pass by value (vector<string> v0, vector<string> v1). 
 * 
 * What is the differennce between:
 * -  pass by reference (e.g. vector<string> & v0),
 * -  pass by value (e.g. vector<string> v0),
 * -  pass by const reference (e.g. const vector<string> & v0),
 */
void writeFile(string filename, vector<string> v0, vector<string> v1){

    ofstream outputFile(filename);
     if (!outputFile) {
        cout << "Error: Could not create data.csv" << endl;
    }

    // write under the structure:
    // Student_Name, Question_#
    for(int i = 0; i < v0.size(); i++){
        outputFile << v0[i] << "," << v1[ranGen(v1.size())] << endl;
    }
    outputFile.close();

}

/**
 * @brief prompts the user to give a file to read
 * 
 */
void promptFile(vector<string> & v){
    cout << "file to read?\n";
    string myFile = "";
    cin >> myFile;
    readFile(myFile, v);
}


/**
 * @brief prints out the elements in v
 * 
 * @param v: vector<string>
 */
void printVec(vector<string> v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << endl;
    }
}