#include <DxLib.h>
#include "Main.h"
#include <cassert>

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	SetWindowText(L"1916010_‹àŽq—É‘¾˜Y");
	ChangeWindowMode(true);									
	if (DxLib_Init() == -1)									
	{
		return false;
	}
	SetDrawScreen(DX_SCREEN_BACK);
	int runImage[15];
	LoadDivGraph(L"Image/Run.png", 15, 15, 1, 1500, 92, runImage);
	while (!ProcessMessage() && !CheckHitKey(KEY_INPUT_ESCAPE))
	{
		ClsDrawScreen();
		DrawGraph(100, 300, runImage[2], true);
		ScreenFlip();
	}
}
