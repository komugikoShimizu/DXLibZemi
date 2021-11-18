#pragma once
#include <DxLib.h>
#include "SceneBase.hpp"
#include <vector>
#include "EffekseerEffectHandle.hpp"
#include "Effect.hpp"
#include "InputController.hpp"
#include "GraphHandle.hpp"
#include "MV1ModelHandle.hpp"

namespace Scene
{
	class GameScene : public SceneBase
	{
	public:
		inline GameScene();
		inline ~GameScene();

		// SceneBase を介して継承されました
		virtual void Calculation(SetDrawCameraInfo&) override;
		virtual void TwoDimensionsDraw() override;
		virtual void ThreeDimensionsDraw() override;
		TransitionType GetNextState() override;

	private:
		Input::InputController inputer;
		//	背景の黒画像をウィンドウサイズに合わせるための変数
		int windowSizeX = 0;
		int windowSizeY = 0;
		// 今回は無視する
		int ColorBitDepth = 0;
		// Effect用黒背景画像
		int backGroundBaseGraphHandle;
		// BackGroundImage
		int skyBoxGraphHandle;
		// リソース
		std::vector<EffekseerEffectHandle> effHndle; // エフェクトリソース
		MV1 model_base; // モデルリソース
		// オブジェクト
		std::vector<Effect> effcs;//メインループで使うエフェクト
		MV1 model_obj;
		float modelScale = 1.f;
		float horizontalRotRad = 1.0f;
		float horizontalrad = 0.f;
		float verticalRotRad = 1.0f;
		MATRIX_ref* modelMatrix = nullptr;
		MATRIX_ref* modelInverseMatrix = nullptr;
		//モデルの位置
		VECTOR_ref model_pos = VECTOR_ref::vget(0.0f, 0.0f, 0.0f);
		//カメラの注視点
		VECTOR_ref camera_target_pos = model_pos;
		//カメラの位置
		VECTOR_ref camera_pos = model_pos;
		//演算用の値
		float x = 0.f;
		float z = 0.f;
		float rad = 0.f;
		float size = 3.;

		MATRIX RIGHT_TILT_MT = MATRIX();
	};

	GameScene::GameScene()
	{
		inputer = Input::InputController();
		backGroundBaseGraphHandle = LoadGraph("Image/Brack.png");
		skyBoxGraphHandle = LoadGraph("Image/SkyBox.png");
		effHndle.resize(effHndle.size() + 1);
		effHndle.back() = EffekseerEffectHandle::load("EffectData/Snow.efkefc");
		effcs.resize(effHndle.size());//エフェクトのセットアップ

		MV1::Load("Model/Kamihikouki.mv1", &model_base, false);
		model_obj = model_base.Duplicate();
		model_obj.SetScale(VGet(modelScale, modelScale, modelScale));
	}

	GameScene::~GameScene()
	{

	}
}


