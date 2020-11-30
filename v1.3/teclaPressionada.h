void TeclaPressionada(unsigned char key, int x, int y)
{
    switch(key)
    {
	    case 27:	// ESC
	    	exit(0);
	    	break;

	    case 32:	// BARRA DE ESPACO

	    	if(flagAtualizaPos == Pause)
	    	{
	    		flagAtualizaPos = True;
	    	}

	    	else
	    	{
	    		flagAtualizaPos = Pause;
	    	}

	    	break;	
		case 'c':
			verificaIluminacao *=-1;
			break;
	}
}