#include "stdafx.h"
#include "Dlg.h"
#include "..\DlgTemplates\ParamDlg.hpp"
namespace{
MIN_EQUAL_VALUE(MinAxes, 0)
MAX_EQUAL_VALUE(MinAxes, 20)

MIN_EQUAL_VALUE(MaxAxes, 0)
MAX_EQUAL_VALUE(MaxAxes, 20)

PARAM_TITLE(MaxAxes, L"��� Y ��������")
PARAM_TITLE(MinAxes, L"��� Y �������")
}
void AxesTableDlg::Do(HWND h)
{
	if(TemplDialog<AxesTable>(Singleton<AxesTable>::Instance()).Do(h, L"��� �������"))
	{
	}
}