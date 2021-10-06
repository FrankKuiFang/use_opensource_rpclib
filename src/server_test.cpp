#pragma  once

#include <iostream>
#include <memory>
#include <fstream>
#include <string>
#include <rpc/server.h>

#include <self_defined_data.h>

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
        
        rpcServer.bind("test_self_defined_data", [this](my_data d) -> my_data {
            return this->test_self_defined_data(d);
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
    
    my_data test_self_defined_data(my_data d) {
		std::cout << "Enter MyServer::test_self_defined_data,  m_a = " << d.m_a << " m_b = " << d.m_b << " m_c = " << d.m_c << std::endl;
		my_data res;
        res.m_a = 5;
        res.m_b = 6;
        res.m_c = "yes";
		return res;
	}
private:
	int m_called_time;
};

int main() {
    MyServer server_obj;
    server_obj.Initialize();
    return 0;
}