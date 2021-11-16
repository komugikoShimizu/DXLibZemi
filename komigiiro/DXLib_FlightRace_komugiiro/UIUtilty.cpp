#include "UIUtilty.h"

namespace UI
{
	map<int, int> fontType;
	map<const char*, unsigned int> fontColor;

	const char* font_Path;
	const char* font_Name;
	int path;

	int gridSize_x;
	int gridSize_y;

	UIUtilty::UIUtilty()
	{
		fontColor["red"] = GetColor(255, 0, 0);
		fontColor["green"] = GetColor(0, 255, 0);
		fontColor["blue"] = GetColor(0, 0, 255);
		fontColor["white"] = GetColor(255, 255, 255);
		fontColor["black"] = GetColor(0, 0, 0);
		fontColor["yellow"] = GetColor(255, 255, 0);
		fontColor["cyan"] = GetColor(0, 255, 255);
		fontColor["magenta"] = GetColor(255, 0, 255);
	}

	void UIUtilty::ColorCreater(const char* colorName, int red, int green, int blue)
	{
		fontColor[colorName] = GetColor(red, green, blue);
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
		if (font_Path != NULL)
		{
			path = CreateFontToHandle(font_Name, fontSize, fontThick);
			fontType[fontSize] = path;
		}
		else
		{
			path = CreateFontToHandle(NULL, fontSize, fontThick);
			fontType[fontSize] = path;
		}
	}

	void UIUtilty::CanvasSizeCreate(int maxCanvasSize)
	{
		int colorBit;
		GetScreenState(&gridSize_x, &gridSize_y,&colorBit);

		gridSize_x = gridSize_x / maxCanvasSize;
		gridSize_y = gridSize_y / maxCanvasSize;
	}

	void UIUtilty::TextCreater(const char* contents,int x,int y) // �G�Ɏg���p�@
	{
		DrawFormatStringToHandle(x, y, fontColor["white"], path, contents);
	}

	void UIUtilty::TextCreater(const char* contents, int x, int y, int fontsize) // �t�H���g�T�C�Y�̂ݎw�肷��p
	{
		DrawFormatStringToHandle(x, y, fontColor["white"], fontType[fontsize], contents);
	}

	void UIUtilty::TextCreater(const char* contents, int x, int y, int fontSize, int red, int green, int blue) // rgb�𒼐ڎw�肷��p
	{
		DrawFormatStringToHandle(x, y, GetColor(red, green, blue), fontType[fontSize], contents);
	}

	void UIUtilty::TextCreater(const char* contents, int x, int y, int fontSize, const char* colorName) // ���ɍ쐬����Ă���J���[�^�C�v���g�p����
	{
		DrawFormatStringToHandle(x, y, fontColor[colorName], fontType[fontSize], contents);
	}

	void UIUtilty::TextCreater(const char* contents, int x, int y, int fontSize, const char* colorName, const char* frameColor,bool fill) // �g�g�݂��쐬����p
	{
		string contents_str = contents;
		int length = GetDrawStringWidthToHandle(contents, contents_str.length(), fontType[fontSize]);
		if (fill) DrawBox(x, y, x + length, y + fontSize, fontColor[frameColor], TRUE);
		else DrawBox(x, y, x + length, y + fontSize, fontColor[frameColor], FALSE);
		DrawFormatStringToHandle(x, y, fontColor[colorName], fontType[fontSize], contents);
	}

	void UIUtilty::TextCreater(const char* contents, CanvasSize size) // �G�Ɏg���p�@
	{
		DrawFormatStringToHandle(gridSize_x * size.x, gridSize_y * size.y, fontColor["white"], path, contents);
	}

	void UIUtilty::TextCreater(const char* contents, CanvasSize size, int fontsize) // �t�H���g�T�C�Y�̂ݎw�肷��p
	{
		DrawFormatStringToHandle(gridSize_x * size.x, gridSize_y * size.y, fontColor["white"], fontType[fontsize], contents);
	}

	void UIUtilty::TextCreater(const char* contents, CanvasSize size, int fontSize, int red, int green, int blue) // rgb�𒼐ڎw�肷��p
	{
		DrawFormatStringToHandle(gridSize_x * size.x, gridSize_y * size.y, GetColor(red, green, blue), fontType[fontSize], contents);
	}

	void UIUtilty::TextCreater(const char* contents, CanvasSize size, int fontSize, const char* colorName) // ���ɍ쐬����Ă���J���[�^�C�v���g�p����
	{
		DrawFormatStringToHandle(gridSize_x * size.x, gridSize_y * size.y, fontColor[colorName], fontType[fontSize], contents);
	}

	void UIUtilty::TextCreater(const char* contents, CanvasSize size, int fontSize, const char* colorName, const char* frameColor, bool fill) // �g�g�݂��쐬����悤
	{
		string contents_str = contents;
		int length = GetDrawStringWidthToHandle(contents, contents_str.length(), fontType[fontSize]);
		if (fill) DrawBox(gridSize_x * size.x, gridSize_y * size.y, gridSize_x * size.x + length, gridSize_y * size.y + fontSize, fontColor[frameColor], TRUE);
		else DrawBox(gridSize_x * size.x, gridSize_y * size.y, gridSize_x * size.x + length, gridSize_y * size.y + fontSize, fontColor[frameColor], FALSE);
		DrawFormatStringToHandle(gridSize_x * size.x, gridSize_y * size.y, fontColor[colorName], fontType[fontSize], contents);
	}
}