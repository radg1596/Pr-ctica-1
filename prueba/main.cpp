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
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
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

	//Poner Código Aquí.
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
				glScalef(0.2, 0.1, 0.50);
				prisma();
			glPopMatrix();
			glTranslatef(0.1, 0.0, 0.0);
			glRotatef(angPulgar2, 0.0, 0.0, 1.0);
			glTranslatef(0.1, 0.0, 0.0);
			glColor3f(0.3, 0.7, 1.0);
			glScalef(0.2, 0.1, 0.50);
			prisma();
		glPopMatrix();
		//Indice
		//dedo2
		glPushMatrix();
			glTranslatef(0.1, -0.25, 0.0);
			glRotatef(angIndice1, 1.0, 0.0, 0.0);
			glTranslatef(0.0, -0.10, 0.0);
			glColor3f(0.2, 0.5, 1.0);
			//parte 1
			glPushMatrix();
				glScalef(0.1, 0.2, 0.25);
				prisma();
			glPopMatrix();
			glTranslatef(0.0, -0.10, 0.0);
			glRotatef(angIndice2, 1.0, 0.0, 0.0);
			glTranslatef(0.0, -0.10, 0.0);
			glColor3f(0.2, 0.7, 0.3);
			glScalef(0.1, 0.2, 0.25);
			prisma();
		glPopMatrix();


		//dedo3
		//Medio
		glPushMatrix();
			glTranslatef(0.0, -0.25, 0.0);
			glRotatef(angMedio1, 1.0, 0.0, 0.0);
			glTranslatef(0.0, -0.15, 0.0);
			glColor3f(0.3, 0.5, 0.0);
			//parte 1
			glPushMatrix();
				glScalef(0.1, 0.3, 0.25);
				prisma();
			glPopMatrix();
			glTranslatef(0.0, -0.15, 0.0);
			glRotatef(angMedio2, 1.0, 0.0, 0.0);
			glTranslatef(0.0, -0.15, 0.0);
			glColor3f(0.3, 0.7, 1.0);
			glScalef(0.1, 0.3, 0.25);
			prisma();
		glPopMatrix();

		//dedo4
		//Anular
		glPushMatrix();
			glTranslatef(-0.10, -0.25, 0.0);
			glRotatef(angAnular1, 1.0, 0.0, 0.0);
			glTranslatef(0.0, -0.10, 0.0);
			glColor3f(0.3, 0.5, 0.4);
			//parte 1
			glPushMatrix();
				glScalef(0.1, 0.2, 0.25);
				prisma();
			glPopMatrix();
			glTranslatef(0.0, -0.10, 0.0);
			glRotatef(angAnular2, 1.0, 0.0, 0.0);
			glTranslatef(0.0, -0.10, 0.0);
			glColor3f(0.3, 0.7, 0.3);
			glScalef(0.1, 0.2, 0.25);
			prisma();
		glPopMatrix();

		//dedo5
		//Menique
		glPushMatrix();
			glTranslatef(-0.20, -0.25, 0.0);
			glRotatef(angMenique1, 1.0, 0.0, 0.0);
			glTranslatef(0.0, -0.05, 0.0);
			glColor3f(0.8, 0.5, 0.4);
			//parte 1
			glPushMatrix();
				glScalef(0.1, 0.1, 0.25);
				prisma();
			glPopMatrix();
			glTranslatef(0.0, -0.05, 0.0);
			glRotatef(angMenique2, 1.0, 0.0, 0.0);
			glTranslatef(0.0, -0.05, 0.0);
			glColor3f(0.3, 0.7, 0.9);
			glScalef(0.1, 0.1, 0.25);
			prisma();
		glPopMatrix();

	glPopMatrix();
	//Cuerpo
	glTranslatef(-1.75, -1.25, 0.0);
	glPushMatrix();
		glScalef(3.0, 3.0, 1.0);
		glColor3f(0.0, 0.0, 0.7);
		prisma();
	glPopMatrix();
	//Pierna der
	glPushMatrix();
		glTranslatef(+1.0, -3.5, 0.0);
		glScalef(1.0, 4.0, 1.0);
		glColor3f(0.0, 0.7, 0.0);
		prisma();
	glPopMatrix();
	//Pierna izq
	glPushMatrix();
		glTranslatef(-1.0, -3.5, 0.0);
		glScalef(1.0, 4.0, 1.0);
		glColor3f(0.0, 0.7, 0.0);
		prisma();
	glPopMatrix();
	//cuello
	glTranslatef(0.0, 2.0, 0.0);
	glPushMatrix();
		glScalef(0.5, 1.0, 1.0);
		glColor3f(1.0, 0.5, 0.0);
		prisma();
	glPopMatrix();
	//Cabeza
	glTranslatef(0.0, 1.0, 0.0);
	glPushMatrix();
		glScalef(1.0, 1.0, 1.0);
		glColor3f(1.0, 0.5, 0.0);
		prisma();
	glPopMatrix();
	//Brazo	
	glTranslatef(-1.75, -3.0, 0.0);
	glPushMatrix();
		glScalef(0.5, 3.0, 1.0);
		glColor3f(1.0, 0.5, 0.0);
	prisma();
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
		//hpmbro
		case 't':
		case 'T':
			if (angHombro<90.0)
				angHombro = angHombro + 0.5f;
			break;
		case 'y':
		case 'Y':
			if (angHombro>0.0)
				angHombro = angHombro - 0.5f;
			break;
		//codo
		case 'u':
		case 'U':
			if (angCodo<20.0)
				angCodo = angCodo + 0.5f;
			break;
		case 'i':
		case 'I':
			if (angCodo>0.0)
				angCodo = angCodo - 0.5f;
			break;
		//mano
		case 'o':
		case 'O':
			if (angMano<17.5)
				angMano = angMano + 0.5f;
			break;
		case 'p':
		case 'P':
			if (angMano>-15.0)
				angMano = angMano - 0.5f;
			break;
		//Pulgar
		case 'k':
		case 'K':
			if (angPulgar1<6.0)
				angPulgar1 = angPulgar1 + 0.5f;
			break;
		case 'l':
		case 'L':
			if (angPulgar1>-83.5)
				angPulgar1 = angPulgar1 - 0.5f;
			break;
		case 'm':
			if (angPulgar2<0.0)
				angPulgar2 = angPulgar2 + 0.5f;
			break;
		case 'M':
			if (angPulgar2>-76.0)
				angPulgar2 = angPulgar2 - 0.5f;
			break;
		//indice
		case 'z':
			if ( angIndice1<41.0)
				angIndice1 = angIndice1 + 0.5f;
			break;
		case 'Z':
			if (angIndice1>-3.0)
				angIndice1 = angIndice1 - 0.5f;
			break;
		case 'x':
			if (angIndice2<29.0)
				angIndice2 = angIndice2 + 0.5f;
			break;
		case 'X':
			if (angIndice2>-2.0)
				angIndice2 = angIndice2 - 0.5f;
			break;
		//medio
		case 'c':
			if (angMedio1<41.0)
				angMedio1 = angMedio1 + 0.5f;
			break;
		case 'C':
			if (angMedio1>-3.0)
			angMedio1 = angMedio1 - 0.5f;
			break;
		case 'v':
			if (angMedio2<29.0)
				angMedio2= angMedio2 + 0.5f;
			break;
		case 'V':
			if (angMedio2>-2.0)
			angMedio2 = angMedio2 - 0.5f;
			break;
	    //anular
		case 'b':
			if (angAnular1<41.0)
				angAnular1 = angAnular1 + 0.5f;
			break;
		case 'B':
			if (angAnular1>-3.0)
				angAnular1 = angAnular1 - 0.5f;
			break;
		case 'n':
			if (angAnular2<29.0)
				angAnular2 = angAnular2 + 0.5f;
			break;
		case 'N':
			if (angAnular2>-2.0)
			angAnular2 = angAnular2 - 0.5f;
			break;
		//Menique
		case 'f':
			if (angMenique1<41.0)
				angMenique1 = angMenique1 + 0.5f;
			break;
		case 'F':
			if (angMenique1>-3.0)
				angMenique1 = angMenique1 - 0.5f;
			break;
		case 'g':
			if (angMenique2<29.0)
				angMenique2 = angMenique2 + 0.5f;
			break;
		case 'G':
			if (angMenique2>-2.0)
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
  printf("%.2f\n", angMano);
  printf("%.2f\n", angMano);
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
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 5"); // Nombre de la Ventana
  printf("Resolution H: %i \n", screenW);
  printf("Resolution V: %i \n", screenH);
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutMainLoop        ( );          // 

  return 0;
}



