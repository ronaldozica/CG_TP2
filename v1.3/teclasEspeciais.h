// Funcao callback chamada para gerenciar eventos de teclas especiais (F1,PgDn,...)
void TeclasEspeciais (int tecla, int x, int y)
{
	switch (tecla)
	{
		case GLUT_KEY_LEFT:	

			if(flagAtualizaPos != Pause)
			{
				flagAtualizaPos = False;
			}

			rotY -= 2;

			break;

		case GLUT_KEY_RIGHT:

			if(flagAtualizaPos != Pause)
			{
				flagAtualizaPos = False;
			}

			rotY += 2;	

			break;

		case GLUT_KEY_UP:	rotX++;
							break;
		case GLUT_KEY_DOWN:	rotX--;
							break;
		case GLUT_KEY_HOME:	obsZ++;
							break;
		case GLUT_KEY_END:	obsZ--;
							break;
		case GLUT_KEY_F1:
			
			rotX = 100;
			rotY = 15;
			obsZ = 300;
				
							break;
		case GLUT_KEY_F2:	
			rotX = rotY=0;
			 obsX=obsY=0;obsZ = 180; 	
        						break;
									
	}
	PosicionaObservador();
	 /*glLoadIdentity();
	 EspecificaParametrosVisualizacao();
  	gluLookAt(obsX,obsY,obsZ, 0,0,0, 0,1,0);*/
	glutPostRedisplay();
}