#pragma once
#include "config.h"
#include "Dlg.h"
namespace MainWindowMenu
{
struct MainFile{};
struct MainExit{static void Do(HWND h){DestroyWindow(h);}};

struct MainOptionTypeSize{static void Do(HWND){zprint("");};};
struct MainThresholdOption{};
struct MainCreateTypesize{static void Do(HWND){zprint("");};};
struct MainDeleteTypeSize{static void Do(HWND){zprint("");};};

struct MainOptionUnits{};
struct OptionsCoefficients{};
struct AdditionalParametersTypesize{};
struct InputsOutputs{};
struct MainAbout{static void Do(HWND){zprint("");};};

struct LoadDateFile{static void Do(HWND){zprint("");};};
struct SaveDateFile{static void Do(HWND){zprint("");};};
struct Compute{static void Do(HWND){zprint("");};};
struct MedianFiltreDlg{static void Do(HWND){zprint("");};};
struct DeadAreaDlg{static void Do(HWND){zprint("");};};
struct ACFBorderDlg{static void Do(HWND){zprint("");};};
struct TresholdWindow: TestDlg{};
struct StoredData{static void Do(HWND){zprint("");};};
struct Descriptor1730Dlg{static void Do(HWND){zprint("");};};
struct InputsDlg{static void Do(HWND){zprint("");};};
struct OutputsDlg{static void Do(HWND){zprint("");};};
struct SolenoidParametersTableDlg{static void Do(HWND){zprint("");};};
struct CoordinatesDlg: StoredSizeMainWindow{};
struct L502ParamDlg{static void Do(HWND){zprint("");};};
struct ReferencePointsDlg{static void Do(HWND){zprint("");};};

template<>struct TopMenu<MainFile>
{
	typedef TL::MkTlst<
		MenuItem<LoadDateFile>
		, MenuItem<SaveDateFile>
		, Separator<0>
		, MenuItem<Compute>
		, Separator<1>
		 , MenuItem<MainExit>
	>::Result list;
};

template<>struct SubMenu<AdditionalParametersTypesize>
{
	typedef TL::TypeToTypeLst<
		typename TL::MkTlst<MedianFiltreDlg, DeadAreaDlg, ACFBorderDlg>::Result
		, MenuItem
	>::Result list;
};

template<>struct TopMenu<MainOptionTypeSize>
{
	typedef TL::MkTlst<	
	 MenuItem<TresholdWindow>
		 , Separator<0>
		 , MenuItem<MainCreateTypesize>
		, MenuItem<MainDeleteTypeSize>
		, Separator<1>
		, MenuItem<StoredData>
	>::Result list;
};

template<>struct SubMenu<InputsOutputs>
{
	typedef TL::TypeToTypeLst<
		typename TL::MkTlst<Descriptor1730Dlg, InputsDlg, OutputsDlg>::Result 
		, MenuItem
	>::Result list;
};
struct CommunicationOptions{};

template<>struct TopMenu<MainOptionUnits>
{
	typedef TL::MkTlst<	
#ifndef DISABLE_TCP
		MenuItem<CommunicationOptions>,
#endif
		 MenuItem<SolenoidParametersTableDlg>
		, Separator<0>
		, MenuItem<CoordinatesDlg>
	>::Result list;
};



template<>struct TopMenu<MainAbout>
{
	typedef TL::MkTlst< 
		 MenuItem<MainAbout>
	>::Result list;
};
typedef TL::MkTlst<
	TopMenu<MainFile>
	, TopMenu<MainOptionTypeSize>
	, TopMenu<MainOptionUnits>
	, TopMenu<MainAbout>
>::Result MainMenu;
//--------------------------------------------------------------------------------------------------------
MENU_ITEM(L"����������", Compute)
//--------------------------------------------------------------------------------------------------------

    MENU_TEXT(L"����", TopMenu<MainFile>)
	MENU_TEXT(L"����������", TopMenu<MainOptionTypeSize>)
	MENU_TEXT(L"���������", TopMenu<MainOptionUnits>)
	MENU_TEXT(L"� ���������", TopMenu<MainAbout>)

	//MENU_ITEM(L"��������� ������", MenuItem<SaveDateFile>)
	MENU_ITEM(L"��������� ������", SaveDateFile)
	MENU_ITEM(L"��������� ������", LoadDateFile)
	MENU_ITEM(L"�����", MainExit)
	 
  //  MENU_TEXT(L"�������������� ���������" , SubMenu<AdditionalParametersTypesize>)

	MENU_ITEM(L"��������� ������" , MedianFiltreDlg)
	MENU_ITEM(L"������� ���" , ACFBorderDlg)
	MENU_ITEM(L"̸����� ����" , DeadAreaDlg)
	MENU_ITEM(L"������� �������������" , MainThresholdOption)
	MENU_ITEM(L"������� ����������", MainCreateTypesize)
	MENU_ITEM(L"������� ����������", MainDeleteTypeSize)
	MENU_ITEM(L"�������� ������� ����", StoredData)
	
	MENU_ITEM(L"��������� ���������� �����", L502ParamDlg)	
	MENU_ITEM(L"��������� �������� �����������", CommunicationOptions)	
	MENU_ITEM(L"��������� ����������", SolenoidParametersTableDlg)

	MENU_ITEM(L"������������ �����������", OptionsCoefficients)	
	MENU_ITEM(L"������ �������� �������", ReferencePointsDlg)	
	MENU_ITEM(L"�������� �������", TresholdWindow)
	MENU_ITEM(L"��������� ���������� ����", CoordinatesDlg)
	
	MENU_ITEM(L"� ���������", MainAbout)
}
