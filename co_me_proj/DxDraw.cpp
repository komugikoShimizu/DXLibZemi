#include"DxDraw.hpp"
#include<DxLib.h>

DxDraw::DxDraw()
{
	SetOutApplicationLogValidFlag(FALSE);           /*log*/
	SetMainWindowText("game title");                /*�^�C�g��*/
	ChangeWindowMode(TRUE);                         /*���\��*/
	SetUseDirect3DVersion(DX_DIRECT3D_11);          /*directX ver*/
	SetGraphMode(640, 480, 32);                     /*�𑜓x*/
	SetUseDirectInputFlag(TRUE);                    /*DirectInput�g�p*/
	SetDirectInputMouseMode(TRUE);                  /*DirectInput�}�E�X�g�p*/
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);    /*�E�C���h�E�T�C�Y���蓮�ύX�s�A�E�C���h�E�T�C�Y�ɍ��킹�Ċg������Ȃ��悤�ɂ���*/
	SetUsePixelLighting(TRUE);                      /*�s�N�Z�����C�e�B���O�̎g�p*/
	SetFullSceneAntiAliasingMode(4, 2);             /*�A���`�G�C���A�X*/
	SetEnableXAudioFlag(TRUE);                      /*XAudio��p���邩*/
	Set3DSoundOneMetre(1.0f);                       /*3D�I�[�f�B�I�̊�����w��*/
	SetWaitVSyncFlag(TRUE);                         /*��������*/
	DxLib_Init();                                   /*�c�w���C�u��������������*/
	SetDrawScreen(DX_SCREEN_BACK);					/*����ʂɏ�������*/
	SetSysCommandOffFlag(TRUE);                     /*�^�X�N�X�C�b�`��L���ɂ��邩�ǂ�����ݒ肷��*/
	SetAlwaysRunFlag(TRUE);                         /*background*/
	SetUseZBuffer3D(TRUE);                          /*zbufuse*/
	SetWriteZBuffer3D(TRUE);                        /*zbufwrite*/
	MV1SetLoadModelPhysicsWorldGravity(-9.8f);      /*�d��*/
}

DxDraw::~DxDraw()
{
	DxLib_End();
}