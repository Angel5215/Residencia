
#ifndef _FIGURES_H_
#define _FIGURES_H_

#if _WIN32
	#include "Main.h"
#else
	#include "NVSMain.h"
#endif

class Figures
{

	public:
		void u_prisma(const GLuint &t1);
		void l_prisma(const GLuint &t1);
		void u_cono(const GLfloat &r, const GLfloat &h, const GLfloat &res, const GLuint &t1);
		void l_cono(const GLfloat &r, const GLfloat &h, const GLfloat &res, const GLuint &t1);
		void u_piramide(const GLfloat &l, const GLfloat &w, const GLfloat &h, const GLuint &t1);
		void l_piramide(const GLfloat &l, const GLfloat &w, const GLfloat &h, const GLuint &t1);
		void u_unit_piramide(const GLuint &t1);
		void l_unit_piramide(const GLuint &t1);
		void u_cilindro(const GLfloat &r, const GLfloat &h, const GLfloat &res, const GLuint &t1);
		void u_medio_cilindro(const GLfloat &r, const GLfloat &h, const GLfloat &res, const GLuint &t1);
		void u_cuarto_cilindro(const GLfloat &r, const GLfloat &h, const GLfloat &res, const GLuint &t1);
		void l_cilindro(const GLfloat &r, const GLfloat &h, const GLfloat &res, const GLuint &t1);
		void u_esfera(const GLfloat &r, const GLuint &meridianos, const GLuint &paralelos, const GLuint &t1);
		void l_esfera(const GLfloat &r, const GLuint &meridianos, const GLuint &paralelos, const GLuint &t1);

		//	Otros
		void u_prisma_no_derecha(const GLuint &t1);
		void u_prisma_no_izquierda(const GLuint &t1);
		void l_prisma_no_derecha(const GLuint &t1);
		void l_prisma_no_izquierda(const GLuint &t1);
		void u_prisma_patio(const GLuint &t1);
		void l_prisma_alberca(const GLuint &t1);
		void u_medio_cilindro_sin_tapa(const GLfloat &r, const GLfloat &h, const GLfloat &res, const GLuint &t1);
		void l_cilindro_sin_tapa(const GLfloat &r, const GLfloat &h, const GLfloat &res, const GLuint &t1);

};

#endif