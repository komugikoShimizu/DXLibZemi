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
		// 基礎的な色のセットを作成します
		// ※red green blue cyan magenta yellow black white
		void static ColorCreater();
		// 設定した色情報を文字列で引き出せるようにします
		void static ColorCreater(const char* colorName,int red,int green,int blue); 
		// 使用フォントのみを設定します
		void static FontSeter(const char* fontName,const char* fontPath); 
		// 使用フォントの設定を行ったのち、設定されたフォントサイズを作成します
		void static FontSeter(const char* fontName, const char* fontPath, int fontSize, int fontThick = 20);
	    // デフォルトフォントでフォントサイズを作成します
		void static FontSeter(int fontSize,int fontThick = 20);
		// 入力されたキャンバスサイズを作成します
		void static CanvasSizeCreate(int maxCanvasSize);
		// 指定座標にテキストを表示します
		void static TextCreater(const char* contents,int x,int y);
		// 指定座標にサイズを指定してテキストを表示します
		void static TextCreater(const char* contents, int x, int y, int fontSize);
		// 直接指定されたRGBを使用し指定座標、サイズでテキストを表示します
		void static TextCreater(const char* contents, int x, int y, int fontSize, int red, int green, int blue);
		// 設定済みのフォントカラーを使用し指定座標、サイズでテキストを表示します
		void static TextCreater(const char* contents, int x, int y, int fontSize, const char* fontColor);
		// 枠組み付きでテキストを表示します(枠組みのRGB直接指定には対応していません fillをtrueにすると枠組み内部を塗りつぶします)
		void static TextCreater(const char* contents, int x, int y, int fontSize, const char* fontColor, const char* frameColor,bool fill);
		// 指定キャンバスポジションにテキストを表示します
		void static TextCreater(const char* contents, CanvasPosition position);
		// 指定キャンバスポジションにサイズを指定してテキストを表示します
		void static TextCreater(const char* contents, CanvasPosition position, int fontsize);
		// 直接指定されたRGBを使用し指定ャンバスポジション、サイズでテキストを表示します
		void static TextCreater(const char* contents, CanvasPosition position, int fontSize, int red, int green, int blue);
		// 設定済みのフォントカラーを使用し指定ャンバスポジション、サイズでテキストを表示します
		void static TextCreater(const char* contents, CanvasPosition position, int fontSize, const char* colorName);
		// 枠組み付きでテキストを表示します(枠組みのRGB直接指定には対応していません fillをtrueにすると枠組み内部を塗りつぶします)
		void static TextCreater(const char* contents, CanvasPosition position, int fontSize, const char* fontColor, const char* frameColor, bool fill);
	};
}
