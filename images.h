OBJETO b1,b2,b3,b4,b5;

	b1.image = IMG_Load("b1.png"); 
	b1.k = 1;
	if (!b1.image)	
	{
		printf("Nao consegui carregar imagem b1.png\n");  		exit(ERRO);
	}

	b2.image = IMG_Load("b2.png");
	b2.k = 2;
	if (!b2.image)	
	{
		printf("Nao consegui carregar imagem b2.png\n");  		exit(ERRO);
	}	

	
	b3.image = IMG_Load("b3.png"); 
	b3.k = 3;
	if (!b3.image)	
	{
		printf("Nao consegui carregar imagem b3.png\n");  		exit(ERRO);
	}	


	b4.image = IMG_Load("b4.png"); 
	b4.k = 4;	
	if (!b4.image)	
	{
		printf("Nao consegui carregar imagem b4.png\n");  		exit(ERRO);
	}	

	b5.k = rand() %5 -1;

	if (b5.k == b1.k){ b5.image = b1.image;}
	if (b5.k == b2.k){ b5.image = b2.image;}
	if (b5.k == b3.k){ b5.image = b3.image;}
	if (b5.k == b4.k){ b5.image = b4.image;}
