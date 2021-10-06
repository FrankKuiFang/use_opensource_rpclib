#pragma  once

#include <string>
#include <rpc/msgpack.hpp>

// http://rpclib.net/primer/#using-custom-types-as-parameters
struct my_data{
    int m_a = 3;
    double m_b = 3.5;
    std::string m_c = "love";
    MSGPACK_DEFINE_ARRAY(m_a, m_b, m_c)
};
