#include "stdafx.h"
#include "Dlg.h"
#include "DebugMess.h"

//#include "ParamDlg.h"
//#include "ParamDlg.hpp"
#include "Pass.h"
#include "TablesDefine.h"

//D:\Projects\EmptyProject\Thickness\Dlg\TestDlg.cpp
#include "D:\Projects\EmptyProject\DlgTemplates\ParamDlg.h"
#include "D:\Projects\EmptyProject\DlgTemplates\ParamDlg.hpp"


MIN_VALUE(Frequency502, 0)
MAX_VALUE(Frequency502, 1000)

MIN_VALUE(FrequencyGenerator, -5000)
MAX_VALUE(FrequencyGenerator, 5000)

PARAM_TITLE(Frequency502, L"����� ����������")
PARAM_TITLE(FrequencyGenerator, L"������������� �������� �� �������")

MIN_VALUE(InputRangeSignal, 0)
MAX_VALUE(InputRangeSignal, 1000)

MIN_VALUE(RangeReferenceSignal, -5000)
MAX_VALUE(RangeReferenceSignal, 5000)

PARAM_TITLE(InputRangeSignal, L"����� ����������")
PARAM_TITLE(RangeReferenceSignal, L"������������� �������� �� �������")

//TABLE_ONE_ROW(PaintMakerTable)

void TestDlg::Do(HWND h)
{
	if(TemplDialog<SolenoidParametersTable>(Singleton<SolenoidParametersTable>::Instance()).Do(h, L"���������������"))
	{

	}
}

