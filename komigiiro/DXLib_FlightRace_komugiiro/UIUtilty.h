#pragma once
#include "DxLib.h"
#include "vector"
#include "string"
#include <map>

using namespace std;


namespace UI
{
	struct CanvasPosition
	{
	public:
		double x;
		double y;
	};

	static class UIUtilty
	{
	public:
		// ��b�I�ȐF�̃Z�b�g���쐬���܂�
		// ��red green blue cyan magenta yellow black white
		void static ColorCreater();
		// �ݒ肵���F���𕶎���ň����o����悤�ɂ��܂�
		void static ColorCreater(const char* colorName,int red,int green,int blue); 
		// �g�p�t�H���g�݂̂�ݒ肵�܂�
		void static FontSeter(const char* fontName,const char* fontPath); 
		// �g�p�t�H���g�̐ݒ���s�����̂��A�ݒ肳�ꂽ�t�H���g�T�C�Y���쐬���܂�
		void static FontSeter(const char* fontName, const char* fontPath, int fontSize, int fontThick = 20);
	    // �f�t�H���g�t�H���g�Ńt�H���g�T�C�Y���쐬���܂�
		void static FontSeter(int fontSize,int fontThick = 20);
		// ���͂��ꂽ�L�����o�X�T�C�Y���쐬���܂�
		void static CanvasSizeCreate(int maxCanvasSize);
		// �w����W�Ƀe�L�X�g��\�����܂�
		void static TextCreater(const char* contents,int x,int y);
		// �w����W�ɃT�C�Y���w�肵�ăe�L�X�g��\�����܂�
		void static TextCreater(const char* contents, int x, int y, int fontSize);
		// ���ڎw�肳�ꂽRGB���g�p���w����W�A�T�C�Y�Ńe�L�X�g��\�����܂�
		void static TextCreater(const char* contents, int x, int y, int fontSize, int red, int green, int blue);
		// �ݒ�ς݂̃t�H���g�J���[���g�p���w����W�A�T�C�Y�Ńe�L�X�g��\�����܂�
		void static TextCreater(const char* contents, int x, int y, int fontSize, const char* fontColor);
		// �g�g�ݕt���Ńe�L�X�g��\�����܂�(�g�g�݂�RGB���ڎw��ɂ͑Ή����Ă��܂��� fill��true�ɂ���Ƙg�g�ݓ�����h��Ԃ��܂�)
		void static TextCreater(const char* contents, int x, int y, int fontSize, const char* fontColor, const char* frameColor,bool fill);
		// �w��L�����o�X�|�W�V�����Ƀe�L�X�g��\�����܂�
		void static TextCreater(const char* contents, CanvasPosition position);
		// �w��L�����o�X�|�W�V�����ɃT�C�Y���w�肵�ăe�L�X�g��\�����܂�
		void static TextCreater(const char* contents, CanvasPosition position, int fontsize);
		// ���ڎw�肳�ꂽRGB���g�p���w�胃���o�X�|�W�V�����A�T�C�Y�Ńe�L�X�g��\�����܂�
		void static TextCreater(const char* contents, CanvasPosition position, int fontSize, int red, int green, int blue);
		// �ݒ�ς݂̃t�H���g�J���[���g�p���w�胃���o�X�|�W�V�����A�T�C�Y�Ńe�L�X�g��\�����܂�
		void static TextCreater(const char* contents, CanvasPosition position, int fontSize, const char* colorName);
		// �g�g�ݕt���Ńe�L�X�g��\�����܂�(�g�g�݂�RGB���ڎw��ɂ͑Ή����Ă��܂��� fill��true�ɂ���Ƙg�g�ݓ�����h��Ԃ��܂�)
		void static TextCreater(const char* contents, CanvasPosition position, int fontSize, const char* fontColor, const char* frameColor, bool fill);
	};
}
