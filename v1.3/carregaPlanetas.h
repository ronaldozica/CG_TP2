void carregaPlanetas(){

	int i;
		for( i = 1; i <10; i++)
			planetas[i] = glGenLists(i);

	//Mercurio
	glNewList(planetas[1], GL_COMPILE);
		GLUquadric *qobj = gluNewQuadric();
		gluQuadricTexture(qobj,GL_TRUE);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,text_mercurio);

		gluSphere(qobj,0.51,50,50);
		glDisable(GL_TEXTURE_2D);

	glEndList();

	//Venus
	glNewList(planetas[2], GL_COMPILE);
		gluQuadricTexture(qobj,GL_TRUE);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,text_venus);
		gluSphere(qobj,0.82,50,50);
		glDisable(GL_TEXTURE_2D);
	glEndList();
	//Terra
	glNewList(planetas[3], GL_COMPILE);
		gluQuadricTexture(qobj,GL_TRUE);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,text_terra);
		gluSphere(qobj,0.88,50,50);
		glDisable(GL_TEXTURE_2D);
	glEndList();
	//Marte
	glNewList(planetas[8], GL_COMPILE);
		gluQuadricTexture(qobj,GL_TRUE);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,text_marte);
		gluSphere(qobj,0.46,50,50);
		glDisable(GL_TEXTURE_2D);
	glEndList();
	//Jupiter
	glNewList(planetas[4], GL_COMPILE);
		gluQuadricTexture(qobj,GL_TRUE);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,text_jupiter);
		gluSphere(qobj,1.70,50,50);
		glDisable(GL_TEXTURE_2D);
	glEndList();
	//Saturno
	glNewList(planetas[5], GL_COMPILE);
		gluQuadricTexture(qobj,GL_TRUE);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,text_saturno);
		gluSphere(qobj,1.5,50,50);
		glDisable(GL_TEXTURE_2D);
	glEndList();
	//Urano
	glNewList(planetas[6], GL_COMPILE);
		gluQuadricTexture(qobj,GL_TRUE);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,text_urano);
		gluSphere(qobj,0.56,50,50);
		glDisable(GL_TEXTURE_2D);
	glEndList();
	//Netuno
	glNewList(planetas[7], GL_COMPILE);
		gluQuadricTexture(qobj,GL_TRUE);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,text_netuno);
		gluSphere(qobj,0.54,50,50);
		glDisable(GL_TEXTURE_2D);
	glEndList();

	//Fundo()
	glNewList(planetas[9], GL_COMPILE);
		gluQuadricTexture(qobj,GL_TRUE);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,idTexturaFundo);
		gluSphere(qobj,300,50,50);
		glDisable(GL_TEXTURE_2D);
	glEndList();

}