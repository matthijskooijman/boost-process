// Copyright (c) 2016 Klemens D. Morgenstern
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/core/lightweight_test.hpp>
#include <iostream>
#include <windows.h>


#include <boost/process/pipe.hpp>

using namespace std;
namespace bp = boost::process;

int main(int , char* [])
{
    bp::pipe pipe;

    std::string in  = "test";


    pipe.write(in.c_str(), in.size());


    std::string out;
    out.resize(4);

    pipe.read(&out.front(), out.size());

    BOOST_TEST(out == in);

    return boost::report_errors();
}




