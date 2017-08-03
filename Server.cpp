
#include "Server.h"
#include "InfosI.h"

int main(int argc, char* argv[])
{
    cout <<"�������̣�"<<endl;
    
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
    cout<<"����run������"<<endl;
    PropertiesPtr properties = NULL;
    properties = communicator()->getProperties();
    string s = properties->getProperty("servername");
    cout <<s<<endl; 
    
    
    
    Ice::ObjectAdapterPtr adapter = NULL;
    adapter = communicator()->createObjectAdapter("server");
    if ( false == adapter )
    {
        cout<<"����ͨ��������ʱ�������˴���"<<endl;
        return -1;
    }
    
    // ���ִ���ӿڵ�����ָ��
    Ice::ObjectPtr pDR = NULL;          
    pDR = new CInfosI();
    if ( false == pDR )
    {
        cout<<"�������ִ���ӿ�ʱ�������˴���"<<endl;
        return -1;
    }
    adapter->add(pDR,communicator()->stringToIdentity("server"));
    shutdownOnInterrupt();
    
    try
    {
       adapter->activate();
       cout<<"���ݽ��շ�����׼������!"<<endl;
       communicator()->waitForShutdown();
    }
    catch(const Ice::ObjectAdapterDeactivatedException& ex)
    {
        cout << "����������ʧ�ܣ�" << endl;
    }
    catch ( exception* e) 
    {
        cout<<"���ݽ�������������ʱ�������˴���"<<endl;
    }
    catch ( ... ) 
    {
        cout<<"���ݽ�������������ʱ�������˴���"<<endl;
    }
    return 0;
}