#include "PCB.hpp"

#include <iostream>
using namespace std;

PCB::PCB(int id)
{
    this->id = id;
}
       
int PCB::getID()
{
    return(this->id);
}

void PCB::setChild(PCB* targetkid)
{
    if(this->firstChild ==  0)
    {
        this->firstChild = targetkid;
        targetkid->parent = this;
    } else {
        PCB* targetProcess = this->firstChild;
        int setFlag = 0;
        while (setFlag == 0)
        {
            if (targetProcess->youngerSib)
            {
                targetProcess = targetProcess->youngerSib;

            } else {
                targetProcess->youngerSib = targetkid;
                targetkid->olderSib = targetProcess;
                setFlag = 1;
            }
        }
    }
}

PCB* PCB::getChild()
{
    return(this->firstChild);
}

void PCB::showChildren(PCB* childToShow)
{
    
    cout<< (childToShow->id);
    if (childToShow->youngerSib != 0)
    {
        this->showChildren(childToShow->youngerSib);
    }
}

void PCB::removeChildAtIndex(int index)
{
    PCB* targetProcess = this->firstChild;

    if (index == 0)
    {
        this->firstChild = this->firstChild->youngerSib;
        return;
    }

    while(index > 0)
    {
        if(targetProcess == this->firstChild)
        {
            targetProcess = targetProcess-> youngerSib;
            index--;
        } else {
            targetProcess = targetProcess->youngerSib;
            index--;
        }
    }
    if (targetProcess->youngerSib)
    {
        olderSib->youngerSib = targetProcess->youngerSib;
    } else {
        olderSib->youngerSib = 0;
    }
}