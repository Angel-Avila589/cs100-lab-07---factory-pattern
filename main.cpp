#include <iostream>
#include "gtest/gtest.h"
#include "base.hpp"
#include "op_test.hpp"
#include "parse.hpp"

int main(int argc, char** argv) 
{
    Base* sol;
    Parse p;
    
    sol = p.parse(argv + 1, argc - 1);
    if(sol == nullptr)
	std::cout << "Invalid Input" << std::endl;
    else
	std::cout << sol->stringify() << " = " << sol->evaluate() << std::endl;
    return 0;
}
