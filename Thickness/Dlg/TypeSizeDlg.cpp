#include "stdafx.h"
#include "../DlgTemplates/ParamDlg.h"
#include "../DlgTemplates/ParamDlg.hpp"
#include "Dlg.h"
#include "Emptywindow.h"

#include "MainWindow.h"
namespace{
	PARAM_TITLE(Border2Class, L"����� ����� 1")
	PARAM_TITLE(Border3Class, L"����� ����� 2")	
	PARAM_TITLE(BorderDefect, L"����� ����� 3")	

	MIN_EQUAL_VALUE(Border2Class, 2)
	MAX_EQUAL_VALUE(Border2Class, 15)

	MIN_EQUAL_VALUE(Border3Class, 2)
	MAX_EQUAL_VALUE(Border3Class, 15)

	MIN_EQUAL_VALUE(BorderDefect, 2)
	MAX_EQUAL_VALUE(BorderDefect, 15)

	
	template<class O, class P>struct __test__X: __test__<O, P>{};

	template<class O, class T>double GetVal(T &t)
	{
		wchar_t buf[128];
		GetWindowText(t->get<DlgItem<O>>().hWnd, buf, dimention_of(buf));
		return Wchar_to<double>()(buf);
	}
	/// \brief ��������� �������� �� ������������ BorderDefect	< Border3Class < Border2Class
	template<class T>bool GrowthTestThresholds(T *t)
	{
		double _d =  GetVal<BorderDefect>(t);
		double _3 =  GetVal<Border3Class>(t);
		double _2 =  GetVal<Border2Class>(t);

		HWND h = t->get<DlgItem<BorderDefect>>().hWnd;
		if(_d > _3)
		{
			MessageBox(h, L"�������� \"����� ����� 2\" ������ ���� ������ ��������� \"����� ����� 3\""
				, L"������", MB_ICONERROR);
			return false;
		}
		if(_3 > _2)
		{
			MessageBox(h, L"�������� \"����� ����� 1\" ������ ���� ������ ��������� \"����� ����� 2\""
				, L"������", MB_ICONERROR);
			return false;
		}
		return true;
	}
}

namespace TL
{
	/// \brief ������������ �������� ������������� ����� ������� �������
	template<>struct find<TemplDialog<typename ThresholdsTable>::list, __test__>
	{
		template<class O, class P>bool operator()(O *o, P *p)
		{	
			return find<TemplDialog<typename ThresholdsTable>::list, __test__X>()(o, p) && GrowthTestThresholds(o);
		}
	};
}

void ThicknessDlg::Do(HWND h)
{
	TemplDialog<ThresholdsTable>(Singleton<ThresholdsTable>::Instance()).Do(h, L"������"))
	{
		///\brief  ����� ��������� ����� ���������� ���������
	}
}

namespace{
	PARAM_TITLE(DeadAreaMM0, L"������ �����")
	PARAM_TITLE(DeadAreaMM1, L"����� �����")	

	MIN_EQUAL_VALUE(DeadAreaMM0, 0)
	MAX_EQUAL_VALUE(DeadAreaMM0, 500)

	MIN_EQUAL_VALUE(DeadAreaMM1, 0)
	MAX_EQUAL_VALUE(DeadAreaMM1, 500)
}
void DeadAreaDlg::Do(HWND h)
{
	if(TemplDialog<DeadAreaTable>(Singleton<DeadAreaTable>::Instance()).Do(h, L"̸����� ���� (��)"))
	{
		///\brief  ����� ��������� ����� ���������� ���������
	}
}
namespace{
	PARAM_TITLE(MinimumThicknessPipeWall, L"����������� �������")
	PARAM_TITLE(MaximumThicknessPipeWall, L"������������ �������")	

	MIN_EQUAL_VALUE(MinimumThicknessPipeWall, 2)
	MAX_EQUAL_VALUE(MinimumThicknessPipeWall, 15)

	MIN_EQUAL_VALUE(MaximumThicknessPipeWall, 2)
	MAX_EQUAL_VALUE(MaximumThicknessPipeWall, 15)
}
void BorderCredibilityDlg::Do(HWND h)
{
	if(TemplDialog<BorderCredibilityTable>(Singleton<BorderCredibilityTable>::Instance()).Do(h, L"���������� ������� ������ �����(��)"))
	{
		///\brief  ����� ��������� ����� ���������� ���������
	}
}
namespace {
	PARAM_TITLE(TestBit<SpeedRLBitOut>, L"�������� RL")
	PARAM_TITLE(TestBit<SpeedRMBitOut>, L"�������� RM")
	PARAM_TITLE(TestBit<SpeedRHBitOut>, L"�������� RH")
}
void RotationalSpeedDlg::Do(HWND h)
{
	if(TemplDialog<RotationalSpeedSensorsTable>(Singleton<RotationalSpeedSensorsTable>::Instance()).Do(h, L"�������� �������� ����� ��������"))
	{
		///\brief  ����� ��������� ����� ���������� ���������
	}
}
//--------------------------------------------------------------------------------------------
namespace{
	STR_PARAM(InputText, 128, L"")

	struct putsDlg_OkBtn
	{
		static const int width = 120;
		static const int height = 30;
		static const int ID = IDOK;
		wchar_t *Title(){return L"���������";}
		template<class Owner>void BtnHandler(Owner &owner, HWND h)
		{
			if(TypesizePasswordDlg().Do(h))
			{
				CBase base(ParametersBase().name());
				if(base.IsOpen())
				{			
					Holder<> &name = owner.items.get<DlgItem<InputText> >().value.value;
					GetWindowText(owner.items.get<DlgItem<InputText> >().hWnd, name.buffer, dimention_of(name.buffer));
					if(0 == wcslen(name.buffer))
					{
						MessageBox(h, L"���������� ���������� �������� �����������", L"������", MB_ICONERROR);
						return;
					}
					int id = Select<ParametersTable>(base).eq<NameParam>(name).Execute();
					if(id != 0)
					{
						MessageBox(h, L"�������� ����������� ���� � ���� ������", L"������", MB_ICONERROR);
						return;
					}

					CurrentParametersTable &param = Singleton<CurrentParametersTable>::Instance();
					Select<CurrentParametersTable>(base).ID(1).Execute(param);
					id = param.items.get<CurrentID>().value;
					ParametersTable typeSizeParam;
					Select<ParametersTable>(base).ID(id).Execute(typeSizeParam);
					typeSizeParam.items.get<NameParam>().value = name.buffer;
					Insert_Into<ParametersTable>(typeSizeParam, base).Execute();
					id = Select<ParametersTable>(base).eq<NameParam>(name).Execute();
					Update<CurrentParametersTable>(base).set<CurrentID>(id).Where().ID(1).Execute();
					MainWindow *o = (MainWindow *)GetWindowLongPtr(GetParent(h), GWLP_USERDATA);
					ComboBox_AddString(o->select.hWnd, name.buffer);
					int num = ComboBox_FindStringExact(o->select.hWnd, 0, typeSizeParam.items.get<NameParam>().value);
					if(CB_ERR != num) ComboBox_SetCurSel(o->select.hWnd, num);

					CurrentParametersTable &current = Singleton<CurrentParametersTable>::Instance();
					Select<CurrentParametersTable>(base).ID(1).Execute(current);	
					EndDialog(h, TRUE);
					return; 
				}
				MessageBox(h, L"�� ���� ������� ���� ������", L"������", MB_ICONERROR);
				return; 
			}
		}
	};

	struct NewTypesizeTable
	{
		typedef TL::MkTlst<
			InputText
		>::Result items_list;
		typedef NullType unique_list;
		typedef TL::Factory<items_list> TItems;
		TItems items;
		const wchar_t *name(){return L"NewTypesizeTable";}
	};
	PARAM_TITLE(InputText, L"")
		DO_NOT_CHECK(InputText)

		template<int N>struct DlgSubItems<InputText, Holder<N> >: EditItems<InputText, 420>{};
}
//-----------------------------------------------------------------
void SelectTypeSizeNewDlg::Do(HWND h)
{	
	NewTypesizeTable t;
	if(TemplDialog<NewTypesizeTable, TL::MkTlst<putsDlg_OkBtn, CancelBtn>::Result>(t).Do(h, L"������� ����������"))
	{
	}
}
//------------------------------------------------------------
namespace{
	template<class O, class P>struct __update_param__{void operator()(O *, P *){}};

	template<class Table, class P>struct __update_param__<ID<Table>, P>
	{
		typedef ID<Table> O;
		void operator()(O *o, P *p)
		{
			Select<Table>(*p).ID(CurrentId<O>(*p)).Execute(Singleton<Table>::Instance());
		}
	};
}
void SelectTypeSizeDeleteDlg::Do(HWND hWnd)
{	
	if(TypesizePasswordDlg().Do(hWnd))
	{
		CBase base(ParametersBase().name());
		ADODB::_RecordsetPtr rec;
		Select<ParametersTable>(base).Execute(rec);
		int i = 0;
		while (!rec->EndOfFile) 
		{			
			++i;
			rec->MoveNext(); 
		}	
		if(1 < i)
		{	
			MainWindow *o = (MainWindow *)GetWindowLongPtr(hWnd, GWLP_USERDATA);
			wchar_t buf[128];
			GetWindowText(o->select.hWnd, buf, dimention_of(buf));
			NameParam::type_value txt;
			txt = buf;
			Delete<ParametersTable>(base).eq<NameParam>(txt).Execute();
			int num = ComboBox_FindStringExact(o->select.hWnd, 0, buf);
			ComboBox_DeleteString(o->select.hWnd, num);
			ComboBox_SetCurSel(o->select.hWnd, 0);

			GetWindowText(o->select.hWnd, buf, dimention_of(buf));
			txt = buf;
			ParametersTable typeSizeParam;
			int id = Select<ParametersTable>(base).eq<NameParam>(txt).Execute(typeSizeParam);
			if(id != 0)
			{
				Update<CurrentParametersTable>(base).set<CurrentID>(id).Where().ID(1).Execute();
				TL::foreach<ParametersTable::items_list, __update_param__>()(&typeSizeParam.items, &base);
			}
		}
		else
		{
			MessageBox(hWnd, L"���������� ������������ ������ ���� ������ 1", L"���������", MB_ICONINFORMATION);
		}
	}
}

