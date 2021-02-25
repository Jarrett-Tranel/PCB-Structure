class PCB
{
    private:
        PCB* parent;
        PCB* child;
        int id = 0;
        PCB* nextPCB;
        PCB* head;

    public:
        PCB(int id);        
        PCB* getNextPCB();
        void setNextPCB(PCB* setPCB);
        int getID();
        void setChild(PCB* targetkid);
        PCB* getChild();
        void showChildren(PCB* childToShow);
        void removeChildAtIndex(int index);
     
};