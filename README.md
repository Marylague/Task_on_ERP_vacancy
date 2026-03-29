# Task_on_ERP_vacancy

### Описание проекта

Консольная утилита для управления домашним складом с поддержкой учета остатков, операций приемки/отгрузки и ведением истории изменений.

Проект реализован на C++ (RAD Studio C++ Builder) с использованием базы данных SQLite.


### Реализованный функционал
#### 1 Работа с товарами
- Просмотр списка товаров
- Просмотр товаров по складу
- Добавление товара
- Изменение цены товара

#### 2 Операции со складом
- Приемка товара (увеличение количества)
- Отгрузка товара (уменьшение количества)
- Проверка на достаточность остатков


#### 3 Работа со складами
- Просмотр списка складов
- Добавление склада
- Привязка товара к складу

#### 4 История изменений (прослеживаемость)
- Запись всех операций:
- тип операции (receipt / shipment)
- количество
- остаток до и после
- склад
- дата операции
- Просмотр полной истории изменений

#### 5 Проверки и ограничения

Реализованы базовые проверки корректности ввода:

- Запрет отрицательного количества
- Запрет отрицательной цены
- Запрет отгрузки при недостаточном количестве
- Проверка существования товара
- Проверка корректности ID склада

При ошибках пользователю выводится причина отказа.


### Были созданы следующие таблицы:

``` cpp
    db.execute(
        "CREATE TABLE IF NOT EXISTS storehouses ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "name TEXT UNIQUE,"
        "location TEXT);"
    );

    db.execute(
        "CREATE TABLE IF NOT EXISTS products ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "name TEXT,"
        "quantity INTEGER DEFAULT 0,"
        "price REAL,"
        "storehouse_id INTEGER,"
        "FOREIGN KEY(storehouse_id) REFERENCES storehouses(id));"
    );

    db.execute(
        "CREATE TABLE IF NOT EXISTS history ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "product_id INTEGER,"
        "operation_type TEXT,"
        "operation_quantity INTEGER,"
        "previous_quantity INTEGER,"
        "new_quantity INTEGER,"
        "storehouse_id INTEGER,"
        "created_at DATETIME DEFAULT CURRENT_TIMESTAMP);"
    );

```
### Архитектура проекта

Проект разделен на основные компоненты:

- Database — работа с SQLite (выполнение SQL-запросов)
- StorehouseService — бизнес-логика
- main.cpp — пользовательский интерфейс (консольное меню)

### Особенности реализации
- Используется чистый SQL (без ORM)
- Все данные хранятся в базе данных
- Реализована простая система прослеживаемости товаров
- Поддерживается работа с несколькими складами

