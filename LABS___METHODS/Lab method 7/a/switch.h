#include <map>
#include <string>
/*!
������������� ����� � switch - case
*/

///����� ��������� ������
static const enum cmd_value {
	add, ///< ������� ���������� ��������
	get, ///< ������� ��������� ��������
	del ///< ������� �������� ��������
};

static std::map<std::string, cmd_value> cmd_map; /*!< ��������� map ��� �������� �������� ������ � �� ����� */

												 /*!
												 ������������� ������ � �� ������
												 */
static void init_switch()
{
	cmd_map["add"] = add;
	cmd_map["get"] = get;
	cmd_map["del"] = del;
}