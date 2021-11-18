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

		// SceneBase ����Čp������܂���
		virtual void Calculation(SetDrawCameraInfo&) override;
		virtual void TwoDimensionsDraw() override;
		virtual void ThreeDimensionsDraw() override;
		TransitionType GetNextState() override;

	private:
		Input::InputController inputer;
		//	�w�i�̍��摜���E�B���h�E�T�C�Y�ɍ��킹�邽�߂̕ϐ�
		int windowSizeX = 0;
		int windowSizeY = 0;
		// ����͖�������
		int ColorBitDepth = 0;
		// Effect�p���w�i�摜
		int backGroundBaseGraphHandle;
		// BackGroundImage
		int skyBoxGraphHandle;
		// ���\�[�X
		std::vector<EffekseerEffectHandle> effHndle; // �G�t�F�N�g���\�[�X
		MV1 model_base; // ���f�����\�[�X
		// �I�u�W�F�N�g
		std::vector<Effect> effcs;//���C�����[�v�Ŏg���G�t�F�N�g
		MV1 model_obj;
		float modelScale = 1.f;
		float horizontalRotRad = 1.0f;
		float horizontalrad = 0.f;
		float verticalRotRad = 1.0f;
		MATRIX_ref* modelMatrix = nullptr;
		MATRIX_ref* modelInverseMatrix = nullptr;
		//���f���̈ʒu
		VECTOR_ref model_pos = VECTOR_ref::vget(0.0f, 0.0f, 0.0f);
		//�J�����̒����_
		VECTOR_ref camera_target_pos = model_pos;
		//�J�����̈ʒu
		VECTOR_ref camera_pos = model_pos;
		//���Z�p�̒l
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
		effcs.resize(effHndle.size());//�G�t�F�N�g�̃Z�b�g�A�b�v

		MV1::Load("Model/Kamihikouki.mv1", &model_base, false);
		model_obj = model_base.Duplicate();
		model_obj.SetScale(VGet(modelScale, modelScale, modelScale));
	}

	GameScene::~GameScene()
	{

	}
}


