
#ifndef BASICCMD_H
#define BASICCMD_H

class BasicCmd{
public:
    virtual void execute() = 0;
};

class Double : public BasicCmd{
public:
    void execute(int* points);
};

class Half : public BasicCmd{
public:
    void execute(int* points);
};

class Next : public BasicCmd{
public:
    void execute();
};

#endif