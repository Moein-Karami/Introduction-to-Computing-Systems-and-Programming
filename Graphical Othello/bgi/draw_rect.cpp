#include "CONST_VALUES_AND_LIBRARYS.h"
#include "draw.h"
void draw_rect(int x, int y, int color)
{
	setcolor(color);
	rectangle(x, y, x + RECT_SIZE, y + RECT_SIZE);
	setfillstyle(SOLID_FILL, color);
	floodfill(x+2, y+2, color);/*paint inside the rectangle*/
}