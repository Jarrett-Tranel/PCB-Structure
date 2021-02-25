//this project will represent the pcb as a linked list
using namespace std;
#include <iostream>
#include "PCB.hpp"


void removeParent(PCB* parentarray[], int index)
{
    parentarray[index] = NULL;
}

int main()
{    
    PCB* p0 = new PCB(2); 
    PCB* p1 = new PCB(1);
    PCB* p2 = new PCB(6);
    PCB* p3 = new PCB(9);
    PCB* p4 = new PCB(5);
    PCB* p5 = new PCB(17);

    PCB* parents [3] = {p0, p4, p5};

    cout<<(parents[1]->getID());
    cout<<("\n");

    cout<< (p0->getID());
    cout <<("\n");
    p0->setChild(p1);
    p0->setChild(p2);
    p0->setChild(p3);
    p0->showChildren(p0->getChild());
    cout <<("\n");
    p0->removeChildAtIndex(2);
    p0->showChildren(p0->getChild());
    cout<< ("\n");
    removeParent(parents, 1);
   
}

