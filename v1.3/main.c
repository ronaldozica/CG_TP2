
// TP2 - Sistema Solar
//
// Alunos:
// Nasser Rafael Franca Kilesse
// Ronaldo Mendonca Zica
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
#include "variaveisGlobais.h"
#include "structEnum.h"
#include "inicializaTexturas.h"
#include "defineIluminacao.h"
#include "carregaPlanetas.h"
#include "rotacionaEsfera.h"
#include "desenhaPlanetas.h"
#include "inicializa.h"
#include "posicionaObservador.h"
#include "especificaParametrosVisualizacao.h"
#include "alteraTamanhoJanela.h"
#include "gerenciaMouse.h"
#include "teclasEspeciais.h"
#include "teclaPressionada.h"

// Programa Principal
int main()
{
	int argc = 0;
	char *argv[] = { (char *)"gl", 0 };

	glutInit(&argc,argv);

	// Define do modo de operacao da GLUT
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); 
	// Especifica a posicao inicial da janela GLUT
    glutInitWindowPosition(5,5);

	// Especifica o tamanho inicial em pixels da janela GLUT
	glutInitWindowSize(1280,800);

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