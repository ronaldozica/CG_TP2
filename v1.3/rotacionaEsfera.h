void rotacionaEsfera(){

	if(flagAtualizaPos == True)
	{
		a += .05f;
	}

	if(flagAtualizaPos == False)
	{
		flagAtualizaPos = True;
	}

	glutPostRedisplay();
}