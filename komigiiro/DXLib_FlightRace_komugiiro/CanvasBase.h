#pragma once

enum UIType
{
	TEXT,
	SPRITE,
	UI,
	COUNT,
	NONE
};

class CanvasBase
{
public:
	virtual void CanvasWrite() = 0;
	virtual void CanvasErase() = 0;
	virtual void CanvasBind() = 0;
private:
	UIType uiType = NONE;
};