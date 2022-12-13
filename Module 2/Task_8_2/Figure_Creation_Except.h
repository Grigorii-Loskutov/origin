#pragma once

#include <iostream>
#include <string.h>
#include <exception>

class Figure_Creation_Except :public std::exception {
private:
	std::string err;
public:
	Figure_Creation_Except(std::string error) : err(error) {}
	virtual const char* what() const override
	{
		return err.c_str();
	}
};