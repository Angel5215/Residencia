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
void arbol(const GLuint &text);
void cocina();
void sillon_uno();
void mesa_centro();
void mesa_comedor();
void mesa_cocina();
void divisiones();
void divisiones_superior();
void sillon_dos();
void mueble_buro();
void mueble_armario();
void mueble_librero();
void lampara();
void pato();
void taza_banio();
void mueble_banio();
/*int w = 500, h = 500;
int frame=0,time,timebase=0;
int deltaTime = 0;*/

//	Objeto para dibujar figuras
//CFiguras figures;
Figures figures;
Figures mov_agua;

CCamera objCamera;	//Create objet Camera

GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW) 

GLfloat Diffuse[]= { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[]= { 0.0f, 7.0f, -5.0f, 0.0f };			// Light Position
GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

//Variables de apoyo para colocar figuras
float xx=0.0, yy = 0.0, zz = 0.0;
float tamx = 1.0, tamy = 1.0, tamz = 1.0;

//	Variables para animar al pato
GLfloat pos_pato_x = 0.f;
GLfloat pos_pato_y = 0.f;
GLfloat pos_pato_z = 0.f;
GLfloat rot_pato = 0.f;
GLfloat ant_pos_pato_z = 0.f;

// 1 (Adelante), 2(Atras), 3(Giro)
int estadoPato = 1;


//CTexture text1;
//CTexture text2;
//CTexture text3;	//Flecha

//	Texturas para el refrigerador
CTexture cuarzo;
CTexture metal_cromo;
CTexture pared_interior;
CTexture puertaFrente;
CTexture garage;
CTexture pisoRojo;
CTexture mosaicoVintage;
CTexture textAlberca;
CTexture pisoPatioT;
CTexture agua;
CTexture porcelana;
CTexture plata;
CTexture cielo_lateral;
CTexture cielo_frontal;
CTexture cielo_superior;
CTexture pasto;
CTexture lamp;
CTexture refri;
CTexture tele;
CTexture sillon;
CTexture librero;
CTexture vitrina;
CTexture chimenea;
CTexture madera;
CTexture muebleBanio;
CTexture negroMate;
CTexture muebleBuro;
CTexture almohada;
CTexture cabecera;
CTexture cobija;
CTexture piso;
CTexture tree_tex;

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
	cuarzo.LoadTGA("textures/paredExt.tga");
	cuarzo.BuildGLTexture();
	cuarzo.ReleaseImage();

	metal_cromo.LoadTGA("textures/metal_cromo.tga");
	metal_cromo.BuildGLTexture();
	metal_cromo.ReleaseImage();

	pared_interior.LoadTGA("textures/pared.tga");
	pared_interior.BuildGLTexture();
	pared_interior.ReleaseImage();

	puertaFrente.LoadTGA("textures/puerta.tga");
	puertaFrente.BuildGLTexture();
	puertaFrente.ReleaseImage();

	garage.LoadTGA("textures/garage.tga");
	garage.BuildGLTexture();
	garage.ReleaseImage();

	tele.LoadTGA("textures/tele.tga");
	tele.BuildGLTexture();
	tele.ReleaseImage();

	pisoRojo.LoadTGA("textures/piso_entrada.tga");
	pisoRojo.BuildGLTexture();
	pisoRojo.ReleaseImage();

	refri.LoadTGA("textures/metalPulido.tga");
	refri.BuildGLTexture();
	refri.ReleaseImage();

	piso.LoadTGA("textures/piso.tga");
	piso.BuildGLTexture();
	piso.ReleaseImage();

	mosaicoVintage.LoadTGA("textures/mosaico_vintage.tga");
	mosaicoVintage.BuildGLTexture();
	mosaicoVintage.ReleaseImage();

	chimenea.LoadTGA("textures/chimenea.tga");
	chimenea.BuildGLTexture();
	chimenea.ReleaseImage();

	vitrina.LoadTGA("textures/vitrina.tga");
	vitrina.BuildGLTexture();
	vitrina.ReleaseImage();

	muebleBuro.LoadTGA("textures/muebleSala.tga");
	muebleBuro.BuildGLTexture();
	muebleBuro.ReleaseImage();

	lamp.LoadTGA("textures/lampara.tga");
	lamp.BuildGLTexture();
	lamp.ReleaseImage();

	textAlberca.LoadTGA("textures/alberca.tga");
	textAlberca.BuildGLTexture();
	textAlberca.ReleaseImage();

	pisoPatioT.LoadTGA("textures/ladrillo.tga");
	pisoPatioT.BuildGLTexture();
	pisoPatioT.ReleaseImage();

	agua.LoadTGA("textures/water.tga");
	agua.BuildGLTexture();
	agua.ReleaseImage();

	librero.LoadTGA("textures/librero.tga");
	librero.BuildGLTexture();
	librero.ReleaseImage();

	porcelana.LoadTGA("textures/porcelana.tga");
	porcelana.BuildGLTexture();
	porcelana.ReleaseImage();

	plata.LoadTGA("textures/plata.tga");
	plata.BuildGLTexture();
	plata.ReleaseImage();

	sillon.LoadTGA("textures/sillon.tga");
	sillon.BuildGLTexture();
	sillon.ReleaseImage();

	cielo_frontal.LoadTGA("textures/cielo_2.tga");
	cielo_frontal.BuildGLTexture();
	cielo_frontal.ReleaseImage();	

	cielo_lateral.LoadTGA("textures/cielo_3.tga");
	cielo_lateral.BuildGLTexture();
	cielo_lateral.ReleaseImage();

	cielo_superior.LoadTGA("textures/cielo.tga");
	cielo_superior.BuildGLTexture();
	cielo_superior.ReleaseImage();

	pasto.LoadTGA("textures/pasto.tga");
	pasto.BuildGLTexture();
	pasto.ReleaseImage();

	madera.LoadTGA("textures/maderaa.tga");
	madera.BuildGLTexture();
	madera.ReleaseImage();

	muebleBanio.LoadTGA("textures/muebleBanio.tga");
	muebleBanio.BuildGLTexture();
	muebleBanio.ReleaseImage();

	negroMate.LoadTGA("textures/negroMate.tga");
	negroMate.BuildGLTexture();
	negroMate.ReleaseImage();

	almohada.LoadTGA("textures/almohada.tga");
	almohada.BuildGLTexture();
	almohada.ReleaseImage();

	cabecera.LoadTGA("textures/cabecera.tga");
	cabecera.BuildGLTexture();
	cabecera.ReleaseImage();

	cobija.LoadTGA("textures/cobija.tga");
	cobija.BuildGLTexture();
	cobija.ReleaseImage();

	tree_tex.LoadTGA("textures/arbol.tga");
	tree_tex.BuildGLTexture();
	tree_tex.ReleaseImage();

	//	posicion     (0, 2.5, 3)
	//	hacia donde  (0, 2.5, 0)
	//	inclinación  (0, 1, 0)
	objCamera.Position_Camera(9.5, 2.5f, 40, 9.5, 2.5f, 37, 0, 1, 0);

	//	Reproducir música si se está en Windows
	#if _WIN32
	PlaySound(TEXT("halo_channel.wav"), NULL, SND_LOOP | SND_ASYNC);
	#endif

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
	/*glPushMatrix();
		glTranslatef(-6, 2.4, -6.99);
		glScalef(8, 4.8, 1);
		glBindTexture(GL_TEXTURE_2D, garage.GLindex);
		glBegin(GL_QUADS);
			glTexCoord2f(1, 0); glVertex3f(0.5, -0.5, 0.5);
			glTexCoord2f(0, 0); glVertex3f(-0.5, -0.5, 0.5);
			glTexCoord2f(0, 1); glVertex3f(-0.5, 0.5, 0.5);
			glTexCoord2f(1, 1); glVertex3f(0.5, 0.5, 0.5);
		glEnd();
	glPopMatrix();*/

}

void cocina(void){

	glPushMatrix();
		glTranslatef(0.45, 2.35, -23);
		glRotatef(90,0,1,0);
		refrigerador();
	//MESA 2
	glPopMatrix();
	//TABLA MESA 2
	glPushMatrix();
	glTranslatef(0.51,1.75,-26);
		glPushMatrix(); //ALACENA 2 ARRIBA
		glTranslatef(0,2.35,0);
		glColor3f(0.8901,0.7803,0.6235);
		glScalef(0.5,1,1.25);
		figures.u_prisma(0);
		glPopMatrix();
	glPushMatrix();
	glTranslatef(0.20,0.8,0.0);
	glRotatef(90,0,1,0);
	glScalef(2.5,0.1,1.25);
	glColor3f(0.5843,0.4196,0.1843);
	figures.u_prisma(0);
	glPopMatrix();

	glRotatef(90,0,1,0);
	glScalef(2.3,1.5,1);
	glColor3f(0.8901,0.7803,0.6235);
	figures.u_prisma(0);
	glPopMatrix();

	//TABLA MESA 2
	glPushMatrix();
	glTranslatef(0.51,1.75,-32);
		glPushMatrix(); //ALACENA 2 ARRIBA
		glTranslatef(0,2.35,0);
		glColor3f(0.8901,0.7803,0.6235);
		glScalef(0.5,1,1.25);
		figures.u_prisma(0);
		glPopMatrix();
	glPushMatrix();
	glTranslatef(0.20,0.8,0.0);
	glRotatef(90,0,1,0);
	glScalef(2.5,0.1,1.25);
	glColor3f(0.5843,0.4196,0.1843);
	figures.u_prisma(0);
	glPopMatrix();

	glRotatef(90,0,1,0);
	glScalef(2.3,1.5,1);
	glColor3f(0.8901,0.7803,0.6235);
	figures.u_prisma(0);
	glPopMatrix();


	//ESTUFA 1
	glPushMatrix();
	glTranslatef(0.51,1.75,-28.5);
	glScalef(1,1.5,1);
	glColor3f(0.3254,0.4784,0.4549);
	figures.u_prisma(0);
	glPopMatrix();

	//ESTUFA 2
	glPushMatrix();
	glTranslatef(0.51,1.75,-29.5);
	glScalef(1,1.5,1);
	glColor3f(0,0.4784,0.4549);
	figures.u_prisma(0);
	glPopMatrix();

	glPushMatrix();
			glTranslatef(4.5,1.8,-28);
			mesa_cocina();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(4,1.75,-21.5);


	//ALACENA ARRIBA
	glPushMatrix();
	glTranslatef(0,2.75,0.20);
	glColor3f(0.8901,0.7803,0.6235);
	glScalef(1.25,1,0.5);
	figures.u_prisma(0);
	glPopMatrix();

	//ALACENA GRANDE
	glPushMatrix();
	glTranslatef(0,1.25,-14.2);
	glScalef(2,4,0.5);
	glColor3f(0.9019,0.6196,0.4117);
	figures.u_prisma(0);
	glPopMatrix();

	//TABLA DE MESA 1
	glPushMatrix();
	glTranslatef(0,0.8,-0.05);
	glScalef(3.25,0.15,1.15);
	glColor3f(0.5843,0.4196,0.1843);
	figures.u_prisma(0);
	glPopMatrix();

	glScalef(3,1.5,1);
	glColor3f(0.8901,0.7803,0.6235);
	figures.u_prisma(0);
	glPopMatrix();

}

void alberca(void){

	glPushMatrix(); //alberca
		glTranslatef(7.8+5.9, -4-0.2, -62.4-3.8);
		glPushMatrix(); //agua
			glTranslatef(0,4.2,0);
			glScalef(9.99,0.1,19.99);
			mov_agua.l_prisma_agua(agua.GLindex);
		glPopMatrix(); //agua
		glScalef(10,10,20);
		figures.l_prisma_alberca(textAlberca.GLindex);
	glPopMatrix(); //alberca

	/*
	glPushMatrix(); //jacuzzi
		glTranslatef(17, -3.4, -46);
		glPushMatrix(); //alberca parte 1
			glTranslatef(-8.45, -6.2, -4.8);
			figures.u_medio_cilindro_sin_tapa(8,10,10,textAlberca.GLindex);
			glPushMatrix(); //alberca parte 2
				//glTranslatef(-8.45,-6.4,-4.8);
				glRotatef(180,0,1,0);
				glScalef(1,1,2);
				figures.u_medio_cilindro_sin_tapa(8,10,10,textAlberca.GLindex);
			glPopMatrix(); //alberca parte 2
		glPopMatrix(); //alberca parte 1
			
		figures.l_cilindro_sin_tapa(2,5,10,textAlberca.GLindex);
	glPopMatrix(); //jacuzzi

	///Agua en la alberca
	glPushMatrix(); //agua
		glTranslatef(17,0.8,-46);
		glPushMatrix(); //alberca parte 1
			glTranslatef(-8.45, -2.2, -4.8);
			figures.u_medio_cilindro_sin_tapa(7.99,0.1,10,agua.GLindex);
			glPushMatrix(); //alberca parte 2
				//glTranslatef(-8.45,-6.4,-4.8);
				glRotatef(180,0,1,0);
				glScalef(1,1,2);
				figures.u_medio_cilindro_sin_tapa(7.99,0.1,10,agua.GLindex);
			glPopMatrix(); //alberca parte 2
		glPopMatrix(); //alberca parte 1
		figures.l_cilindro_sin_tapa(1.99,0.1,10,agua.GLindex);
	glPopMatrix(); //agua
	*/

}

void patioTrasero(void){

	glPushMatrix();
	glTranslatef(9.2,-1.51,-43.4);

	glPushMatrix();
		glTranslatef(22.2, 1, 6);
		glScalef(25.4, 1, 25.2);
		figures.u_prisma_patio(pisoPatioT.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(16.52+5.6, 0.99-0.4, -16.8-2.4-0.22);
		glScalef(25.8-0.6, 2, 24.4+1+1.25);
		figures.u_prisma_patio(pisoPatioT.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.2, 1, -0.17);
		glScalef(18.8, 1, 25.2);
		figures.u_prisma_patio(pisoPatioT.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-11.81, 1, -19.2);
		glScalef(22.6, 0.8, 27.2);
		figures.u_prisma_patio(pisoPatioT.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-16, 1.2, 5.2);
		glScalef(14.2, 0.4, 21.6);
		figures.u_prisma_patio(pisoPatioT.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-15.4, 0.9, 18.2);
		glScalef(15.4, 0.8, 18.8);
		figures.u_prisma_patio(pisoPatioT.GLindex);
	glPopMatrix();

	glPopMatrix();

}

void taza_banio(void){


	glPushMatrix(); //toilet
		//glTranslatef(0,2, 12.8);
		glTranslatef(15.6, 1.6, -16.6);

		glScalef(0.4,0.4,0.4);

		glPushMatrix(); //base
			glTranslatef(0, -1.4, -0.4);
			figures.u_cono(1,2,10,porcelana.GLindex);
		glPopMatrix(); //base

		glPushMatrix(); //caja
			glTranslatef(0, 2.2, -1);
			glScalef(2, 2.0, 0.6);
			figures.l_prisma(porcelana.GLindex);

			glPushMatrix(); //palanca
				glTranslatef(0.4,0.35,0.6);
				glRotatef(90,1,0,0);
				figures.u_cilindro(0.05,0.1,5,plata.GLindex);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(0.45, 0.35, 0.6);
				glScalef(0.15, 0.02, 0.2);
				figures.u_prisma(plata.GLindex);
			glPopMatrix(); //palanca

		glPopMatrix(); //caja

		glScalef(1,1,1.7);
		figures.u_cilindro(1,1,10,porcelana.GLindex);

	glPopMatrix(); //toilet

}

void mueble_banio()
{
	glPushMatrix(); //mueble
		glTranslatef(19.6, 1.6+1, -16.6);

		glPushMatrix(); //lavabo
			glTranslatef(-0.6, 1.85, 0);

			glPushMatrix(); //base llave
				glTranslatef(-0.4, -0.6, -0.4);

				glPushMatrix();
					glTranslatef(0.2, 1.0, 0.2);
					glRotatef(90,0,0,1);
					glRotatef(-45, 1, 0, 0);
					figures.u_cilindro(0.05, 0.4, 5, plata.GLindex);
				glPopMatrix();

				figures.u_cilindro(0.05, 1.2, 10, plata.GLindex);
			glPopMatrix(); //base llave

			glRotatef(90,1,0,0);
			figures.u_media_esfera(0.5, 20,20, plata.GLindex);
		glPopMatrix(); //lavabo

		glScalef(2.5,1.5+1.2,1);
		//glColor3f(1,0,1);
		figures.u_prisma_mueble(negroMate.GLindex,muebleBanio.GLindex);
		glPopMatrix();
		//glColor3f(1,1,1);
	glPopMatrix(); //mueble
}

void cama(void){


	glPushMatrix();

	glTranslatef(-16.75,6,5.65);

		glTranslatef(22, 1.6, -11.6);
		//glScalef(1.4, 0.6, 3);

		glPushMatrix(); //pata 1 derecha
		glTranslatef(1.3+0.4,-0.75+0.1,0.40+0.8);
		
		//glColor3f(0,0,0);
		figures.u_cilindro(0.1,1,5,madera.GLindex);
		glPopMatrix();

		glPushMatrix(); //pata 2 
		glTranslatef(1.3+0.4,-0.75+0.1,-0.40-0.8);
		//glColor3f(0,0,0);
		figures.u_cilindro(0.1,1,5,madera.GLindex);
		glPopMatrix();

		glPushMatrix(); //pata 3 izquierda
		glTranslatef(-1.3-0.6,-0.75+0.1,0.40+0.8);
		//glColor3f(0,0,0);
		figures.u_cilindro(0.1,1,5,madera.GLindex);
		glPopMatrix();

		glPushMatrix(); //pata 4
		glTranslatef(-1.3-0.6,-0.75+0.1,-0.40-0.8);
		//glColor3f(0,0,0);
		figures.u_cilindro(0.1,1,5,madera.GLindex);
		glPopMatrix();

		glPushMatrix(); //almohadas
			glTranslatef(1.2, 1, -0.8);
			glScalef(1, 0.4, 1);
			figures.u_prisma(almohada.GLindex);
		glPopMatrix(); 
			
		glPushMatrix();
			glTranslatef(1.2, 1, 0.8);
			glScalef(1, 0.4, 1);
			figures.u_prisma(almohada.GLindex);
		glPopMatrix(); //almohadas


		glPushMatrix();
		glTranslatef(0,0.5,0);

		glPushMatrix(); //cobija
			//glTranslatef(0,0.3,0);
			glTranslatef(-1, 0.21, 0);
			glScalef(1.4, 0.1, 3);
			glScalef(3-1.2,1+1.2,1+0.02);
			figures.u_prisma(cobija.GLindex);
		glPopMatrix(); //cobija

		glPushMatrix(); //Cabecera
			glTranslatef(2.4, 0, 0);
			glScalef(0.6, 3.2, 3.6);
			figures.u_prisma(cabecera.GLindex);
		glPopMatrix(); //Cabecera

		glScalef(1.4, 0.6, 3);
		glScalef(3,1,1);
		glColor3f(1,1,1);
		figures.u_prisma(0);
		glPopMatrix();
		//glColor3f(1,1,1);

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
			
			glPushMatrix(); //Creamos cielo
				glDisable(GL_LIGHTING);
				glTranslatef(0,29.98,0);
				glScalef(150, 60, 200);
				figures.skybox(0, 0, cielo_superior.GLindex, pasto.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();


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

			glPushMatrix();
			glTranslatef(11.4,0.4,-63.4);
			pato();
			glPopMatrix();

			cocina();

			glPushMatrix();
			glTranslatef(13.75,2,-34);
			//glRotatef(-90,0,1,0);
			silla();
			glPopMatrix();

			glPushMatrix();
			glTranslatef(13.75,2,-31);
			glRotatef(180,0,1,0);
			silla();
			glPopMatrix();

			glPushMatrix();
			glTranslatef(12,2,-32.5);
			glRotatef(90,0,1,0);
			silla();
			glPopMatrix();

			glPushMatrix();
			glTranslatef(15.5,2,-32.5);
			glRotatef(-90,0,1,0);
			silla();
			glPopMatrix();

			glPushMatrix();
			glTranslatef(13.8,0,-32.5);
			glRotatef(45,0,1,0);
			mesa_comedor();
			glPopMatrix();

			glPushMatrix();
			glTranslatef(20.5,1.8,-14);
			glRotatef(180,0,1,0);
			sillon_uno();
			glPopMatrix();

			glPushMatrix();
			glTranslatef(23,0,-15);
			lampara();
			glPopMatrix();

			glPushMatrix();
			glTranslatef(20.5,0,-9.4);
			mueble_librero();
			glPopMatrix();

			glPushMatrix(); //CHIMENEA Y TELE
			glTranslatef(20.5,2,-23.5);

			glPushMatrix();
			glTranslatef(0,2.5,-0.35);
			glColor3f(1,1,1);
			glRotatef(-90,1,0,0);
			figures.u_prisma_tele(0.25,2.5,2.5,negroMate.GLindex,tele.GLindex);
			glPopMatrix();

			glScalef(1.5,2,1);
			glColor3f(1,1,1);
			figures.u_prisma_mueble(0,chimenea.GLindex);
			glColor3f(1,1,1);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(11.3,1.8,-17);
			glRotatef(90,0,1,0);
			mueble_buro();
			glPopMatrix();

			glPushMatrix();
			glTranslatef(17.75,2.3,-25.5);
			glRotatef(-90,0,1,0);
			mueble_armario();
			glPopMatrix();

			glPushMatrix();
			glTranslatef(18,1.5,-14);
			mesa_centro();
			glPopMatrix();

			glPushMatrix();
			glTranslatef(16.5,1.8,-15);
			glRotatef(135,0,1,0);
			sillon_dos();
			glPopMatrix();

			glPushMatrix();
			glTranslatef(23,1.8,-18);
			glRotatef(255,0,1,0);
			sillon_dos();
			glPopMatrix();


			glDisable(GL_LIGHTING);
				fachada();
				puertas();
				alberca();
				patioTrasero();
				glPushMatrix();
				glTranslatef(40.6,5.9,-28.40);
				glRotatef(180,0,1,0);
				taza_banio();
				glPopMatrix();

				glPushMatrix();
				glTranslatef(40.4,5.9,-28.2);
				glRotatef(180,0,1,0);
				mueble_banio();
				glPopMatrix();

				cama();
			glEnable(GL_LIGHTING);
			divisiones();
			divisiones_superior();
			
			glPushMatrix();
				glTranslatef(5, 0, 5);
				//glScalef(0.3, 0.3, 0.3);
				arbol(tree_tex.GLindex);
			glPopMatrix();

		glPopMatrix(); 

	glPopMatrix();

	glutSwapBuffers();
}

void animacion()
{
	//	Movimiento del agua
	mov_agua.t_ini -= 0.001;
	mov_agua.t_fin -= 0.001;

	if (mov_agua.t_ini < -1.0)
	{
		mov_agua.t_ini = 0.0;
	}
	if(mov_agua.t_fin < 0.0)
	{
		mov_agua.t_fin = 1.0;
	}

	switch (estadoPato)
	{
		case 1:
			pos_pato_z += 0.01;
			if(pos_pato_z >= 6)
			{
				estadoPato = 2;
				ant_pos_pato_z = pos_pato_z;
			}
			break;
		case 2:
			pos_pato_z += 0.01;
			pos_pato_x += 0.05;
			rot_pato += 3;
			if(rot_pato >= 180)
			{
				estadoPato = 3;
				ant_pos_pato_z = pos_pato_z;
			}
			break;
		case 3:
			pos_pato_z -= 0.01;
			if(pos_pato_z <= -10)
			{
				estadoPato = 4;
			}
			break;
		case 4:
			pos_pato_z -= 0.01;
			pos_pato_x -= 0.05;
			rot_pato += 3;
			if(rot_pato >= 360)
			{
				rot_pato = 0;
				estadoPato = 1;
				pos_pato_x = 0;
			}
			break;
	}



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

		//Tecla para colocar la camara al frente de la casa
		case 'f':
		case 'F':
			objCamera.Position_Camera(9.5, 2.5f, 40, 9.5, 2.5f, 38, 0, 1, 0);
			break;

		//Tecla para colocar la camara al interior de un cuarto de la casa
		case 'c':
		case 'C':
			objCamera.Position_Camera(16.27, 9.5f, -9.68, 14, 9.5f, -7, 0, 1, 0);
			break;

		//Tecla para colocar la camara a un lado de la alberca
		case 'p':
		case 'P':
			//objCamera.Position_Camera(22.13, 6.69f, -38.55, -48.94, 2.5f, -69.66, 0, 1, 0);
			objCamera.Position_Camera(22.13, 6.69f, -38.55, 20, 4.0f, -40, 0, 1, 0);
			break;

		//Tecla para colocar la camara en una vista isometrica de la casa
		case 'i':
		case 'I':
			objCamera.Position_Camera(-23.94, 58.5f, 16.99, -5, 2.5f, -12.39, 0, 1, 0);
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

		case '1':
			tamx += 0.2;
			break;
		case '2':
			tamx -= 0.2;
			break;

		case '3':
			tamy += 0.2;
			break;

		case '4':
			tamy -= 0.2;
			break;

		case '5':
			tamz += 0.2;
			break;

		case '6':
			tamz -= 0.2;
			break;

		case 'l':
		case 'L':
			printf("(xx,yy,zz) (%f,%f,%f)\n", xx,yy,zz);
			printf("(tamx,tamy,tamz) (%f,%f,%f)\n", tamx,tamy,tamz);
			//printf("(mPos) (%f, %f, %f)\n", objCamera.mPos.x, objCamera.mPos.y, objCamera.mPos.z);
			//printf("(mView) (%f, %f, %f)\n", objCamera.mView.x, objCamera.mView.y, objCamera.mView.z);
			//printf("(mUp) (%f, %f, %f)\n", objCamera.mUp.x, objCamera.mUp.y, objCamera.mUp.z);
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
	//glTranslatef(1, 1.25, -0.4);

	//	Principal (trasera)
	glPushMatrix();
		glTranslatef(0,0.5,0);
		glScalef(2, 3.5, 0.8);
		figures.u_prisma(refri.GLindex);
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
		glTranslatef(0, 0.2505, 0.505);

		//	Manija (superior)
		glPushMatrix();
			glTranslatef(-0.7, 0.50, 0.130);
			glScalef(0.05, 0.1, 0.05);
			figures.u_prisma(metal_cromo.GLindex);
		glPopMatrix();

		//	Manija (cilindro)
		glPushMatrix();
			glTranslatef(-0.7, -0.15, 0.150);
			figures.u_cilindro(0.025, 0.7, 6, metal_cromo.GLindex);
		glPopMatrix();

		//	Manija (inferior)
		glPushMatrix();
			glTranslatef(-0.7, -0.1, 0.130);
			glScalef(0.05, 0.1, 0.05);
			figures.u_prisma(metal_cromo.GLindex);
		glPopMatrix();

		glScalef(2, 3, 0.2);
		figures.u_prisma(refri.GLindex);
	glPopMatrix();

	//	Principal (delantera, arriba)
	glPushMatrix();
		glTranslatef(0, 1.7505, 0.505);

		//	Manija (superior)
		glPushMatrix();
			glTranslatef(-0.7, -0.25, 0.130);
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
			glTranslatef(-0.7, 0.23, 0.130);
			glScalef(0.05, 0.1, 0.05);
			figures.u_prisma(metal_cromo.GLindex);
		glPopMatrix();

		glScalef(2, 1, 0.2);
		figures.u_prisma(refri.GLindex);
	glPopMatrix();
	
}

void silla()
{

	//RESPALDO
	glPushMatrix();
	glTranslatef(0,0.50,-0.22);
	glPushMatrix();
	glTranslatef(0,0.375,0.031);
	glRotatef(-90,1,0,0);
	glColor3f(0.3529,0.1764,0.0862);
	figures.u_medio_cilindro(0.25,0.0625,30,madera.GLindex);
	glPopMatrix();
	glScalef(0.5,0.75,0.0625);
	glColor3f(0.3529,0.1764,0.0862);
	figures.u_prisma(madera.GLindex);
	glPopMatrix();
	glColor3f(1,1,0);
	//PATA 1
	glPushMatrix();
	glTranslatef(0.1875,-0.5,0.1875);
	glScalef(0.125,0.75,0.125);
	glColor3f(0.3529,0.1764,0.0862);
	figures.u_prisma(madera.GLindex);
	glPopMatrix();
	//PATA  2
	glPushMatrix();
	glTranslatef(0.1875,-0.5,-0.1875);
	glScalef(0.125,0.75,0.125);
	glColor3f(0.3529,0.1764,0.0862);
	figures.u_prisma(madera.GLindex);
	glPopMatrix();
	//PATA 3
	glPushMatrix();
	glTranslatef(-0.1875,-0.5,-0.1875);
	glScalef(0.125,0.75,0.125);
	glColor3f(0.3529,0.1764,0.0862);
	figures.u_prisma(madera.GLindex);
	glPopMatrix();
	//PATA 4
	glPushMatrix();
	glTranslatef(-0.1875,-0.5,0.1875);
	glScalef(0.125,0.75,0.125);
	glColor3f(0.3529,0.1764,0.0862);
	figures.u_prisma(madera.GLindex);
	glPopMatrix();
	glScalef(0.5,0.25,0.5);
	glColor3f(0.3529,0.1764,0.0862);
	figures.u_prisma(madera.GLindex);
	//glColor3f(1,1,1);
}

void arbol(const GLuint &text)
{

	glPushMatrix();
		//glDisable(GL_LIGHTING);
		glEnable(GL_ALPHA_TEST);
		glAlphaFunc(GL_GREATER, 0.1);

		glBindTexture(GL_TEXTURE_2D, text);
		for(int i = 0; i < 12; i++)
		{
			glPushMatrix();
				glRotatef(30 / 2.0 * i, 0, 1, 0);
				glNormal3f(0, 0, 1);
				glBegin(GL_QUADS);
					glTexCoord2f(0.0f, 0.0f); glVertex3f(-5.0, 0.0, 0.0);
					glTexCoord2f(1.0f, 0.0f); glVertex3f(5.0, 0.0, 0.0);
					glTexCoord2f(1.0f, 1.0f); glVertex3f(5.0, 10.0, 0.0);
					glTexCoord2f(0.0f, 1.0f); glVertex3f(-5.0, 10.0, 0.0);
				glEnd();
			glPopMatrix();

		}
		//glEnable(GL_LIGHTING);
		glDisable(GL_ALPHA_TEST);
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
	glPushMatrix(); //DESCANSO BRAZP DER
	glTranslatef(1.20,0.5,0.5);
	glColor3f(1,1,1);
	glRotatef(-90,1,0,0);
	figures.u_medio_cilindro(0.30,0.75,30,sillon.GLindex);
	glPopMatrix();

	glPushMatrix(); //DESCANSO BRAZO IZQ
	glTranslatef(-1.20,0.5,0.5);
	glColor3f(1,1,1);
	glRotatef(-90,1,0,0);
	figures.u_medio_cilindro(0.30,0.75,30,sillon.GLindex);
	glPopMatrix();

	glPushMatrix(); //RESPALDO
	glTranslatef(0,1.10,-0.375);

	glPushMatrix();
	glTranslatef(1.2,-0.3,0);

	glPushMatrix(); 
	glTranslatef(-0.3,0.3,0.125);
	glColor3f(1,1,1);
	glRotatef(-90,1,0,0);
	figures.u_cuarto_cilindro(0.6,0.25,30,sillon.GLindex);
	glPopMatrix();

	glScalef(0.6,0.6,0.25);
	glColor3f(1,1,1);
	figures.u_prisma(sillon.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.2,-0.3,0);

	glPushMatrix(); 
	glTranslatef(0.3,0.3,-0.125);
	glColor3f(1,1,1);
	glRotatef(-90,1,0,0);
	glRotatef(180,0,0,1);
	figures.u_cuarto_cilindro(0.6,0.25,30,sillon.GLindex);
	glPopMatrix();

	glScalef(0.6,0.6,0.25);
	glColor3f(1,1,1);
	figures.u_prisma(sillon.GLindex);
	glPopMatrix();

	glScalef(1.8,1.20,0.25);
	glColor3f(1,1,1);
	figures.u_prisma(sillon.GLindex);
	glPopMatrix();

	glPushMatrix(); //pata del sillon 1 derecha
	glTranslatef(1.3,-0.75,0.40);
	glColor3f(0,0,0);
	figures.u_cilindro(0.1,0.25,5,madera.GLindex);
	glPopMatrix();
	glPushMatrix(); //pata del sillon 2 
	glTranslatef(1.3,-0.75,-0.40);
	glColor3f(0,0,0);
	figures.u_cilindro(0.1,0.25,5,madera.GLindex);
	glPopMatrix();
	glPushMatrix(); //pata del sillon 3 izquierda
	glTranslatef(-1.3,-0.75,0.40);
	glColor3f(0,0,0);
	figures.u_cilindro(0.1,0.25,5,madera.GLindex);
	glPopMatrix();
	glPushMatrix(); //pata del sillon 4
	glTranslatef(-1.3,-0.75,-0.40);
	glColor3f(0,0,0);
	figures.u_cilindro(0.1,0.25,5,madera.GLindex);
	glPopMatrix();
	glScalef(3,1,1);
	glColor3f(1,1,1);
	figures.u_prisma(sillon.GLindex);
	glPopMatrix();
	glColor3f(1,1,1);
}

void sillon_dos()
{
	glPushMatrix(); //PUSH DE PRISMA PRINCIPAL
	/*glPushMatrix();
	glTranslatef(0,0.75,0.0);
	glScalef(2.5,0.5,1.5);
	glColor3f(0,0,1);
	figures.u_prisma(0);
	glPopMatrix();*/
	

	glPushMatrix();
	glTranslatef(0.6,0.65,0.12);
	glPushMatrix(); //DESCANSO BRAZP DER
	glTranslatef(0,0.15,0.375);
	glColor3f(1,1,1);
	glRotatef(-90,1,0,0);
	figures.u_medio_cilindro(0.15,0.75,30,sillon.GLindex);
	glPopMatrix();
	glColor3f(1,1,1);
	glScalef(0.3,0.3,0.75);
	figures.u_prisma(sillon.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.6,0.65,0.12);
	glPushMatrix(); //DESCANSO BRAZP DER
	glTranslatef(0,0.15,0.375);
	glColor3f(1,1,1);
	glRotatef(-90,1,0,0);
	figures.u_medio_cilindro(0.15,0.75,30,sillon.GLindex);
	glPopMatrix();
	glColor3f(1,1,1);
	glScalef(0.3,0.3,0.75);
	figures.u_prisma(sillon.GLindex);
	glPopMatrix();


	glPushMatrix(); //RESPALDO
	glTranslatef(0,0.90,-0.375);

	glPushMatrix();
	glTranslatef(0.6,-0.1,0);

	glPushMatrix(); 
	glTranslatef(-0.15,0.3,0.125);
	glColor3f(1,1,1);
	glRotatef(-90,1,0,0);
	figures.u_cuarto_cilindro(0.3,0.25,30,sillon.GLindex);
	glPopMatrix();

	glScalef(0.3,0.6,0.25);
	glColor3f(1,1,1);
	figures.u_prisma(sillon.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.6,-0.1,0);

	glPushMatrix(); 
	glTranslatef(0.15,0.3,-0.125);
	glColor3f(1,1,1);
	glRotatef(-90,1,0,0);
	glRotatef(180,0,0,1);
	figures.u_cuarto_cilindro(0.3,0.25,30,sillon.GLindex);
	glPopMatrix();

	glScalef(0.3,0.6,0.25);
	glColor3f(1,1,1);
	figures.u_prisma(sillon.GLindex);
	glPopMatrix();

	glScalef(0.9,1.0,0.25);
	glColor3f(1,1,1);
	figures.u_prisma(sillon.GLindex);
	glPopMatrix();

	glPushMatrix(); //pata del sillon 1 derecha
	glTranslatef(0.65,-0.75,0.40);
	glColor3f(0,0,0);
	figures.u_cilindro(0.1,0.25,5,madera.GLindex);
	glPopMatrix();
	glPushMatrix(); //pata del sillon 2 
	glTranslatef(0.65,-0.75,-0.40);
	glColor3f(0,0,0);
	figures.u_cilindro(0.1,0.25,5,madera.GLindex);
	glPopMatrix();
	glPushMatrix(); //pata del sillon 3 izquierda
	glTranslatef(-0.65,-0.75,0.40);
	glColor3f(0,0,0);
	figures.u_cilindro(0.1,0.25,5,madera.GLindex);
	glPopMatrix();
	glPushMatrix(); //pata del sillon 4
	glTranslatef(-0.65,-0.75,-0.40);
	glColor3f(0,0,0);
	figures.u_cilindro(0.1,0.25,5,madera.GLindex);
	glPopMatrix();
	glScalef(1.5,1,1);
	glColor3f(1,1,1);
	figures.u_prisma(sillon.GLindex);
	glPopMatrix();
	glColor3f(1,1,1);
}
void lampara()
{
	glPushMatrix();
	glTranslatef(0,1,0.0);

	glPushMatrix();
	glTranslatef(0,0.0625,0);
	glPushMatrix();
	glTranslatef(0,2,0);
	//glColor3f(1,1,1);
	figures.u_cono(0.3,1,10,lamp.GLindex);
	glPopMatrix();
	glColor3f(1,1,1);
	figures.u_cilindro(0.01,2,5,0);
	glPopMatrix();

	glColor3f(0,0,0);
	figures.u_cilindro(0.25,0.0625,30,0);
	glPopMatrix();
	glColor3f(1,1,1);
}

void mueble_buro()
{
	glPushMatrix();
	glTranslatef(0,0.3,0);
	glPushMatrix();//PATA1
	glTranslatef(0.9,-1.1,0.15);
	glColor3f(0.2745,0.1882,0.1333);
	figures.u_cilindro(0.05,0.4,5,madera.GLindex);
	glPopMatrix();

	glPushMatrix();//PATA2
	glTranslatef(-0.9,-1.1,0.15);
	glColor3f(0.2745,0.1882,0.1333);
	figures.u_cilindro(0.05,0.4,5,madera.GLindex);
	glPopMatrix();

	glPushMatrix();//PATA3
	glTranslatef(-0.9,-1.1,-0.15);
	glColor3f(0.2745,0.1882,0.1333);
	figures.u_cilindro(0.05,0.4,5,madera.GLindex);
	glPopMatrix();

	glPushMatrix();//PATA4
	glTranslatef(0.9,-1.1,-0.15);
	glColor3f(0.2745,0.1882,0.1333);
	figures.u_cilindro(0.05,0.4,5,madera.GLindex);
	glPopMatrix();

	glPushMatrix();//PATA5
	glTranslatef(0.0,-1.1,0.15);
	glColor3f(0.2745,0.1882,0.1333);
	figures.u_cilindro(0.05,0.4,5,madera.GLindex);
	glPopMatrix();

	glPushMatrix();//PATA6
	glTranslatef(0.0,-1.1,-0.15);
	glColor3f(0.2745,0.1882,0.1333);
	figures.u_cilindro(0.05,0.4,5,madera.GLindex);
	glPopMatrix();


	glScalef(2,1.5,0.5);
	glColor3f(0.2745,0.1882,0.1333);
	figures.u_prisma_mueble(madera.GLindex,muebleBuro.GLindex);
	glPopMatrix();
	glColor3f(1,1,1);

}

void mueble_armario()
{
	glPushMatrix();
	glTranslatef(0,1.0,0);
	glPushMatrix();
	glTranslatef(0,2.25,0);
	glColor3f(0.2745,0.1882,0.1333);
	figures.u_prisma_trapecio(0.5,2,0.5,madera.GLindex);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0,-2.125,0);
	glColor3f(0.2745,0.1882,0.1333);
	figures.u_prisma_trapecio(0.5,2,0.5,madera.GLindex);
	glPopMatrix();
	glScalef(2,4.0,0.5);
	glColor3f(0.2745,0.1882,0.1333);
	figures.u_prisma_mueble(madera.GLindex,vitrina.GLindex);
	glPopMatrix();
	glColor3f(1,1,1);
}


void mueble_librero()
{
	glPushMatrix();
	glTranslatef(0,3.0,0);
	glScalef(3,4,0.75);
	glRotatef(180,0,1,0);
	glColor3f(0.2745,0.1882,0.1333);
	figures.u_prisma_mueble(madera.GLindex,librero.GLindex);
	glPopMatrix();
	glColor3f(1,1,1);

}
void mesa_centro()
{

	glPushMatrix();

	for (int i = 0; i < 4; i++)
	{
		glPushMatrix();
		//glColor3f(1,0.25,0.5);
		glTranslatef(0.4*cos(PI/2 * i),-0.5,0.4*sin(PI/2 * i));
		figures.u_cilindro(0.05,1,5,madera.GLindex);
		glPopMatrix();
	}

	//glColor3f(0.75,1,0.25);
	glTranslatef(0,0.5,0);
	figures.u_cilindro(0.5,0.1,30,madera.GLindex);
	
	glPopMatrix();
	//glColor3f(1,1,1);
}

void mesa_comedor()
{
	glPushMatrix();
	glTranslatef(0,1.05,0);
	glPushMatrix();
	glPushMatrix();
	glTranslatef(0,1.5,0);
	glColor3f(0.3529,0.1764,0.0862);
	figures.u_cilindro(1.5,0.1,20,madera.GLindex);
	glPopMatrix();
	glColor3f(0.3529,0.1764,0.0862);
	figures.u_cilindro(0.125,1.5,15,madera.GLindex);
	glPopMatrix();
	glScalef(1.5,0.05,1.5);
	glColor3f(0.3529,0.1764,0.0862);
	figures.u_prisma(madera.GLindex);
	glPopMatrix();
}

void mesa_cocina()
{
	glPushMatrix();
	glPushMatrix();
	glTranslatef(0,0.80,0);
	glScalef(2.5,0.1,2.5);
	glColor3f(0.8901,0.7803,0.6235);
	figures.u_prisma(0);
	glPopMatrix();
	glScalef(1.5,1.5,2);
	glColor3f(0.6901,0.4980,0.2196);
	figures.u_prisma(0);
	glPopMatrix();	
}

void pato()
{
	glPushMatrix();

	glTranslatef(pos_pato_x, pos_pato_y, pos_pato_z);
	glRotatef(rot_pato, 0, 1, 0);

	glPushMatrix();//Ala derecha
	glTranslatef(0.25,0.1,0);
	glScalef(0.1,0.75,0.325);
	glColor3f(0.4431,0.4901,0.4941);
	figures.u_prisma(0);
	glPopMatrix();	

	glPushMatrix();//Ala derecha
	glTranslatef(-0.25,0.1,0);
	glScalef(0.1,0.75,0.325);
	glColor3f(0.4431,0.4901,0.4941);
	figures.u_prisma(0);
	glPopMatrix();

	//PATAS
	glPushMatrix();//IZQUIERDA
	glTranslatef(-0.15,-0.75,0);
	glPushMatrix();
	glTranslatef(0,-0.25,0.1);
	glScalef(0.15,0.1,0.15);
	glColor3f(0.8627,0.4627,0.2);
	figures.u_prisma(0);
	glPopMatrix();
	glScalef(0.05,0.5,0.075);
	glColor3f(0.8627,0.4627,0.2);
	figures.u_prisma(0);
	glPopMatrix();

	glPushMatrix();//DERECHA
	glTranslatef(0.15,-0.75,0);
	glPushMatrix();
	glTranslatef(0,-0.25,0.1);
	glScalef(0.15,0.1,0.15);
	glColor3f(0.8627,0.4627,0.2);
	figures.u_prisma(0);
	glPopMatrix();
	glScalef(0.05,0.5,0.075);
	glColor3f(0.8627,0.4627,0.2);
	figures.u_prisma(0);
	glPopMatrix();

	//CABEZA
	glPushMatrix();
	glTranslatef(0,0.65,0.25);
	glPushMatrix();//PUSH DE LA BOCA
	glTranslatef(0,0,0.07);

	glPushMatrix();//PUSH DE OJO IZQ
	glTranslatef(-0.095,0.15,0);
	glScalef(0.025,0.05,0.05);
	glColor3f(0,0,0);
	figures.u_prisma(0);
	glPopMatrix();

	glPushMatrix();//PUSH DE OJO DER
	glTranslatef(0.095,0.15,0);
	glScalef(0.025,0.05,0.05);
	glColor3f(0,0,0);
	figures.u_prisma(0);
	glPopMatrix();

	glScalef(0.25,0.25,0.05);
	glColor3f(0.9568,0.8156,0.2470);
	figures.u_prisma(0);
	glPopMatrix();
	glScalef(0.25,0.75,0.1);
	glColor3f(0.6666,0.7176,0.7215);
	figures.u_prisma(0);
	glPopMatrix();

	glScalef(0.5,1,0.5);
	glColor3f(0.4745,0.4901,0.4980);
	figures.u_prisma(0);
	glPopMatrix();
}

void divisiones() {

	glPushMatrix();
		//	División entrada (derecha)
		glTranslatef(17, 3, -4.502);
		glScalef(18, 6, 9);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	glPushMatrix();
		//	División entrada (derecha sala)
		glTranslatef(9.5, 3, -17);
		glScalef(3, 6, 8);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(10, 3, -12.5);
		glScalef(4, 6, 1);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	//	División central entrada sala
	glPushMatrix();
		glTranslatef(8.5, 5.5, -10.5);
		glScalef(1, 1, 3);
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
		glColor3f(0.8,0.8,0.8);
		glTranslatef(2, 0.25, -10);
		glScalef(4, 0.5, 2);
		figures.u_prisma_escalera(piso.GLindex,piso.GLindex);
		//glColor3f(1,1,1);
	glPopMatrix();

	glPushMatrix();	// 02
	glColor3f(1,1,0);
	glTranslatef(1.5, 0.5, -10.5);
	glScalef(3, 1, 1);
	figures.u_prisma_escalera(piso.GLindex,piso.GLindex);
	glColor3f(1,1,1);
	glPopMatrix();

	glPushMatrix();	// 03
	glColor3f(1,1,0);
	glTranslatef(1.5, 0.75, -11.5);
	glScalef(3, 1.5, 1);
	figures.u_prisma_escalera(piso.GLindex,piso.GLindex);
	glColor3f(1,1,1);
	glPopMatrix();

	glPushMatrix();	// 04
	glColor3f(1,1,0);
	glTranslatef(1.5, 1, -12.5);
	glScalef(3, 2, 1);
	figures.u_prisma_escalera(piso.GLindex,piso.GLindex);
	glColor3f(1,1,1);
	glPopMatrix();

	glPushMatrix();	// 05
	glColor3f(1,1,0);
	glTranslatef(1.5, 1.25, -13.5);
	glScalef(3, 2.5, 1);
	figures.u_prisma_escalera(piso.GLindex,piso.GLindex);
	glColor3f(1,1,1);
	glPopMatrix();

	glPushMatrix();	// 06
	glColor3f(1,1,0);
	glTranslatef(1.5, 1.5, -14.5);
	glScalef(3, 3, 1);
	figures.u_prisma_escalera(piso.GLindex,piso.GLindex);
	glColor3f(1,1,1);
	glPopMatrix();

	glPushMatrix();	// 07
	glColor3f(1,1,0);
	glTranslatef(1.5, 1.75, -15.5);
	glScalef(3, 3.5, 1);
	figures.u_prisma_escalera(piso.GLindex,piso.GLindex);
	glColor3f(1,1,1);
	glPopMatrix();

	//	Escalera (vuelta)
	glPushMatrix();	// 08-1
	glColor3f(1,1,0);
	glTranslatef(1.5, 3.5, -16.5);
	glScalef(3, 1.01, 1.01);
	figures.u_prisma_escalera(piso.GLindex,piso.GLindex);
	glColor3f(1,1,1);
	glPopMatrix();

	glPushMatrix();	// 08-2
	glColor3f(1,1,0);
	glTranslatef(1.5, 3.75, -18);
	glScalef(3, 0.501, 4.01);
	figures.u_prisma_escalera(piso.GLindex,piso.GLindex);
	glColor3f(1,1,1);
	glPopMatrix();

	glPushMatrix();	// 09
	glColor3f(1,1,0);
	glTranslatef(3.5, 4.25, -18);
	glScalef(1, 0.5, 4);
	figures.u_prisma_escalera(piso.GLindex,piso.GLindex);
	glColor3f(1,1,1);
	glPopMatrix();

	glPushMatrix();	// 10
	glColor3f(1,1,0);
	glTranslatef(4.5, 4.5, -18);
	glScalef(1, 1, 4);
	figures.u_prisma_escalera(piso.GLindex,piso.GLindex);
	glColor3f(1,1,1);
	glPopMatrix();

	glPushMatrix();	// 11
	glColor3f(1,1,0);
	glTranslatef(5.5, 4.75, -18);
	glScalef(1, 1.5, 4);
	figures.u_prisma_escalera(piso.GLindex,piso.GLindex);
	glColor3f(1,1,1);
	glPopMatrix();

	glPushMatrix();	// 12
	glColor3f(1,1,0);
	glTranslatef(6.5, 5, -18);
	glScalef(1, 2, 4);
	figures.u_prisma_escalera(piso.GLindex,piso.GLindex);
	glColor3f(1,1,1);
	glPopMatrix();

	glPushMatrix();	// 13
	glColor3f(1,1,0);
	glTranslatef(7.5, 5.25, -18);
	glScalef(1, 2.5, 4);
	figures.u_prisma_escalera(piso.GLindex,piso.GLindex);
	glColor3f(1,1,1);
	glPopMatrix();

	glPushMatrix();	// 14
	glColor3f(1,1,0);
	glTranslatef(8.5, 5.5, -18);
	glScalef(1, 3, 4);
	figures.u_prisma_escalera(piso.GLindex,piso.GLindex);
	glColor3f(1,1,1);
	glPopMatrix();	//	Fin escaleras


	//	Modificaciones sala
	glPushMatrix();
		glTranslatef(26.5, 3.5, -11);
		glScalef(1, 5, 4);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(26.5, 3, -11);
		glScalef(1.05, 6, 4.05);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(27.5, 3.5, -16.5);
		glScalef(1, 7, 9);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(27.5, 1, -22.5);
		glScalef(1, 2, 3);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(27.5, 6, -22.5);
		glScalef(1, 2, 3);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(27.5, 3.5, -24.5);
		glScalef(1, 7, 1);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(25.5, 1, -24.5);
		glScalef(3, 2, 1);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(25.5, 6, -24.5);
		glScalef(3, 2, 1);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(21.5, 3.5, -24.5);
		glScalef(5, 7, 1);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	//	PISO SALA
	glPushMatrix();
		glTranslatef(19, 0.5, -16.5);
		glScalef(16, 1, 15);
		figures.u_prisma(metal_cromo.GLindex);
	glPopMatrix();

	//	Fin modificaciones sala

	//	División sala-comedor
	glPushMatrix();
		glTranslatef(18.5, 3.5, -30);
		glScalef(1, 7, 11.995);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(17.495, 3.5, -27.5);
		glScalef(3, 7, 1);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();


	//	División cocina-comedor
	glPushMatrix();
		glTranslatef(9.5, 3.5, -27.5);
		glScalef(3, 7, 1);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(8.5, 3.5, -29);
		glScalef(1, 7, 2);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(8.5, 3.5, -35);
		glScalef(1, 7, 1.995);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	//	Pared Escaleras
	glPushMatrix();
		glTranslatef(4.5, 12.49, -20.5);
		glScalef(8.995, 17, 1);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	//	PISO COCINA/COMEDOR
	glPushMatrix();
		glTranslatef(9.5, 0.5, -28.5);
		glScalef(18.995, 0.995, 14.995);
		figures.u_prisma(metal_cromo.GLindex);
	glPopMatrix();

	//	Escalones hacia la sala
	glPushMatrix();
		glTranslatef(9.5, 0.25, -10.5);
		glScalef(1, 0.5, 3);
		figures.u_prisma(pared_interior.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(10.5, 0.5, -10.5);
		glScalef(1, 1, 3);
		figures.u_prisma(pared_interior.GLindex);
	glPopMatrix();

	//	Escalones hacia el comedor
	glPushMatrix();
		glTranslatef(7, 0.25, -20.25);
		glScalef(2, 0.5, 0.5);
		figures.u_prisma(pared_interior.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(7, 0.5, -20.75);
		glScalef(2, 1, 0.5);
		figures.u_prisma(pared_interior.GLindex);
	glPopMatrix();

	/*glPushMatrix();
		glTranslatef(5, 5, 5);
		figures.u_cuarto_cilindro(3, 3, 20, pared_interior.GLindex);
	glPopMatrix();*/

	//	Escalones en la entrada
	glPushMatrix();
		glTranslatef(4.8, 0.3, 1.05);
		glScalef(8, 0.5, 2);
		figures.u_prisma(pared_interior.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(4.8, 0.6, 0.505);
		glScalef(5, 1, 1);
		figures.u_prisma(pared_interior.GLindex);
	glPopMatrix();



}

void divisiones_superior()
{
	//	PISO SUPERIOR CENTRAL
	glPushMatrix();
		glTranslatef(11, 6.5, -16.5);
		glScalef(5.995, 0.995, 16.995);
		figures.u_prisma(metal_cromo.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(8.5, 14, -22.5);
		glScalef(1, 13.995, 4.995);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(11, 14, -24.5);
		glScalef(6, 13.995, 1);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(14.5, 14, -20.5);
		glScalef(1, 13.995, 7);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	//	DIVISION CUARTO TRACEY-BAÑO
	glPushMatrix();
		glTranslatef(21, 14, -14.5);
		glScalef(14, 13.995, 1);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	//	PARED EXTERIOR
	glPushMatrix();
		glTranslatef(27.5, 14, -19.5);
		glScalef(1, 13.995, 11);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(21, 20, -24.5);
		glScalef(14, 1.995, 1);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(21, 9, -24.5);
		glScalef(13.995, 3.995, 0.995);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(17, 15.995, -24.5);
		glScalef(6, 10, 1);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(25, 15.995, -24.5);
		glScalef(4, 10, 1);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	//	DIVISIÓN PUERTA TECHO TRACEY
	glPushMatrix();
		glTranslatef(14.5, 15.995, -16);
		glScalef(1, 10, 2);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	//	PISO CUARTO TRACEY
	glPushMatrix();
		glTranslatef(21, 6.5, -19);
		glScalef(13.995, 0.995, 9.995);
		figures.u_prisma(metal_cromo.GLindex);
	glPopMatrix();

	//	TECHO COCINA/COMEDOR
	glPushMatrix();
		glTranslatef(9.5, 6.505, -28.5);
		glScalef(18.995, 1, 14.995);
		figures.u_prisma(metal_cromo.GLindex);
	glPopMatrix();

	//	PISO PASILLO BAÑO SUPERIOR CENTRAL
	glPushMatrix();
		glTranslatef(20.5, 6.5, -12.5);
		glScalef(13, 1, 3);
		figures.u_prisma(metal_cromo.GLindex);
	glPopMatrix();


	//	PRISMA CUARTO DE MICHAEL
	glPushMatrix();
		glTranslatef(4.5, 13.5, -11.5);
		glScalef(8.995, 14.995, 1);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	//	PARTE 1 PUERTA CUARTO DE MICHAEL¡
	glPushMatrix();
		glTranslatef(8.5, 13.5, -10.5);
		glScalef(1, 14.995, 1);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	//	DIVISIÓN PUERTA CUARTO DE MICHAEL¡
	glPushMatrix();
		glTranslatef(11, 13.5, -7.5);
		glScalef(6, 14.995, 1);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	//	DIVISIÓN PUERTA CUARTO DE MICHAEL-BAÑO¡
	glPushMatrix();
		glTranslatef(8.5, 13.5, -6);
		glScalef(0.995, 14.995, 3.995);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	//	DIVISIÓN PUERTA CUARTO DE MICHAEL-BAÑO 2
	glPushMatrix();
		glTranslatef(8.5, 13.5, -1);
		glScalef(0.995, 14.995, 1.995);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	//	DIVISIÓN PUERTA CUARTO DE MICHAEL-BAÑO 3
	glPushMatrix();
		glTranslatef(8.5, 15.5, -3);
		glScalef(0.995, 10.995, 2);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	//	DIVISIÓN PUERTA CUARTO DE MICHAEL-BAÑO 4
	glPushMatrix();
		glTranslatef(8.5, 15.5, -9);
		glScalef(0.995, 10.995, 2);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	//	PISO
	glPushMatrix();
		glTranslatef(4.5, 6.495, -6);
		glScalef(8.995, 1, 11.995);
		figures.u_prisma(metal_cromo.GLindex);
	glPopMatrix();

	//	PISO 2 (baño)
	glPushMatrix();
		glTranslatef(11, 6.5, -4);
		glScalef(6, 1, 7.995);
		figures.u_prisma(metal_cromo.GLindex);
	glPopMatrix();


	//	PISO 3 (CUARTO DE JIMMY)
	glPushMatrix();
		glTranslatef(20, 6.5, -5.505);
		glScalef(11.995, 1, 11);
		figures.u_prisma(metal_cromo.GLindex);
	glPopMatrix();

	//	Cerrar superficie principal
	glPushMatrix();
		glTranslatef(19, 0, 0);
		glBindTexture(GL_TEXTURE_2D, cuarzo.GLindex);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
			glNormal3f(0, 0, 1);
			glTexCoord2f(0.0, 0.0); glVertex3f(0, 0, 0);
			glTexCoord2f(1.0, 0.0); glVertex3f(7, 0, 0);
			glTexCoord2f(1.0, 1.0); glVertex3f(7, 21, 0);
			glTexCoord2f(0.0, 1.0); glVertex3f(0, 21, 0);
		glEnd();
		glEnable(GL_LIGHTING);

		glTranslatef(0, 0, -0.02);
		glBegin(GL_POLYGON);
			glNormal3f(0, 0, -1);
			glTexCoord2f(0.0, 0.0); glVertex3f(0, 0, 0);
			glTexCoord2f(1.0, 0.0); glVertex3f(7, 0, 0);
			glTexCoord2f(1.0, 1.0); glVertex3f(7, 21, 0);
			glTexCoord2f(0.0, 1.0); glVertex3f(0, 21, 0);
		glEnd();
	glPopMatrix();

	//	DIVISIÓN PUERTA CUARTO DE JIMMY
	glPushMatrix();
		glTranslatef(15, 13.5, -5.5);
		glScalef(2, 14.995, 10.995);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	//	DIVISIÓN CENTRAL PUERTA CUARTO DE JIMMY
	glPushMatrix();
		glTranslatef(17, 15.5, -10.5);
		glScalef(2, 10.995, 1);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	//	DIVISIÓN PUERTA CUARTO DE JIMMY
	glPushMatrix();
		glTranslatef(22.5, 13.5, -10.5);
		glScalef(9, 14.995, 1);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();


	//	DIVISIÓN FINAL CUARTO 1
	glPushMatrix();
		glTranslatef(26.5, 10.5, -2.5);
		glScalef(1, 21, 5);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	//	DIVISIÓN FINAL CUARTO 2
	glPushMatrix();
		glTranslatef(26.5, 5, -6.5);
		glScalef(1, 10, 3);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	//	DIVISIÓN FINAL CUARTO 3
	glPushMatrix();
		glTranslatef(26.5, 17.5, -6.5);
		glScalef(1, 7, 3);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	//	DIVISIÓN FINAL CUARTO 4
	glPushMatrix();
		glTranslatef(26.5, 10.5, -9.5);
		glScalef(1, 21, 3);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	//	DIVISIÓN FINAL CUARTO 4
	glPushMatrix();
		glTranslatef(27.5, 10.5, -11.5);
		glScalef(1, 21, 5);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	//	Cerrar superficie superior
	glPushMatrix();
		glTranslatef(23, 20.5, -12.5);
		glScalef(8, 1, 25);
		figures.l_prisma(cuarzo.GLindex);
	glPopMatrix();

	glPushMatrix();
		glDisable(GL_LIGHTING);
		glTranslatef(23.5, 20.5, -12.5);
		glScalef(9.05, 1.05, 25.05);
		figures.u_prisma(cuarzo.GLindex);
		glEnable(GL_LIGHTING);
	glPopMatrix();

	//	CIERRE FINAL COMEDOR(SUPERIOR)
	glPushMatrix();
		glTranslatef(18.5, 14, -30);
		glScalef(1, 13.995, 11.995);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();
	
}

void fachada()
{
	glPushMatrix();

	glTranslatef(9.5, 10.5, -18);
	
	//	Figura A (central)
	
	glPushMatrix();
	glScalef(19, 21, -36);
	figures.u_prisma_no_derecha(cuarzo.GLindex);	
	glPopMatrix();

	glEnable(GL_LIGHTING);
	glPushMatrix();
	glScalef(18.995, 20.995, -35.995);
	figures.l_prisma_no_derecha(cuarzo.GLindex, metal_cromo.GLindex);	
	glPopMatrix();
	glDisable(GL_LIGHTING);

	//	Figura B (garage)
	glPushMatrix();
	glTranslatef(-15.501, -7.5, 3.5);
	glScalef(12, 6, 16);
	figures.u_prisma_garage(garage.GLindex, pared_interior.GLindex, metal_cromo.GLindex);
	glPopMatrix();

	glEnable(GL_LIGHTING);
	glPushMatrix();
	glTranslatef(-15.501, -7.5, 3.5);
	glScalef(11.995, 5.995, 15.995);
	figures.l_prisma_garage(garage.GLindex, pared_interior.GLindex, metal_cromo.GLindex);
	glPopMatrix();
	glDisable(GL_LIGHTING);

	/*//	Figura C (sala)
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
	glPopMatrix();*/

	//	Chimenea
	//glColor3f(1, 0, 0);
	glPushMatrix();
	glTranslatef(-10.501, 1.5, -11.5);
	glScalef(2, 24, 2);
	figures.u_prisma(pisoPatioT.GLindex);
	glPopMatrix();

	glColor3f(1, 1, 1);

	glPopMatrix();
}