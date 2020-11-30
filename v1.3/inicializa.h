// Inicializacao
void Inicializa(void)
{
	especMaterial = 150;

		//Habilita o uso da textura
		glEnable (GL_TEXTURE_2D);
        // Define a cor de fundo da janela de visualizacao como branca
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    
        // Habilita a definicao da cor do material a partir da cor corrente
        glEnable(GL_COLOR_MATERIAL);
        //Habilita o uso de iluminacao
        glEnable(GL_LIGHTING);  
        // Habilita a luz de numero 0
        glEnable(GL_LIGHT0);
        // Habilita o depth-buffering
        glEnable(GL_DEPTH_TEST);
 
        // Habilita o modelo de colorizacao de Gouraud
      	glShadeModel(GL_FLAT);
     
        // Inicializa a variavel que especifica o angulo da projecao
        // perspectiva
        angle=60;
    	inicializaTexturas();
    	carregaPlanetas();
        // Inicializa as variaveis usadas para alterar a posicao do 
        // observador virtual
        rotX = 0;
        rotY = 0;
        obsX=obsY=0;
        obsZ = 180;

        flagAtualizaPos = True; 
}