#include "primitivas.h"

#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

#define ROTATE_SPEED 5.0f;
#define MOVE_SPEED 0.1f;
#define HEIGHT_SPEED 0.1f;

#define MENU_ENTRY_LINES GL_LINE
#define MENU_ENTRY_FILL  GL_FILL
#define MENU_ENTRY_POINT GL_POINT

int curr_polygon_mode = MENU_ENTRY_FILL;
float altura = 2;
float x_off = 0, y_off = 0, height = 2;
float angle = 0;
float v_angle = 0;

void changeSize(int w, int h) {

   // Prevent a divide by zero, when window is too short
   // (you cant make a window with zero width).
   if(h == 0)
      h = 1;

   // compute window's aspect ratio 
   float ratio = w * 1.0 / h;

   // Set the projection matrix as current
   glMatrixMode(GL_PROJECTION);
   // Load Identity Matrix
   glLoadIdentity();
   
   // Set the viewport to be the entire window
    glViewport(0, 0, w, h);

   // Set perspective
   gluPerspective(45.0f ,ratio, 1.0f ,1000.0f);

   // return to the model view matrix mode
   glMatrixMode(GL_MODELVIEW);
}

void renderScene(void) {

   // clear buffers
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   // set the camera
   glLoadIdentity();
   gluLookAt(0.0,3.0,10.0, 
            0.0,0.0,0.0,
           0.0f,1.0f,0.0f);
   
   glTranslatef(x_off, 0, y_off);
   glRotatef(angle, 0, 1, 0);
   glPolygonMode(GL_FRONT, GL_LINE);
   // pôr instruções de desenho aqui
   cubo(1);
   // End of frame
   glutSwapBuffers();
}



// escrever função de processamento do teclado
void keyboard_handle(unsigned char key, int x, int y) {
   printf("%c\n", key);
   printf("%f %f\n", x_off, y_off);
   switch(key) {
      case 'W':
      case 'w':
         y_off -= MOVE_SPEED; break;
      case 'S':
      case 's':
         y_off += MOVE_SPEED; break;
      case 'A':
      case 'a':
         x_off -= MOVE_SPEED; break;
      case 'D':
      case 'd':
         x_off += MOVE_SPEED; break;
   }

   glutPostRedisplay();
}

void keyboard_special_handle(int key, int x, int y) {
   switch(key) {
      case GLUT_KEY_LEFT:
         angle -= ROTATE_SPEED; break;
      case GLUT_KEY_RIGHT:
         angle += ROTATE_SPEED; break;
      case GLUT_KEY_UP:
         height += HEIGHT_SPEED; break;
      case GLUT_KEY_DOWN:
         height -= HEIGHT_SPEED; break;
   }

   glutPostRedisplay();
}


// escrever função de processamento do menu
void menu_handle(int op) {
   curr_polygon_mode = op;

   glutPostRedisplay();
}


int main(int argc, char **argv) {

// inicialização
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
   glutInitWindowPosition(100,100);
   glutInitWindowSize(800,800);
   glutCreateWindow("CG@DI-UM");
   glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
      

// registo de funções 
   glutDisplayFunc(renderScene);
   //glutIdleFunc(renderScene);
   glutReshapeFunc(changeSize);

// pôr aqui registo da funções do teclado e rato
   glutKeyboardFunc(keyboard_handle);
   glutSpecialFunc(keyboard_special_handle);

// pôr aqui a criação do menu
   glutCreateMenu(menu_handle);
   glutAddMenuEntry("Fill", MENU_ENTRY_FILL);
   glutAddMenuEntry("Lines", MENU_ENTRY_LINES);
   glutAddMenuEntry("Dots", MENU_ENTRY_POINT);
   glutAttachMenu(GLUT_RIGHT_BUTTON);


// alguns settings para OpenGL
   glEnable(GL_DEPTH_TEST);
   glEnable(GL_CULL_FACE);
   
// entrar no ciclo do GLUT 
   glutMainLoop();
   
   return 0;
}
