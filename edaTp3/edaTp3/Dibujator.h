typedef unsigned int uint;

class Dibujator
{
	uint Hcount;
	uint Wcount;
	uint robotCount;
	ALLEGRO_DISPLAY *display;
	uint unidad;
	void setUnit();
public:
	Dibujator(uint h, uint w, uint nRobots);
	draw(tpos pos);
};

