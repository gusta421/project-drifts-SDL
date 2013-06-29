#define offscreen -150

void update_positions(OBJETO *b)
{
	
	//atualizar a superficie BMP
	b->px += b->incx;
	b->py += b->incy;
	
	//if((b->px > (largura - b->image->w)) || (b->px < 0)) b->incx = -b->incx;
	//if((b->py > (altura - b->image->h)) || (b->py < 0)) b->incy = -b->incy;
}

