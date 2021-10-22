#include <DxLib.h>
#include <Memory>
#include "DxDraw.hpp"

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	char Buf[256];
	auto draw = std::make_unique<DxDraw>();
	while (ProcessMessage() == 0)
	{
		/*演算*/
		{
			GetHitKeyStateAll(Buf);
		}
		/*描画*/
		{
			//3D(主描画)
			{
			}
			//2D(UI:ユーザーインターフェース)
			{
				clsDx();
				printfDx("Buf[KEY_INPUT_Z] = %d \n", Buf[KEY_INPUT_Z]);
			}
		}
		ScreenFlip();
		//ESCキーを押すとゲームループから抜けます
		if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) {
			break;
		}
	}

	return 0;              // ソフトの終了 
}