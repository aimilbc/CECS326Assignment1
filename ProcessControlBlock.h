//
//  ProcessControlBlock.h
//  cecs326Assignment1
//
//  Created by AIMI ROSS on 2/9/20.
//  Copyright © 2020 AIMI ROSS. All rights reserved.
//

#ifndef ProcessControlBlock_h
#define ProcessControlBlock_h
#include "MemoryBlockTable.h"
//#include <sys/types.h>
//#include <unistd.h>

class ProcessControlBlock{
    int pid, size;
    int* pageTablePtr;
public:
    ProcessControlBlock();
    ProcessControlBlock(int randPID, int randNumForSize, MemoryBlockTable&);
    void print();
    void printPID();
    void printSize();
    void printMBTIndex();
};

#endif /* ProcessControlBlock_h */
