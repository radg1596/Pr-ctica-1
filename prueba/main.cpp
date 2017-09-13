//Semestre 2018 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//Desiderio Gonzalez Ricardo Abraham
//Visual studio 2015
//*************											******//
//*************											******//
//************************************************************//
#include "Main.h"

float transZ = -5.0f;
float transX = 0.0f;
float angleX = 0.0f;
float angleY = 0.0f;
float angHombro = 0.0;
float angCodo = 0.0;
float angMano = 0.0;
float angPulgar1 = 0.0;
float angPulgar2 = 0.0;
float angIndice1 = 0.0;
float angIndice2 = 0.0;
float angMedio1 = 0.0;
float angMedio2 = 0.0;
float angAnular1 = 0.0;
float angAnular2 = 0.0;
float angMenique1 = 0.0;
float angMenique2 = 0.0;
int screenW = 0.0;
int screenH = 0.0;


GLfloat Position[]= { 0.0f, 3.0f, 0.0f, 1.0f };			// Light Position
GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

void InitGL ( void )     // Inicializamos parametros
{

	glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing

	//Configuracion luz
	glLightfv(GL_LIGHT0, GL_POSITION, Position);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Position2);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);


	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glEnable ( GL_COLOR_MATERIAL );
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void prisma(void)
{
	GLfloat vertice [8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas V�rtice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas V�rtice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas V�rtice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas V�rtice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas V�rtice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas V�rtice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas V�rtice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas V�rtice 7 V7
				};

		glBegin(GL_POLYGON);	//Front
			glNormal3f( 0.0f, 0.0f, 1.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[1]);
		glEnd();

		glBegin(GL_POLYGON);	//Right
			glNormal3f( 1.0f, 0.0f, 0.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			glNormal3f( 0.0f, 0.0f, -1.0f);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			glNormal3f( -1.0f, 0.0f, 0.0f);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
			glNormal3f( 0.0f, -1.0f, 0.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[2]);
			glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);  //Top
			glNormal3f( 0.0f, 1.0f, 0.0f);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[7]);
		glEnd();
}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
	//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(transX, 0.0f, transZ);
	glRotatef(angleY, 0.0, 1.0, 0.0);
	glRotatef(angleX, 1.0, 0.0, 0.0);
	//Poner C�digo Aqu�.
//Brazo detallado

	glPushMatrix();
		//hombro
		glRotatef(angHombro, 0.0, 0.0, 1.0);
		glPushMatrix();
			glColor3f(0.0, 1.0, 0.0);
			glScalef(0.5, 0.5, 1);
			prisma();
		glPopMatrix();
		//bicep
		glTranslatef(0.0, -0.75, 0.0);
		glPushMatrix();
			glScalef(0.5, 1.0, 1.0);
			glColor3f(1.0, 0.0, 0.0);
			prisma();
		glPopMatrix();
		//codo
		glRotatef(angCodo, 0.0, 0.0, 1.0);
		glTranslatef(0.0, -0.75, 0.0);
		glPushMatrix();
			glColor3f(0.0, 0.0, 1.0);
			glScalef(0.5, 0.5, 1.0);
			prisma();
		glPopMatrix();
		//Antebrazo
		glTranslatef(0.0, -0.75, 0.0);
			glPushMatrix();
			glColor3f(1.0, 1.0, 0.0);
			glScalef(0.5, 1.0, 1.0);
			prisma();
		glPopMatrix();
		//mano
		glTranslatef(0.0, -0.75, 0.0);
		glRotatef(angMano, 0.0, 0.0, 1.0);
		glPushMatrix();
			glColor3f(0.0, 1.0, 1.0);
			glScalef(0.5, 0.5, 1.0);
			prisma();
		glPopMatrix();
		//pulgar
		//dedo1
		glPushMatrix();
			glTranslatef(0.25, 0.0, 0.0);
			glRotatef(angPulgar1, 0.0, 0.0, 1.0);
			glTranslatef(0.1, 0.0, 0.0);
			glColor3f(0.3, 0.5, 0.0);
			//parte 1
			glPushMatrix();
				glScalef(0.2, 0.1, 1.0);
				prisma();
			glPopMatrix();
			glTranslatef(0.1, 0.0, 0.0);
			glRotatef(angPulgar2, 0.0, 0.0, 1.0);
			glTranslatef(0.1, 0.0, 0.0);
			glColor3f(0.3, 0.7, 1.0);
			glScalef(0.2, 0.1, 1.0);
			prisma();
		glPopMatrix();
		//Indice
		//dedo2
		glPushMatrix();
			glTranslatef(0.1, -0.25, 0.0);
			glRotatef(angIndice1, 0.0, 0.0, 1.0);
			glTranslatef(0.0, -0.10, 0.0);
			glColor3f(0.2, 0.5, 1.0);
			//parte 1
			glPushMatrix();
				glScalef(0.1, 0.2, 1.0);
				prisma();
			glPopMatrix();
			glTranslatef(0.0, -0.10, 0.0);
			glRotatef(angIndice2, 0.0, 0.0, 1.0);
			glTranslatef(0.0, -0.10, 0.0);
			glColor3f(0.2, 0.7, 0.3);
			glScalef(0.1, 0.2, 1.0);
			prisma();
		glPopMatrix();


		//dedo3
		//Medio
		glPushMatrix();
			glTranslatef(0.0, -0.25, 0.0);
			glRotatef(angMedio1, 0.0, 0.0, 1.0);
			glTranslatef(0.0, -0.15, 0.0);
			glColor3f(0.3, 0.5, 0.0);
			//parte 1
			glPushMatrix();
				glScalef(0.1, 0.3, 1.0);
				prisma();
			glPopMatrix();
			glTranslatef(0.0, -0.15, 0.0);
			glRotatef(angMedio2, 0.0, 0.0, 1.0);
			glTranslatef(0.0, -0.15, 0.0);
			glColor3f(0.3, 0.7, 1.0);
			glScalef(0.1, 0.3, 1.0);
			prisma();
		glPopMatrix();

		//dedo4
		//Anular
		glPushMatrix();
			glTranslatef(-0.10, -0.25, 0.0);
			glRotatef(angAnular1, 0.0, 0.0, 1.0);
			glTranslatef(0.0, -0.10, 0.0);
			glColor3f(0.3, 0.5, 0.4);
			//parte 1
			glPushMatrix();
				glScalef(0.1, 0.2, 1.0);
				prisma();
			glPopMatrix();
			glTranslatef(0.0, -0.10, 0.0);
			glRotatef(angAnular2, 0.0, 0.0, 1.0);
			glTranslatef(0.0, -0.10, 0.0);
			glColor3f(0.3, 0.7, 0.3);
			glScalef(0.1, 0.2, 1.0);
			prisma();
		glPopMatrix();

		//dedo5
		//Menique
		glPushMatrix();
			glTranslatef(-0.20, -0.25, 0.0);
			glRotatef(angMenique1, 0.0, 0.0, 1.0);
			glTranslatef(0.0, -0.05, 0.0);
			glColor3f(0.8, 0.5, 0.4);
			//parte 1
			glPushMatrix();
				glScalef(0.1, 0.1, 1.0);
				prisma();
			glPopMatrix();
			glTranslatef(0.0, -0.05, 0.0);
			glRotatef(angMenique2, 0.0, 0.0, 1.0);
			glTranslatef(0.0, -0.05, 0.0);
			glColor3f(0.3, 0.7, 0.9);
			glScalef(0.1, 0.1, 1.0);
			prisma();
		glPopMatrix();

	glPopMatrix();

		
	
		
  											
	glutSwapBuffers ( );
  // Swap The Buffers
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
	//glOrtho(-5,5,-5,5,0.2,20);	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	//glLoadIdentity();									
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		//Manipulacion de brazo
		case 't':
		case 'T':
			angHombro = angHombro + 0.5f;
			break;
		case 'y':
		case 'Y':
			angHombro = angHombro - 0.5f;
			break;
		case 'u':
		case 'U':
			angCodo = angCodo + 0.5f;
			break;
		case 'i':
		case 'I':
			angCodo = angCodo - 0.5f;
			break;
		case 'o':
		case 'O':
			angMano = angMano + 0.5f;
			break;
		case 'p':
		case 'P':
			angMano = angMano - 0.5f;
			break;
		case 'k':
		case 'K':
			angPulgar1 = angPulgar1 + 0.5f;
			break;
		case 'l':
		case 'L':
			angPulgar1 = angPulgar1 - 0.5f;
			break;
		case 'm':
			angPulgar2 = angPulgar2 + 0.5f;
			break;
		case 'M':
			angPulgar2 = angPulgar2 - 0.5f;
			break;
		case 'z':
			angIndice1 = angIndice1 + 0.5f;
			break;
		case 'Z':
			angIndice1 = angIndice1 - 0.5f;
			break;
		case 'x':
			angIndice2 = angIndice2 + 0.5f;
			break;
		case 'X':
			angIndice2 = angIndice2 - 0.5f;
			break;
		case 'c':
			angMedio1 = angMedio1 + 0.5f;
			break;
		case 'C':
			angMedio1 = angMedio1 - 0.5f;
			break;
		case 'v':
			angMedio2= angMedio2 + 0.5f;
			break;
		case 'V':
			angMedio2 = angMedio2 - 0.5f;
			break;
		case 'b':
			angAnular1 = angAnular1 + 0.5f;
			break;
		case 'B':
			angAnular1 = angAnular1 - 0.5f;
			break;
		case 'n':
			angAnular2 = angAnular2 + 0.5f;
			break;
		case 'N':
			angAnular2 = angAnular2 - 0.5f;
			break;
		case 'f':
			angMenique1 = angMenique1 + 0.5f;
			break;
		case 'F':
			angMenique1 = angMenique1 - 0.5f;
			break;
		case 'g':
			angMenique2 = angMenique2 + 0.5f;
			break;
		case 'G':
			angMenique2 = angMenique2 - 0.5f;
			break;
		case 'w':
		case 'W':
			transZ +=0.2f;
			break;
		case 's':
		case 'S':
			transZ -=0.2f;
			break;
		case 'a':
		case 'A':
			transX +=0.2f;
			break;
		case 'd':
		case 'D':
			transX -=0.2f;
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
    case GLUT_KEY_UP:		// Presionamos tecla ARRIBA...
		angleX +=2.0f;
		break;
    case GLUT_KEY_DOWN:		// Presionamos tecla ABAJO...
		angleX -=2.0f;
		break;
	case GLUT_KEY_LEFT:
		angleY +=2.0f;
		break;
	case GLUT_KEY_RIGHT:
		angleY -=2.0f;
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
  screenW = glutGet(GLUT_SCREEN_WIDTH);
  screenH = glutGet(GLUT_SCREEN_HEIGHT);
  glutInitWindowSize  (500, 500);	// Tama�o de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 5"); // Nombre de la Ventana
  printf("Resolution H: %i \n", screenW);
  printf("Resolution V: %i \n", screenH);
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut funci�n de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut funci�n en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut funci�n de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutMainLoop        ( );          // 

  return 0;
}



