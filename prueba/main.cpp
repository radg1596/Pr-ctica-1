//Semestre 2017 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************											******//
//*************											******//
//************************************************************//
//Desiderio González Ricardo Abraham
//Visual studio 2015
//#include <gl/gl.h>     // The GL Header File
//#include <GL/glut.h>   // The GL Utility Toolkit (Glut) Header
//#include <stdlib.h>
#include "Main.h"

float angleX = 0.0f;
float angleY = 0.0f;
float angleZ = 0.0f;
float transX = 0.0f;
float transY = 0.0f;
float transZ = -5.0f;


void InitGL ( GLvoid )     // Inicializamos parametros
{

	//glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	//glEnable(GL_LIGHTING);
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	//glEnable ( GL_COLOR_MATERIAL );
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void color(char c)
{
	switch (c)
	{
	case'V':
		glColor3f(0.0, 1.0, 0.0);//Verde fuerte
		break;
	case'v':
		glColor3f(0.196078, 0.8, 0.196078);//Verde claro
		break;
	case'Z':
		glColor3f(0.0, 0.0, 1.0);//Azul fuerte
		break;
	case'z':
		glColor3f(0.0, 1.0, 1.0);//Azul claro
		break;
	case'a':
		glColor3f(1.0, 1.0, 0.0);//Amarillo
		break;
	case'r':
		glColor3f(1.0, 0.0, 0.0);//Rojo
		break;
	case'm':
		glColor3f(1.0, 0.0, 1.0);//Morado
		break;
	case'c':
		glColor3f(0.647059, 0.164706, 0.164706);//Cafe
		break;
	case'n':
		glColor3f(1.0, 0.5, 0.0);//Naranja
		break;
	case'N':
		glColor3f(0.0, 0.0, 0.0);//Negro
		break;
	case'b':
		glColor3f(1.0, 1.0, 1.0);//Blanco
		break;
	}
}

void prisma(char front, char back, char right, char left, char bottom, char top, float base, float altura)
{
	GLfloat vertice [8][3] = {
				{base/2 ,-altura/2, base/2 },    //Coordenadas Vértice 0 V0
				{-base/2 ,-altura/2, base/2 },    //Coordenadas Vértice 1 V1
				{-base/2 ,-altura/2, -base/2 },    //Coordenadas Vértice 2 V2
				{ base/2 ,-altura/2, -base/2 },    //Coordenadas Vértice 3 V3
				{ base/2 ,altura/2, base/2 },    //Coordenadas Vértice 4 V4
				{ base/2 ,altura/2, -base/2 },    //Coordenadas Vértice 5 V5
				{-base/2 ,altura/2, -base/2 },    //Coordenadas Vértice 6 V6
				{-base/2 ,altura/2, base/2 },    //Coordenadas Vértice 7 V7
				};

		glBegin(GL_POLYGON);	//Front
			color(front);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[1]);
		glEnd();

		glBegin(GL_POLYGON);	//Right
			color(right);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			color(back);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			color(left);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
			color(bottom);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[2]);
			glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);  //Top
			color(top);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[7]);
		glEnd();
}




void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//Dibujar
	glTranslatef(0.0 + transX, 0.0 + transY, -5.0 + transZ);
	glRotatef(angleX, 1.0, 0.0, 0.0);
	glRotatef(angleY, 0.0, 1.0, 0.0);
	glRotatef(angleZ, 0.0, 0.0, 1.0);
	/*La fución recibe los argumentos (en ese orden):
	Color front
	Color back
	Color right
	Color left
	Color bottom
	Color top
	base
	altura
	Los argumentos de colores son caracteres basados en el siguiente código de colores:
	Verde fuerte ´V´
	Verde claro ´v´
	Azul fuerte ´Z´
	Azul claro ´z´
	Amarillo ´a´
	Rojo ´r´
	Morado ´m´
	Cafe ´C´
	Naranja ´n´
	Negro ´N´
	Blanco ´b
	El código de colores se creo con la finalidad de facilitar la obtención de colores básicos, además de evitar tener 18 argumentos en la función,
	los cual haría tediosa la llamada a función. Si quisieran obtenerse una gama de colores más amplia, habría que replantear la función de nuevo.
	Base y altura son flotantes.´
	*/
	//Ejemplo de función
	prisma('m','c','n','N','b','r',9.0,3.0);
  									
    glutSwapBuffers ( );
    //glFlush();
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
	//glOrtho(-5,5,-5,5,0.1,20);	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.05, 40.0);
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'r':
		case 'R':
			transZ +=0.2f;
			printf("Posicion en Z: %f\n", transZ);
			break;
		case 'f':
		case 'F':
			transZ -=0.2f;
			printf("Posicion en Z: %f\n", transZ);
			break;
		case 'a':
		case 'A':
			transX -=0.2f;
			break;
		case 'd':
		case 'D':
			transX +=0.2f;
			break;
		case 's':
		case 'S':
			transY -= 0.2f;
			break;
		case 'w':
		case 'W':
			transY += 0.2f;
			break;
		case 't'://Rotar eje Z
		case 'T':
			angleZ += 6.0f;
			break;
		case 'g':
		case 'G':
			angleZ -= 6.0f;
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
    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		angleX += 6.0f;
		break;
      //glutFullScreen ( ); // Full Screen Mode
      //break;
    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		angleX -= 6.0f;
		break;
      //glutReshapeWindow ( 500, 500 ); // Cambiamos tamano de Ventana
      //break;
	case GLUT_KEY_LEFT:
		angleY += 6.0f;
		break;
	case GLUT_KEY_RIGHT:
		angleY -= 6.0f;
		break;
    default:
      break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  //glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 3"); // Nombre de la Ventana
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutMainLoop        ( );          // 

  return 0;
}



