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
    std::map<std::string, std::map<std::string,std::string>> Sections;  //Section <Section_name, <var_name,var_value>>
    std::map<std::string, std::map<std::string, std::string>>::iterator section_iterator; //итератор для секций
    std::map<std::string, std::string>::iterator var_iterator; //итератор для переменных внутри секции
    std::string section_finder(std::string str_for_find) {
        int b_pos{ 0 }, e_pos{ 0 };
        b_pos = str_for_find.find('[');
        int com_pos = str_for_find.find(';');
        if (b_pos < 0) { return ""; }
        if (com_pos == 0) return "";
        e_pos = str_for_find.find(']');
        if (e_pos < 0) { return ""; }
        return str_for_find.substr(b_pos + 1, e_pos - b_pos - 1);
    }
    std::string var_finder(std::string str_for_find) {
        int com_pos = str_for_find.find(';');
        if (com_pos == 0) return "";
        int equal_pos = str_for_find.find('=');
        if (equal_pos < 0) { return ""; }
        int b_pos{ 0 };
        std::string::iterator IT = str_for_find.begin();
        while ((*IT == ' ') || (*IT == '    ')) {
            IT++; b_pos++;
        }
        //if (com_pos > -1 && com_pos < b_pos) return "";
        int symbol_num{ 1 };
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
        std::string line;
        int line_number{ 0 };
        while (!(fin).eof()) {
            std::getline(fin, line);
            std::cout << line_number << ": ";
            std::string tm_str = "";
            tm_str = section_finder(line);
            if (tm_str != "") { std::cout << tm_str << "\n";  }
            tm_str = var_finder(line);
            if (tm_str != "") { std::cout << tm_str << " "; }
            tm_str = var_value_finder(line);
            if (tm_str != "") { std::cout << tm_str; }
            line_number++;
            std::cout << "\n";
        }
       
    }
};

int main(int argc, char** argv)
{
   
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ini_parcer test_parset("example.ini");
}
