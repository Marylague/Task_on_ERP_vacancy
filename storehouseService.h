//---------------------------------------------------------------------------

#ifndef storehouseServiceH
#define storehouseServiceH

#include "Database.h"
class StorehouseService {
private:
    Database& db;

public:
    StorehouseService(Database& database);

    void showProducts();
    void showProductsByStorehouse();
    void addProduct();
    void updateProduct();

    void receiveProduct();
    void shipProduct();

    void showHistory();

    void showStorehouses();
    void addStorehouse();
};

#endif
