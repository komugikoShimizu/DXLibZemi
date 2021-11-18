#pragma once
#include <DxLib.h>

namespace Input
{
	constexpr int BUF_SIZE = 256;
	static char crrentBuf[BUF_SIZE];
	static char beforeBuf[BUF_SIZE];
	static void KeyUpdate()
	{
		*beforeBuf = *crrentBuf;
		GetHitKeyStateAll(crrentBuf);
	}

	static bool GetKeyDown(int keyCode)
	{
		if (crrentBuf[keyCode] != 1) return false;
		if (beforeBuf[keyCode] != 0) return false;
		return true;
	}
	static bool GetKeyUp(int keyCode)
	{
		if (crrentBuf[keyCode] != 0) return false;
		if (beforeBuf[keyCode] != 1) return false;
		return true;
	}
	static bool GetKey(int keyCode)
	{
		if (crrentBuf[keyCode] != 1) return false;
		return true;
	}
}