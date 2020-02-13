//
//  ProcessControlBlock.cpp
//  cecs326Assignment1
//
//  Created by AIMI ROSS on 2/9/20.
//  Copyright © 2020 AIMI ROSS. All rights reserved.
//
#include "ProcessControlBlock.h"
#include "MemoryBlockTable.h"
//#include <sys/types.h>
//#include <unistd.h>
#include <iomanip>
#include <stdio.h>
#include <iostream>
using namespace std;

ProcessControlBlock::ProcessControlBlock(){         // default constructor
    this->pid = -111111;
//    printf("pid: %lun", pid);     // statement to check if its working
//    cout << endl;
}

ProcessControlBlock::ProcessControlBlock(int pid, int size, MemoryBlockTable &mbt){  // constructor with parameter
//    pid = getpid();
//    printf("pid: %lun", pid);     // statement to check if its working
//    cout << endl;
    
    this->pid = pid;
    this->size = size;
    cout << "\nPID: " << this->pid << endl;
    pageTablePtr = new int[size];  // created a array of pointers size of the generated random number
    mbt.initiateBlocks(size, pageTablePtr); // calling MBT function to initiate values in free element in MBT
    // the function "initiateBlocks" will change the status of each available element to not available, and assign the index number to pageTable pointers
    delete[] pageTablePtr;
}

void ProcessControlBlock::print(){  // printng the PID
    cout << "\nPrint Process Control Block data" << endl;
    printPID();
    printSize();
    printMBTIndex();
    
}

void ProcessControlBlock::printPID(){
    
    cout << "PID: " << this->pid << endl;
    
}

void ProcessControlBlock::printSize(){
    
    cout << "SIZE: " << this->size << endl;
    
}

void ProcessControlBlock::printMBTIndex(){
    
//    for(int i = 0; i < this->size; i++){
//        cout << "Am i doing right?" << pageTablePtr[i] << endl;
//    }
    
    cout << "\t" ;
    for (int i = 0; i < 10; i++){
        cout << left << setw(4) << (i);
    }
    cout << endl << endl;
    for (int i = 1; i <= this->size; i++){
        if((i % 10) == 1){
            cout << (i-1) << "\t";
        }
        cout << left << setw(5) << pageTablePtr[i];
        if((i % 10) == 0){
            cout << endl;
        }
    }
    
}
