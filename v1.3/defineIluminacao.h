
// Funcao responsavel pela especificao dos par�metros de iluminacao
void DefineIluminacao (void)
{
        GLfloat luzAmbiente[4]={0.4,0.4,0.4,1.0}; 
        GLfloat luzDifusa[4]={0.7,0.7,0.7,1.0};          // "cor" 
        GLfloat luzEspecular[4]={1.0, 1.0,1.0, 1.0};// "brilho" 
        GLfloat posicaoLuz[4]={1.35,1.35, 8, 1.0};
 
        // Capacidade de brilho do material
        GLfloat especularidade[4]={0.8,0.8,0.8,1.0}; 
        GLint especMaterial = 100 ;
 
        // Define a refletencia do material 
        glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade);
        //Define a concentracao do brilho
        glMateriali(GL_FRONT,GL_SHININESS,especMaterial);
 
        // Define os parametros da luz de numero 0
        glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa );
        glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular );
        glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz );   
}