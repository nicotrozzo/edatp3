#include "Dibujator.h"

#define UNIDAD1 5
#define UNIDAD2 10
#define UNIDAD3 15
#define LIMPIO false
#define SUCIO true

Dibujator::Dibujator(uint h, uint w, uint nRobots)
{
	Hcount = h;
	Wcount = w;
	robotCount = nRobots;
	//inicializar allegro
	setUnit();
	display = al_create_display(w*unidad, h*unidad);
	if (display == NULL)
	{
		err
	}
}

/*Define el tamaño de cada lado en funcion del ancho y el alto*/
void Dibujator::setUnit()
{
	if (Hcount > 50 || Wcount > 35)
	{
		unidad = UNIDAD1;
	}
	else if (Hcount > 30 || Hcount > 20)
	{
		unidad = UNIDAD2;
	}
	else
	{
		unidad = UNIDAD3;
	}
}

void Dibujator::drawTile(double x, double y, bool state)
{
	if (state == true)
	{
		al_draw_scaled_bitmap( baldosaSucia, 0, 0, al_get_bitmap_width(baldosaSucia), al_get_bitmap_height(baldosaSucia), x * unidad, y * unidad, unidad, unidad, 0);
	}
	else
	{
		al_draw_scaled_bitmap( baldosaLimpia, 0, 0, al_get_bitmap_width(baldosaLimpia), al_get_bitmap_height(baldosaLimpia), x * unidad, y * unidad, unidad, unidad, 0);
	}
}

void Dibujator::drawRobot(tpos pos,double angle)
{
	al_draw_scaled_rotated_bitmap(robot, 0, 0, );
}