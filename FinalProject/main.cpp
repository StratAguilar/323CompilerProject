//
//  main.cpp
//  FinalProject
//
//  Created by Stratton Aguilar and Mario Andrade on 4/17/14.
//  Copyright (c) 2014 Stratton Aguilar. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "ProjectClean.h"
#include "CheckError.h"
#include "CPlusPlusConversion.h"
using namespace std;

int main(int argc, const char * argv[])
{
    bool Success;
    string inFile = "/Users/rabbitofalice/Documents/finaltext.txt" ; //file input
    string outFile= "/Users/rabbitofalice/Documents/finaltext2.txt";  // file output
    Success = ConvertFile(inFile, outFile);
    
    if(Success)
    {
        cout << "File ready for Compiler."<< endl;
    
        if(ScanCode(outFile))
        {
            convert2cplusplus(outFile);
            cout << "File Converted to C++ Format."<< endl;
        }
    }
    
    return 0;
}

