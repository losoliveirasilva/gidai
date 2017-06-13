#ifndef DATABASE_H
#define DATABASE_H

#include <mysql.h>
#include <my_global.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <cstdlib>

namespace agenda {

class Database {

public:
    Database(){
		con = mysql_init(NULL);
		
		if(mysql_real_connect(con, "localhost", "root", "", "gidai", 0, NULL, 0) == NULL)
		{
			printf("%s\n", mysql_error(con));
			mysql_close(con);
			return;
		}
	}

	void addAgenda(std::string name, int color){
		std::stringstream query;
		query << "INSERT INTO AGENDAS (NAME, COLOR) VALUES ( '" << name << "', " << color << ");";
		std::string str = query.str();
		auto ret = mysql_query(con, str.c_str());
		mysql_commit(con);
	}

	void addEntry(std::string date, std::string description, std::string agendaName){
		std::stringstream query;
		query << "INSERT INTO ENTRIES (`DATE`, DESCRIPTION, AGENDA_ID) VALUES ('" << date << "', '" << description << "', '" << agendaID(agendaName) << "');";
		std::string str = query.str();
		auto ret = mysql_query(con, str.c_str());
		mysql_commit(con);
	}

	void select(){
		MYSQL_RES *res_set;
		MYSQL_ROW row;
		mysql_query(con, "SHOW TABLES;");
		unsigned int i=0;

		res_set=mysql_store_result(con);

		unsigned int numrows = mysql_num_rows(res_set);

		while (((row=mysql_fetch_row(res_set)) !=NULL))
		{
			std::cout << row[i] << std::endl;
		}
	}

	void showTables(){
		MYSQL_RES *res;
		MYSQL_ROW row;
		res = mysql_perform_query(con, "show tables");
		printf("MySQL Tables in mysql database:\n");
		while ((row = mysql_fetch_row(res)) !=NULL)
			printf("%s\n", row[0]);
	}

private:
	MYSQL *con;

	MYSQL_RES* mysql_perform_query(MYSQL *connection, char *sql_query)
	{
	   // send the query to the database
	   if (mysql_query(connection, sql_query))
	   {
		  printf("MySQL query error : %s\n", mysql_error(connection));
	   }

	   return mysql_use_result(connection);
	}

	unsigned int agendaID(std::string name){
		MYSQL_RES *res_set;
		MYSQL_ROW row;
		unsigned int i=0;
		std::stringstream query;
		query << "SELECT ID FROM AGENDAS WHERE NAME='" << name << "';";
		std::string str = query.str();
		mysql_query(con, str.c_str());
		res_set=mysql_store_result(con);

		unsigned int numrows = mysql_num_rows(res_set);

		while (((row=mysql_fetch_row(res_set)) !=NULL))
		{
			//std::cout << row[i] << " i=" << i << std::endl;
			return atoi(row[i]);
		}
		return 0;
	}

};

}  /* namespace agenda */

#endif

