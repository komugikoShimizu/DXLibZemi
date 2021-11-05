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
		int x;
		int y;
	};

	struct Object
	{

	};

	class UIUtilty
	{
	public:
		inline UIUtilty();
		inline ~UIUtilty();

		void UISeter();
		void FontSeter(const char* fontName,const char* fontPath,int sizeAmount);
		void FontSeter(const char* fontName,const char* fontPath);
		void FontSeter(const char* fontName, const char* fontPath, int fontSize, int fontThick);
		void FontSeter(int fontSize,int fontThick);
		void TextCreater(const char* contents,int x,int y);
		void TextCreater(const char* contents, CanvasPosition position);
		void TextCreater(const char* contents, int x, int y, int fontSize);
		void TextCreater(const char* contents, CanvasPosition position, int fontHandle);
		//void CanvasWrite();
		//void CanvasErase();
		//void CanvasBind();
	private:
	};

	UIUtilty::UIUtilty()
	{

	}

	UIUtilty::~UIUtilty()
	{
	}
}
