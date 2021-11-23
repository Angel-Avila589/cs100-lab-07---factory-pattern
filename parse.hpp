#ifndef __PARSE_HPP__
#define __PARSE_HPP__

#include "base.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "pow.hpp"
#include <exception>

class Parse
{
public:
	Base* parse(char** input, int length)
	{
		Base* out = nullptr;
		double val = 0;
		
		if ((length < 1) || ((length % 2) == 0)) //if few arguments are entered
		{
			return nullptr;
		}

		//1st operand is a special case that needs to be done outside the for loop
		try
		{
			out = new Op(std::stod(input[0]));
		}
		catch(std::exception e)
		{
			return nullptr;
		}
		//Loop through list
		for(int i = 1; i < length; i += 2)
		{
			try
			{
				val = std::stod(input[i + 1]);
			}
			catch(std::exception e)
			{
				return nullptr;
			}

			if(std::string(input[i]) == "+")
			{
				out = new Add(out, new Op(val));
			}
			else if(std::string(input[i]) == "-")
			{
				out = new Sub(out, new Op(val));
			}
			else if(std::string(input[i]) == "*")
			{
				out = new Mult(out, new Op(val));
			}
			else if(std::string(input[i]) == "/")
			{
				out = new Div(out, new Op(val));
			}
			else if(std::string(input[i]) == "**")
			{
				out = new Pow(out, new Op(val));
			}
			else
				return nullptr;
		}
		return out;
	}
};
#endif //__PARSE_HPP__ 
