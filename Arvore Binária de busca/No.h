#ifndef NO_H_INCLUDED
#define NO_H_INCLUDED
#include "NoArv.h"

class No
{
private:
    NoArv* info;
    No* prox;
public:
    No()                    {};
    ~No()                   {};
    void setInfo(NoArv* val)   { info = val; };
    void setProx(No* p)     { prox = p; };
    NoArv* getInfo()           { return info; };
    No * getProx()          { return prox; };
};

#endif // NO_H_INCLUDED
