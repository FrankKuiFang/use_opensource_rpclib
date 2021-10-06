#pragma  once

#include <iostream>
#include <memory>
#include <fstream>
#include <string>
#include <rpc/server.h>

class MyServer {
public:
    MyServer() :m_called_time(0)
    {};

    ~MyServer() {};

    int Initialize() {
		std::cout << "Enter Initialize......" << std::endl;
        ::rpc::server rpcServer("192.168.0.107", 8089);

        rpcServer.bind("test", [this](double x = 9.0, std::string str = "FF") -> int {
            return this->test(x, str);
        });

        rpcServer.run();
        //rpcServer.AsyncRun(1u);
        return 0;
    }
	
	int test(double x, std::string str) {
		std::cout << "Enter MyServer::test  x = " << x << " str = " << str << std::endl;
		m_called_time ++;
		return m_called_time;
	}
private:
	int m_called_time;
};

int main() {
    MyServer server_obj;
    server_obj.Initialize();
    return 0;
}