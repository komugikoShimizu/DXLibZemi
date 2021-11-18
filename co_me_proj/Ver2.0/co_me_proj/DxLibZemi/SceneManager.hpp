#pragma once
#include <DxLib.h>
#include"SceneBase.hpp"
#include"GameScene.hpp"
#include"ResultScene.hpp"
#include"TitleScene.hpp"

namespace Scene
{
	enum class StateType
	{
		TITLE = 0,
		GAME,
		RESULT,
		COUNT
	};
	

	class SceneManager
	{
	public:
		inline SceneManager();
		inline ~SceneManager();
		// ゲームループを回すための主要関数
		bool SceneProcess();
		void SetDraw_Screen(const bool& clear);
		void SetDraw_Screen(const SetDrawCameraInfo& info);

	private:
		// 現在のシーンのステート
		StateType state;
		// シーンの配列
		SceneBase* scenes[(int)StateType::COUNT];
		// カメラの情報
		SetDrawCameraInfo info;
	};

	SceneManager::SceneManager()
	{
		info = SetDrawCameraInfo();
		state = StateType::GAME;
		scenes[0] = new TitleScene();
		scenes[1] = new GameScene();
		scenes[2] = new ResultScene();
	}

	SceneManager::~SceneManager()
	{
		for (int i = 0; i < (int)StateType::COUNT; i++)
		{
			delete scenes[i];
		}
	}

}
