
#include "Server.h"
#include "InfosI.h"

int main(int argc, char* argv[])
{
    cout <<"开启进程！"<<endl;
    
    CServer app;
    return  app.main(argc, argv);
    
}


CServer::CServer()
{
}

CServer::~CServer()
{
}

int CServer::run(int argc, char* argv[])
{
    cout<<"进入run函数！"<<endl;
    PropertiesPtr properties = NULL;
    properties = communicator()->getProperties();
    string s = properties->getProperty("servername");
    cout <<s<<endl; 
    
    
    
    Ice::ObjectAdapterPtr adapter = NULL;
    adapter = communicator()->createObjectAdapter("server");
    if ( false == adapter )
    {
        cout<<"创建通信适配器时，发生了错误！"<<endl;
        return -1;
    }
    
    // 握手处理接口的智能指针
    Ice::ObjectPtr pDR = NULL;          
    pDR = new CInfosI();
    if ( false == pDR )
    {
        cout<<"创建握手处理接口时，发生了错误！"<<endl;
        return -1;
    }
    adapter->add(pDR,communicator()->stringToIdentity("server"));
    shutdownOnInterrupt();
    
    try
    {
       adapter->activate();
       cout<<"数据接收服务器准备就绪!"<<endl;
       communicator()->waitForShutdown();
    }
    catch(const Ice::ObjectAdapterDeactivatedException& ex)
    {
        cout << "适配器激活失败：" << endl;
    }
    catch ( exception* e) 
    {
        cout<<"数据接收主进程运行时，发生了错误："<<endl;
    }
    catch ( ... ) 
    {
        cout<<"数据接收主进程运行时，发生了错误。"<<endl;
    }
    return 0;
}