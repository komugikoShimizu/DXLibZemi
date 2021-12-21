#include "GameScene.h"

namespace Scene
{
	void GameScene::Calculation()
	{
		//if (Input::isAdvance()) pos += 1;
		//else if (Input::isBack()) pos -= 1;
		//string str = "My Character Position:";
		//str += std::to_string(pos);
		//ui->TextCreater(str.c_str(), CanvasPosition{0,0},30,"white");
		//ui->TextCreater("position 100 or -100... GameOver", CanvasPosition{ 5,20 }, 30, "yellow", "black", true);
		string str = "目標地点: x.";
		str += to_string(box2->pivot->x);
		str += ":y.";
		str += to_string(box2->pivot->y);
		str += ":z.";
		str += to_string(box2->pivot->z);
		UIUtilty::TextCreater(str.c_str(), CanvasPosition{0,0},20,"yellow");

		string str2 = "現在の座標：x.";
		str2 += to_string(box->pivot->x);
		str2 += ":y.";
		str2 += to_string(box->pivot->y);
		str2 += ":z.";
		str2 += to_string(box->pivot->z);
		UIUtilty::TextCreater(str2.c_str(), CanvasPosition{ 0,50 }, 20, "red");

		box->posSet();

		box->Draw();
		box2->Draw();
	}

	void GameScene::TwoDimentionsDraw()
	{

	}

	void GameScene::ThreeDimensionsDraw()
	{

	}

	TransitionType GameScene::GetNextScene()
	{
		// if (CheckHitKey(KEY_INPUT_RETURN)) return TransitionType::NEXT;
		if (BoxCollider::HitCollider(box, box2))
		{
			*box->pivot = VGet(100, 100, 100);
			*box2->pivot = VGet(300, 300, 300);

			return TransitionType::NEXT;
		}
		return TransitionType::STAY;
	}
}
