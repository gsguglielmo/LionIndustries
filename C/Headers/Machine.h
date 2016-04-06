#ifndef Machine_h
#define Machine_h

class Machine{
    public: 
    virtual void setPump(int pos,bool status)=0;
    virtual void setPipe(int pos,bool status)=0;
    virtual void moveOn(int pos)=0;
    virtual bool getPump(int pos)=0;
    virtual bool getPipe(int pos)=0;
    virtual int getPosition()=0;
};

#endif