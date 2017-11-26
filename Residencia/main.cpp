//Semestre 2018 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************											******//
//*************											******//
//************************************************************//
//************************************************************//

#include "texture.h"
//#include "figuras.h"
#include "Camera.h"
#include "Figures.h"

//	Prototipos de funciones
void fachada();
void refrigerador();
void silla();
void arbol();
void cocina();
void sillon_uno();
void mesa_centro();
void divisiones();

/*int w = 500, h = 500;
int frame=0,time,timebase=0;
int deltaTime = 0;*/

//	Objeto para dibujar figuras
//CFiguras figures;
Figures figures;

CCamera objCamera;	//Create objet Camera

GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW) 

GLfloat Diffuse[]= { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[]= { 0.0f, 7.0f, -5.0f, 0.0f };			// Light Position
GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

float xx=0.0, yy = 0.0, zz = 0.0;

//CTexture text1;
//CTexture text2;
//CTexture text3;	//Flecha

//	Texturas para el refrigerador
CTexture cuarzo;
CTexture metal_cromo;
CTexture pared_interior;
CTexture puertaFrente;
CTexture garage;

//CTexture tree;

//CFiguras sky;
const double PI = 3.1415926535897;
void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo	

	glEnable(GL_TEXTURE_2D);

	glShadeModel (GL_SMOOTH);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable ( GL_COLOR_MATERIAL );

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);

	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.3f);


	//	Texturas
	cuarzo.LoadTGA("textures/cuarzo.tga");
	cuarzo.BuildGLTexture();
	cuarzo.ReleaseImage();

	metal_cromo.LoadTGA("textures/metal_cromo.tga");
	metal_cromo.BuildGLTexture();
	metal_cromo.ReleaseImage();

	pared_interior.LoadTGA("textures/pared_interior_5.tga");
	pared_interior.BuildGLTexture();
	pared_interior.ReleaseImage();

	puertaFrente.LoadTGA("textures/puerta.tga");
	puertaFrente.BuildGLTexture();
	puertaFrente.ReleaseImage();

	garage.LoadTGA("textures/garage.tga");
	garage.BuildGLTexture();
	garage.ReleaseImage();

	//	posicion     (0, 2.5, 3)
	//	hacia donde  (0, 2.5, 0)
	//	inclinación  (0, 1, 0)
	objCamera.Position_Camera(9.5, 2.5f, 40, 9.5, 2.5f, 38, 0, 1, 0);

}

void puertas(void){

	//Puerta Frontal
	glPushMatrix();
		glTranslatef(4.8, 5.0, -0.4);
		glScalef(4, 8, 1);
		glBindTexture(GL_TEXTURE_2D, puertaFrente.GLindex);
		glBegin(GL_QUADS);
			glTexCoord2f(1, 0); glVertex3f(0.5, -0.5, 0.5);
			glTexCoord2f(0, 0); glVertex3f(-0.5, -0.5, 0.5);
			glTexCoord2f(0, 1); glVertex3f(-0.5, 0.5, 0.5);
			glTexCoord2f(1, 1); glVertex3f(0.5, 0.5, 0.5);
		glEnd();

	glPopMatrix();

	//Puerta garage
	glPushMatrix();
		glTranslatef(-6, 2.4, -6.99);
		glScalef(8, 4.8, 1);
		glBindTexture(GL_TEXTURE_2D, garage.GLindex);
		glBegin(GL_QUADS);
			glTexCoord2f(1, 0); glVertex3f(0.5, -0.5, 0.5);
			glTexCoord2f(0, 0); glVertex3f(-0.5, -0.5, 0.5);
			glTexCoord2f(0, 1); glVertex3f(-0.5, 0.5, 0.5);
			glTexCoord2f(1, 1); glVertex3f(0.5, 0.5, 0.5);
		glEnd();
	glPopMatrix();

}

void cocina(void){

	glPushMatrix();
		glTranslatef(5, 5, 30);
		refrigerador();
	glPopMatrix();

}


void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();
	
		
	glPushMatrix();
		glRotatef(g_lookupdown,1.0f,0,0);

		gluLookAt(	objCamera.mPos.x,  objCamera.mPos.y,  objCamera.mPos.z,	
					objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,	
					objCamera.mUp.x,   objCamera.mUp.y,   objCamera.mUp.z);
	

		glPushMatrix();		
			
			/*glPushMatrix(); //Creamos cielo
				glDisable(GL_LIGHTING);
				glTranslatef(0,60,0);
				sky.skybox(130.0, 130.0, 130.0,text1.GLindex);
				glEnable(GL_LIGHTING);
				glColor3f(1.0,1.0,1.0);
			glPopMatrix();*/


			//	Ejes de referencia
			glPushMatrix();
			glBegin(GL_LINES);
			glVertex3f(0.0, 0.0, 0.0);
			glVertex3f(100.0, 0.0, 0.0);

			glVertex3f(0.0, 0.0, 0.0);
			glVertex3f(0.0, 100.0, 0.0);

			glVertex3f(0.0, 0.0, 0.0);
			glVertex3f(0.0, 0.0, 100.0);
			glEnd();
			glPopMatrix();

			cocina();

			glPushMatrix();
			glTranslatef(10,5,30);
			silla();
			glPopMatrix();

			glPushMatrix();
			glTranslatef(15,5,30);
			sillon_uno();
			glPopMatrix();

			glPushMatrix();
			glTranslatef(20,5,30);
			mesa_centro();
			glPopMatrix();

			glDisable(GL_LIGHTING);
			fachada();
			divisiones();
			puertas();
			glEnable(GL_LIGHTING);

		glPopMatrix(); 

	glPopMatrix();

	glutSwapBuffers();
}

void animacion()
{
	glutPostRedisplay();
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
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 170.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {

		case 'w':   //Movimientos de camara
		case 'W':
			objCamera.Move_Camera( CAMERASPEED+0.2 );
			break;

		case 's':
		case 'S':
			objCamera.Move_Camera(-(CAMERASPEED+0.2));
			break;

		case 'a':
		case 'A':
			objCamera.Strafe_Camera(-(CAMERASPEED+0.4));
			break;

		case 'd':
		case 'D':
			objCamera.Strafe_Camera( CAMERASPEED+0.4 );
			break;

		case 'q':
		case 'Q':
			objCamera.UpDown_Camera(CAMERASPEED+0.2);
			break;

		case 'z':
		case 'Z':
			objCamera.UpDown_Camera(-(CAMERASPEED+0.2));
			break;

		case 'u':
		case 'U':
			zz -= 0.2;
			break;

		case 'j':
		case 'J':
			zz += 0.2;
			break;

		case 'h':
		case 'H':
			xx -= 0.2;
			break;

		case 'k':
		case 'K':
			xx += 0.2;
			break;

		case 'y':
		case 'Y':
			yy += 0.2;
			break;

		case 'n':
		case 'N':
			yy -= 0.2;
			break;

		case 'l':
		case 'L':
			printf("(%f,%f,%f)", xx,yy,zz);
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
		objCamera.UpDown_Camera(CAMERASPEED);
		break;

	case GLUT_KEY_PAGE_DOWN:
		objCamera.UpDown_Camera(-CAMERASPEED);
		break;

    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		g_lookupdown -= 1.0f;
		break;

    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		g_lookupdown += 1.0f;
		break;

	case GLUT_KEY_LEFT:
		objCamera.Rotate_View(-CAMERASPEED);
		break;

	case GLUT_KEY_RIGHT:
		objCamera.Rotate_View( CAMERASPEED);
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
  glutInitWindowSize  (2000, 2000);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Jerarquia"); // Nombre de la Ventana
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



void refrigerador()
{
	glTranslatef(1, 1.25, -0.4);

	//	Principal (trasera)
	glPushMatrix();
		glScalef(2, 2.5, 0.8);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	//	Delantera (izquierda)
	glPushMatrix();
		glTranslatef(-0.95, -1.3505, 0.55);
		figures.u_cilindro(0.05, 0.1, 6, metal_cromo.GLindex);
	glPopMatrix();

	//	Delantera (derecha)
	glPushMatrix();
		glTranslatef(0.95, -1.3505, 0.55);
		figures.u_cilindro(0.05, 0.1, 6, metal_cromo.GLindex);
	glPopMatrix();

	//	Trasera (izquierda)
	glPushMatrix();
		glTranslatef(-0.95, -1.3505, -0.35);
		figures.u_cilindro(0.05, 0.1, 6, metal_cromo.GLindex);
	glPopMatrix();

	//	Trasera (derecha)
	glPushMatrix();
		glTranslatef(0.95, -1.3505, -0.35);
		figures.u_cilindro(0.05, 0.1, 6, metal_cromo.GLindex);
	glPopMatrix();

	//	Principal (delantera, abajo)
	glPushMatrix();
		glTranslatef(0, -0.505, 0.505);

		//	Manija (superior)
		glPushMatrix();
			glTranslatef(-0.7, 0.3, 0.130);
			glScalef(0.05, 0.1, 0.05);
			figures.u_prisma(metal_cromo.GLindex);
		glPopMatrix();

		//	Manija (cilindro)
		glPushMatrix();
			glTranslatef(-0.7, -0.35, 0.150);
			figures.u_cilindro(0.025, 0.7, 6, metal_cromo.GLindex);
		glPopMatrix();

		//	Manija (inferior)
		glPushMatrix();
			glTranslatef(-0.7, -0.3, 0.130);
			glScalef(0.05, 0.1, 0.05);
			figures.u_prisma(metal_cromo.GLindex);
		glPopMatrix();

		glScalef(2, 1.5, 0.2);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	//	Principal (delantera, arriba)
	glPushMatrix();
		glTranslatef(0, 0.7505, 0.505);

		//	Manija (superior)
		glPushMatrix();
			glTranslatef(-0.7, 0.25, 0.130);
			glScalef(0.05, 0.1, 0.05);
			figures.u_prisma(metal_cromo.GLindex);
		glPopMatrix();

		//	Manija (cilindro)
		glPushMatrix();
			glTranslatef(-0.7, -0.3, 0.150);
			figures.u_cilindro(0.025, 0.6, 6, metal_cromo.GLindex);
		glPopMatrix();

		//	Manija (inferior)
		glPushMatrix();
			glTranslatef(-0.7, -0.25, 0.130);
			glScalef(0.05, 0.1, 0.05);
			figures.u_prisma(metal_cromo.GLindex);
		glPopMatrix();

		glScalef(2, 1, 0.2);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();
	
}

void silla()
{
	glTranslatef(0.5,0.5,0.5);

	//RESPALDO
	glPushMatrix();
	glTranslatef(0,1.0,-0.45);
	glPushMatrix();
	glTranslatef(0,0.75,0.06);
	glRotatef(-90,1,0,0);
	glColor3f(0,1,0);
	figures.u_medio_cilindro(0.5,0.125,30,0);
	glPopMatrix();
	glPushMatrix();
	
	glPopMatrix();
	glScalef(1.0,1.5,0.125);
	glColor3f(0,1,0);
	figures.u_prisma(0);
	glPopMatrix();
	glColor3f(1,1,0);
	//PATA 1
	glPushMatrix();
	glTranslatef(0.375,-1,0.375);
	glScalef(0.25,1.5,0.25);
	figures.u_prisma(0);
	glPopMatrix();
	//PATA  2
	glPushMatrix();
	glTranslatef(-0.375,-1,0.375);
	glScalef(0.25,1.5,0.25);
	figures.u_prisma(0);
	glPopMatrix();
	//PATA 3
	glPushMatrix();
	glTranslatef(-0.375,-1,-0.375);
	glScalef(0.25,1.5,0.25);
	figures.u_prisma(0);
	glPopMatrix();
	//PATA 4
	glPushMatrix();
	glTranslatef(0.375,-1,-0.375);
	glScalef(0.25,1.5,0.25);
	figures.u_prisma(0);
	glPopMatrix();
	glScalef(1,0.5,1);
	glColor3f(1,0,0);
	figures.u_prisma(0);
	glColor3f(1,1,1);
}

void arbol()
{
	glPushMatrix();
					glDisable(GL_LIGHTING);
					glEnable( GL_ALPHA_TEST );
					//glDisable(GL_DEPTH_TEST);   // Turn Depth Testing Off
					glAlphaFunc( GL_GREATER, 0.1 );
					//glEnable(GL_BLEND);     // Turn Blending On
					//glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
					//glBindTexture(GL_TEXTURE_2D, tree.GLindex);
					glBegin(GL_QUADS); //plano
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f( 0.0f, 0.0f, 1.0f);
						glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
						glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
					glEnd();
			glPopMatrix();

			glPushMatrix();
					glRotatef(45, 0, 1, 0);
					glBegin(GL_QUADS); //plano
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f( 0.0f, 0.0f, 1.0f);
						glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
						glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
					glEnd();
			glPopMatrix();

			glPushMatrix();
					glRotatef(-45, 0, 1, 0);
					glBegin(GL_QUADS); //plano
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f( 0.0f, 0.0f, 1.0f);
						glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
						glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
					glEnd();
			glPopMatrix();

			glPushMatrix();
					glRotatef(90, 0, 1, 0);
					glBegin(GL_QUADS); //plano
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f( 0.0f, 0.0f, 1.0f);
						glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
						glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
					glEnd();
					glDisable( GL_ALPHA_TEST );
					//glDisable(GL_BLEND);        // Turn Blending Off
					//glEnable(GL_DEPTH_TEST);    // Turn Depth Testing On
					glEnable(GL_LIGHTING);
				
			glPopMatrix();
}

void sillon_uno()
{
	glPushMatrix(); //PUSH DE PRISMA PRINCIPAL
	/*glPushMatrix();
	glTranslatef(0,0.75,0.0);
	glScalef(2.5,0.5,1.5);
	glColor3f(0,0,1);
	figures.u_prisma(0);
	glPopMatrix();*/
	glPushMatrix();
	glTranslatef(1.20,0.5,0.5);
	glColor3f(0,0,1);
	glRotatef(-90,1,0,0);
	figures.u_medio_cilindro(0.30,0.75,30,0);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-1.20,0.5,0.5);
	glColor3f(0,0,1);
	glRotatef(-90,1,0,0);
	figures.u_medio_cilindro(0.30,0.75,30,0);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0,1,-0.375);
	glScalef(3,1,0.25);
	glColor3f(0,1,1);
	figures.u_prisma(0);
	glPopMatrix();
	glPushMatrix(); //pata del sillon 1 derecha
	glTranslatef(1.3,-0.75,0.40);
	glColor3f(0,1,0);
	figures.u_cilindro(0.1,0.25,5,0);
	glPopMatrix();
	glPushMatrix(); //pata del sillon 2 
	glTranslatef(1.3,-0.75,-0.40);
	glColor3f(0,1,0);
	figures.u_cilindro(0.1,0.25,5,0);
	glPopMatrix();
	glPushMatrix(); //pata del sillon 3 izquierda
	glTranslatef(-1.3,-0.75,0.40);
	glColor3f(0,1,0);
	figures.u_cilindro(0.1,0.25,5,0);
	glPopMatrix();
	glPushMatrix(); //pata del sillon 4
	glTranslatef(-1.3,-0.75,-0.40);
	glColor3f(0,1,0);
	figures.u_cilindro(0.1,0.25,5,0);
	glPopMatrix();
	glScalef(3,1,1);
	glColor3f(1,1,0);
	figures.u_prisma(0);
	glPopMatrix();
	glColor3f(1,1,1);
}

void mesa_centro()
{

	glPushMatrix();



	glColor3f(0.75,1,0.25);
	figures.u_cilindro(0.5,0.1,30,0);
	for (int i = 0; i < 4; i++)
	{
		glPushMatrix();
		glColor3f(1,0.25,0.5);
		glTranslatef(0.4*cos(PI/2 * i),-0.5,0.4*sin(PI/2 * i));
		figures.u_cilindro(0.05,0.5,5,0);
		glPopMatrix();
	}
	
	glPopMatrix();
	glColor3f(1,1,1);
}

void divisiones() {

	glPushMatrix();
		//	División entrada (derecha)
		glTranslatef(17, 3, -4.502);
		glScalef(18, 6, 9);
		figures.u_prisma(cuarzo.GLindex);
		/*glBindTexture(GL_TEXTURE_2D, cuarzo.GLindex);
		glBegin(GL_POLYGON);
			glNormal3f(-1, 0, 0);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(8, 0, 0);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(8, 0, -9);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(8, 6, -9);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(8, 6, 0);
		glEnd();*/
	glPopMatrix();

	glPushMatrix();
	//	División entrada (derecha sala)
	glTranslatef(9.5, 3, -17);
	glScalef(3, 6, 8);
	figures.u_prisma(cuarzo.GLindex);

	/*glBindTexture(GL_TEXTURE_2D, cuarzo.GLindex);
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(8, 0, -12);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(8, 0, -21);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(8, 6, -21);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(8, 6, -12);
	glEnd();*/
	glPopMatrix();

	glPushMatrix();
		glTranslatef(10, 3, -12.5);
		glScalef(4, 6, 1);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	//	División central entrada sala
	glPushMatrix();
	glTranslatef(8.5, 5.5, -10.5);
	glScalef(1, 0.5, 3);
	figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	//	División Pasillo Cochera
	glPushMatrix();
	glTranslatef(3, 2, -16.5);
	glScalef(6, 4, 1);
	figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	//	División Pasillo Cochera
	glPushMatrix();
	glTranslatef(3.5, 2, -20.5);
	glScalef(5, 4, 1);
	figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	//	División Pasillo Cochera
	glPushMatrix();
	glTranslatef(0.5, 2, -20);
	glScalef(1, 4, 2);
	figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	//	División Pasillo Cochera
	glPushMatrix();
	glTranslatef(0.5, 3.75, -18);
	glScalef(1, 0.5, 2);
	figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	//	ESCALERAS	
	glPushMatrix();	// 01
		glColor3f(1,1,0);
		glTranslatef(2, 0.25, -10);
		glScalef(4, 0.5, 2);
		figures.u_prisma(pared_interior.GLindex);
		glColor3f(1,1,1);
	glPopMatrix();

	glPushMatrix();	// 02
	glColor3f(1,1,0);
	glTranslatef(1.5, 0.5, -10.5);
	glScalef(3, 1, 1);
	figures.u_prisma(pared_interior.GLindex);
	glColor3f(1,1,1);
	glPopMatrix();

	glPushMatrix();	// 03
	glColor3f(1,1,0);
	glTranslatef(1.5, 0.75, -11.5);
	glScalef(3, 1.5, 1);
	figures.u_prisma(pared_interior.GLindex);
	glColor3f(1,1,1);
	glPopMatrix();

	glPushMatrix();	// 04
	glColor3f(1,1,0);
	glTranslatef(1.5, 1, -12.5);
	glScalef(3, 2, 1);
	figures.u_prisma(pared_interior.GLindex);
	glColor3f(1,1,1);
	glPopMatrix();

	glPushMatrix();	// 05
	glColor3f(1,1,0);
	glTranslatef(1.5, 1.25, -13.5);
	glScalef(3, 2.5, 1);
	figures.u_prisma(pared_interior.GLindex);
	glColor3f(1,1,1);
	glPopMatrix();

	glPushMatrix();	// 06
	glColor3f(1,1,0);
	glTranslatef(1.5, 1.5, -14.5);
	glScalef(3, 3, 1);
	figures.u_prisma(pared_interior.GLindex);
	glColor3f(1,1,1);
	glPopMatrix();

	glPushMatrix();	// 07
	glColor3f(1,1,0);
	glTranslatef(1.5, 1.75, -15.5);
	glScalef(3, 3.5, 1);
	figures.u_prisma(pared_interior.GLindex);
	glColor3f(1,1,1);
	glPopMatrix();

	//	Escalera (vuelta)
	glPushMatrix();	// 08-1
	glColor3f(1,1,0);
	glTranslatef(1.5, 3.5, -16.5);
	glScalef(3, 1.01, 1.01);
	figures.u_prisma(pared_interior.GLindex);
	glColor3f(1,1,1);
	glPopMatrix();

	glPushMatrix();	// 08-2
	glColor3f(1,1,0);
	glTranslatef(1.5, 3.75, -18);
	glScalef(3, 0.501, 4.01);
	figures.u_prisma(pared_interior.GLindex);
	glColor3f(1,1,1);
	glPopMatrix();

	glPushMatrix();	// 09
	glColor3f(1,1,0);
	glTranslatef(3.5, 4.25, -18);
	glScalef(1, 0.5, 4);
	figures.u_prisma(pared_interior.GLindex);
	glColor3f(1,1,1);
	glPopMatrix();

	glPushMatrix();	// 10
	glColor3f(1,1,0);
	glTranslatef(4.5, 4.5, -18);
	glScalef(1, 1, 4);
	figures.u_prisma(pared_interior.GLindex);
	glColor3f(1,1,1);
	glPopMatrix();

	glPushMatrix();	// 11
	glColor3f(1,1,0);
	glTranslatef(5.5, 4.75, -18);
	glScalef(1, 1.5, 4);
	figures.u_prisma(pared_interior.GLindex);
	glColor3f(1,1,1);
	glPopMatrix();

	glPushMatrix();	// 12
	glColor3f(1,1,0);
	glTranslatef(6.5, 5, -18);
	glScalef(1, 2, 4);
	figures.u_prisma(pared_interior.GLindex);
	glColor3f(1,1,1);
	glPopMatrix();

	glPushMatrix();	// 13
	glColor3f(1,1,0);
	glTranslatef(7.5, 5.25, -18);
	glScalef(1, 2.5, 4);
	figures.u_prisma(pared_interior.GLindex);
	glColor3f(1,1,1);
	glPopMatrix();

	glPushMatrix();	// 14
	glColor3f(1,1,0);
	glTranslatef(8.5, 5.5, -18);
	glScalef(1, 3, 4);
	figures.u_prisma(pared_interior.GLindex);
	glColor3f(1,1,1);
	glPopMatrix();

}

void fachada()
{
	glPushMatrix();

	glTranslatef(9.5, 10.5, -18);
	
	//	Figura A (central)
	glPushMatrix();
	glScalef(19, 21, -36);
	figures.u_prisma_no_derecha(metal_cromo.GLindex);	
	glPopMatrix();

	//	Figura B (garage)
	glPushMatrix();
	glColor3f(0, 1, 1);
	glTranslatef(-15.501, -7.5, 3.5);
	glScalef(12, 6, 16);
	figures.u_prisma(metal_cromo.GLindex);
	glPopMatrix();

	//	Figura C (sala)
	glColor3f(1, 1, 0);
	glPushMatrix();
	glTranslatef(20.501, -6.5, 5.5);
	glScalef(22, 8, 25);
	figures.u_prisma_no_izquierda(metal_cromo.GLindex);
	glPopMatrix();

	//	Cuartos (arriba)
	glColor3f(0, 1, 0);
	glPushMatrix();
	glTranslatef(15.01, 1.01, 5.5);
	glScalef(11, 7, 25);
	figures.u_prisma(metal_cromo.GLindex);
	glPopMatrix();

	//	Chimenea
	glColor3f(1, 0, 0);
	glPushMatrix();
	glTranslatef(-10.501, 1.5, -11.5);
	glScalef(2, 24, 2);
	figures.u_prisma(metal_cromo.GLindex);

	glPopMatrix();

	glColor3f(1, 1, 1);

	glPopMatrix();
}