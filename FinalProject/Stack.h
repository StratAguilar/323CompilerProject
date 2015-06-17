//
//  Stack.h
//  FinalProject
//
//  Created by Stratton Aguilar and Mario Andrade on 5/2/14.
//  Copyright (c) 2014 Stratton Aguilar. All rights reserved.
//

#ifndef FinalProject_Stack_h
#define FinalProject_Stack_h

template<class Type, int n>
class stacks
{
private:
    Type elements[n];
    int counter;
    
public:
    void ClearStack()
    {
        counter = 0;
    }
    
    bool EmptyStack()
    {
        return counter == 0?true:false;
    }
    
    bool FullStack()
    {
        return counter == n?true:false;
    }
    
    void push(Type x)
    {
        elements[counter] = x;
        counter++;
    }
    
    Type pop()
    {
        counter--;
        //cout << elements[counter] << "  popped" << endl; // for testing
        return elements[counter];
    }
};



#endif
