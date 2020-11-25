
// TP2 - Sistema Solar
//
// Alunos:
// Násser Rafael França Kilesse
// Ronaldo Mendonça Zica
// Vitor Nelis Santana
//
// Professor:
// Glender
//

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
#include <SOIL/SOIL.h>
#include <GL/freeglut.h>

#define SOL "sol.png"
#define VENUS "venus.png"
#define MERCURIO "mercurio.png"

GLfloat angle, fAspect, rotX, rotY;
GLdouble obsX, obsY, obsZ;

GLuint  text_sol;
GLuint  text_mercurio;
GLuint  text_venus;
GLuint  text_terra;
GLuint  text_marte;
GLuint  text_netuno;
GLuint  text_jupiter;
GLuint  text_saturno;
GLuint  text_urano;
GLuint  idTexturaFundo; 

GLfloat R , G , B;
GLint especMaterial;
GLuint planetas[15];
int movimento = 1;
int verificaIluminacao = 1;
double a =0;

typedef enum {False, True, Pause} flag;
flag flagAtualizaPos;

GLuint carregaTextura(const char* arquivo) {
      GLuint idTextura = SOIL_load_OGL_texture(arquivo,SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);

      if (idTextura == 0) {
          printf("Erro do SOIL: '%s'\n", SOIL_last_result());
      }

      return idTextura;
}

void inicializaTexturas(){

	text_sol = carregaTextura(SOL);
	text_venus = carregaTextura(VENUS);
	text_mercurio = carregaTextura(MERCURIO);
	text_urano = carregaTextura("urano.png");
	text_netuno = carregaTextura("netuno.png");
	text_saturno = carregaTextura("saturno.png");
	text_terra = carregaTextura("terra.png");
	text_jupiter = carregaTextura("jupiter.png");
	text_marte = carregaTextura("marte.png");
	idTexturaFundo = carregaTextura("galaxia.png");

}


// Função responsável pela especificação dos parâmetros de iluminação
void DefineIluminacao (void)
{
        GLfloat luzAmbiente[4]={0.4,0.4,0.4,1.0}; 
        GLfloat luzDifusa[4]={0.7,0.7,0.7,1.0};          // "cor" 
        GLfloat luzEspecular[4]={1.0, 1.0,1.0, 1.0};// "brilho" 
        GLfloat posicaoLuz[4]={0.0, 50.0, 50.0, 1.0};
 
        // Capacidade de brilho do material
        GLfloat especularidade[4]={1.0,1.0,1.0,1.0}; 
        GLint especMaterial = 60 ;
 
        // Define a refletância do material 
        glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade);
        //Define a concentração do brilho
        glMateriali(GL_FRONT,GL_SHININESS,especMaterial);
 
        // Ativa o uso da luz ambiente 
        glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);
 
        // Define os parâmetros da luz de número 0
        glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente); 
        glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa );
        glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular );
        glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz );   
}

void carregaPlanetas(){

	int i;
		for( i = 1; i <9; i++)
			planetas[i] = glGenLists(i);

		
	glNewList(planetas[1], GL_COMPILE);
		GLUquadric *qobj = gluNewQuadric();
		gluQuadricTexture(qobj,GL_TRUE);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,text_mercurio);

		gluSphere(qobj,0.48,50,50);
		glDisable(GL_TEXTURE_2D);

	glEndList();


	glNewList(planetas[2], GL_COMPILE);
		gluQuadricTexture(qobj,GL_TRUE);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,text_venus);
		gluSphere(qobj,0.85,50,50);
		glDisable(GL_TEXTURE_2D);
	glEndList();

	glNewList(planetas[3], GL_COMPILE);
		gluQuadricTexture(qobj,GL_TRUE);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,text_terra);
		gluSphere(qobj,0.48,50,50);
		glDisable(GL_TEXTURE_2D);
	glEndList();

	glNewList(planetas[8], GL_COMPILE);
		gluQuadricTexture(qobj,GL_TRUE);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,text_marte);
		gluSphere(qobj,0.48,50,50);
		glDisable(GL_TEXTURE_2D);
	glEndList();

	glNewList(planetas[4], GL_COMPILE);
		gluQuadricTexture(qobj,GL_TRUE);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,text_jupiter);
		gluSphere(qobj,0.48,50,50);
		glDisable(GL_TEXTURE_2D);
	glEndList();

	glNewList(planetas[5], GL_COMPILE);
		gluQuadricTexture(qobj,GL_TRUE);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,text_saturno);
		gluSphere(qobj,0.48,50,50);
		glDisable(GL_TEXTURE_2D);
	glEndList();

	glNewList(planetas[6], GL_COMPILE);
		gluQuadricTexture(qobj,GL_TRUE);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,text_urano);
		gluSphere(qobj,0.48,50,50);
		glDisable(GL_TEXTURE_2D);
	glEndList();

	glNewList(planetas[7], GL_COMPILE);
		gluQuadricTexture(qobj,GL_TRUE);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,text_netuno);
		gluSphere(qobj,0.48,50,50);
		glDisable(GL_TEXTURE_2D);
	glEndList();


}

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

// Função callback chamada para fazer o desenho
void Desenha(void)
{
	glDrawBuffer(GL_BACK);
	// Limpa a janela de visualização com a cor
	// de fundo definida previamente
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	//Desenha o SOl
	GLUquadric *qobj = gluNewQuadric();
	gluQuadricTexture(qobj,GL_TRUE);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,text_sol);
	glPushMatrix();
		glRotated(30, 0, 0, 1);
		gluSphere(qobj,1.39,25,25);
	glPopMatrix();
	//gluDeleteQuadric(qobj);
	glDisable(GL_TEXTURE_2D);

	//DesenhaMercurio
	glPushMatrix();
		glRasterPos2f(0,-2.8);
		glBindTexture(GL_TEXTURE_2D,text_mercurio);
		glTranslated(-6*-cos(a*0.1),0, -6*-sin(a*0.1));
		glRotated(-20*a, 0, 0, 1);
		glCallList(planetas[1]);
	glPopMatrix();

	//Desenha Venus
	glPushMatrix();
		
		glRasterPos2f(0,-1.9);
		glBindTexture(GL_TEXTURE_2D,text_venus);
		glTranslated(-3*-cos(a*0.1),0, -3*-sin(a*0.1));
		glRotated(-20*a, 0, 0, 1);
		glCallList(planetas[2]);
	glPopMatrix();

	//Terra
	glPushMatrix();
		glRasterPos2f(0,-2.8);
		glBindTexture(GL_TEXTURE_2D,text_terra);
		glTranslated(6*-cos(a*0.1),0, 6*-sin(a*0.1));
		glRotated(-20*a, 0, 0, 1);
		glCallList(planetas[3]);
	glPopMatrix();

	//Marte
	glPushMatrix();
		glRasterPos2f(0,-2.8);
		glBindTexture(GL_TEXTURE_2D,text_marte);
		glTranslated(3*-cos(a*0.1),0, 3*-sin(a*0.1));
		glRotated(-20*a, 0, 0, 1);
		glCallList(planetas[8]);
	glPopMatrix();
	
	//Jupiter
	glPushMatrix();
		glRasterPos2f(0,-2.8);
		glBindTexture(GL_TEXTURE_2D,text_jupiter);
		glTranslated(9*-cos(a*0.1),0, 9*-sin(a*0.1));
		glRotated(-20*a, 0, 0, 1);
		glCallList(planetas[4]);
	glPopMatrix();
	
	//Saturno
	glPushMatrix();
		glRasterPos2f(0,-2.8);
		glBindTexture(GL_TEXTURE_2D,text_saturno);
		glTranslated(-9*-cos(a*0.1),0,-9*-sin(a*0.1));
		glRotated(-20*a, 0, 0, 1);
		glCallList(planetas[5]);
	glPopMatrix();
	
	//Urano
	glPushMatrix();
		glRasterPos2f(0,-2.8);
		glBindTexture(GL_TEXTURE_2D,text_urano);
		glTranslated(3*-cos(a*0.1),3, 3*-sin(a*0.1));
		glRotated(-20*a, 0, 0, 1);
		glCallList(planetas[6]);
	glPopMatrix();
	
	//Netuno
	glPushMatrix();
		glRasterPos2f(0,-2.8);
		glBindTexture(GL_TEXTURE_2D,text_netuno);
		glTranslated(0.2*-cos(a*0.1),5, 0.2*-sin(a*0.1));
		glRotated(-20*a, 0, 0, 1);
		glCallList(planetas[7]);
	glPopMatrix();
	

	//glutSolidSphere(10, 50, 50 );
	


	// Execução dos comandos de desenho
	glutSwapBuffers();
}


// Inicialização
void Inicializa(void)
{
	especMaterial = 60;

		//Habilita o uso da textura
		glEnable (GL_TEXTURE_2D);
        // Define a cor de fundo da janela de visualização como branca
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    
        // Habilita a definição da cor do material a partir da cor corrente
        glEnable(GL_COLOR_MATERIAL);
        //Habilita o uso de iluminação
        glEnable(GL_LIGHTING);  
        // Habilita a luz de número 0
        glEnable(GL_LIGHT0);
        // Habilita o depth-buffering
        glEnable(GL_DEPTH_TEST);
 
        // Habilita o modelo de colorização de Gouraud
      //glShadeModel(GL_SMOOTH);//Questao1
      glShadeModel(GL_FLAT);
     
        // Inicializa a variável que especifica o ângulo da projeção
        // perspectiva
        angle=10;
    	inicializaTexturas();
    	carregaPlanetas();
        // Inicializa as variáveis usadas para alterar a posição do 
        // observador virtual
        rotX = 0;
        rotY = 0;
        obsX=obsY=0;
        obsZ = 180;

        flagAtualizaPos = True; 
}

// Função usada para especificar a posição do observador virtual
void PosicionaObservador(void)
{
	// Especifica sistema de coordenadas do modelo
	glMatrixMode(GL_MODELVIEW);
	// Inicializa sistema de coordenadas do modelo
	glLoadIdentity();
	
        // Chama a função que especifica os parâmetros de iluminação
        DefineIluminacao(); // INCLUA ESTA LINHA
	
	// Especifica posição do observador e do alvo
	//glTranslatef(0,0,-obsZ);
	glTranslatef(-obsX*0.5,-obsY*0.5,-obsZ*0.5);
	glRotatef(rotX,1,0,0);
	glRotatef(rotY,0,1,0);
}


// Função usada para especificar o volume de visualização
void EspecificaParametrosVisualizacao(void)
{
	// Especifica sistema de coordenadas de projeção
	glMatrixMode(GL_PROJECTION);
	// Inicializa sistema de coordenadas de projeção
	glLoadIdentity();

	// Especifica a projeção perspectiva(angulo,aspecto,zMin,zMax)
	gluPerspective(angle,fAspect,0.5,800);

	PosicionaObservador();
}


// Função callback chamada quando o tamanho da janela é alterado
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
	// Para previnir uma divisão por zero
	if ( h == 0 ) h = 1;

	// Especifica as dimensões da viewport
	glViewport(0, 0, w, h);

	// Calcula a correção de aspecto
	fAspect = (GLfloat)w/(GLfloat)h;

	EspecificaParametrosVisualizacao();
}


// Callback para gerenciar eventos do mouse
void GerenciaMouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
		if (state == GLUT_DOWN) {
			// Zoom-in
			if (angle >= 10)
				angle -= 5;
		}
	if (button == GLUT_RIGHT_BUTTON)
		if (state == GLUT_DOWN) {
			// Zoom-out
			if (angle <= 130)
				angle += 5;
		}
	EspecificaParametrosVisualizacao();
	glutPostRedisplay();
}




// Função callback chamada para gerenciar eventos de teclas especiais (F1,PgDn,...)
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
			
			obsZ = 500;
				
							break;
		case GLUT_KEY_F2:	
			 obsX=obsY=0;obsZ = 180; 	
        						break;
									
	}
	PosicionaObservador();
	 /*glLoadIdentity();
	 EspecificaParametrosVisualizacao();
  	gluLookAt(obsX,obsY,obsZ, 0,0,0, 0,1,0);*/
	glutPostRedisplay();
}

void TeclaPressionada(unsigned char key, int x, int y)
{
    switch(key)
    {
	    case 27:													// ESC
	    	exit(0);
	    	break;

	    case 32:													// BARRA DE ESPAÇO

	    	if(flagAtualizaPos == Pause)
	    	{
	    		flagAtualizaPos = True;
	    	}

	    	else
	    	{
	    		flagAtualizaPos = Pause;
	    	}

	    	break;	
	}
}


// Programa Principal
int main()
{
	int argc = 0;
	char *argv[] = { (char *)"gl", 0 };

	glutInit(&argc,argv);

	// Define do modo de operacao da GLUT
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); 
	// Especifica a posição inicial da janela GLUT
    glutInitWindowPosition(5,5);

	// Especifica o tamanho inicial em pixels da janela GLUT
	glutInitWindowSize(1000,800);

	// Cria a janela passando como argumento o titulo da mesma
	glutCreateWindow("TP2 - Sistema Solar");
	// Registra a funcao callback de redesenho da janela de visualizacao
	glutDisplayFunc(Desenha);
	// Registra a funcao callback para tratamento das teclas especiais
	glutSpecialFunc(TeclasEspeciais);
	glutKeyboardFunc(TeclaPressionada);
	// Registra a funcao callback para tratamento do redimensionamento da janela
    glutReshapeFunc(AlteraTamanhoJanela);
	// Registra a funcao callback para tratamento do mouse
	glutMouseFunc(GerenciaMouse);

	glutIdleFunc(rotacionaEsfera);
	Inicializa();

	glutMainLoop();
}

