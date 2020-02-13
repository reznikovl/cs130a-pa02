#include <iostream>
#include "Quash.h"
#include <sstream>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
    Quash quash;
    istringstream ss(argv[1]);
    string command;
    while(ss >> command) {
        if(command == "insert") {
            string temp;
            ss >> temp;
            if(temp.find(",") != string::npos) {
                quash.insert(stoi(temp.substr(0, temp.length()-1)));
            }
            else {
                quash.insert(stoi(temp));
            }
            continue;
        }

        if(command == "lookup") {
            string temp;
            ss >> temp;
            if(temp.find(",") != string::npos) {
                quash.lookup(stoi(temp.substr(0, temp.length()-1)));
            }
            else {
                quash.lookup(stoi(temp));
            }
            continue;
        }

        if(command == "deleteMin" || command == "deleteMin,") {
            quash.deleteMin();
            continue;
        }
        
        if(command == "delete") {
            string temp;
            ss >> temp;
            if(temp.find(",") != string::npos) {
                quash.deleteElement(stoi(temp.substr(0, temp.length()-1)));
            }
            else {
                quash.deleteElement(stoi(temp));
            }
            continue;
        }

        if(command == "print" || command == "print,") {
            quash.print();
        }
        
    }

}