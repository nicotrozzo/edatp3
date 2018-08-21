#include "Header.h"
#include "Simulation.h"

ALLEGRO_DISPLAY* show(uint tickCount, ALLEGRO_FONT *font);

int main(int argc, char *argv[])
{
	alData_t al_data;
	userData user_data;
	int result;
	if (init_allegro(&al_data))
	{
		if ((result = parseCmdLine(argc, argv, parseCallback, &user_data)) > 0)
		{
			if (user_data.mode == 1)
			{
				Simulation sim(user_data.amountOfRobots, user_data.mode, user_data.width, user_data.height);
				uint tickCount = sim.simulate();
				sim.destroy();
				ALLEGRO_DISPLAY *display = show(tickCount,al_data.font);
				if (display != NULL)
				{
					al_rest(5);
					al_destroy_display(display);
				}
			}
			else
			{
				ALLEGRO_DISPLAY *display = al_create_display(M2_DIS_WIDTH, M2_DIS_HEIGHT);
				drawAxis();
				double tickCount[10000];
				bool listo = false;
				for (int n = 1; !listo; n++)
				{
					tickCount[n - 1] = 0;
					for (uint i = 0; i < 1000; i++)
					{
						Simulation sim(n, user_data.mode, user_data.width, user_data.height);
						tickCount[n - 1] += sim.simulate();
						sim.destroy();
					}
					tickCount[n - 1] /= 1000.0;
					drawHistogram(tickCount[n - 1], n,al_data.font);
					if (n > 1)
					{
						listo = (abs(tickCount[n - 2] - tickCount[n - 1]) <= .1);
					}
				}
			}
		}
		else
		{
			cout << "La informacion no fue ingresada de la manera esperada.\n";
			how_to_use(result);
			al_rest(10.0);
		}
	}
	else
	{
		cout << al_data.errDetail;
	}
	return 0;
}

/*Devuelve 1 si se inicializo todo bien, 0 sino
Si hay error queda guardado en al_data->error, y el detalle en al_data->errDetail*/
bool init_allegro(alData_t *al_data)
{
	bool ret = 1;
	if (al_init())
	{
		if (al_init_primitives_addon())
		{
			if (al_init_font_addon())
			{
				if (al_init_ttf_addon())
				{
					al_data->font = al_load_ttf_font("disney.ttf", FONT_SIZE, 0);
					if (al_data->font != NULL)
					{
						if (al_init_image_addon())
						{
							ret = 1;
						}
						else
						{
							ret = 0;
							al_destroy_font(al_data->font);
						}
					}
					else
					{
						ret = 0;
						al_data->error = INIT_IMAGE;
						al_data->errDetail = "No se pudo inicializar el image addon\n";
					}
				}
				else
				{
					ret = 0;
					al_data->error = INIT_TTF;
					al_data->errDetail = "No se pudo inicializar el TTF addon\n";
				}
			}
			else
			{
				ret = 0;
				al_data->error = INIT_FONT;
				al_data->errDetail = "No se pudo inicializar el font addon\n";
			}
		}
		else
		{
			ret = 0;
			al_data->error = INIT_PRIM;
			al_data->errDetail = "No se pudo inicializar el addon de primitives\n";
		}
	}
	else
	{
		ret = 0;
		al_data->error = AL_INIT;
		al_data->errDetail = "No se pudo inicializar allegro\n";
	}
	return ret;
}

/*Dibuja los ejes coordenados*/
void drawAxis(void)
{
	al_clear_to_color(al_map_rgb(255, 255, 255));	//display en blanco
	al_draw_line(0,M2_DIS_HEIGHT - INIT_SEPARATION, M2_DIS_WIDTH-5, M2_DIS_HEIGHT - INIT_SEPARATION,al_map_rgb(0,0,0),0);	//eje x
	al_draw_line(M2_DIS_WIDTH - 5, M2_DIS_HEIGHT - INIT_SEPARATION, M2_DIS_WIDTH - 10, M2_DIS_HEIGHT - INIT_SEPARATION - 3, al_map_rgb(0, 0, 0), 0);	//flecha en la punta del eje
	al_draw_line(M2_DIS_WIDTH - 5, M2_DIS_HEIGHT - INIT_SEPARATION, M2_DIS_WIDTH - 10, M2_DIS_HEIGHT - INIT_SEPARATION + 3, al_map_rgb(0, 0, 0), 0);
	al_draw_line(INIT_SEPARATION, M2_DIS_HEIGHT , INIT_SEPARATION, 5, al_map_rgb(0, 0, 0), 0);	//eje y
	al_draw_line(INIT_SEPARATION, 5, 7, 10, al_map_rgb(0, 0, 0), 0);	//flecha en la punta del eje
	al_draw_line(INIT_SEPARATION, 5, 13, 10, al_map_rgb(0, 0, 0), 0);	
	al_flip_display();
}

/*Dibuja una barra para el valor de n dado y escribe un valor para la escala sobre el eje y*/
void drawHistogram(double tickCount, int n, ALLEGRO_FONT* font)
{
	al_draw_line(INIT_SEPARATION + n * 10, M2_DIS_HEIGHT - INIT_SEPARATION, INIT_SEPARATION + n * 10, M2_DIS_HEIGHT - INIT_SEPARATION - tickCount * SCALE, al_map_rgb(255,0,0), 8);	//grafico de barra
	al_draw_textf(font, al_map_rgb(0,0,0), INIT_SEPARATION , M2_DIS_HEIGHT - INIT_SEPARATION - tickCount * SCALE, ALLEGRO_ALIGN_CENTER, "%dK", floor(tickCount/1000.0) );
	al_flip_display();
}

/*Devuelve NULL si hubo error al abrir el display o al cargar la fuente*/
ALLEGRO_DISPLAY* show(uint tickCount, ALLEGRO_FONT *font)
{
	ALLEGRO_DISPLAY* display = al_create_display(DIS_X, DIS_Y);
	if (display != NULL)
	{
		al_draw_textf(font, al_map_rgb(255, 0, 0), DIS_X / 2, DIS_Y / 2, ALLEGRO_ALIGN_CENTRE, "Simulacion terminada. Tickcount: %d",tickCount);
		al_flip_display();
	}
	return display;
}