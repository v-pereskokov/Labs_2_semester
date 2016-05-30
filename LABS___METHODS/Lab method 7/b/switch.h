#include <map>
#include <string>
/*!
 Использование строк в switch - case
 */

///Набор возможных команд
enum cmd_value {
    add, ///< Команда добавления элемента
    get, ///< Команда получения элемента
    del ///< Команда удаления элемента
};

static std::map<std::string, cmd_value> cmd_map; /*!< Контейнер map для хранения названия команд и их ключа */

/*!
 Инициализация команд и их ключей
 */
static void init_switch()
{
    cmd_map["add"] = add;
    cmd_map["get"] = get;
    cmd_map["del"] = del;
}
