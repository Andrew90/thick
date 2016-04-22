#include "stdafx.h"
#include "Dlg.h"
#include "AppBase.h"
#include "..\DlgTemplates\ParamDlg.hpp"

PARAM_TITLE(IPPort, L"IP ����")
PARAM_TITLE(IPName, L"��� ����������")

DO_NOT_CHECK(IPPort)
DO_NOT_CHECK(IPName)

void TcpDlg::Do(HWND h)
{
   if(TemplDialog<IPAddressTable>(Singleton<IPAddressTable>::Instance()).Do(h, L"��������� TCP"))
	{
#pragma message("���������������� TCP")
	}
}