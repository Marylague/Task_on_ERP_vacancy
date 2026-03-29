//---------------------------------------------------------------------------

#ifndef DatabaseH
#define DatabaseH

#include <string>
#include "sqlite3.h"

class Database {
private:
    sqlite3* db;

public:
    Database(const std::string& dbPath);
    ~Database();

    bool isConnected();
    void execute(const std::string& query);
    sqlite3_stmt* query(const std::string& query);
};


#endif
