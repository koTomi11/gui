#include "GuiPanel.h"

#include "GuiContext.h"

GuiPanel::GuiPanel(int x, int y, int width, int height) : GuiItem(x, y, width, height)
{

	m_r = 200; m_g = 200; m_b = 200;
	m_flags = PanelFlag_Decorated;

	if ((m_flags & PanelFlag_Decorated) != 0) {
		m_titleStr = "bazdmeg";
	}

}

void GuiPanel::activated()
{
	GuiContext::ACTIVATED = this;
}

void GuiPanel::drawNormal(IRender2d* r)
{

	r->setColor(m_r, m_g, m_b);
	r->setPos(m_x, m_y);

	r->fillRect(0, 0, m_width, m_height);


	if ((m_flags & PanelFlag_Decorated) != 0) {
		
		r->setColor(50, 50, 50);
		r->fillRect(0, 0, m_width, 30);

		r->setLineWidth(2);
		r->drawRect(0, 30, m_width, m_height - 30);

		r->setColor(255, 255, 255);
		r->drawString(30, 22, m_titleStr);

	}


}