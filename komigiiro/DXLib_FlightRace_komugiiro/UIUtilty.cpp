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