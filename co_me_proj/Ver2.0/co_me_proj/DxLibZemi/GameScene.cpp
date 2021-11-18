#include "GameScene.hpp"



namespace Scene
{
	void GameScene::Calculation(SetDrawCameraInfo& info)
	{
		/*演算*/
		{
			Input::KeyUpdate();
			if (CheckHitKey(KEY_INPUT_W) != 0)
			{
				horizontalrad += 0.05f;
			}
			if (CheckHitKey(KEY_INPUT_S) != 0)
			{
				horizontalrad -= 0.05f;
			}
			if (CheckHitKey(KEY_INPUT_A) != 0)
			{

			}
			if (CheckHitKey(KEY_INPUT_D) != 0)
			{

			}


			auto tmpMatrix = model_obj.GetMatrix();
			modelMatrix = &tmpMatrix;
			tmpMatrix = tmpMatrix.Inverse();
			modelInverseMatrix = &tmpMatrix;
			horizontalrad += inputer.GetYAxis();
			printfDx("GetYAxis:%f", inputer.GetYAxis());
			model_obj.SetMatrix(model_obj.GetMatrix().RotX(horizontalrad * horizontalRotRad));
			//if (CheckHitKey(KEY_INPUT_A) != 0)
			//{
			//	model_pos += VGet(-10.f * 60 / GetFPS(), 0.f, 0.f);
			//}
			//if (CheckHitKey(KEY_INPUT_D) != 0)
			//{
			//	//rad -= DX_PI_F / 180 * 6 * 60 / GetFPS();
			//	model_pos += VGet(10.f * 60 / GetFPS(), 0.f, 0.f);
			//}
			
		}
		//エフェクトの更新
		{
			for (size_t index = 0; index < effHndle.size(); ++index) {
				effcs[index].put(effHndle[index]);
			}
		}
		{

			camera_target_pos = model_pos + VECTOR_ref::vget(0.f, 0.f, 0.f);//注視点
			camera_pos = camera_target_pos + VECTOR_ref::vget(0.f, 10.f, 300.f);
		}

		GetScreenState(&windowSizeX, &windowSizeY, &ColorBitDepth);

		info.campos = camera_pos;
		info.camvec = camera_target_pos;
		info.camup = VGet(0, 1, 0);
		info.fov = DX_PI_F / 4;
		info.near_ = 0.1f;
		info.far_ = 100000.0f;

	}

	void GameScene::TwoDimensionsDraw()
	{
		DrawPixel(320, 240, GetColor(255, 255, 255));   // 点を打つ
		// DrawExtendGraph(0, 0, windowSizeX, windowSizeY, backGroundBaseGraphHandle, FALSE);
	}

	void GameScene::ThreeDimensionsDraw()
	{
		DrawExtendGraph(0, 0, windowSizeX, windowSizeY, backGroundBaseGraphHandle, FALSE);
		DrawExtendGraph(0, 0, windowSizeX, windowSizeY, skyBoxGraphHandle, FALSE);
		Effekseer_Sync3DSetting();
		{
			UpdateEffekseer3D();
			//draw3D
			model_obj.DrawModel();

			DrawEffekseer3D();
		}
	}

	TransitionType GameScene::GetNextState()
	{
		//if (inputer.GetIsFinishKey()) return 

		static bool isHitKeyRetrun;
		bool beforeIsHitKeyRetrun = isHitKeyRetrun;
		isHitKeyRetrun = CheckHitKey(KEY_INPUT_RETURN) == 1;
		if (!isHitKeyRetrun) return TransitionType::STAY;
		if (beforeIsHitKeyRetrun) return TransitionType::STAY;
		return TransitionType::NEXT;
	}
}

