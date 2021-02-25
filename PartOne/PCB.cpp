#include "PCB.hpp"

#include <iostream>
using namespace std;

PCB::PCB(int id)
{
    this->id = id;
}
       
PCB* PCB::getNextPCB()
{
    return(this->nextPCB);
}

void PCB::setNextPCB(PCB* setPCB)
{
    this->nextPCB = setPCB;
}

int PCB::getID()
{
    return(this->id);
}

void PCB::setChild(PCB* targetkid)
{
    if(this->child ==  0)
    {
        this->child = targetkid;
        this->head = targetkid;
    } else {
        PCB* targetProcess = this->child;
        int setFlag = 0;
        while (setFlag == 0)
        {
            if (targetProcess->nextPCB)
            {
                targetProcess = targetProcess->nextPCB;

            } else {
                targetProcess->setNextPCB(targetkid);
                setFlag = 1;
            }
        }
    }
}

PCB* PCB::getChild()
{
    return(this->child);
}

void PCB::showChildren(PCB* childToShow)
{
    
    cout<< (childToShow->id);
    if (childToShow->nextPCB != 0)
    {
        this->showChildren(childToShow->getNextPCB());
    }
}

void PCB::removeChildAtIndex(int index)
{
    PCB* targetProcess = this->child;
    PCB* prevProcess;
    if (index == 0)
    {
        this->child = this->child->getNextPCB();
        this->head = this->head->getNextPCB();
        return;
    }
    while(index > 0)
    {
        if(targetProcess == this->head)
        {
            prevProcess = targetProcess;
            targetProcess = targetProcess->getNextPCB();
            index--;
        } else {
            prevProcess = prevProcess->getNextPCB();
            targetProcess = targetProcess->getNextPCB();
            index--;
        }
    }
    if (targetProcess->getNextPCB())
    {
        prevProcess->setNextPCB(targetProcess->getNextPCB());
    } else {
        prevProcess->setNextPCB(0);
    }
}