#include <GL\glut.h>
#include <math.h>      // For math routines (such as sqrt & trig).
 
GLdouble radius=1.5;
GLfloat qaWhite[] = {1.0, 1.0, 1.0, 1.0}; //White Color
GLfloat qaRed[] = {1.0, 0.0, 0.0, 1.0}; //Red Color

    // Set lighting intensity and color
GLfloat qaAmbientLight[]    = {0.1, 0.1, 0.1, 1.0};
GLfloat qaDiffuseLight[]    = {1, 1, 1, 1.0};
    // Light source position
GLfloat qaLightPosition[]    = {-2, 0, -9.5, 1};// Positional Light
GLfloat qaLightDirection[]    = {1, 1, 1, 0};// Directional Light

void display(void);
void reshape(int x, int y);
 
void initLighting()
{
    // Add smooth
    glShadeModel(GL_FLAT);
    // Enable lighting
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

     // Set lighting intensity and color
       glLightfv(GL_LIGHT0, GL_AMBIENT, qaAmbientLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, qaDiffuseLight);
     glLightfv(GL_LIGHT0, GL_POSITION, qaLightPosition);
    ////////////////////////////////////////////////
    //glLightf( GL_LIGHT0, GL_CONSTANT_ATTENUATION, 0.2f );
     glLightf( GL_LIGHT0, GL_LINEAR_ATTENUATION , 0.5f );
    //glLightf( GL_LIGHT0, GL_QUADRATIC_ATTENUATION , 0.009f );

        

}
void keyboard(unsigned char key, int x, int y)
{
    
     
     if (key == 'l' || key == 'L')  
    { 
          glEnable(GL_LIGHTING);
    }
    else if (key == 'd' || key == 'D')  
    { 
        glDisable(GL_LIGHTING);
    }

}

 
int main (int argc, char **argv)
{
    glutInit(&argc, argv); 
     glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
    glutInitWindowSize(750,750);
    glutCreateWindow("Teapot -light attenuation");
    initLighting(); 

     
 
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard); // Register keyboard callback
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
 
void display(void)
{


    glMatrixMode(GL_MODELVIEW);
    // clear the drawing buffer.
    glClear(GL_COLOR_BUFFER_BIT);
    // clear the identity matrix.
    glLoadIdentity();
   
    glTranslatef(0.0,0.0,-5.0);
 
    


      glPushMatrix();
 
      glTranslatef(0.0,0.0,-2.0);
    // Set material properties
       glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, qaRed);

    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, qaRed);

 
     glutSolidTeapot(radius);
     glPopMatrix();


     

    glFlush();
    glutSwapBuffers();      
   
}
 
void reshape(int x, int y)
{
    if (y == 0 || x == 0) return;   
    glMatrixMode(GL_PROJECTION);  
    glLoadIdentity(); 
    
    gluPerspective(39.0,(GLdouble)x/(GLdouble)y,0.6,40.0);
    glMatrixMode(GL_MODELVIEW);
    glViewport(0,0,x,y);  //Use the whole window for rendering
} - See more at: http://www.codemiles.com/c-opengl-examples/change-the-shading-of-object-t9179.html#sthash.bJlntr7i.dpuf