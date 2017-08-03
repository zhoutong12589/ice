
#ifndef _H_SERVER_
#define _H_SERVER_
#include <iostream>

#include <Ice/Ice.h>
#include <Ice/Application.h>
#include <Ice/PropertiesF.h>
#include <string>

using namespace std;
using namespace Ice;

class CServer : public Ice::Application
{
public:
    CServer();
    ~CServer();
    virtual int run(int argc, char* argv[]);
    
};


#endif //_H_SERVER_







