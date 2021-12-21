#pragma once
#include "SceneBase.h"
#include "DxLib.h"
#include "UIUtilty.h"
#include "InputManager.h"
#include "BoxCollider.h"

using namespace Collider;

namespace Scene
{
	class GameScene : public SceneBase
	{
	public:
		inline GameScene();
		inline ~GameScene();

		// SceneBase ����Čp������܂���
		virtual void Calculation() override;

		virtual void TwoDimentionsDraw() override;

		virtual void ThreeDimensionsDraw() override;

		virtual TransitionType GetNextScene() override;

		BoxCollider* box; // �R���C�_�[�ϐ�(��������)
		BoxCollider* box2; // �R���C�_�[�ϐ�(�����Ȃ���)
		VECTOR pos = VGet(100, 100, 100); // �������W�l(boxCollider 1)
		VECTOR pos2 = VGet(300, 300, 300); // �������W�l(boxCollider 2)
	private:
	};

	GameScene::GameScene()
	{
		box = new BoxCollider(300,300,100,pos);
		box2 = new BoxCollider(300,300,100,pos2);
	}

	GameScene::~GameScene()
	{
		delete box;
		delete box2;
	}
}