class PCB
{
    private:
        PCB* parent;
        int id = 0;
        PCB* olderSib;
        PCB* youngerSib;
        PCB* firstChild;

    public:
        PCB(int id);        
        int getID();
        void setChild(PCB* targetkid);
        PCB* getChild();
        void showChildren(PCB* childToShow);
        void removeChildAtIndex(int index);
     
};