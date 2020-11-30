// Funcao callback chamada para fazer o desenho
void Desenha(void)
{

	// Limpa a janela de visualizacao com a cor
	// de fundo definida previamente
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glColor3f(1, 1, 1);

	//Desenha Fundo
	glPushMatrix();
		glRasterPos2f(0,-2.8);
		
		glBindTexture(GL_TEXTURE_2D,idTexturaFundo);
		glTranslated(0,0,0);
		glCallList(planetas[9]);
	glPopMatrix();

	//Desenha o Sol
	GLUquadric *qobj = gluNewQuadric();
	gluQuadricTexture(qobj,GL_TRUE);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,text_sol);
	glPushMatrix();
	glTranslated(0,0,0);
	glRotated(-2.5*a, 0, 1, 0);
	glRotatef(90, -1, 0, 0);

		gluSphere(qobj,3.52,100,100);
		if(verificaIluminacao ==1){
	
			DefineIluminacao();
			glEnable(GL_LIGHT0);
		} else{
			glDisable(GL_LIGHT0);
		}	
		
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);

 
	DefineIluminacao();
	//Desenha Mercurio
	glPushMatrix();
		glRasterPos2f(0,-2.8);
		glBindTexture(GL_TEXTURE_2D,text_mercurio);
		glTranslated(6*-cos(a*0.3),0, 6*-sin(a*0.3));
		glRotated(-20*a, 0, 1, 0);
		glRotatef(90, -1, 0, 0);
		glCallList(planetas[1]);
	glPopMatrix();

	//Desenha Venus
	glPushMatrix();
		
		glRasterPos2f(0,-2.8);
		glBindTexture(GL_TEXTURE_2D,text_venus);
		glTranslated(10*-cos(a*0.1),0, 10*-sin(a*0.1));
		glRotated(-20*a, 0, 1, 0);
		glRotatef(90, -1, 0, 0);
		glCallList(planetas[2]);
	glPopMatrix();
 
	//Terra
	glPushMatrix();
		glRasterPos2f(0,-2.8);
		glBindTexture(GL_TEXTURE_2D,text_terra);
		glTranslated(20*-cos(a*0.088),0, 20*-sin(a*0.088));
		glRotated(-20*a, 0, 1, 0);
        glRotatef(90, -1, 0, 0);
		glCallList(planetas[3]);
	glPopMatrix();

	//Marte
	glPushMatrix();
		glRasterPos2f(0,-2.8);
		glBindTexture(GL_TEXTURE_2D,text_marte);
		glTranslated(35*-cos(a*0.040),0, 35*-sin(a*0.040));
		glRotated(-20*a, 0, 1, 0);
		glRotatef(90, -1, 0, 0);
		glCallList(planetas[8]);
	glPopMatrix();
	
	//Jupiter
	glPushMatrix();
		glRasterPos2f(0,-2.8);
		glBindTexture(GL_TEXTURE_2D,text_jupiter);
		glTranslated(45*-cos(a*0.035),0, 45*-sin(a*0.035));
		glRotated(-20*a, 0, 1, 0);
		glRotatef(90, -1, 0, 0);
		glCallList(planetas[4]);
	glPopMatrix();
	
	//Saturno
	glPushMatrix();
		glRasterPos2f(0,-2.8);
		glBindTexture(GL_TEXTURE_2D,text_saturno);
		glTranslated(55*-cos(a*0.027),0,55*-sin(a*0.027));
		glRotated(-20*a, 0, 1, 0);
		glRotatef(90, -1, 0, 0);
		glCallList(planetas[5]);
	glPopMatrix();
	
	//Urano
	glPushMatrix();
		glRasterPos2f(0,-2.8);
		glBindTexture(GL_TEXTURE_2D,text_urano);
		glTranslated(65*-cos(a*0.02),0, 65*-sin(a*0.02));
		glRotated(-20*a, 0, 1, 0);
		glRotatef(90, -1, 0, 0);
		glCallList(planetas[6]);
	glPopMatrix();
	
	//Netuno
	glPushMatrix();
		glRasterPos2f(0,-2.8);
		glBindTexture(GL_TEXTURE_2D,text_netuno);
		glTranslated(75*-cos(a*0.01),0, 75*-sin(a*0.01));
		glRotated(-20*a, 0, 1, 0);
		glRotatef(90, -1, 0, 0);
		glCallList(planetas[7]);
	glPopMatrix();

	// Execucao dos comandos de desenho
	glutSwapBuffers();
}