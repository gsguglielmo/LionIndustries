#ifndef Machine_h
#define Machine_h

class Machine{
    public: 
    virtual void setPump(int pos,bool status);
    virtual void setPipe(int pos,bool status);
    virtual void moveOn(int pos);
    virtual bool getPump(int pos);
    virtual bool getPipe(int pos);
    virtual int getPosition();
};

#endif