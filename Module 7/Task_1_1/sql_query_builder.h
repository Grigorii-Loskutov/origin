#pragma once
#include <string>
#include <vector>
#include <set>
#include <map>

class SqlSelectQueryBuilder {
	std::string Table = "*";
	std::set<std::string> Column;
	std::map<std::string,std::string> Where;

public:
	SqlSelectQueryBuilder() = default;
	~SqlSelectQueryBuilder() = default;
	SqlSelectQueryBuilder& AddColumn(const std::string Column);
	SqlSelectQueryBuilder& AddFrom(const std::string Table);
	SqlSelectQueryBuilder& AddWhere(const std::string Where_key, const std::string Where_par);
	
	//SqlSelectQueryBuilder& AddWhere(const std::map<std::string, std::string>& kv) noexcept;
	//SqlSelectQueryBuilder& AddColumns(const std::vector<std::string>& columns) noexcept;

	std::string BuildQuery();
};