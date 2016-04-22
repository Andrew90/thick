#include "stdafx.h"
#include "Dlg.h"
#include "..\DlgTemplates\ParamDlg.hpp"

namespace{
template<>struct allowable_limit_on_the_parameter<MedianFilter>
{
	typedef MedianFilter T;
	bool operator()(T::type_value &t, HWND h)
	{
		if(t < 2)
		{
			unsigned res = MessageBox(h, L"��������� ������ ����� ��������", L"���������", MB_ICONEXCLAMATION | MB_YESNO);
			if(res == IDYES)
			{
				t = 0;
				return true;
			}
			return false;
		}
		if(0 ==(t & 1))
		{
			unsigned res = MessageBox(h, L"������ ���������� ������� ������ ���� ��������", L"���������", MB_ICONEXCLAMATION | MB_YESNO);
			if(res == IDYES)
			{
				++t;
				return true;
			}
			return false;
		}
		if(t < 31) return true;
		MessageBox(h, L"�������� \"������ �������\" ������ ������ 30", L"������!!!", MB_ICONEXCLAMATION);
		return false;
	}	
};
PARAM_TITLE(MedianFilter, L"������ �������")
}



void MedianFiltreDlg::Do(HWND h)
{
	if(TemplDialog<MedianFilterTable>(Singleton<MedianFilterTable>::Instance()).Do(h, L"��������� ������"))
	{
	}
}

