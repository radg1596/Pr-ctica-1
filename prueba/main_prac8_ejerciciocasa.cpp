//Semestre 2012 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//Desiderio Gonzalez Ricardo Abraham
//Visual Studio 2015
//*************											******//
//*************											******//
//************************************************************//
#include "texture.h"

float pos_camX = 0, pos_camY = 0, pos_camZ = -5; 
int eye_camX = 0, eye_camY = 0.0, eye_camZ = 0;


GLfloat Diffuse[]= { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[]= { 0.0f, 3.0f, 0.0f, 1.0f };			// Light Position
GLfloat Position2[]= { 0.0f, -5.0f, 0.0f, 1.0f };			// Light Position



CTexture t_piedra;
CTexture t_puerta;
CTexture t_ventana;
CTexture t_pasto;
CTexture t_techo;
CTexture t_tronco;
CTexture t_hojas;
CTexture t_mar;

int font=(int)GLUT_BITMAP_TIMES_ROMAN_24;



void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.5f, 0.5f, 0.8f, 0.0f);				// Azul de fondo	

	glEnable(GL_TEXTURE_2D);

	//glShadeModel (GL_SMOOTH);
	glLightfv(GL_LIGHT0, GL_POSITION, Position);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Position2);
	

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	t_piedra.LoadTGA("piedra.tga");//carga la textura
	t_piedra.BuildGLTexture();
	t_piedra.ReleaseImage();

	t_puerta.LoadTGA("puerta.tga");//carga la textura
	t_puerta.BuildGLTexture();
	t_puerta.ReleaseImage();

	t_ventana.LoadTGA("ventana.tga");//carga la textura
	t_ventana.BuildGLTexture();
	t_ventana.ReleaseImage();

	t_pasto.LoadTGA("pasto.tga");//carga la textura
	t_pasto.BuildGLTexture();
	t_pasto.ReleaseImage();

	t_mar.LoadTGA("mar.tga");//carga la textura
	t_mar.BuildGLTexture();
	t_mar.ReleaseImage();

	t_techo.LoadTGA("techo.tga");//carga la textura
	t_techo.BuildGLTexture();
	t_techo.ReleaseImage();

	t_tronco.LoadTGA("tronco.tga");//carga la textura
	t_tronco.BuildGLTexture();
	t_tronco.ReleaseImage();

	t_hojas.LoadTGA("hojas.tga");//carga la textura
	t_hojas.BuildGLTexture();
	t_hojas.ReleaseImage();

	
}


void renderBitmapCharacter(float x, float y, float z, void *font,char *string)
{
  
  char *c;     //Almacena los caracteres a escribir
  glRasterPos3f(x, y, z);	//Posicion apartir del centro de la ventana
  //glWindowPos2i(150,100);
  for (c=string; *c != '\0'; c++) //Condicion de fin de cadena
  {
    glutBitmapCharacter(font, *c); //imprime
  }
}



void prisma (GLuint textura1, float r)  //Funcion creacion prisma
{

	GLfloat vertice [8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
				};

		
		glBindTexture(GL_TEXTURE_2D, textura1);   // choose the texture to use.
		glBegin(GL_POLYGON);	//Front
			glColor3f(1.0, 1.0, 1.0);
			glNormal3f(0.0f, 0.0f, 1.0f);
			glTexCoord2f(r, 0.0f);		 glVertex3fv(vertice[0]);//asignar vertices, coordenadas de textura
			glTexCoord2f(r, r);			glVertex3fv(vertice[4]);
			glTexCoord2f(0.0f, r);	glVertex3fv(vertice[7]);
			glTexCoord2f(0.0f, 0.0f); 	glVertex3fv(vertice[1]);
		glEnd();
		glBegin(GL_POLYGON);	//Right
			glNormal3f( 1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(r, 0.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(r, r); glVertex3fv(vertice[5]);
			glTexCoord2f(0.0f, r); glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			glNormal3f(0.0f, 0.0f, -1.0f);
			glTexCoord2f(0.0f, r); glVertex3fv(vertice[6]);
			glTexCoord2f(r, r); glVertex3fv(vertice[5]);
			glTexCoord2f(r, 0.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(0.0f, 0.0f);  glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			glNormal3f(-1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(r, 0.0f); glVertex3fv(vertice[7]);
			glTexCoord2f(r, r); glVertex3fv(vertice[6]);
			glTexCoord2f(0.0f, r); glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
			glNormal3f( 0.0f,-1.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(r, 0.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(r, r); glVertex3fv(vertice[2]);
			glTexCoord2f(0.0f, r); glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);  //Top
			glNormal3f( 0.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0, 0.0f); glVertex3fv(vertice[4]);
			glTexCoord2f(r, 0.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(r, r); glVertex3fv(vertice[6]);
			glTexCoord2f(0.0f, r); glVertex3fv(vertice[7]);
		glEnd();
}

void prismatf(GLuint textura1, float r)  //Funcion creacion prisma
{

	GLfloat vertice[8][3] = {
		{ 0.5 ,-0.5, 0.5 },    //Coordenadas Vértice 0 V0
		{ -0.5 ,-0.5, 0.5 },    //Coordenadas Vértice 1 V1
		{ -0.5 ,-0.5, -0.5 },    //Coordenadas Vértice 2 V2
		{ 0.5 ,-0.5, -0.5 },    //Coordenadas Vértice 3 V3
		{ 0.5 ,0.5, 0.5 },    //Coordenadas Vértice 4 V4
		{ 0.5 ,0.5, -0.5 },    //Coordenadas Vértice 5 V5
		{ -0.5 ,0.5, -0.5 },    //Coordenadas Vértice 6 V6
		{ -0.5 ,0.5, 0.5 },    //Coordenadas Vértice 7 V7
	};


	   // choose the texture to use
	glBindTexture(GL_TEXTURE_2D, textura1); 
	glBegin(GL_POLYGON);	//Front
		glColor3f(1.0, 1.0, 1.0);
		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(r, 0.0f);		 glVertex3fv(vertice[0]);//asignar vertices, coordenadas de textura
		glTexCoord2f(r, r);			glVertex3fv(vertice[4]);
		glTexCoord2f(0.0f, r);	glVertex3fv(vertice[7]);
		glTexCoord2f(0.0f, 0.0f); 	glVertex3fv(vertice[1]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, NULL);
	glBegin(GL_POLYGON);	//Right
		glNormal3f(1.0f, 0.0f, 0.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
		glTexCoord2f(r, 0.0f); glVertex3fv(vertice[3]);
		glTexCoord2f(r, r); glVertex3fv(vertice[5]);
		glTexCoord2f(0.0f, r); glVertex3fv(vertice[4]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura1);
	glBegin(GL_POLYGON);	//Back
	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(0.0f, r); glVertex3fv(vertice[6]);
	glTexCoord2f(r, r); glVertex3fv(vertice[5]);
	glTexCoord2f(r, 0.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(0.0f, 0.0f);  glVertex3fv(vertice[2]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, NULL);
	glBegin(GL_POLYGON);  //Left
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(r, 0.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(r, r); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, r); glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Bottom
	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(r, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(r, r); glVertex3fv(vertice[2]);
	glTexCoord2f(0.0f, r); glVertex3fv(vertice[3]);
	glEnd();

	glBegin(GL_POLYGON);  //Top
	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(0.0, 0.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(r, 0.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(r, r); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, r); glVertex3fv(vertice[7]);
	glEnd();
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();

	glPushMatrix();
	glTranslatef(pos_camX, pos_camY, pos_camZ);
		glRotatef(eye_camX, 1.0, 0.0, 0.0);
		glRotatef(eye_camY, 0.0, 1.0, 0.0);
		glRotatef(eye_camZ, 0.0, 0.0, 1.0);
		//Dibujar
		glPushMatrix(); 

			glPushMatrix();
				glColor3f(1.0, 1.0, 1.0);
				glPushMatrix();//Bloque1
					glTranslated(1.0, 2.0, -0.5);
					glScalef(2.0, 4.0, 1.0);
					prisma(t_piedra.GLindex, 1.0f);
				glPopMatrix();
				
				glPushMatrix();//Puerta
					glTranslated(3.0, 2.0, -0.5);
					glScalef(2.0, 4.0, 1.0);
					prisma(t_puerta.GLindex, 1.0f);
				glPopMatrix();
				
				glPushMatrix();//Bloque2
					glTranslated(5.0, 2.0, -0.5 );
					glScalef(2.0, 4.0, 1.0);
					prisma(t_piedra.GLindex, 1.0f);
				glPopMatrix();
		
				glPushMatrix();//Ventana
					glTranslated(7.0, 2.0, -0.5);
					glScalef(2.0, 4.0, 1.0);
					prisma(t_ventana.GLindex, 1.0f);
				glPopMatrix();

				glPushMatrix();//Bloque3
					glTranslated(7.5, 2.0, -5.0);
					glScalef(1.0, 4.0, 8.0);
					prisma(t_piedra.GLindex, 1.0f);
				glPopMatrix();

				glPushMatrix();//Bloque4
					glTranslated(0.5, 2.0, -5.0);
					glScalef(1.0, 4.0, 8.0);
					prisma(t_piedra.GLindex, 1.0f);
				glPopMatrix();

				glPushMatrix();//Bloque5
					glTranslated(4.0, 2.0, -9.5);
					glScalef(8.0, 4.0, 1.0);
					prisma(t_piedra.GLindex, 1.0f);
				glPopMatrix();

				glPushMatrix();//Pasto
					glTranslated(4.0, -0.5, -5.0);
					glScalef(50.0, 1.0, 50.0);
					prisma(t_pasto.GLindex, 10.0f);
				glPopMatrix();

				glPushMatrix();//MAr
					glTranslated(4.0, -2.0, -5.0);
					glScalef(500.0, 1.0, 500.0);
					prisma(t_mar.GLindex, 1.0f);
				glPopMatrix();

				glPushMatrix();//Techo1
					glTranslated(4.0, 4.5, -5.0);
					glScalef(10.0, 1.0, 10.0);
					prisma(t_techo.GLindex, 1.0f);
				glPopMatrix();

				glPushMatrix();//Techo2
					glTranslated(4.0, 5.5, -5.0);
					glScalef(8.0, 1.0, 10.0);
					prisma(t_techo.GLindex, 1.0f);
				glPopMatrix();

				glPushMatrix();//Techo3
					glTranslated(4.0, 6.5, -5.0);
					glScalef(6.0, 1.0, 8.0);
					prisma(t_techo.GLindex, 1.0f);
				glPopMatrix();


				glPushMatrix();//Techo4
					glTranslated(4.0, 7.5, -5.0);
					glScalef(4.0, 1.0, 6.0);
					prisma(t_techo.GLindex, 1.0f);
				glPopMatrix();


				glPushMatrix();//Techo5
					glTranslated(4.0, 8.5, -5.0);
					glScalef(2.0, 1.0, 4.0);
					prisma(t_techo.GLindex, 1.0f);
				glPopMatrix();


				glPushMatrix();//Techo6
					glTranslated(4.0, 7.5, -5.0);
					glScalef(1.0, 1.0, 2.0);
					prisma(t_techo.GLindex, 1.0f);
				glPopMatrix();


				glPushMatrix();//Techo7
				glTranslated(4.0, 8.5, -5.0);
				glScalef(0.5, 1.0, 1.0);
				prisma(t_techo.GLindex, 1.0f);
				glPopMatrix();

				glPushMatrix();//Tronco
					glTranslated(-10.0, 5.0, -5.0);
					glScalef(2.0, 10.0, 2.0);
					prisma(t_tronco.GLindex, 2.0f);
				glPopMatrix();

				glPushMatrix();//Hojas
					glTranslated(-10.0, 13.0, -5.0);
					glScalef(6.0, 6.0, 6.0);
					prisma(t_hojas.GLindex, 8.0f);
				glPopMatrix();

				glPushMatrix();//Tronco2
					glTranslated(15.0, 5.0, -5.0);
					glScalef(2.0, 10.0, 2.0);
					prisma(t_tronco.GLindex, 2.0f);
				glPopMatrix();

				glPushMatrix();//Hojas2
					glTranslated(15.0, 13.0, -5.0);
					glScalef(6.0, 6.0, 6.0);
					prisma(t_hojas.GLindex, 8.0f);
				glPopMatrix();

				glPushMatrix();//Tronco3
					glTranslated(15.0, 5.0, 5.0);
					glScalef(2.0, 10.0, 2.0);
					prisma(t_tronco.GLindex, 2.0f);
				glPopMatrix();

				glPushMatrix();//Hojas3
					glTranslated(15.0, 13.0, 5.0);
					glScalef(6.0, 6.0, 6.0);
					prisma(t_hojas.GLindex, 8.0f);
				glPopMatrix();

				glPushMatrix();//Tronco4
					glTranslated(15.0, 5.0, 15.0);
					glScalef(2.0, 10.0, 2.0);
					prisma(t_tronco.GLindex, 2.0f);
				glPopMatrix();

				glPushMatrix();//Hojas4
					glTranslated(15.0, 13.0, 15.0);
					glScalef(6.0, 6.0, 6.0);
					prisma(t_hojas.GLindex, 8.0f);
				glPopMatrix();

				glPushMatrix();//Tronco5
					glTranslated(15.0, 5.0, -15.0);
					glScalef(2.0, 10.0, 2.0);
					prisma(t_tronco.GLindex, 2.0f);
				glPopMatrix();

				glPushMatrix();//Hojas5
					glTranslated(15.0, 13.0, -15.0);
					glScalef(6.0, 6.0, 6.0);
					prisma(t_hojas.GLindex, 8.0f);
				glPopMatrix();

				glPushMatrix();//Tronco6
					glTranslated(-10.0, 5.0, -15.0);
					glScalef(2.0, 10.0, 2.0);
					prisma(t_tronco.GLindex, 2.0f);
				glPopMatrix();

				glPushMatrix();//Hojas6
					glTranslated(-10.0, 13.0, -15.0);
					glScalef(6.0, 6.0, 6.0);
					prisma(t_hojas.GLindex, 8.0f);
				glPopMatrix();

				glPushMatrix();//Tronco7
					glTranslated(-10.0, 5.0, 5.0);
					glScalef(2.0, 10.0, 2.0);
					prisma(t_tronco.GLindex, 2.0f);
				glPopMatrix();
				
				glPushMatrix();//Hojas7
					glTranslated(-10.0, 13.0, 5.0);
					glScalef(6.0, 6.0, 6.0);
					prisma(t_hojas.GLindex, 8.0f);
				glPopMatrix();

				glPushMatrix();//Tronco8
					glTranslated(-10.0, 5.0, 15.0);
					glScalef(2.0, 10.0, 2.0);
					prisma(t_tronco.GLindex, 2.0f);
				glPopMatrix();

				glPushMatrix();//Hojas8
					glTranslated(-10.0, 13.0, 15.0);
					glScalef(6.0, 6.0, 6.0);
					prisma(t_hojas.GLindex, 8.0f);
				glPopMatrix();

				glPushMatrix();//Tronco9
					glTranslated(-2.5, 5.0, -15.0);
					glScalef(2.0, 10.0, 2.0);
					prisma(t_tronco.GLindex, 2.0f);
				glPopMatrix();

				glPushMatrix();//Hojas9
					glTranslated(-2.5, 13.0, -15.0);
					glScalef(6.0, 6.0, 6.0);
					prisma(t_hojas.GLindex, 8.0f);
				glPopMatrix();

				glPushMatrix();//Tronco10
					glTranslated(5.5, 5.0, -15.0);
					glScalef(2.0, 10.0, 2.0);
					prisma(t_tronco.GLindex, 2.0f);
				glPopMatrix();

				glPushMatrix();//Hojas10
					glTranslated(5.5, 13.0, -15.0);
					glScalef(6.0, 6.0, 6.0);
					prisma(t_hojas.GLindex, 8.0f);
				glPopMatrix();

			glPopMatrix();

		glPopMatrix();


	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
		renderBitmapCharacter(-11, 12.0, -14.0, (void *)font, "Practica 8");
		renderBitmapCharacter(-11, 10.5, -14, (void *)font, "Texturas");
	glEnable(GL_TEXTURE_2D);

	glutSwapBuffers ( );

}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 200.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void animacion()
{
	

	glutPostRedisplay();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':   //Movimientos de camara
		case 'W':
			pos_camZ += 0.5f;
			//eye_camZ -= 0.5f;
			break;

		case 's':
		case 'S':
			pos_camZ -= 0.5f;
			//eye_camZ += 0.5f;
			break;

		case 'a':
		case 'A':
			pos_camX += 0.5f;
			//eye_camX -= 0.5f;
			break;
		case 'd':
		case 'D':
			pos_camX -= 0.5f;
			//eye_camX += 0.5f;
			break;
		case 'r':
		case 'R':
			eye_camZ = (eye_camZ + 15) % 360;
			//eye_camX -= 0.5f;
			break;
		case 't':
		case 'T':
			eye_camZ = (eye_camZ - 15) % 360;
			//eye_camX += 0.5f;
			break;

		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
			break;        
		default:        // Cualquier otra
			break;
  }
	glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
	case GLUT_KEY_PAGE_UP:
		pos_camY -= 0.5f;
		//eye_camY += 0.5f;
		break;

	case GLUT_KEY_PAGE_DOWN:
		pos_camY += 0.5f;
		//eye_camY -= 0.5f;
		break;

    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		eye_camX = (eye_camX-15) % 360;
		break;

    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		eye_camX = (eye_camX+15) % 360;
		break;

	case GLUT_KEY_LEFT:
		eye_camY = (eye_camY-15) % 360;
		break;

	case GLUT_KEY_RIGHT:
		eye_camY = (eye_camY+15) % 360;
		break;
    default:
      break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (5000, 5000);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 8"); // Nombre de la Ventana
  //glutFullScreen     ( );         // Full Screen
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );
  glutMainLoop        ( );          // 

  return 0;
}