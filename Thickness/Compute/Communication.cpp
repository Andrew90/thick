#include "stdafx.h"
#ifdef DEBUG_ITEMS
#include "Communication.h"
#include "PrimaryData.h"
#include "../emul/emulLan/TestLanBuffer.h"

//todo ������� �������� �������� � ������������ �������� ���
void Communication::GetOffset()
{
	primaryData.countZones = mapped.buf->countZones;
	memmove(primaryData.offsetOfTime, mapped.buf->offsetsTime, sizeof(double) * primaryData.countZones);
}
#endif
