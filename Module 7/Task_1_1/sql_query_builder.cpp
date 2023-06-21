#include <vector>
#include <string>
#include <algorithm>

#include "sql_query_builder.h"

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddColumn(const std::string Column) {
	this->Column.emplace(Column);
	return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddFrom(const std::string Table) {
	this->Table = Table;
	return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddWhere(const std::string Where_key, const std::string Where_par) {
	this->Where[Where_key] = Where_par;
	return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddColumns(const std::vector<std::string>& columns) {
	for (auto const& i : columns) {
		this->Column.emplace(i);
	}
	return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddManyWhere(const std::map<std::string, std::string>& kv) {
	for (auto const& i : kv) {
		this->Where[i.first]=i.second;
	}
	return *this;
}

std::string SqlSelectQueryBuilder::BuildQuery() {
	std::string temp_str = "SELECT ";
	int iter = 0;
	for (auto const& i : Column) {
		temp_str += i;
		if (iter >= 0 && iter < (Column.size() - 1)) { temp_str += ", "; }
		++iter;
	}
	temp_str += " FROM ";
	temp_str += Table;
	temp_str += " WHERE ";
	iter = 0;

	for (auto const& i : Where) {
		temp_str += i.first;
		temp_str += " = ";
		temp_str += i.second;
		if (iter >= 0 && iter < (Where.size() - 1)) { temp_str += " AND "; }
		++iter;
	}
	temp_str += ";";
	return temp_str;
}