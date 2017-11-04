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
int i = 0;
bool inicializarframes = true;
float posX, posY, posZ;
float angleX = 0.0f;
float angleY = 0.0f;
float angMano=0.0f;
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

//Arreglos 
float cero[10] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
float piedra[10] = { -54.0, -51.0, 42.0, 30.0, 42.0, 30.0, 42.0, 30.0, 42.0, 24.0 };
float tijera[10] = { -37.5, -51.0, 0.0, 0.0, 0.0, 0.0, 42.0, 30.0, 42.0, 27.0 };

#define MAX_FRAMES 60//El maximo de frames
int i_max_steps = 90;//Frames intermedios, mas bajo==mas rapido
int i_curr_steps = 0;

typedef struct _frame
{
	//Variables para GUARDAR Key Frames
	float posX;		//Variable para PosicionX
	float posY;		//Variable para PosicionY
	float posZ;		//Variable para PosicionZ
	float incX;		//Variable para IncrementoX
	float incY;		//Variable para IncrementoY
	float incZ;		//Variable para IncrementoZ
	float angPulgar1;
	float angPulgar2;
	float angIndice1;
	float angIndice2;
	float angMedio1;
	float angMedio2;
	float angAnular1;
	float angAnular2;
	float angMenique1;
	float angMenique2;

	float angPulgar1Inc;
	float angPulgar2Inc;
	float angIndice1Inc;
	float angIndice2Inc;
	float angMedio1Inc;
	float angMedio2Inc;
	float angAnular1Inc;
	float angAnular2Inc;
	float angMenique1Inc;
	float angMenique2Inc;
}FRAME;

FRAME KeyFrame[MAX_FRAMES];
int FrameIndex = 0;			//introducir datos
bool play = false;
int playIndex = 0;

int w = 500, h = 500;
int frame = 0, time, timebase = 0;
char s[30];

GLfloat Position[]= { 0.0f, 3.0f, 0.0f, 1.0f };			// Light Position
GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

void saveFrame(void) // se modifico 
{

	printf("frameindex %d\n", FrameIndex);

	KeyFrame[FrameIndex].posX = posX;
	KeyFrame[FrameIndex].posY = posY;
	KeyFrame[FrameIndex].posZ = posZ;

	KeyFrame[FrameIndex].angPulgar1 = angPulgar1;
	KeyFrame[FrameIndex].angPulgar2 = angPulgar2;
	KeyFrame[FrameIndex].angIndice1 = angIndice1;
	KeyFrame[FrameIndex].angIndice2 = angIndice2;
	KeyFrame[FrameIndex].angMedio1 = angMedio1;
	KeyFrame[FrameIndex].angMedio2 = angMedio2;
	KeyFrame[FrameIndex].angAnular1 = angAnular1;
	KeyFrame[FrameIndex].angAnular2 = angAnular2;
	KeyFrame[FrameIndex].angMenique1 = angIndice1;
	KeyFrame[FrameIndex].angMenique2 = angIndice2;

	FrameIndex++;


}

void resetElements(void)
{
	posX = KeyFrame[0].posX;
	posY = KeyFrame[0].posY;
	posZ = KeyFrame[0].posZ;
	angPulgar1 = KeyFrame[0].angPulgar1;
	angPulgar2 = KeyFrame[0].angPulgar2;
	angIndice1 = KeyFrame[0].angIndice1;
	angIndice2 = KeyFrame[0].angIndice2;
	angMedio1 = KeyFrame[0].angMedio1;
	angMedio2 = KeyFrame[0].angMedio2;
	angAnular1 = KeyFrame[0].angAnular1;
	angAnular2 = KeyFrame[0].angAnular2;
	angMenique1 = KeyFrame[0].angMenique1;
	angMenique2 = KeyFrame[0].angMenique2;

}

void interpolation(void) //se modifico
{
	KeyFrame[playIndex].incX = (KeyFrame[playIndex + 1].posX - KeyFrame[playIndex].posX) / i_max_steps;
	KeyFrame[playIndex].incY = (KeyFrame[playIndex + 1].posY - KeyFrame[playIndex].posY) / i_max_steps;
	KeyFrame[playIndex].incZ = (KeyFrame[playIndex + 1].posZ - KeyFrame[playIndex].posZ) / i_max_steps;

	KeyFrame[playIndex].angPulgar1Inc = (KeyFrame[playIndex + 1].angPulgar1 - KeyFrame[playIndex].angPulgar1) / i_max_steps;
	KeyFrame[playIndex].angPulgar2Inc = (KeyFrame[playIndex + 1].angPulgar2 - KeyFrame[playIndex].angPulgar2) / i_max_steps;
	KeyFrame[playIndex].angIndice1Inc = (KeyFrame[playIndex + 1].angIndice1 - KeyFrame[playIndex].angIndice1) / i_max_steps;
	KeyFrame[playIndex].angIndice2Inc = (KeyFrame[playIndex + 1].angIndice2 - KeyFrame[playIndex].angIndice2) / i_max_steps;
	KeyFrame[playIndex].angMedio1Inc = (KeyFrame[playIndex + 1].angMedio1 - KeyFrame[playIndex].angMedio1) / i_max_steps;
	KeyFrame[playIndex].angMedio2Inc = (KeyFrame[playIndex + 1].angMedio2 - KeyFrame[playIndex].angMedio2) / i_max_steps;
	KeyFrame[playIndex].angAnular1Inc = (KeyFrame[playIndex + 1].angAnular1 - KeyFrame[playIndex].angAnular1) / i_max_steps;
	KeyFrame[playIndex].angAnular2Inc = (KeyFrame[playIndex + 1].angAnular2 - KeyFrame[playIndex].angAnular2) / i_max_steps;
	KeyFrame[playIndex].angMenique1Inc = (KeyFrame[playIndex + 1].angMenique1 - KeyFrame[playIndex].angMenique1) / i_max_steps;
	KeyFrame[playIndex].angMenique2Inc = (KeyFrame[playIndex + 1].angMenique2 - KeyFrame[playIndex].angMenique2) / i_max_steps;

}



void InitGL ( void )     // Inicializamos parametros
{

	glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing


	//NEW Iniciar variables de KeyFrames
	for (int i = 0; i<MAX_FRAMES; i++)
	{
		KeyFrame[i].posX = 0;
		KeyFrame[i].posY = 0;
		KeyFrame[i].posZ = 0;
		KeyFrame[i].incX = 0;
		KeyFrame[i].incY = 0;
		KeyFrame[i].incZ = 0;
		KeyFrame[i].angPulgar1 = 0;
		KeyFrame[i].angPulgar2 = 0;
		KeyFrame[i].angIndice1 = 0;
		KeyFrame[i].angIndice2 = 0;
		KeyFrame[i].angMedio1 = 0;
		KeyFrame[i].angMedio2 = 0;
		KeyFrame[i].angAnular1 = 0;
		KeyFrame[i].angAnular2 = 0;
		KeyFrame[i].angMenique1 = 0;
		KeyFrame[i].angMenique2 = 0;
	}
}

void animacion()
{

	//Movimiento del monito
	if (play)
	{

		if (i_curr_steps >= i_max_steps) //end of animation between frames?
		{
			playIndex++;
			if (playIndex>FrameIndex - 2)	//end of total animation?
			{
				printf("termina anim\n");
				playIndex = 0;
				play = false;
			}
			else //Next frame interpolations
			{
				i_curr_steps = 0; //Reset counter
								  //Interpolation
				interpolation();

			}
		}
		else //se modifico
		{
			//Draw animation
			posX += KeyFrame[playIndex].incX;
			posY += KeyFrame[playIndex].incY;
			posZ += KeyFrame[playIndex].incZ;
			angPulgar1 += KeyFrame[playIndex].angPulgar1Inc;
			angPulgar2 += KeyFrame[playIndex].angPulgar2Inc;
			angIndice1 += KeyFrame[playIndex].angIndice1Inc;
			angIndice2 += KeyFrame[playIndex].angIndice2Inc;
			angMedio1 += KeyFrame[playIndex].angMedio1Inc;
			angMedio2 += KeyFrame[playIndex].angMedio2Inc;
			angAnular1 += KeyFrame[playIndex].angAnular1Inc;
			angAnular2 += KeyFrame[playIndex].angAnular2Inc;
			angMenique1 += KeyFrame[playIndex].angMenique1Inc;
			angMenique2 += KeyFrame[playIndex].angMenique2Inc;


			i_curr_steps++;
		}

	}


	glutPostRedisplay();
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

void frames () {
	//inicial
	KeyFrame[FrameIndex].angPulgar1 = cero[0];
	KeyFrame[FrameIndex].angPulgar2 = cero[1];
	KeyFrame[FrameIndex].angIndice1 = cero[2];
	KeyFrame[FrameIndex].angIndice2 = cero[3];
	KeyFrame[FrameIndex].angMedio1 = cero[4];
	KeyFrame[FrameIndex].angMedio1 = cero[5];
	KeyFrame[FrameIndex].angAnular1 = cero[6];
	KeyFrame[FrameIndex].angAnular2 = cero[7];
	KeyFrame[FrameIndex].angMenique1 = cero[8];
	KeyFrame[FrameIndex].angMenique2 = cero[9];

	FrameIndex++;
	//piedra
	for (i = 0; i <= 3; i++) {
			KeyFrame[FrameIndex].angPulgar1 = piedra[0];
			KeyFrame[FrameIndex].angPulgar2 = piedra[1];
			KeyFrame[FrameIndex].angIndice1 = piedra[2];
			KeyFrame[FrameIndex].angIndice2 = piedra[3];
			KeyFrame[FrameIndex].angMedio1 = piedra[4];
			KeyFrame[FrameIndex].angMedio1 = piedra[5];
			KeyFrame[FrameIndex].angAnular1 = piedra[6];
			KeyFrame[FrameIndex].angAnular2 = piedra[7];
			KeyFrame[FrameIndex].angMenique1 = piedra[8];
			KeyFrame[FrameIndex].angMenique2 = piedra[9];

			FrameIndex++;
	}
	//papel
	for (i = 0; i <= 3; i++) {
		KeyFrame[FrameIndex].angPulgar1 = cero[0];
		KeyFrame[FrameIndex].angPulgar2 = cero[1];
		KeyFrame[FrameIndex].angIndice1 = cero[2];
		KeyFrame[FrameIndex].angIndice2 = cero[3];
		KeyFrame[FrameIndex].angMedio1 = cero[4];
		KeyFrame[FrameIndex].angMedio1 = cero[5];
		KeyFrame[FrameIndex].angAnular1 = cero[6];
		KeyFrame[FrameIndex].angAnular2 = cero[7];
		KeyFrame[FrameIndex].angMenique1 = cero[8];
		KeyFrame[FrameIndex].angMenique2 = cero[9];

		FrameIndex++;
	}
	//tijera
	for (i = 0; i <= 3; i++) {
		KeyFrame[FrameIndex].angPulgar1 = tijera[0];
		KeyFrame[FrameIndex].angPulgar2 = tijera[1];
		KeyFrame[FrameIndex].angIndice1 = tijera[2];
		KeyFrame[FrameIndex].angIndice2 = tijera[3];
		KeyFrame[FrameIndex].angMedio1 = tijera[4];
		KeyFrame[FrameIndex].angMedio1 = tijera[5];
		KeyFrame[FrameIndex].angAnular1 = tijera[6];
		KeyFrame[FrameIndex].angAnular2 = tijera[7];
		KeyFrame[FrameIndex].angMenique1 = tijera[8];
		KeyFrame[FrameIndex].angMenique2 = tijera[9];

		FrameIndex++;
	}
}
void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
	//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//Poner Código Aquí.
	glEnable(GL_COLOR_MATERIAL);
//Brazo detallado
	glRotatef(180, 0, 0, 1);
	glTranslatef(0, 0.6, -1.8);
	glPushMatrix();
		glRotatef(179, 0, 1, 0);
		glRotatef(20.0, 1.0, 0.0, 0.0);
		glRotatef(angleY, 0.0, 1.0, 0.0);
		glRotatef(angleX, 1.0, 0.0, 0.0);
		glTranslatef(posX, posY, posZ);
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
	glDisable(GL_COLOR_MATERIAL);
  											
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
		case 'o':		//
		case 'O':
			if (FrameIndex<MAX_FRAMES)
			{
				//saveFrame();
			}

		break;
	
		case 'p':
		case 'P':
			if (inicializarframes == true) {
				frames();
				inicializarframes = false;
			}

			if (play == false && (FrameIndex>1))
			{

				resetElements();
				//First Interpolation				
				interpolation();

				play = true;
				playIndex = 0;
				i_curr_steps = 0;
			}
			else
			{
				play = false;
			}
			break;
		//Pulgar
		case 'K':
			if (angPulgar1<6.0)
				angPulgar1 = angPulgar1 + 1.5f;
			break;
		case 'k':
			if (angPulgar1>-83.5)
				angPulgar1 = angPulgar1 - 1.5f;
			break;
		case 'L':
			if (angPulgar2<=0.0)
				angPulgar2 = angPulgar2 + 1.5f;
			break;
		case 'l':
			if (angPulgar2>-76.0)
				angPulgar2 = angPulgar2 - 1.5f;
			break;
		//indice
		case 'z':
			if ( angIndice1<41.0)
				angIndice1 = angIndice1 + 1.5f;
			break;
		case 'Z':
			if (angIndice1>-3.0)
				angIndice1 = angIndice1 - 1.5f;
			break;
		case 'x':
			if (angIndice2<29.0)
				angIndice2 = angIndice2 + 1.5f;
			break;
		case 'X':
			if (angIndice2>-2.0)
				angIndice2 = angIndice2 - 1.5f;
			break;
		//medio
		case 'c':
			if (angMedio1<41.0)
				angMedio1 = angMedio1 + 1.5f;
			break;
		case 'C':
			if (angMedio1>-3.0)
			angMedio1 = angMedio1 - 1.5f;
			break;
		case 'v':
			if (angMedio2<29.0)
				angMedio2= angMedio2 + 1.5f;
			break;
		case 'V':
			if (angMedio2>-2.0)
			angMedio2 = angMedio2 - 1.5f;
			break;
	    //anular
		case 'b':
			if (angAnular1<41.0)
				angAnular1 = angAnular1 + 1.5f;
			break;
		case 'B':
			if (angAnular1>-3.0)
				angAnular1 = angAnular1 - 1.5f;
			break;
		case 'n':
			if (angAnular2<29.0)
				angAnular2 = angAnular2 + 1.5f;
			break;
		case 'N':
			if (angAnular2>-2.0)
			angAnular2 = angAnular2 - 1.5f;
			break;
		//Menique
		case 'f':
			if (angMenique1<41.0)
				angMenique1 = angMenique1 + 1.5f;
			break;
		case 'F':
			if (angMenique1>-3.0)
				angMenique1 = angMenique1 - 1.5f;
			break;
		case 'g':
			if (angMenique2<29.0)
				angMenique2 = angMenique2 + 1.5f;
			break;
		case 'G':
			if (angMenique2>-2.0)
				angMenique2 = angMenique2 - 1.5f;
			break;
		case 'w':
		case 'W':
			posZ +=0.2f;
			break;
		case 's':
		case 'S':
			posZ -=0.2f;
			break;
		case 'a':
		case 'A':
			posX +=0.2f;
			break;
		case 'd':
		case 'D':
			posX -=0.2f;
			break;
		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
		break;        
		default:        // Cualquier otra
		break;
  }

  printf ("%.2f \n",  angPulgar1);
  printf ("%.2f \n",  angPulgar2);
  printf ("%.2f \n",  angIndice1);
  printf ("%.2f \n",  angIndice2);
  printf ("%.2f \n",  angMedio1);
  printf ("%.2f \n",  angMedio2);
  printf ("%.2f \n",  angAnular1);
  printf ("%.2f \n",  angAnular2);
  printf ("%.2f \n",  angMenique1);
  printf ("%.2f \n\n",  angMenique2);

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

void menuKeyFrame(int id)
{
	switch (id)
	{
	case 0:	//Save KeyFrame
		if (FrameIndex<MAX_FRAMES)
		{
			saveFrame();
		}
		break;

	case 1:	//Play animation
		if (play == false && FrameIndex >1)
		{

			resetElements();
			//First Interpolation
			interpolation();

			play = true;
			playIndex = 0;
			i_curr_steps = 0;
		}
		else
		{
			play = false;
		}
		break;


	}
}


void menu(int id)
{

}

int main ( int argc, char** argv )   // Main Function
{
  int submenu;
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  screenW = glutGet(GLUT_SCREEN_WIDTH);
  screenH = glutGet(GLUT_SCREEN_HEIGHT);
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 11"); // Nombre de la Ventana
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc(animacion);

  submenu = glutCreateMenu(menuKeyFrame);
  glutAddMenuEntry("Guardar KeyFrame", 0);
  glutAddMenuEntry("Reproducir Animacion", 1);
  glutCreateMenu(menu);
  glutAddSubMenu("Animacion Monito", submenu);
  
  glutMainLoop        ( );          // 
  
  return 0;
  }



