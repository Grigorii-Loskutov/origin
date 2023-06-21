// Task_1_1.cpp : Научиться использовать шаблон Builder для построения простых SQL-запросов.
//https://github.com/netology-code/dpcpp-homeworks/blob/main/01/readme.md

#include <iostream>
#include <vector>
#include <windows.h>

#include "sql_query_builder.h"

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russia");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	SqlSelectQueryBuilder query_builder;
	query_builder.AddColumn("name").AddColumn("phone");
	query_builder.AddFrom("students");
	query_builder.AddWhere("id", "42").AddWhere("name", "John");
	std::cout << query_builder.BuildQuery();
	return 0;
}