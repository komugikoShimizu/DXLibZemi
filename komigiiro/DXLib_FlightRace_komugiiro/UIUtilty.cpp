#include "UIUtilty.h"

namespace UI
{
	map<int, int> fontType;

	const char* font_Path;
	const char* font_Name;
	int path;
	void UIUtilty::UISeter()
	{

	}

	void UIUtilty::FontSeter(const char* fontName, const char* pathName)
	{
		// �t�H���g�̑��΃p�X�̖��O�𐶐� (Font/(pathName).ttf)
		string str = "Font\\";
		str += pathName;
		str += ".ttf";

		font_Path = str.c_str(); // �����������΃p�X��const Char* �^�ɕϊ�

		LPCSTR font_path = font_Path; // �ǂݍ��ރt�H���g�t�@�C���̃p�X
		if (AddFontResourceEx(font_path, FR_PRIVATE, NULL) > 0) {
		}
		else {
			// �t�H���g�Ǎ��G���[����
			MessageBox(NULL, "�t�H���g�Ǎ����s", "", MB_OK);
		}

		font_Name = fontName; // �t�H���g����ۑ����Ă���
		path = CreateFontToHandle(fontName,20,10,-1); // �t�H���g�������Ƀt�H���g�p�X�𐶐�
	}

	void UIUtilty::FontSeter(const char* fontName,const char* pathName,int fontSize,int fontThick)
	{
		// �t�H���g�̑��΃p�X�̖��O�𐶐�
		string str = "Font\\";
		str += pathName;
		str += ".ttf";

		font_Path = str.c_str(); // �����������΃p�X��const Char* �^�ɕϊ�

		LPCSTR font_path = font_Path; // �ǂݍ��ރt�H���g�t�@�C���̃p�X
		if (AddFontResourceEx(font_path, FR_PRIVATE, NULL) > 0) {
		}
		else {
			// �t�H���g�Ǎ��G���[����
			MessageBox(NULL, "�t�H���g�Ǎ����s", "", MB_OK);
		}

		font_Name = fontName; // �t�H���g����ۑ����Ă���
		path = CreateFontToHandle(fontName, fontSize, fontThick, -1); // �t�H���g�������Ƀt�H���g�p�X�𐶐�
		fontType[fontSize] = path;
	}

	void UIUtilty::FontSeter(int fontSize, int fontThick) // �t�H���g�p�X�̃t�H���g�T�C�Y�A�t�H���g�`�b�N�̂ݕύX���s��(�������ɂ͗��p�ł��Ȃ�)
	{
		path = CreateFontToHandle(font_Name,fontSize,fontThick);
		fontType[fontSize] = path;
	}

	void UIUtilty::TextCreater(const char* contents,int x,int y)
	{
		DrawFormatStringToHandle(x, y, GetColor(255, 255, 255), path, contents);
	}

	void UIUtilty::TextCreater(const char* contents, CanvasPosition position)
	{
		DrawFormatStringToHandle(position.x, position.y, GetColor(255, 255, 255), path, contents);
	}

	void UIUtilty::TextCreater(const char* contents, int x, int y, int fontsize)
	{
		SetFontSize(fontsize);
		DrawFormatStringToHandle(x, y, GetColor(255, 255, 255), fontType[fontsize], contents);
	}
}