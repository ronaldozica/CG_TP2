// Funcao usada para especificar a posicao do observador virtual
void PosicionaObservador(void)
{
	// Especifica sistema de coordenadas do modelo
	glMatrixMode(GL_MODELVIEW);
	// Inicializa sistema de coordenadas do modelo
	glLoadIdentity();
	
	// Especifica posicao do observador e do alvo
	//glTranslatef(0,0,-obsZ);
	glTranslatef(-obsX*0.5,-obsY*0.5,-obsZ*0.5);
	glRotatef(rotX,1,0,0);
	glRotatef(rotY,0,1,0);
}