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
#include <sys/types.h>
#include <unistd.h>

class ProcessControlBlock{
    pid_t pid;
    int* pageTable;
public:
    ProcessControlBlock();
    ProcessControlBlock(int, MemoryBlockTable&);
    void print();
};

#endif /* ProcessControlBlock_h */
