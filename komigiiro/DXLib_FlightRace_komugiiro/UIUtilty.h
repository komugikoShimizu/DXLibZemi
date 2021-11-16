#pragma once
#include "DxLib.h"
#include "vector"
#include "string"
#include <map>

using namespace std;

struct CanvasSize
{
public:
	double x;
	double y;
};

namespace UI
{
	class UIUtilty
	{
	public:
		UIUtilty();
		inline ~UIUtilty();

		void ColorCreater(const char* colorName,int red,int green,int blue);
		void FontSeter(const char* fontName,const char* fontPath);
		void FontSeter(const char* fontName, const char* fontPath, int fontSize, int fontThick = 20);
		void FontSeter(int fontSize,int fontThick = 20);
		void CanvasSizeCreate(int maxCanvasSize);
		void TextCreater(const char* contents,int x,int y);
		void TextCreater(const char* contents, int x, int y, int fontSize);
		void TextCreater(const char* contents, int x, int y, int fontSize, int red, int green, int blue);
		void TextCreater(const char* contents, int x, int y, int fontSize, const char* fontColor);
		void TextCreater(const char* contents, int x, int y, int fontSize, const char* fontColor, const char* frameColor,bool fill);
		void TextCreater(const char* contents, CanvasSize size);
		void TextCreater(const char* contents, CanvasSize size, int fontsize);
		void TextCreater(const char* contents, CanvasSize size, int fontSize, int red, int green, int blue);
		void TextCreater(const char* contents, CanvasSize size, int fontSize, const char* colorName);
		void TextCreater(const char* contents, CanvasSize position, int fontSize, const char* fontColor, const char* frameColor, bool fill);
	private:
	};


	UIUtilty::~UIUtilty()
	{
	}
}
