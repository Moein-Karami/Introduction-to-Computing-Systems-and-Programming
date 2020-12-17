#include "CONST_VALUES_AND_LIBRARYS.h"

void draw_circle(int x, int y, int color, int wait)
{
	setcolor(color);
	for (int i = 1;i <= CIRCLE_RAD;i++)
	{
		circle(x, y, i);
		delay(wait);/*paint the circle slowly*/
	}
}