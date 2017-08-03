
#ifndef _H_INFOSI_
#define _H_INFOSI_

#include <iostream>
#include "Infos.h"

using namespace std;

class CInfosI : public Info::Infos
{
public:
    virtual float getCpuRate(const Ice::Current &);
    
};





#endif //_H_INFOSI_



