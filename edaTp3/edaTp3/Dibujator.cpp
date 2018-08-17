#include "Dibujator.h"

#define UNIDAD1 5
#define UNIDAD2 10
#define UNIDAD3 15

Dibujator::Dibujator(uint h, uint w, uint nRobots)
{
	Hcount = h;
	Wcount = w;
	robotCount = nRobots;
	//inicializar allegro
	setUnit();
	display = al_create_display(w*unidad, h*unidad);
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

void Dibujator::draw(tpos pos)
{


}



