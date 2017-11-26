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

//CTexture text1;
//CTexture text2;
//CTexture text3;	//Flecha

//	Texturas para el refrigerador
CTexture cuarzo;
CTexture metal_cromo;

//CTexture tree;

//CFiguras sky;

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


	//	Texturas refrigerador
	cuarzo.LoadTGA("textures/cuarzo.tga");
	cuarzo.BuildGLTexture();
	cuarzo.ReleaseImage();

	metal_cromo.LoadTGA("textures/metal_cromo.tga");
	metal_cromo.BuildGLTexture();
	metal_cromo.ReleaseImage();


	//	posicion     (0, 2.5, 3)
	//	hacia donde  (0, 2.5, 0)
	//	inclinación  (0, 1, 0)
	objCamera.Position_Camera(9.5, 2.5f, 40, 9.5, 2.5f, 37, 0, 1, 0);

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

			fachada();

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

void fachada()
{
	glPushMatrix();

	glTranslatef(9.5, 10.5, -18);
	
	//	Figura A
	glPushMatrix();
	glScalef(19, 21, -36);
	figures.u_prisma(0);	
	glPopMatrix();

	//	Figura B
	glPushMatrix();
	glColor3f(0, 1, 1);
	glTranslatef(-15.501, -7.5, 3.5);
	glScalef(12, 6, 16);
	figures.u_prisma(0);
	glPopMatrix();

	//	Figura C
	glColor3f(1, 1, 0);
	glPushMatrix();
	glTranslatef(20.501, -6.5, 5.5);
	glScalef(22, 8, 25);
	figures.u_prisma(0);
	glPopMatrix();

	glColor3f(0, 1, 0);
	glPushMatrix();
	glTranslatef(15.01, 1.01, 5.5);
	glScalef(11, 7, 25);
	figures.u_prisma(0);
	glPopMatrix();

	glColor3f(1, 0, 0);
	glPushMatrix();
	glTranslatef(-10.501, 1.5, -11.5);
	glScalef(2, 24, 2);
	figures.u_prisma(0);

	glPopMatrix();

	glColor3f(1, 1, 1);

	glPopMatrix();
}