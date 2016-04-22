#include "WindowsPosition.h"
namespace ZonesWindowMenu
{
struct MainFile{};
struct MainExit{static void Do(HWND h){DestroyWindow(h);}};

struct MainOptionUnits{};
struct OptionsCoordinates: StoredWindowPosition<ZonesWindow>{};

template<>struct TopMenu<MainFile>
{
	typedef TL::MkTlst<
		MenuItem<MainExit>
	>::Result list;
};

template<>struct TopMenu<MainOptionUnits>
{
	typedef TL::MkTlst<
		MenuItem<OptionsCoordinates>
	>::Result list;
};

typedef TL::MkTlst<
	TopMenu<MainFile>
	, TopMenu<MainOptionUnits>
>::Result MainMenu;

MENU_TEXT(L"����", TopMenu<MainFile>)
MENU_ITEM(L"�����", MainExit)
MENU_TEXT(L"���������", TopMenu<MainOptionUnits>)
MENU_ITEM(L"��������� ���������� ����", OptionsCoordinates)
}