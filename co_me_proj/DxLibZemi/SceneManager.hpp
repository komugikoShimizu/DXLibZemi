#pragma once
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
		bool SceneProcess();
	private:

		StateType state;
		SceneBase* scenes[(int)StateType::COUNT];
	};

	SceneManager::SceneManager()
	{
		state = StateType::TITLE;
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
