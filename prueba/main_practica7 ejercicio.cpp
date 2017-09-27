//Semestre 2018 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//Desiderio Gonzalez Ricardo Abraham
//Visual Studio 2015
//*************											******//
//*************											******//
//************************************************************//
#include "Main.h"


// Variables used to calculate frames per second: (Windows)
DWORD dwFrames = 0;
DWORD dwCurrentTime = 0;
DWORD dwLastUpdateTime = 0;
DWORD dwElapsedTime = 0;


//Variables used to create movement

int sol = 0;
int mercurio = 0;
int venus = 0;
int tierra = 0;
int luna = 0;
int marte = 0;
int jupiter = 0;
int lunaj1 = 0;
int lunaj2 = 0;
int lunaj3 = 0;
int lunaj4 = 0;
int saturno = 0;
int urano = 0;
int neptuno = 0;


float camaraZ = 0.0;
float camaraX = 0.0;

GLfloat SunDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };			// Diffuse Light Values
GLfloat SunSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat SunPosition[] = { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position

GLfloat MercurioDiffuse[] = { 0.545, 0.271, 0.075, 1.0f };			// Mercurio
GLfloat MercurioSpecular[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat MercurioShininess[] = { 50.0 };

GLfloat VenusDiffuse[] = { 0.957, 0.643, 0.376, 1.0f };			// Venus
GLfloat VenusSpecular[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat VenusShininess[] = { 50.0 };

GLfloat EarthDiffuse[] = { 0.2f, 0.2f, 1.0f, 1.0f };			// Tierra
GLfloat EarthSpecular[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat EarthShininess[] = { 50.0 };

GLfloat MoonDiffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };			// Luna
GLfloat MoonSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat MoonShininess[] = { 50.0 };

GLfloat MarsDiffuse[] = { 0.8f, 0.4f, 0.1f, 1.0f };			// Marte
GLfloat MarsSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat MarsShininess[] = { 50.0 };

GLfloat JupiterDiffuse[] = { 1.0, 0.0, 0.0, 1.0f };			// Jupiter
GLfloat JupiterSpecular[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat JupiterShininess[] = { 50.0 };

GLfloat SaturnoDiffuse[] = { 1.0, 1.0, 0.0, 1.0f };			// Saturno
GLfloat SaturnoSpecular[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat SaturnoShininess[] = { 50.0 };

GLfloat UranoDiffuse[] = { 0.5, 1.0, 1.0, 1.0f };			// Urano
GLfloat UranoSpecular[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat UranoShininess[] = { 50.0 };

GLfloat NeptunoDiffuse[] = { 0.4, 0.0, 1.0, 1.0f };			// Neptuno
GLfloat NeptunoSpecular[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat NeptunoShininess[] = { 50.0 };


void InitGL(GLvoid)     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT1);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, SunDiffuse);//nombre de la luz, tipo, arreglo
	glLightfv(GL_LIGHT1, GL_SPECULAR, SunSpecular);

}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(camaraX, 0.0, -5.0 + camaraZ);			//camara
	//Sol
	glPushMatrix();
		glRotatef(sol, 0.0, 1.0, 0.0);	//El Sol gira sobre su eje
		glColor3f(1.0, 1.0, 0.0);	//Sol amarillo
		glLightfv(GL_LIGHT1, GL_POSITION, SunPosition);
		glDisable(GL_LIGHTING);
		glutSolidSphere(1.9, 12, 12);  //Draw Sun (radio,H,V);
		glEnable(GL_LIGHTING);
	glPopMatrix();
	//Mercurio
	glPushMatrix();
		glColor3f(0.545, 0.271, 0.075);
		glRotatef(mercurio, 0.0, 1.0, 0.0);
		glTranslatef(2.5, 0.2, 0.2);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, MercurioDiffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, MercurioSpecular);
		glMaterialfv(GL_FRONT, GL_SHININESS, MercurioShininess);
		glutSolidSphere(0.3, 12, 12);
	glPopMatrix();
	//Venus
	glPushMatrix();
		glColor3f(0.957, 0.643, 0.376);
		glRotatef(venus, 0.0, 1.0, 0.0);
		glTranslatef(3.5, 0.2, 0.2);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, VenusDiffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, VenusSpecular);
		glMaterialfv(GL_FRONT, GL_SHININESS, VenusShininess);
		glutSolidSphere(0.4, 12, 12);
	glPopMatrix();
	//Tierra
	glPushMatrix();
		glColor3f(0.0, 0.0, 1.0);
		glPushMatrix();
			glRotatef(tierra, 0.0, 1.0, 0.0);
			glTranslatef(5.5, 0.2, 0.2);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, EarthDiffuse);
			glMaterialfv(GL_FRONT, GL_SPECULAR, EarthSpecular);
			glMaterialfv(GL_FRONT, GL_SHININESS, EarthShininess);
			glutSolidSphere(0.5, 12, 12);
		glPopMatrix();

		//luna
		glRotatef(tierra, 0.0, 1.0, 0.0);
		glPushMatrix();
			glTranslatef(5.5, 0.2, 0.2);
			glColor3f(0.957, 0.9, 0.9);
			glPushMatrix();
				glRotatef(luna, 0.0, 0.0, 1.0);
				glTranslatef(0.2, 0.8, 0.2);
				glRotatef(luna + 5, 0.0, 1.0, 0.0);
				glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
				glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
				glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
				glutSolidSphere(0.2, 10, 10);
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();
	//Marte
	glPushMatrix();

		glColor3f(1.0, 0.5, 0.0);
		glRotatef(marte, 0.0, 1.0, 0.0);
		glTranslatef(7.5, 0.2, 0.2);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, MarsDiffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, MarsSpecular);
		glMaterialfv(GL_FRONT, GL_SHININESS, MarsShininess);
		glutSolidSphere(0.3, 12, 12);

	glPopMatrix();
	//Jupiter
	glPushMatrix();

		glColor3f(1.0, 0.0, 0.0);
		glPushMatrix();
			glRotatef(jupiter, 0.0, 1.0, 0.0);
			glTranslatef(11.5, 0.2, 0.2);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, JupiterDiffuse);
			glMaterialfv(GL_FRONT, GL_SPECULAR, JupiterSpecular);
			glMaterialfv(GL_FRONT, GL_SHININESS, JupiterShininess);
			glutSolidSphere(1.2, 12, 12);
		glPopMatrix();

		//luna1
		glRotatef(jupiter, 0.0, 1.0, 0.0);
		glPushMatrix();
			glTranslatef(11.5, 0.2, 0.2);
			glColor3f(0.957, 0.9, 0.9);
			glPushMatrix();
				glRotatef(lunaj1, 0.0, 0.0, 1.0);
				glTranslatef(1.6, 0.4, 0.2);
				glRotatef(lunaj1 + 5, 0.0, 1.0, 0.0);
				glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
				glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
				glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
				glutSolidSphere(0.1, 10, 10);
			glPopMatrix();
		glPopMatrix();
		//luna2
		glPushMatrix();
			glTranslatef(11.5, 0.2, 0.2);
			glColor3f(0.957, 0.9, 0.9);
			glRotatef(lunaj2, 0.0, 0.0, 1.0);
			glTranslatef(1.9, 0.4, 0.2);
			glRotatef(lunaj2 + 5, 0.0, 1.0, 0.0);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
			glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
			glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
			glutSolidSphere(0.1, 10, 10);
		glPopMatrix();
		//luna3
		glPushMatrix();
			glTranslatef(11.5, 0.2, 0.2);
			glColor3f(0.957, 0.9, 0.9);
			glRotatef(lunaj3, 0.0, 0.0, 1.0);
			glTranslatef(2.2, 0.4, 0.2);
			glRotatef(lunaj3 + 5, 0.0, 1.0, 0.0);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
			glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
			glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
			glutSolidSphere(0.1, 10, 10);
		glPopMatrix();
		//luna4
		glPushMatrix();
			glTranslatef(11.5, 0.2, 0.2);
			glColor3f(0.957, 0.9, 0.9);
			glRotatef(lunaj4, 0.0, 0.0, 1.0);
			glTranslatef(2.5, 0.4, 0.2);
			glRotatef(lunaj4 + 5, 0.0, 1.0, 0.0);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
			glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
			glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
			glutSolidSphere(0.1, 10, 10);
		glPopMatrix();

	glPopMatrix();

//Saturno
	glPushMatrix();

		glColor3f(1.0, 1.0, 0.0);
		glRotatef(saturno, 0.0, 1.0, 0.0);
		glTranslatef(16.5, 0.2, 0.2);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, SaturnoDiffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, SaturnoSpecular);
		glMaterialfv(GL_FRONT, GL_SHININESS, SaturnoShininess);
		glutSolidSphere(0.7, 12, 12);
		glColor3f(1.0, 0.0, 0.0);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
		glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
		glutWireTorus(0.15, 0.8, 10, 10);

	glPopMatrix();

//urano
	glPushMatrix();

		glColor3f(0.5, 1.0, 1.0);
		glRotatef(urano, 0.0, 1.0, 0.0);
		glTranslatef(20.0, 0.2, 0.2);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, UranoDiffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, UranoSpecular);
		glMaterialfv(GL_FRONT, GL_SHININESS, UranoShininess);
		glutSolidSphere(0.7, 12, 12);
		glColor3f(1.0, 0.0, 0.0);

	glPopMatrix();

//neptuno
	glPushMatrix();

		glColor3f(0.4, 0.0, 1.0);
		glRotatef(neptuno, 0.0, 1.0, 0.0);
		glTranslatef(22.5, 0.2, 0.2);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, NeptunoDiffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, NeptunoSpecular);
		glMaterialfv(GL_FRONT, GL_SHININESS, NeptunoShininess);
		glutSolidSphere(0.6, 12, 12);
		glColor3f(1.0, 0.0, 0.0);

	glPopMatrix();


	glutSwapBuffers();

}

void animacion()
{
	// Calculate the number of frames per one second:
	//dwFrames++;
	dwCurrentTime = GetTickCount(); // Even better to use timeGetTime()
	dwElapsedTime = dwCurrentTime - dwLastUpdateTime;

	if (dwElapsedTime >= 30)
	{
		sol = (sol - 1) % 360;
		mercurio = (mercurio - 6) % 360;
		venus = (venus - 7) % 360;
		tierra = (tierra - 1) % 360;
		luna = (luna - 4) % 360;
		marte = (marte - 4) % 360;
		jupiter = (jupiter - 2) % 360;
		lunaj1 = (lunaj1 - 2) % 360;
		lunaj2 = (lunaj2 - 3) % 360;
		lunaj3 = (lunaj3 - 4) % 360;
		lunaj4= (lunaj4 - 5) % 360;
		saturno = (saturno - 3) % 360;
		urano = (urano - 5) % 360;
		neptuno = (neptuno - 4) % 360;
		dwLastUpdateTime = dwCurrentTime;
	}

	glutPostRedisplay();
}

void reshape(int width, int height)   // Creamos funcion Reshape
{
	if (height == 0)										// Prevenir division entre cero
	{
		height = 1;
	}

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista

	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
														//glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {
	case 'w':   //Movimientos de camara
	case 'W':
		camaraZ += 0.5f;
		break;
	case 's':
	case 'S':
		camaraZ -= 0.5f;
		break;
	case 'a':
	case 'A':
		camaraX -= 0.5f;
		break;
	case 'd':
	case 'D':
		camaraX += 0.5f;
		break;

	case 'i':		//Movimientos de Luz
	case 'I':

		break;
	case 'k':
	case 'K':

		break;

	case 'l':   //Activamos/desactivamos luz
	case 'L':
		break;
	case 27:        // Cuando Esc es presionado...
		exit(0);   // Salimos del programa
		break;
	default:        // Cualquier otra
		break;
	}
	glutPostRedisplay();
}

void arrow_keys(int a_keys, int x, int y)  // Funcion para manejo de teclas especiales (arrow keys)
{
	switch (a_keys) {
	case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...

		break;
	case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...

		break;
	case GLUT_KEY_LEFT:

		break;
	case GLUT_KEY_RIGHT:

		break;
	default:
		break;
	}
	glutPostRedisplay();
}


int main(int argc, char** argv)   // Main Function
{
	glutInit(&argc, argv); // Inicializamos OpenGL
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
	glutInitWindowSize(500, 500);	// Tamaño de la Ventana
	glutInitWindowPosition(20, 60);	//Posicion de la Ventana
	glutCreateWindow("Practica 6"); // Nombre de la Ventana
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutIdleFunc(animacion);
	glutMainLoop();          // 

	return 0;
}