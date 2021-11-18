#include "SceneManager.hpp"


namespace Scene
{
	/// <summary>
	/// Scene管理関数
	/// </summary>
	/// <returns>isFinish</returns>
	bool SceneManager::SceneProcess()
	{
		ClearDrawScreen();
		// Debug用描画の初期化
		clsDx();
		// 対応してるシーンの演算関数をコール
		scenes[(int)state]->Calculation(info);
		// カメラを設定するための情報付きSetDrawScreen関数
		SetDraw_Screen(info);
		// ノーマルのSetDrawScreen関数
		// SetDraw_Screen(true);
		// 対応してるシーンの3D描画関数をコール
		scenes[(int)state]->ThreeDimensionsDraw();
		// 対応してるシーンの2D描画関数をコール
		scenes[(int)state]->TwoDimensionsDraw();
		// 画面を表示する
		ScreenFlip();

		// 次のシーンへの遷移情報の取得
		switch (scenes[(int)state]->GetNextState())
		{
		case TransitionType::STAY:
			// 何もしない
			break;
		case TransitionType::NEXT:
			// stateを1進める Count以上は繰り返し
			state = (StateType)(((int)state + 1) % (int)StateType::COUNT);
			break;
		case TransitionType::BACK:
			// stateを1戻す 0以下は繰り返し
			state = (StateType)(((int)state - 1 + (int)StateType::COUNT) % (int)StateType::COUNT);
			break;
		default:
			break;
		}
		bool isHitKeyEscape = false;
		static bool beforeIsHitKeyEscape = isHitKeyEscape;
		isHitKeyEscape = CheckHitKey(KEY_INPUT_ESCAPE) == 1;
		if (isHitKeyEscape && beforeIsHitKeyEscape) return true;
		return false;
	}

	// 通常のSetDrawScreen関数
	void SceneManager::SetDraw_Screen(const bool& clear = true)
	{
		SetDrawScreen(DX_SCREEN_BACK);
		if (clear)
		{
			ClearDrawScreen();
		}
	}

	// カメラ設定付きのSetDrawScreen関数(大体おまじない)
	void SceneManager::SetDraw_Screen(const SetDrawCameraInfo& info)
	{
		SetDrawScreen(DX_SCREEN_BACK);
		SetCameraNearFar(info.near_, info.far_);
		SetupCamera_Perspective(info.fov);
		SetCameraPositionAndTargetAndUpVec(info.campos.get(), info.camvec.get(), info.camup.get());
	}
}
