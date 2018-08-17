#include "Dibujator.h"

#define UNIDAD1 5
#define UNIDAD2 10
#define UNIDAD3 15
#define LIMPIO false
#define SUCIO true
#define SCALE 0.5

using namespace std;

Dibujator::Dibujator(uint h, uint w, uint nRobots)
{
	Hcount = h;
	Wcount = w;
	robotCount = nRobots;
	error.errNum = NO_ERROR;
	//inicializar allegro
	setUnit();
	initializeAllegro();
}

void Dibujator::initializeAllegro()
{
	baldosaLimpia = al_load_bitmap("baldosa_limpia.png");
	if(baldosaLimpia != NULL)
	{
		baldosaSucia = al_load_bitmap("baldosa_sucia.png");
		if (baldosaSucia != NULL)
		{
			robot = al_load_bitmap("robot.png");
			if (robot != NULL)
			{
				display = al_create_display(w*unidad, h*unidad);
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
					cout << "No se pudo crear el display" << endl;
				}
			}
			else
			{
				al_destroy_bitmap(baldosaLimpia);
				al_destroy_bitmap(baldosaSucia);
				error.errNum = BITMAP_ERR;
				cout << "Error al cargar robot.png" << endl;
			}
		}
		else
		{
			al_destroy_bitmap(baldosaLimpia);
			error.errNum = BITMAP_ERR;
			cout << "Error al cargar baldosa_sucia.png" << endl;
		}
	else
	{
		error.errNum = BITMAP_ERR;
		cout << "Error al cargar baldosa_limpia.png" << endl;
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
	al_draw_scaled_rotated_bitmap(robot, 0, 0, pos.x * unidad, pos.y * unidad, SCALE, SCALE, angle, 0);
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