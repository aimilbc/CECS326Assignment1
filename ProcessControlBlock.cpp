//
//  ProcessControlBlock.cpp
//  cecs326Assignment1
//
//  Created by AIMI ROSS on 2/9/20.
//  Copyright © 2020 AIMI ROSS. All rights reserved.
//
#include "ProcessControlBlock.h"
#include "MemoryBlockTable.h"
#include <stdio.h>
#include <iostream>
using namespace std;

ProcessControlBlock::ProcessControlBlock(){         // default constructor
    pid = -1;
//    printf("pid: %lun", pid);     // statement to check if its working
//    cout << endl;
}

ProcessControlBlock::ProcessControlBlock(int size, MemoryBlockTable &mbt){  // constructor with parameter
    this->pid = fork();
    pid = getpid();
    printf("pid: %lun", pid);     // statement to check if its working
    cout << endl;
    
    pageTable = new int[size];  // created a array of pointers size of the generated random number
    mbt.initiateBlocks(size, &pageTable); // calling MBT function to initiate values in free element in MBT
    // the function "initiateBlocks" will change the status of each available element to not available, and assign the index number to pageTable pointers
}

void ProcessControlBlock::print(){
    cout << pid << endl;
}
