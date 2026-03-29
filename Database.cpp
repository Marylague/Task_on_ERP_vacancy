//---------------------------------------------------------------------------

#pragma hdrstop
#include "Database.h"
#include <iostream>

Database::Database(const std::string& dbPath) {
    if (sqlite3_open(dbPath.c_str(), &db) != SQLITE_OK) {
        std::cout << "Cannot open database: " << sqlite3_errmsg(db) << std::endl;
    }
}

Database::~Database() {
    sqlite3_close(db);
}

bool Database::isConnected() {
    return db != nullptr;
}

void Database::execute(const std::string& query) {
    char* errMsg = 0;

    if (sqlite3_exec(db, query.c_str(), 0, 0, &errMsg) != SQLITE_OK) {
        std::cout << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
}

sqlite3_stmt* Database::query(const std::string& query) {
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, 0) != SQLITE_OK) {
        std::cout << "Prepare failed: " << sqlite3_errmsg(db) << std::endl;
        return nullptr;
    }

    return stmt;
}

#pragma package(smart_init)

