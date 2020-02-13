//
//  main.cpp
//  cecs326Assignment1
//
//  Created by AIMI ROSS on 2/7/20.
//  Copyright © 2020 AIMI ROSS. All rights reserved.
//
#include "MemoryBlockTable.h"
#include "ProcessControlBlock.h"
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <iostream>

using namespace std;

struct Node{
    ProcessControlBlock data;
    Node *link;
    Node(ProcessControlBlock *pcb){
        data = *pcb;
        link = NULL;
    }
};

class Queue{
    Node *front, *rear;

public:
    
    Queue()
    {
        front =rear = NULL;
    }
    
    void enque(ProcessControlBlock *pcb){
        Node *temp = new Node(pcb);
        if(rear == NULL){
            front = rear = temp;
            return;
        }
        rear->link = temp;
        rear = temp;
    }
    
    void dequeue(){
        if(front == NULL){
            cout << "It's empty..." << endl;
        }
        
        Node *temp = front;
        front = front->link;
        if(front == NULL){
            rear = NULL;
        }
        
        delete temp;
//
//        Node *ptr;
//        if(front == NULL)
//            cout << "It's empty..." << endl;
//        else if (front == rear){
//            delete front;
//            front = rear = NULL;
//        }else{
//            ptr = front;
//            front = front->link;
//            delete ptr;
//        }
    }
    
    void print(){
        Node *temp;
        temp = front;
        if(front == NULL)
            cout << "There is no ready queue." << endl;
        while(temp != NULL){
            temp->data.print();
            temp = temp->link;
        }
    }
};

int mainMenu(){
    int pickedAction;
    cout << "\n========================= Main Menu ========================================" << endl;
    cout << "\t\t\t\t1) Initiate process" << endl;
    cout << "\t\t\t\t2) Print" << endl;
    cout << "\t\t\t\t3) Terminate" << endl;
    cout << "\t\t\t\t4) Exit" << endl;
    cout << "\t\t\t\tEnter an integer between 1-4: ";
    cin >> pickedAction;
    
    return pickedAction;
}

int main(int argc, const char * argv[]) {
    int randNum;
    int randPID = 1000;
    int menuAction = mainMenu();
    Queue readyQ;
    MemoryBlockTable mbt;
    //MemoryBlockTable *mbt = new MemoryBlockTable();
    
    while (menuAction<1 || menuAction>4)
        menuAction = mainMenu();
    while (menuAction>0 && menuAction<4){
        if(menuAction == 1){
            cout << "\n-----------------------------1) Initiate process-----------------------------" << endl;    // initiate process
            srand (time(NULL));
            randNum = rand() % 120 + 25;
            if(randNum>mbt.isEmptyBlocks()){
                cout << "\t\t\t\tRequested block number is " << randNum << endl;
                cout << "\t\t\t\tAvailable block number is " << mbt.isEmptyBlocks() << endl;
                cout << "\t\t\t\tNot enoug space, please try again. This system is returning to the menu." << endl;
                menuAction = mainMenu();
            }
            else{
                
                cout << "\t\t\t\tRequested block number is " << randNum << endl;
                cout << "\t\t\t\tAvailable block number is " << mbt.isEmptyBlocks() << endl;
                cout << "\t\t\t\tI'll proceed your request..." << endl;
                randPID++;
                ProcessControlBlock *pcb = new ProcessControlBlock(randPID, randNum, mbt);
                cout << "\t\t\t\tThe next available index number is " << mbt.nextEmplyBlockIndex();
                readyQ.enque(pcb);
                delete pcb;
            }
        }else if (menuAction==2){
            cout << "\n-----------------------------------2) Print----------------------------------" << endl; // print
            cout << "Memory Block Table" << endl;
            mbt.print();
            readyQ.print();
        }else if (menuAction==3){
            cout << "\n---------------------------------3) Terminate--------------------------------" << endl; // terminate with a specific PID
            // terminate
        }
        menuAction = mainMenu();
    }
    return 0;
};

