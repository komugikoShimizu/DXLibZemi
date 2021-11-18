#pragma once
#include "DXLib_vec.hpp"
#include "EffekseerEffectHandle.hpp"
#include <memory>
#include <array>
#include <vector>
#include <cmath>

//�G�t�F�N�g
class Effect {
public:
    bool flug = false;                  // �G�t�F�N�g�̕\���t���O
    size_t id = 0;                      // �G�t�F�N�g��ID
    Effekseer3DPlayingHandle handle;    // �G�t�F�N�g�̃n���h��
    VECTOR pos;                         // �G�t�F�N�g�̏ꏊ
    VECTOR nor;                         // �G�t�F�N�g��Y���̌���
    float scale = 1.f;                  // �G�t�F�N�g�̃X�P�[��
    // �G�t�F�N�g�̏ꏊ���w�肵�J�n�t���O�𗧂Ă�
    void set(const VECTOR& pos_, const VECTOR& nor_, float scale_ = 1.f) {
        this->flug = true;
        this->pos = pos_;
        this->nor = nor_;
        this->scale = scale_;
    }
    // �G�t�F�N�g�̊J�n�t���O�������Ă���΃G�t�F�N�g���Đ�
    void put(const EffekseerEffectHandle& handle_) {
        if (this->flug) {
            //�Đ��`�F�b�N
            if (this->handle.IsPlaying()) {
                this->handle.Stop();
            }
            //�Đ�
            this->handle = handle_.Play3D();
            //�ꏊ���w��
            this->handle.SetPos(this->pos);
            //�������w��
            this->handle.SetRotation(atan2(this->nor.y, std::hypotf(this->nor.x, this->nor.z)), atan2(-this->nor.x, -this->nor.z), 0);
            //�傫�����w��
            this->handle.SetScale(this->scale);
            //�J�n�t���O��؂�
            this->flug = false;
        }
    }
};