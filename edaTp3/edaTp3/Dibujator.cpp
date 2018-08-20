#include "Dibujator.h"
#include <allegro5/allegro_image.h>

#define UNIDAD1 20
#define UNIDAD2 25
#define UNIDAD3 30
#define LIMPIO false
#define SUCIO true
#define SCALE 0.5

Dibujator::Dibujator(uint h, uint w, uint nRobots, uint mode)
{
	Hcount = h;
	Wcount = w;
	robotCount = nRobots;
	error.errNum = NO_ERROR;
	setUnit();
	if (mode == 1)	//si esta en el modo 2 no necesita cargar los bitmaps
	{
		initializeAllegro();
	}
}

void Dibujator::initializeAllegro()
{
	baldosaLimpia = al_load_bitmap("baldosa_limpia.png");
	if (baldosaLimpia != NULL)
	{
		baldosaSucia = al_load_bitmap("baldosa_sucia.png");
		if (baldosaSucia != NULL)
		{
			robot = al_load_bitmap("robot.png");
			if (robot != NULL)
			{
				display = al_create_display(Wcount*unidad, Hcount*unidad);
				if (display != NULL)
				{
					error.errNum = NO_ERROR;
				}
				else
				{
					al_destroy_bitmap(baldosaLimpia);
					al_destroy_bitmap(baldosaSucia);
					al_destroy_bitmap(robot);
					error.errNum = DISPLAY_ERR;
					error.detail = "No se pudo crear el display\n";
				}
			}
			else
			{
				al_destroy_bitmap(baldosaLimpia);
				al_destroy_bitmap(baldosaSucia);
				error.errNum = BITMAP_ERR;
				error.detail = "Error al cargar robot.png\n";
			}
		}
		else
		{
			al_destroy_bitmap(baldosaLimpia);
			error.errNum = BITMAP_ERR;
			error.detail = "Error al cargar baldosa_sucia.png\n";
		}
	}
	else
	{
		error.errNum = BITMAP_ERR;
		error.detail = "Error al cargar baldosa_limpia.png\n";
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
	if (state == LIMPIO)
	{
		al_draw_scaled_bitmap(baldosaLimpia, 0, 0, al_get_bitmap_width(baldosaLimpia), al_get_bitmap_height(baldosaLimpia), x * unidad, y * unidad, unidad, unidad, 0);
	}
	else
	{
		al_draw_scaled_bitmap(baldosaSucia, 0, 0, al_get_bitmap_width(baldosaSucia), al_get_bitmap_height(baldosaSucia), x * unidad, y * unidad, unidad, unidad, 0);
	}
}

void Dibujator::drawRobot(tpos pos,double angle)
{
	float xscale = unidad/(float)al_get_bitmap_width(robot);
	float yscale = unidad/(float)al_get_bitmap_height(robot);
	al_draw_scaled_rotated_bitmap(robot, 0, 0, pos.x * unidad, pos.y * unidad, xscale/2, yscale/2, angle, 0);
}

void Dibujator::destroy()
{
	if (display != NULL)
	{
		al_destroy_display(display);
	}
	if (baldosaLimpia != NULL)
	{
		al_destroy_bitmap(baldosaLimpia);
	}
	if (baldosaSucia != NULL)
	{
		al_destroy_bitmap(baldosaSucia);
	}
	if (robot != NULL)
	{
		al_destroy_bitmap(robot);
	}
}

errorType Dibujator::getError()
{
	return error;
}