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

		// SceneBase を介して継承されました
		virtual void Calculation() override;

		virtual void TwoDimentionsDraw() override;

		virtual void ThreeDimensionsDraw() override;

		virtual TransitionType GetNextScene() override;

		BoxCollider* box; // コライダー変数(動かす側)
		BoxCollider* box2; // コライダー変数(動かない側)
		VECTOR pos = VGet(100, 100, 100); // 初期座標値(boxCollider 1)
		VECTOR pos2 = VGet(300, 300, 300); // 初期座標値(boxCollider 2)
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