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
		// �Q�[�����[�v���񂷂��߂̎�v�֐�
		bool SceneProcess();
		void SetDraw_Screen(const bool& clear);
		void SetDraw_Screen(const SetDrawCameraInfo& info);

	private:
		// ���݂̃V�[���̃X�e�[�g
		StateType state;
		// �V�[���̔z��
		SceneBase* scenes[(int)StateType::COUNT];
		// �J�����̏��
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
