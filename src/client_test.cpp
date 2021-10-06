#pragma  once

#include <iostream>
#include <memory>
#include <fstream>
#include <string>
#include <rpc/client.h>

#include <self_defined_data.h>


int main(){
    std::cout << "start client......... \n" << std::endl;
    ::rpc::client client("192.168.0.107", 8089);

    auto res = client.call("test", 3, "its me").as<int>();
    std::cout << "res = " << res << std::endl;
    
    
    my_data param;
    param.m_a = 55;
    param.m_b = 66;
    param.m_c = "yes_no";
    auto res_data = client.call("test_self_defined_data", param).as<my_data>();
    std::cout << "res_data:  m_a = " << res_data.m_a << " m_b = " << res_data.m_b << " m_c = " << res_data.m_c << std::endl;
}