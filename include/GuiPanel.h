#pragma once

#include "GuiItem.h"

enum PanelFlag
{
	PanelFlag_None = 0,
	PanelFlag_Decorated = 1 << 0,
	PanelFlag_TitleBar = 1 << 1,


};

class GuiPanel : public GuiItem
{

public:

	std::string m_titleStr;
	uint8_t m_flags;
	uint8_t m_r, m_g, m_b;
	GuiItem* m_title;

	GuiPanel(int x, int y, int width, int height);

	void activated() override;

	void drawNormal(IRender2d* r) override;

};