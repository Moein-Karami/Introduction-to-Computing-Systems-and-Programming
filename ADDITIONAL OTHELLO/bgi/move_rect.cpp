#include "CONST_VALUES_AND_LIBRARYS.h"
#include "draw.h"
void move_rect(int x, int y, int final_x, int final_y ,int first_color,int final_color)
{
	int first_circle_x = x + RECT_SIZE / 2, first_circle_y = y + RECT_SIZE / 2,
		final_circle_x = final_x + RECT_SIZE / 2, final_circle_y = final_y + RECT_SIZE / 2;
	int i, j,speed=5;/*speed is for moving rectangle faster*/
	while(x!=final_x)/*harkat ogoghi*/
	{
		draw_rect(x, y, MY_LIGHT_BLUE);/*hamrang kardan mostatil ba pas zamine*/
		draw_circle(first_circle_x, first_circle_y, first_color, 0);/*baz sazi dayere avalie*/
		draw_circle(final_circle_x, final_circle_y, final_color, 0);/*baz sazi dayere maghsad*/
		if (x < final_x)
			x+=speed;
		else
			x-=speed;
		draw_rect(x, y, RED);
	}
	while (y != final_y)/*harkat amoodi*/
	{
		draw_rect(x, y, MY_LIGHT_BLUE);/*hamrang kardan mostatil ba pas zamine*/
		draw_circle(first_circle_x, first_circle_y, first_color, 0);/*baz sazi dayere avalie*/
		draw_circle(final_circle_x, final_circle_y, final_color, 0);/*baz sazi dayere maghsad*/
		if (y < final_y)
			y+=speed;
		else
			y-=speed;
		draw_rect(x, y, RED);
	}
}