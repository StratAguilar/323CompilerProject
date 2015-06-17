//
//  ProjectClean.h
//  FinalProject
//
//  Created by Stratton Aguilar and Mario Andradeon 5/2/14.
//  Copyright (c) 2014 Stratton Aguilar. All rights reserved.
//

#ifndef FinalProject_ProjectClean_h
#define FinalProject_ProjectClean_h

#include <iostream>
#include <fstream>
using namespace std;

bool ConvertFile(string inFile, string outFile)
{
    
    ifstream instream;
    ofstream outstream;
    
	instream.open(inFile); // path for input file
	if(!instream.is_open())
	{
		cout << "Error opening file!!!!"<< endl;
		return false;
	}
    
    outstream.open(outFile); // path for output file
	if(!outstream.is_open())
	{
		cout << "Error opening file!!!!"<< endl;
		return false;
	}
    
    string tempString;
    int length;
    bool content = false;
    bool comment = false;
    
    while(instream.good())
    {
        
        content = false;
        
        getline(instream, tempString);
        int i = 0;
        length = int(tempString.length());
        
        while(i < length)
        {
            if(tempString[i] == ';')  // check for ';' to terminate line
            {
                outstream << ';';
                i++;
            }
            
            else if ((i + 1 < length && tempString[i]  == '(' && tempString[i + 1] == '*') || comment == true)
            {
                comment = true;
                
                while(i < length && comment == true)
                {
                    if(i < length + 1 && tempString[i]  == '*' && tempString[i + 1] == ')')
                    {
                        comment = false;
                        i++;
                    }
                    i++;
                }
            }
            
            else
            {
                if(isalpha(tempString[i]) || '_' == tempString[i]) // check for vars or fuction names
                {
                    content = true;
                    
                    while(isalpha(tempString[i]) || tempString[i] == '_' || isdigit(tempString[i]))
                    {
                        outstream << tempString[i];
                        i++;
                    }
                    
                    if(!(tempString[i] == '.'))
                    {
                        outstream << " ";                        // no output
                    }
                    i--;
                }
                
                else if(isdigit(tempString[i]))  // check for integers
                {
                    content = true;
                    
                    while(isdigit(tempString[i]))
                    {
                        outstream << tempString[i];
                        i++;
                    }
                    outstream << " ";
                    i--;
                }
                
                else if(tempString[i] == ',' || tempString[i] == '*' || // check for arithmic expressions
                        tempString[i] == '/' || tempString[i] == '+' || // also ',' seperations
                        tempString[i] == '-' || tempString[i] == '=' ||
                        tempString[i] == ':')
                {
                    outstream<< tempString[i] <<" ";
                }
                
                else if(tempString[i] == '{' || tempString[i] == '}') // check for brackets
                {
                    outstream<< tempString[i];
                    content = true;
                }
                else if(tempString[i] == '(' || tempString[i] == ')' || tempString[i] == '.')
                {
                    outstream << tempString[i]<< " ";
                }
                i++;
            }
        }
        
        if(content)                 // if the line containts content output end of line
        {
            outstream<< "\n";
        }
    }
    instream.close();
    outstream.close();
    return true;
}


#endif
