//
//  CheckError.h
//  FinalProject
//
//  Created by Stratton Aguilar and Mario Andrade on 5/3/14.
//  Copyright (c) 2014 Stratton Aguilar. All rights reserved.
//

#ifndef FinalProject_CheckError_h
#define FinalProject_CheckError_h

#include <iostream>
#include "Stack.h"
#include <vector>
#include <fstream>

using namespace std;
int CharIndex(char);
bool CheckTerm(char);
char tableConversion(string);
string ErrorValue(char);
string tableError(char, char);

bool ScanCode(string filename)
{
    stacks<char, 100> Stack;
    Stack.ClearStack();
    ifstream infile;
    int arrayLength = 0;
    string tempString;
    string userString[100];
    infile.open(filename);
    
    if(!infile.is_open())
	{
		cout << "Error opening file!!!!"<< endl;
		return false;
	}
    
    
    while(infile.good())
    {
        infile >> tempString;
        if(tempString != "\n")
        {
            if(tempString[tempString.length() -1 ] == '\n')
            {
                tempString = tempString.substr(0, tempString.length() - 2);
            }
            userString[arrayLength] = tempString;
            arrayLength++;
        }
    }
    infile.close();
    arrayLength--;
    
    string table [20][19] {
    // (     )     *     +     ,    -     /    :    ;    =    a  b    d    e     i      n        p      r    $
        
      "0",  "0",  "0", "0",  "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0",  "0", "pB;aCbFe", "0", "0",//A
      "0",  "0",  "0",  "0",  "0", "0",  "0", "0", "0", "0", "0", "0", "0", "0", "iO",  "0", "0", "0", "0",//B
      "0",  "0",  "0",  "0",  "0", "0",  "0", "0", "0", "0", "0", "0", "0", "0", "D:n;",  "0", "0", "0", "0",//C
      "0",  "0",  "0",  "0",  "0", "0",  "0", "0", "0", "0", "0", "0", "0", "0", "BU",  "0", "0", "0", "0",//D
      "0",  "0",  "0",  "0",  "0", "0",  "0", "0", "0", "0", "0", "0", "0", "0", "iI",  "0", "0", "0", "0",//E
      "0",  "0",  "0",  "0",  "0", "0",  "0", "0", "0", "0", "0", "0", "0", "0", "GS",  "0", "0", "GS", "0",//F
      "0",  "0",  "0",  "0",  "0", "0",  "0", "0", "0", "0", "0", "0", "0", "0", "B=J;",  "0", "0", "r(B);", "0",//G
      "0",  "M",  "M",  "M",  "0", "M",  "M", "0", "M", "0", "0", "0", "dI", "0", "iI",  "0", "0", "0", "0",//I
      "KV", "0",  "0",  "KV", "0", "KV",  "0", "0", "0", "0", "0", "0", "KV", "0", "KV",  "0", "0", "0", "0",//J
      "LX", "0",  "0",  "LX", "0", "LX",  "0", "0", "0", "0", "0", "0", "LX", "0", "LX",  "0", "0", "0", "0",//K
      "(J)", "0", "0",  "NT", "0", "NT",  "0", "0", "0", "0", "0", "0", "NT", "0", "E",  "0", "0", "0", "0",//L
      "0",  "0",  "0",  "+",  "0", "-",  "0", "0", "0", "0", "0", "0", "M", "0", "0",  "0", "0", "0", "0",//N
      "0",  "M",  "0",  "0",  "M", "0",  "0", "M", "M", "M", "0", "0", "dO", "0", "iO", "0", "0",  "0", "0",//O
      "0",  "0",  "0",  "0",  "0", "0",  "0", "0", "0", "0", "0", "0", "0", "M", "F",  "0", "0", "F", "0",//S
      "0",  "0",  "0",  "0",  "0", "0",  "0", "0", "0", "0", "0", "0", "dZ", "0", "0",  "0", "0", "0", "0",//T
      "0",  "0",  "0",  "0", ",BU", "0",  "0", "M", "0", "0", "0", "0", "0", "0", "0",  "0", "0", "0", "0",//U
      "0",  "M",  "0", "+J",  "0", "-J", "0", "0", "M", "0", "0", "0", "0", "0", "0",  "0", "0", "0", "0",//V
      "0",  "M", "*LX", "M",  "0", "M", "/LX", "0", "M", "0", "0", "0", "0", "0", "0",  "0", "0", "0", "0",//X
      "0",  "0",  "0",  "0",  "0", "0",  "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0",//Y
      "0",  "M",  "M",  "M",  "0", "M",  "M", "0", "M", "0", "0", "0", "dZ", "0", "0",  "0", "0", "0", "0" //Z
    };
    
    Stack.push('$');			//starting values
    Stack.push('A');
    
    bool valid = true;
    int i = 0;
    int varlength = 1;
    char userChar;
    char popValue = 'H';
    char errorState = 'Q';
    char errorTable = 'Q';
    string temp;
    string tableString;
    bool var = false;
    bool assign = true;
    bool found = false;
    vector<string> variableList;
    
    
    while(i < arrayLength && valid)
    {
        if((userString[i]!="writeln" && userString[i][0]> 117 && userString[i][0]<123) || isdigit(userString[i][0]))
        {
            varlength = int(userString[i].length());
            var = true;
        }
        else
        {
            varlength = 1;
            var = false;
        }
        
        for(int k = 0; k < varlength && valid; k++)
        {
            if(var)
            {
                temp = userString[i][k];
                userChar = tableConversion(temp);
                //cout<< i << " character is "<< temp << endl; // testing output
            }
            else
            {
                userChar = tableConversion(userString[i]);
                
                if(userChar == 'b')
                {
                    assign = false;
                }
                
                //cout<< i << " character is "<< userString[i] << endl; // testing output
            }
            
        
            while (!Stack.EmptyStack() && !CheckTerm(popValue = Stack.pop()))
            {
                //cout << "\t popped value is " << popValue << endl; // testing output
                tableString = table[CharIndex(popValue)][CharIndex(userChar)];
                //cout << "\t\t indexed string is " << tableString << endl; // testing output
                if(tableString == "0") // reached invalid value
                {
                    
                    valid = false;
                    errorState = popValue;
                    errorTable = userChar;
                    //cout<< "Valid is now False"<<endl; // testing output
                }
                else if(tableString == "M")
                {
                
                }
                else
                {
                    for(int j = int(tableString.length() - 1) ; j >= 0; j--)
                    {
                        Stack.push(tableString[j]);
                        //cout<< "\t\t\t Pushed value is " << tableString[j] << endl; // testing output
                    }
                }
            
            }
        
            if(!(popValue == userChar))  // if popped variable does not mach input value
            {
                
                cout << "ERROR MESSAGE: " << tableError(errorState, errorTable)<< endl;
                
                if(popValue != 'e' && errorTable != 'i' && errorTable != 'd')
                {
                    cout << "ERROR MESSAGE: expected \""<< ErrorValue(popValue)<< "\""<< endl;
                }
                
                //cout << "popValue is :" << popValue << " userChar is :" << userChar << endl; //for testing
                valid = false;
            }
            if(var && !(isdigit(userString[i][0])))
            {
                if(assign)
                {
                    variableList.push_back(userString[i]);
                }
                else
                {
                    found = false;
                    for(int l = 0; !found && l < variableList.size(); l++)
                    {
                        if(userString[i] == variableList[l])
                        {
                            found = true;
                        }
                    }
                    if(!found)
                    {
                        cout << "ERROR MESSAGE: UNDEFINED VARIABLE: "<< userString[i]<< endl;
                        valid = false;
                    }
                }
            }
        }
        
        i++;
        //cout<< "incremented"<<endl;
    }
    
    while (!Stack.EmptyStack())  //pop remaining stack
    {
        popValue = Stack.pop();
        //cout << popValue << endl;
        
        
        if(popValue != '$')
        {
            valid = false;
        }
        
    }

    
    
    if(valid == false)
    {
        if(userString[arrayLength - 1] != "END.")
        {
            cout << "ERROR MESSAGE: \"END.\" not found"<< endl;
        }
        cout << "Rejected."<<endl;
    }
    else
    {
        cout << "No Errors"<< endl;
    }
    return valid;
}

int CharIndex(char c)
{
    int returnInt;
    switch(c)  // values for table by index
    {
        case 'A': returnInt = 0;
            break;
        case 'B': returnInt = 1;
            break;
        case 'C': returnInt = 2;
            break;
        case 'D': returnInt = 3;
            break;
        case 'E': returnInt = 4;
            break;
        case 'F': returnInt = 5;
            break;
        case 'G': returnInt = 6;
            break;
        case 'I': returnInt = 7;
            break;
        case 'J': returnInt = 8;
            break;
        case 'K': returnInt = 9;
            break;
        case 'L': returnInt = 10;
            break;
        case 'N': returnInt = 11;
            break;
        case 'O': returnInt = 12;
            break;
        case 'S': returnInt = 13;
            break;
        case 'T': returnInt = 14;
            break;
        case 'U': returnInt = 15;
            break;
        case 'V': returnInt = 16;
            break;
        case 'X': returnInt = 17;
            break;
        case 'Y': returnInt = 18;
            break;
        case 'Z': returnInt = 19;
            break;
        case '(': returnInt = 0;
            break;
        case ')': returnInt = 1;
            break;
        case '*': returnInt = 2;
            break;
        case '+': returnInt = 3;
            break;
        case ',': returnInt = 4;
            break;
        case '-': returnInt = 5;
            break;
        case '/': returnInt = 6;
            break;
        case ':': returnInt = 7;
            break;
        case ';': returnInt = 8;
            break;
        case '=': returnInt = 9;
            break;
        case 'a': returnInt = 10;
            break;
        case 'b': returnInt = 11;
            break;
        case 'd': returnInt = 12;
            break;
        case 'e': returnInt = 13;
            break;
        case 'i': returnInt = 14;
            break;
        case 'n': returnInt = 15;
            break;
        case 'p': returnInt = 16;
            break;
        case 'r': returnInt = 17;
            break;
        case '$': returnInt = 18;
            break;
        default: returnInt = 100;
    }
    return returnInt;
};

bool CheckTerm(char c)  // defines term as Node or variable
{
    bool isTerm = false;
    switch(c)
    {
        case 'A':
        case 'B':
        case 'C':
        case 'D':
        case 'E':
        case 'F':
        case 'G':
        case 'I':
        case 'J':
        case 'K':
        case 'L':
        case 'N':
        case 'O':
        case 'S':
        case 'T':
        case 'U':
        case 'V':
        case 'X':
        case 'Y':
        case 'Z':
            break;
        case '(':
        case ')':
        case '*':
        case '+':
        case ',':
        case '-':
        case '/':
        case ':':
        case ';':
        case '=':
        case 'a':
        case 'b':
        case 'd':
        case 'e':
        case 'i':
        case 'n':
        case 'p':
        case 'r':
        case '$': isTerm = true;
            break;
        default: ;
    }
    
    return isTerm;
};

char tableConversion(string x)
{
    char convertedValue;
    
    if(x != "writeln" && x[0]> 117 && x[0] < 123)
    {
        convertedValue = 'i';
    }
    else if(isdigit(x[0]))
    {
        convertedValue = 'd';
    }
    else if(x.length() < 2)
    {
        convertedValue = char(x[0]);
    }
    else
    {
        if(x == "BEGIN") convertedValue = 'b';
        else if(x == "PROGRAM") convertedValue = 'p';
        else if(x == "VAR") convertedValue = 'a';
        else if(x == "INTEGER") convertedValue = 'n';
        else if(x == "END.") convertedValue = 'e';
        else if(x == "writeln") convertedValue = 'r';
        else
        {
           convertedValue = 'm';
        }
    }
    return convertedValue;
}

string ErrorValue(char c)
{
    string value;
    switch(c)
    {
        case '(': value = "(";
            break;
        case ')': value = ")";
            break;
        case '*': value = "*";
            break;
        case '+': value = "+";
            break;
        case ',': value = ",";
            break;
        case '-': value = "-";
            break;
        case '/': value = "/";
            break;
        case ':': value = ":";
            break;
        case ';': value = ";";
            break;
        case '=': value = "=";
            break;
        case 'a': value = "VAR";
            break;
        case 'b': value = "BEGIN";
            break;
        case 'd': value = "DIGIT";
            break;
        case 'e': value = "END.";
            break;
        case 'i': value = "ID";
            break;
        case 'n': value = "INTEGER";
            break;
        case 'p': value = "PROGRAM";
            break;
        case 'r': value = "writeln";
            break;
        case '$': value = "$";
            break;
        default:
            value = "Unknown Value";
    }
    
    return value;
}

string tableError(char state, char tableChar)
{
    string error;
    if(state == 'O' || state == 'B' || state == 'U')
    {
        
        if(tableChar == 'd')
        {
               error = "Invalid variable name";
        }
        else if(isalpha(tableChar))
        {
            error = "Unidentified variable";
        }
        else
        {
            error = "Syntax Error";
        }
    }
    else if(state == 'S')
    {
        if(isdigit(tableChar) || (isalpha(tableChar)))
        {
            error = "Unidentified variable";
        }
        else
        {
            error = "Syntax Error";
        }
    }
    else if(state == 'A')
    {
        error = "\"PROGRAM\" not found";
    }
    else
    {
        error = "Syntax Error";
    }
    return error;
}
#endif
