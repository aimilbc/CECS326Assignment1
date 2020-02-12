//
//  MemoryBlockTable.h
//  cecs326Assignment1
//
//  Created by AIMI ROSS on 2/9/20.
//  Copyright © 2020 AIMI ROSS. All rights reserved.
//

#ifndef MemoryBlockTable_h
#define MemoryBlockTable_h
const int BLOCKSIZE = 512;

class MemoryBlockTable{
    int index;
    bool blocks[BLOCKSIZE];
public:
    MemoryBlockTable();
    int isEmptyBlocks();
    void print();
    int nextEmplyBlockIndex();
    void initiateBlocks(int, int**);
};

#endif /* MemoryBlockTable_h */
