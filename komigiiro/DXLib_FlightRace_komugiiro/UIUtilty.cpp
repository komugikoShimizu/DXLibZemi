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
		// フォントの相対パスの名前を生成 (Font/(pathName).ttf)
		string str = "Font\\";
		str += pathName;
		str += ".ttf";

		font_Path = str.c_str(); // 生成した相対パスをconst Char* 型に変換

		LPCSTR font_path = font_Path; // 読み込むフォントファイルのパス
		if (AddFontResourceEx(font_path, FR_PRIVATE, NULL) > 0) {
		}
		else {
			// フォント読込エラー処理
			MessageBox(NULL, "フォント読込失敗", "", MB_OK);
		}

		font_Name = fontName; // フォント名を保存しておく
		path = CreateFontToHandle(fontName,20,10,-1); // フォント名を元にフォントパスを生成
	}

	void UIUtilty::FontSeter(const char* fontName,const char* pathName,int fontSize,int fontThick)
	{
		// フォントの相対パスの名前を生成
		string str = "Font\\";
		str += pathName;
		str += ".ttf";

		font_Path = str.c_str(); // 生成した相対パスをconst Char* 型に変換

		LPCSTR font_path = font_Path; // 読み込むフォントファイルのパス
		if (AddFontResourceEx(font_path, FR_PRIVATE, NULL) > 0) {
		}
		else {
			// フォント読込エラー処理
			MessageBox(NULL, "フォント読込失敗", "", MB_OK);
		}

		font_Name = fontName; // フォント名を保存しておく
		path = CreateFontToHandle(fontName, fontSize, fontThick, -1); // フォント名を元にフォントパスを生成
		fontType[fontSize] = path;
	}

	void UIUtilty::FontSeter(int fontSize, int fontThick) // フォントパスのフォントサイズ、フォントチックのみ変更を行う(初期化には利用できない)
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

	void UIUtilty::TextCreater(const char* contents,int x,int y) // 雑に使う用　
	{
		DrawFormatStringToHandle(x, y, fontColor["white"], path, contents);
	}

	void UIUtilty::TextCreater(const char* contents, int x, int y, int fontsize) // フォントサイズのみ指定する用
	{
		DrawFormatStringToHandle(x, y, fontColor["white"], fontType[fontsize], contents);
	}

	void UIUtilty::TextCreater(const char* contents, int x, int y, int fontSize, int red, int green, int blue) // rgbを直接指定する用
	{
		DrawFormatStringToHandle(x, y, GetColor(red, green, blue), fontType[fontSize], contents);
	}

	void UIUtilty::TextCreater(const char* contents, int x, int y, int fontSize, const char* colorName) // 既に作成されているカラータイプを使用する
	{
		DrawFormatStringToHandle(x, y, fontColor[colorName], fontType[fontSize], contents);
	}

	void UIUtilty::TextCreater(const char* contents, int x, int y, int fontSize, const char* colorName, const char* frameColor,bool fill) // 枠組みを作成する用
	{
		string contents_str = contents;
		int length = GetDrawStringWidthToHandle(contents, contents_str.length(), fontType[fontSize]);
		if (fill) DrawBox(x, y, x + length, y + fontSize, fontColor[frameColor], TRUE);
		else DrawBox(x, y, x + length, y + fontSize, fontColor[frameColor], FALSE);
		DrawFormatStringToHandle(x, y, fontColor[colorName], fontType[fontSize], contents);
	}

	void UIUtilty::TextCreater(const char* contents, CanvasSize size) // 雑に使う用　
	{
		DrawFormatStringToHandle(gridSize_x * size.x, gridSize_y * size.y, fontColor["white"], path, contents);
	}

	void UIUtilty::TextCreater(const char* contents, CanvasSize size, int fontsize) // フォントサイズのみ指定する用
	{
		DrawFormatStringToHandle(gridSize_x * size.x, gridSize_y * size.y, fontColor["white"], fontType[fontsize], contents);
	}

	void UIUtilty::TextCreater(const char* contents, CanvasSize size, int fontSize, int red, int green, int blue) // rgbを直接指定する用
	{
		DrawFormatStringToHandle(gridSize_x * size.x, gridSize_y * size.y, GetColor(red, green, blue), fontType[fontSize], contents);
	}

	void UIUtilty::TextCreater(const char* contents, CanvasSize size, int fontSize, const char* colorName) // 既に作成されているカラータイプを使用する
	{
		DrawFormatStringToHandle(gridSize_x * size.x, gridSize_y * size.y, fontColor[colorName], fontType[fontSize], contents);
	}

	void UIUtilty::TextCreater(const char* contents, CanvasSize size, int fontSize, const char* colorName, const char* frameColor, bool fill) // 枠組みを作成するよう
	{
		string contents_str = contents;
		int length = GetDrawStringWidthToHandle(contents, contents_str.length(), fontType[fontSize]);
		if (fill) DrawBox(gridSize_x * size.x, gridSize_y * size.y, gridSize_x * size.x + length, gridSize_y * size.y + fontSize, fontColor[frameColor], TRUE);
		else DrawBox(gridSize_x * size.x, gridSize_y * size.y, gridSize_x * size.x + length, gridSize_y * size.y + fontSize, fontColor[frameColor], FALSE);
		DrawFormatStringToHandle(gridSize_x * size.x, gridSize_y * size.y, fontColor[colorName], fontType[fontSize], contents);
	}
}