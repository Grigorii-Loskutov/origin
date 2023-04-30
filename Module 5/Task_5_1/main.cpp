#include <iostream>
#include <pqxx/pqxx>
#include <exception>
#include <tuple>
#include <windows.h>

class sq_base_control {
private:
	std::unique_ptr <pqxx::connection> c1;
public:
	//sq_base_control(pqxx::connection connect) {
	//	pqxx::work base { connect };
	//}
	sq_base_control() {}
	void SetConnection(std::unique_ptr<pqxx::connection> in_c) {
		c1 = std::move(in_c);
	}
	sq_base_control(const sq_base_control&) = delete;
	sq_base_control& operator=(const sq_base_control&) = delete;

	void table_create(const std::string str_creation) {
		pqxx::work tx{ *c1 };
		tx.exec(str_creation);
		tx.commit();
	}
	void client_add(const std::string name, const std::string surname, const std::string email) {
		pqxx::work tx{ *c1 };
		//std::string str_client_add = "INSERT INTO clients (name) VALUES ('" + name + "')";
		std::string str_client_add = "INSERT INTO clients (name, surname, email) VALUES ('" + tx.esc(name) + "','" + tx.esc(surname) + "', '" + tx.esc(email) + "')";

		/*str_client_add += "INSERT INTO clients (surname) VALUES ('" + surname + "');";
		str_client_add += "INSERT INTO clients (email) VALUES ('" + email + "');";*/

		tx.exec(str_client_add);
		tx.commit();

	}
	void phone_add(const int client_id, const std::string new_phone) {
		pqxx::work tx{ *c1 };
		std::string str_phone_add = "INSERT INTO phones (client_id, phone) VALUES (" + tx.esc(std::to_string(client_id)) + ", '" + tx.esc(new_phone) + "')";
		tx.exec(str_phone_add);
		tx.commit();
	}
	//для удаления телефона не обязательно нужно знать ID клиента, т.к. телефон уникален
	void 
		phone_delete(const std::string phone_for_del) {
		pqxx::work tx{ *c1 };
		std::string str_phone_delete = "DELETE FROM phones WHERE phone = '" + tx.esc(phone_for_del) + "'";
		tx.exec(str_phone_delete);
		tx.commit();
	}
	void client_update(const int client_id, const std::string new_name, const std::string new_surname, const std::string new_email) {
		pqxx::work tx{ *c1 };
		std::string str_client_update = "UPDATE clients "
			"SET name = '" + tx.esc(new_name)+ "',"
			"surname = '" + tx.esc(new_surname) + "',"
			"email = '" + tx.esc(new_email) + "' " +

			"WHERE id = " + tx.esc(std::to_string(client_id));
		tx.exec(str_client_update);
		tx.commit();

	}
	void client_delete(const int client_id) {
		pqxx::work tx{ *c1 };
		std::string str_phone_delete = "DELETE FROM phones WHERE client_id = " + tx.esc(std::to_string(client_id));
		std::string str_client_delete = "DELETE FROM clients WHERE id = " + tx.esc(std::to_string(client_id));
		tx.exec(str_phone_delete);
		tx.exec(str_client_delete);
		tx.commit();
	}
	//в ощем случае данный метод может вернуть несколько ID. Желательно, чтобы тип возвращаемого значения был список, кортеж. Как это изящно сделать?
	int get_clients_id(std::string find_name = "%", std::string find_surname = "%", std::string find_email = "%", std::string find_phone="%") {
		pqxx::work tx{ *c1 };
		std::string str_request_id = "SELECT clients.id from "
			"clients left join phones on client_id = clients.id "
			"WHERE "
			"name LIKE '" + tx.esc(find_name) +"' AND "
			"surname LIKE '" + tx.esc(find_surname) +"' AND "
			"email LIKE '" + tx.esc(find_email) + "' "
			//"phone LIKE '" + tx.esc(find_phone) + "' " //криво работает, если телефон ещё не ввели
			"LIMIT 1";
		return tx.query_value<int>(str_request_id);
	}

};

int main()
{
	//setlocale(LC_ALL, "Russian");
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	try
	{
		const std::string str_connection = { 
			"host=localhost "
			"port=5432 "
			"dbname=clients "
			"user=postgres "
			"password=cfhvf810"
		};
		const std::string str_creation = {
			"CREATE TABLE IF NOT EXISTS clients ("
			"id SERIAL PRIMARY KEY, "
			"name VARCHAR(40) NOT NULL, "
			"surname VARCHAR(40) NOT NULL, "
			"email VARCHAR(40) NOT NULL); "
			"CREATE TABLE IF NOT EXISTS phones ("
			"id SERIAL PRIMARY KEY, "
			"phone VARCHAR(12) NOT NULL, "
			"client_id INTEGER NOT NULL REFERENCES clients(id)); "
			
		};
		std::unique_ptr<pqxx::connection> c = std::make_unique<pqxx::connection>(str_connection);

		sq_base_control clients_base;

		clients_base.SetConnection(std::move(c));

		//Демонстрация работы
		//---------------------------------------

		//создадим таблицы
		clients_base.table_create(str_creation); 

		//Добавим клиентов
		clients_base.client_add("Jora", "Ivanov", "jora_i@yandex.ru");
		clients_base.client_add("Peter", "Sydorov", "peter_s@yandex.ru");
		clients_base.client_add("Vasil", "Egorov", "vasil_e@yandex.ru");
		clients_base.client_add("Gregory", "Loskutov", "greg_l@yandex.ru");

		//Узнаем ID клинетов идобавим им телефоны
		int client_id = 0;
		client_id = clients_base.get_clients_id("Jora", "%", "%", "%");
		clients_base.phone_add(client_id, "+79996990001");
		clients_base.phone_add(client_id, "+79996990011");

		client_id = clients_base.get_clients_id("%", "Sydorov", "%", "%");
		clients_base.phone_add(client_id, "+79996990002");
		clients_base.phone_add(client_id, "+79996990012");

		client_id = clients_base.get_clients_id("%", "%", "vasil_e@yandex.ru", "%");
		clients_base.phone_add(client_id, "+79996990003");
		
		client_id = clients_base.get_clients_id("%", "Loskutov", "greg_l@yandex.ru", "%");
		clients_base.phone_add(client_id, "+79996990004");

		//удалим телефон из базы
		clients_base.phone_delete("+79996990011");


		//удалим клиента из базы, узнав его ID
		client_id = clients_base.get_clients_id("%", "Loskutov", "%", "%");
		clients_base.client_delete(client_id);

		//заапдейтим Жору
		client_id = clients_base.get_clients_id("Jora", "%", "%", "%");
		clients_base.client_update(client_id, "Jora", "Peterson", "peterson@yandex.ru");

		//получим ID Жоры
		std::cout << clients_base.get_clients_id("Jora", "%", "%", "%");
	}
	catch (pqxx::sql_error e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
