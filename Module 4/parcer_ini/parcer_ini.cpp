// parcer_ini.cpp : Курсовой проект «Парсер INI-файлов»
// https://github.com/netology-code/cppl-diplom

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <exception>
#include <windows.h>

class ini_parcer {
private:
    //Пусть имя секции, имя переменной и значение переменной будут строкой
    std::map<std::string, std::string> Sections;  //Section <Section_name, <var_name,var_value>>
    //std::map<std::string, std::string> var_pair;
        std::string section_finder(std::string str_for_find) {
        int b_pos{ 0 }, e_pos{ 0 };
        b_pos = str_for_find.find('[');
        int com_pos = str_for_find.find(';');
        if (b_pos < 0) { return ""; }
        if (com_pos == 0) return "";
        e_pos = str_for_find.find(']');
        if (e_pos < 0) { return""; }
        return str_for_find.substr(b_pos + 1, e_pos - b_pos - 1);
    }
    std::string var_finder(std::string str_for_find) {
        int com_pos = str_for_find.find(';');
        if (com_pos == 0) return "";
        int equal_pos = str_for_find.find('=');
        if (equal_pos < 0) { return""; }
        int b_pos{ 0 };
        std::string::iterator IT = str_for_find.begin();
        while ((*IT == ' ') || (*IT == '    ')) {
            IT++; b_pos++;
        }
        //if (com_pos > -1 && com_pos < b_pos) return "";
        int symbol_num{ 0 };
        while ((*IT != ' ') && (*IT != '    ') && (*IT != '=')) {
            IT++;
            symbol_num++;
            if (*IT == ';') return "";
        }
        return str_for_find.substr(b_pos, symbol_num); //лучше получать индекс символа через итератор, но я не знаю как
    }
    std::string var_value_finder(std::string str_for_find) {
        int com_pos = str_for_find.find(';');
        if (com_pos == 0) return "";
        int equal_pos = str_for_find.find('=');
        if (equal_pos < 0) { return ""; }
        if (equal_pos == str_for_find.length() - 1) { return ""; }
        int b_pos = equal_pos + 1;
        std::string::iterator IT = str_for_find.begin() + b_pos;
        while ((*IT == ' ') || (*IT == '    ')) { IT++; b_pos++; }
        int symbol_num{ 1 };

        while ((*IT != ' ') && (*IT != '    ') && (*IT != ';') && (IT < str_for_find.end() - 1)) {
            IT++;
            symbol_num++;
        }
         return str_for_find.substr(b_pos, symbol_num);
    }
public:
    ini_parcer(std::string file_path) {
        std::ifstream fin(file_path);
        if (!fin.is_open()) { throw std::invalid_argument("file is not exists"); }
        std::string line;
        std::string section = "";
        std::string var = "";
        std::string var_value = "";
        int line_number{ 0 };
        while (!(fin).eof()) {
            std::getline(fin, line);
            //std::cout << line_number << ": ";
            std::string tmp_str = "";
            tmp_str = section_finder(line);
            if (tmp_str != "") { 
                section = tmp_str;
                //std::cout << section << "\n";
            }
            tmp_str = var_finder(line);
            if (tmp_str != "") { 
                var = tmp_str; 
                //std::cout << var << " ";
            }
            tmp_str = var_value_finder(line);
            if ((tmp_str != "") && (var != "") && (section != "")) {
                var_value = tmp_str; 
                //std::cout << var_value; 
                Sections[section + "." + var] = var_value;
            }
            //std::map<std::string, std::string>(var, var_value);
            //std::cout << "\n";
            line_number++;
        }
        if (section == "") { throw std::domain_error("no sections in file: " + file_path); }
        if (var == "" || var_value == "") { throw std::domain_error("no variables defined in file: " + file_path); }
        fin.close();
    }
    template<typename T>
    T get_value(const std::string section_var) {
        static_assert(get_value(), "not implemented conversion");
    }
    template<>
    int get_value(const std::string section_var) {
        /*int dot_pos = section_var.find('.');
        std::string section_out = section_var.substr(0, dot_pos);
        std::string var_out = section_var.substr(dot_pos + 1, section_var.length() - 1 - dot_pos);*/
        auto answer = Sections[section_var];
        if (answer == "") { throw std::invalid_argument("no such pair section + var:" + section_var); }
        return std::stoi(Sections[section_var]);
        //std::pair<std::string, std::string> n{ Sections[section_out]};
        //return Sections[var_pair[section_out]];
    }
    template<>
    double get_value(const std::string section_var) {
        auto answer = Sections[section_var];
        if (answer=="") { throw std::invalid_argument("no such pair section + var:" + section_var); }
        return std::stod(answer);
    }
    template<>
    std::string get_value(const std::string section_var) { 
        auto answer = Sections[section_var];
        if (answer == "") { throw std::invalid_argument("no such pair section+var: " + section_var); }
        return Sections[section_var];
    }
};

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    try {
        ini_parcer test_parser("example.ini");
        std::cout << test_parser.get_value<int>("Section1.var1") << "\n";
        std::cout << test_parser.get_value<std::string>("Section1.var2") << "\n";
        std::cout << test_parser.get_value<double>("Section1.var20") << "\n";
        std::cout << test_parser.get_value<double>("Section1.var2") << "\n";
    }
    catch (const std::exception& ex) {
        std::string except = ex.what();
        std::cout << "\n" << except;
        //std::cout << ex.what() << std::endl;
    }
}
