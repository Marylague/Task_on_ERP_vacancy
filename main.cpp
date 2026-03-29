#include <iostream>
#include <tchar.h>
#include "Database.h"
#include "storeHouseService.h"

int _tmain(int argc, _TCHAR* argv[])
{
    std::cout << " Wellcome to store program! \n";

    Database db("store.db");

    if (!db.isConnected()) {
    	std::cout << "Can not connect to Data Base";
        return 1;
    }

//    db.execute(
//        "CREATE TABLE IF NOT EXISTS storehouses ("
//        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
//        "name TEXT UNIQUE,"
//        "location TEXT);"
//    );
//
//    db.execute(
//        "CREATE TABLE IF NOT EXISTS products ("
//        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
//        "name TEXT,"
//        "quantity INTEGER DEFAULT 0,"
//        "price REAL,"
//        "storehouse_id INTEGER,"
//        "FOREIGN KEY(storehouse_id) REFERENCES storehouses(id));"
//    );
//
//    db.execute(
//        "CREATE TABLE IF NOT EXISTS history ("
//        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
//        "product_id INTEGER,"
//        "operation_type TEXT,"
//        "operation_quantity INTEGER,"
//        "previous_quantity INTEGER,"
//        "new_quantity INTEGER,"
//        "storehouse_id INTEGER,"
//        "created_at DATETIME DEFAULT CURRENT_TIMESTAMP);"
//    );

    StorehouseService service(db);

    int choice;

    while (true) {
        std::cout << "\n--------------------------------------\n";
        std::cout << "Menu (Choose action, type it below)\n";
        std::cout << "1. Show products\n";
        std::cout << "2. Show products by storehouse\n";
        std::cout << "3. Add product\n";
        std::cout << "4. Update product (price)\n";
        std::cout << "5. Receive\n";
        std::cout << "6. Ship\n";
        std::cout << "7. History\n";
        std::cout << "8. Show storehouses\n";
        std::cout << "9. Add storehouse\n";
        std::cout << "0. Exit\n";

        std::cin >> choice;

        switch (choice) {
            case 1: service.showProducts(); break;
            case 2: service.showProductsByStorehouse(); break;
            case 3: service.addProduct(); break;
            case 4: service.updateProduct(); break;
            case 5: service.receiveProduct(); break;
            case 6: service.shipProduct(); break;
            case 7: service.showHistory(); break;
            case 8: service.showStorehouses(); break;
            case 9: service.addStorehouse(); break;
            case 0: return 0;
        }
    }
    return 0;
}
