#include <DxLib.h>
#include <cassert>
#include <string>
#include <sstream>
#include <iomanip>
#include "Main.h"

#define BULLETMAX 50
struct POS
{
	int x;
	int y;
};
struct SHOT
{
	POS bPos;
	bool flag;
	float move;
};
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	SetWindowText(L"1916010_���q�ɑ��Y");
	ChangeWindowMode(true);									
	if (DxLib_Init() == -1)									
	{
		return false;
	}
	SetDrawScreen(DX_SCREEN_BACK);
	//char keyState[256];
	//GetHitKeyStateAll(keyState);
	
	//�ړ��摜
	int runImage[8];
	//�����摜
	int idleImage = LoadGraph(L"Image/PNGExports/Idle.png");
	//�A�N�V�����摜
	int actionImage[2];
	int bulletImage = LoadGraph(L"Image/PNGExports/item1.png");
	if (LoadDivGraph(L"Image/PNGExports/Run.png", 8, 8, 1, 80, 48, &runImage[0]) == -1)
	{
		
	}
	if (LoadDivGraph(L"Image/PNGExports/ShootGun1.png", 2, 2, 1, 80, 48, &actionImage[0]) == -1)
	{

	}
	int animCnt = 0;
	//�v���C���[�̈ʒu
	POS pPos = { 100,300 };
	//�ړ���
	float move = 1.0f;
	//���̈ʒu
	SHOT bullet[BULLETMAX] = { pPos.x + 130,pPos.y + 70 };
	for (int i = 0; i < 50; i++)
	{
		bullet[i].bPos = { pPos.x + 130,pPos.y + 70 };
		bullet[i].move = 5.0f;
		bullet[i].flag = false;
	}
	while (!ProcessMessage() && !CheckHitKey(KEY_INPUT_ESCAPE))
	{
		ClsDrawScreen();
		
		animCnt++;
		//�ړ��̃A�j���[�V����
		int tmpAnim = (animCnt / 10) % 8;
		//�A�N�V�����̃A�j���[�V����
		int actionAnim = (animCnt / 10) % 2;

		if (CheckHitKey(KEY_INPUT_RIGHT))
		{
			DrawExtendGraph(pPos.x, pPos.y, pPos.x + 200, pPos.y + 150, runImage[tmpAnim], true);
			pPos.x += move;
		}
		else if (CheckHitKey(KEY_INPUT_LEFT))
		{
			DrawExtendGraph(pPos.x, pPos.y, pPos.x + 200, pPos.y + 150, runImage[tmpAnim], true);
			pPos.x -= move;
		}
		else if (CheckHitKey(KEY_INPUT_SPACE))
		{
				
			DrawExtendGraph(pPos.x, pPos.y, pPos.x + 200, pPos.y + 150, actionImage[actionAnim], true);
			
		}
		else
		{
			DrawExtendGraph(pPos.x, pPos.y, pPos.x + 200, pPos.y + 150, idleImage, true);
		}
		
		
		DrawString(0, 15, L"�e���L�[�����ňړ�", 0xffffff, true);
		DrawString(0, 45, L"�X�y�[�X�L�[�Ń��[�V����", 0xffffff, true);
		ScreenFlip();
	}
}
