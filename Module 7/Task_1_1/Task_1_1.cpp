// Task_1_1.cpp : Научиться использовать шаблон Builder для построения простых SQL-запросов.
//https://github.com/netology-code/dpcpp-homeworks/blob/main/01/readme.md

#include <iostream>
#include <vector>
#include <windows.h>
#include <map>


#include "sql_query_builder.h"

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russia");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//методы задачи 1
	SqlSelectQueryBuilder query_builder;
	query_builder.AddColumn("name").AddColumn("phone");
	query_builder.AddFrom("students");
	query_builder.AddWhere("id", "42").AddWhere("name", "John");
	std::cout << query_builder.BuildQuery() << std::endl;
	
	//методы задачи 2
	SqlSelectQueryBuilder query_builder_new;
	query_builder_new.AddFrom("students");
	std::vector<std::string> columns_vec { "student1", "student2" };
	query_builder_new.AddColumns(columns_vec);
	std::map<std::string, std::string> KV;
	KV["id"] = "43";
	KV["name"] = "John";
	query_builder_new.AddManyWhere(KV);
	std::cout << query_builder_new.BuildQuery();
	return 0;
}