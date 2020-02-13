//
//  MemoryBlockTable.cpp
//  cecs326Assignment1
//
//  Created by AIMI ROSS on 2/9/20.
//  Copyright © 2020 AIMI ROSS. All rights reserved.
//
#include "MemoryBlockTable.h"
#include <stdio.h>
#include <iostream>
#include <iomanip>
using namespace std;

MemoryBlockTable::MemoryBlockTable(){
    index = -1;
    fill_n(blocks, BLOCKSIZE+1, 1);
    for(int i = 0; i <= 32; i++){
        blocks[i] = false;
    }
    print();
}

void MemoryBlockTable::print(){
    
    cout << "\t" ;
    for (int i = 0; i < 10; i++){
        cout << left << setw(5) << (i);
    }
    cout << endl << endl;
    for (int i = 1; i <= BLOCKSIZE; i++){
        if((i % 10) == 1){
            cout << (i-1) << "\t";
        }
        cout << left << setw(5) << blocks[i];
        if((i % 10) == 0){
            cout << endl;
        }
    }
}

int MemoryBlockTable::isEmptyBlocks(){
    int counter=0;
    for(int i = 32; i < BLOCKSIZE; i++){
        counter += blocks[i];
    }
    return counter;
}

int MemoryBlockTable::nextEmplyBlockIndex(){
    int i = 0;
    while(blocks[i] == 0){
        i++;
    }
    return i-1;
}

void MemoryBlockTable::initiateBlocks(int size, int *&pt){
    index = nextEmplyBlockIndex();          // initializing the first empty element's index number to int index in MBT
    int until = nextEmplyBlockIndex() + size; // storing the end index number
    for (int i = index; i < until; i++){
        blocks[i] = false;                  // change the status of each box
        pt[i-index] = i;                            // initiate a pointer from PCB to int index in MBT
    }
//    cout << "okay, let's see the pagetable..." << endl;  // statement to check if the function is working properly
//    for (int i = index; i < until; i++){
//        cout << *pt[i] << endl;;
//    }
}
