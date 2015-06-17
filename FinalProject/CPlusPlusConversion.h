//
//  CPlusPlusConversion.h
//  FinalProject
//
//  Created by Stratton Aguilar and Mario Andrade on 5/6/14.
//  Copyright (c) 2014 Stratton Aguilar. All rights reserved.
//

#ifndef FinalProject_CPlusPlusConversion_h
#define FinalProject_CPlusPlusConversion_h

#include <iostream>
#include <fstream>

using namespace std;

bool convert2cplusplus (string inFile) {
    string readIn, fileName;
    ifstream fin;
    ofstream fout;
    
	fin.open(inFile); // path for input file
	if(!fin.is_open())
	{
		cout << "Error opening file!!!!"<< endl;
		return false;
	}
    
    fileName = "/Users/rabbitofalice/Documents/";
    
    fin >> readIn;
    
    if (readIn == "PROGRAM") {
        fin >> readIn;
        fileName += readIn + ".cpp";
        fout.open(fileName);
        if(!fout.is_open())
        {
            cout << "Error opening file!!!!"<< endl;
            return false;
        }
        
        fin >> readIn;
        readIn.clear();
        
        fout << "#include <iostream>\nusing namespace std;\n";
        
        while (fin.good()) {
            fin >> readIn;
            
            if (readIn == "VAR") {
                string variables = " ";
                while (readIn != ";") {
                    fin >> readIn;
                    if (readIn == "INTEGER") {
                        fout << "int" + variables + ";\n";
                        fin >> readIn;
                    }
                    else if (readIn == ":") {
                        readIn.clear();
                    }
                    else {
                        variables += readIn + " ";
                    }
                }
            }
            else if (readIn == "BEGIN") {
                fout << "int main() {\n";
            }
            else if (readIn == "writeln") {
                fin >> readIn;
                readIn.clear();
                fin >> readIn;
                fout << "cout << " + readIn + " ;\n";
                fin >> readIn;
                readIn.clear();
                fin >> readIn;
                readIn.clear();
            }
            else if (readIn == "END.") {
                fout << "return 0;\n}";
                readIn.clear();
            }
            else if (readIn == ";") {
                fout << ";\n";
            }
            else if (isdigit(readIn.front()) || readIn.front() == 'v' || readIn.front() == 'w' || readIn.front() == 'x' || readIn.front() == 'y' || readIn.front() == 'z') {
                fout << readIn + " ";
            }
            else if (readIn == "=" || readIn == "+" || readIn == "-" || readIn == "*" || readIn == "/" || readIn == "(" || readIn == ")" || readIn == ")") {
                fout << readIn + " ";
            }
            
        }
        fin.close();
        fout.close();
        return true;
    }
    fin.close();
    return false;
}


#endif
