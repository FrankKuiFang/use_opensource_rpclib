#pragma  once

#include <iostream>
#include <memory>
#include <fstream>
#include <string>
#include <rpc/client.h>

int main(){
    std::cout << "start client......... \n" << std::endl;
    ::rpc::client client("192.168.0.107", 8089);

    auto res = client.call("test", 3, "its me").as<int>();
    std::cout << "res = " << res << std::endl;
}