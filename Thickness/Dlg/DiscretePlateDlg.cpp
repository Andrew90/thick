#include "stdafx.h"
#include "Dlg.h"
#include "..\DlgTemplates\ParamDlg.hpp"

namespace{
	template<class O, class P>struct __compress__
	{
		void operator()(O *o, P *p)
		{
			unsigned offs = p->get<O>().value;
			unsigned bit = 0;
			while(offs >>= 1) ++bit;
			o->value = bit;
		}
	};
	template<class O, class P>struct __set__
	{
		void operator()(O *o, P *p)
		{
			p->get<O>().value = o->value;
		}
	};
	struct putsDlg_OkBtn
	{
		static const int width = 120;
		static const int height = 30;
		static const int ID = IDOK;
		wchar_t *Title(){return L"���������";}
		template<class Owner>void BtnHandler(Owner &owner, HWND h)
		{
			TL::foreach<Owner::list, __uncompress__>()(&owner.items,  (int *)NULL);
			OkBtn().BtnHandler(owner, h);
		}
	};

#define OFFS(n, txt)template<>struct __data_from_widget__<DlgItem<n>, unsigned>\
	{\
		typedef int T;\
		typedef DlgItem<n> O;\
		T operator()(O &o)\
		{ \
			wchar_t buf[64];\
			GetWindowText(o.hWnd, buf, dimention_of(buf));\
			unsigned t = Wchar_to<T>()(buf);\
			return 1 << t;\
		}\
	};\
	template<>struct DlgSubItems<n, unsigned>: UpDownSubItem<n>{}; \
	DO_NOT_CHECK(n)\
	PARAM_TITLE(n, txt)

	OFFS(SQ1BitIn           , L"SQ1 ������������ ����������(���� �����)")
	OFFS(SQ3BitIn           , L"SQ3 ������������ ����������(����� �����)")
	OFFS(StateBBitIn        , L"�(��������� ���������� ���������������)")
	OFFS(StateABitIn        , L"�(��������� ���������� ���������������)")
	OFFS(RunBitIn           , L"RUN(��������� ���������� ���������������)")
	OFFS(ControlCircuitBitIn, L"���� ����������")
	OFFS(WorkBitIn          , L"������(�� ����� 9955-191/16)")
	OFFS(SycleBitIn         , L"����(�� ����� 9955-191/16)")
	OFFS(BaseBitIn    	   	, L"����(�� ����� 9955-191/16)")

	OFFS(PowerInverterBitOut, L"������� ���������� ���������������")
	OFFS(SpeedRLBitOut    	, L"�������� RL")
	OFFS(SpeedRMBitOut    	, L"�������� RM")
	OFFS(SpeedRHBitOut    	, L"�������� RH")
	OFFS(STFBitOut        	, L"STF")
	OFFS(PowerScannerBitOut	, L"������� ������������ ����������")
	OFFS(ReadyBitOut      	, L"����������(� ���� 9955-191/16)")
	OFFS(ControlBitOut    	, L"��������(� ���� 9955-191/16)")
	OFFS(ResultBitOut     	, L"���������(� ���� 9955-191/16)")
#undef OFFS

	PARAM_TITLE(NamePlate1730, L"���������� �����")
	DO_NOT_CHECK(NamePlate1730)
}

void DiscretePlateInputsDlg::Do(HWND h)
{
   InputBitsTable table;
   TL::foreach<InputBitsTable::items_list, __compress__>()(&table.items,  &Singleton<InputBitsTable>::Instance().items);
   TemplDialog<InputBitsTable>dlg(table);
   if(dlg.Do(h, L"������� ����� ���������� �����"))
   {
   TL::foreach<InputBitsTable::items_list, __set__>()(&table.items,  &Singleton<InputBitsTable>::Instance().items);
   }
}

void DiscretePlateOutputsDlg::Do(HWND h)
{
	OutputBitsTable table;
	TL::foreach<OutputBitsTable::items_list, __compress__>()(&table.items,  &Singleton<OutputBitsTable>::Instance().items);
	TemplDialog<OutputBitsTable>dlg(table);
	if(dlg.Do(h, L"�������� ����� ���������� �����"))
	{
		TL::foreach<OutputBitsTable::items_list, __set__>()(&table.items,  &Singleton<OutputBitsTable>::Instance().items);
	}
}

void DiscretePlateDescriptorDlg::Do(HWND h)
{
	if(TemplDialog<NamePlate1730ParametersTable>(Singleton<NamePlate1730ParametersTable>::Instance()).Do(h, L"���������� �����"))
	{
	}
}