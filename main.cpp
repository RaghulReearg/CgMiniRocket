#include<stdio.h>
#include<iostream>
using namespace std;
#include<GL/glut.h>
#include<math.h>
#include<windows.h>
#include<mmsystem.h>
float xdir=0,zdir=0;
int p=0;
int i,zoom=0;
float aa=0, z_viewvol= -8;
float zoomit=1;
int flagDetach=0,Detach=0;
int flag=1,click=0;
float a=.5,b=.5,c=.5;
float angle = 82,angle1=90,anglefire=0;
float xScale=.05,yScale=.05,zScale=.05,xScale1=.5,xScale2=1;
float counts =0;



static void resize(int width, int height)
{
const float ar = (float) width / (float) height;
glViewport(0, 0, width, height);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
gluLookAt(0.0, 0.0, 0.0, 0.0, 0.0, -100.0, 0.0, 1.0, 0.0);
}////////////////////////////////////////////////////////////////////////////////

GLfloat light_ambient[]  = { 0.6f, 0.6f, 0.6f, 1.0f };
GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
GLfloat mat_diffuse[]    = { 1.0f, 1.0f, 0.8f, 1.0f };
GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat high_shininess[] = { 100.0f };
//////////////////////////////////////////////////////////////TEXT?????????
void renderBitmapString(float x, float y, const char *string){
const char *c;
glRasterPos3f(x, y,-5);
for (c=string; *c != '\0'; c++) {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
}
}
void renderBitmapString1(float x, float y, const char *string){
const char *c;
glRasterPos3f(x, y,-5);
for (c=string; *c != '\0'; c++) {
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
}
}
/////////////////////////////////////////////////////////
void rotateFunc(int key, int x, int y){
switch (key) {
case GLUT_KEY_RIGHT:
    if(angle<105){
    angle += 1;
    angle1+=10;

    }
    if (angle > 360) angle = 0.0;
    break;
case GLUT_KEY_LEFT:
    if(angle>75){
    angle -= 1;
    angle1-=10;

    }
    if (angle > 360) angle = 0.0;
    break;
    case GLUT_KEY_DOWN:
      /*  if(xScale>0.7)*/

   /* xScale -= 0.01;
    yScale-=0.01;
    zScale-=0.01;*/
    xScale+=.11;
    xScale1+=.05;
xScale2+=.086;
click=1;
    counts+=.1;
    if(zoom==1){
        zoomit+=.05;
        zdir+=.02;
        xdir+=.005;
    }

    break;
case GLUT_KEY_UP:
   /* if(xScale<1.5){
   /* xScale+=0.01;
    yScale+=0.01;
    zScale+=0.01;*/
   /* }*/
xScale-=.11;
xScale1-=.05;
xScale2-=.086;
if(zoom==1){
        zoomit-=.05;
    }


counts-=.1;
    break;
case GLUT_KEY_PAGE_UP:
    Detach=1;
    aa+=.05;
    click=1;

    break;



}
glutPostRedisplay();
}
////////////////////////////
void scaleFunc(int key, int x, int y){
switch (key) {




}
glutPostRedisplay();
}
////////////////////////////
void change(){
//glEnable(GL_CULL_FACE);
glCullFace(GL_BACK);

glEnable(GL_DEPTH_TEST);
glDepthFunc(GL_LESS);

glEnable(GL_LIGHT0);
glEnable(GL_NORMALIZE);
glEnable(GL_COLOR_MATERIAL);
glEnable(GL_LIGHTING);


glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
glLightfv(GL_LIGHT0, GL_POSITION, light_position);

glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
}
void change1(){
//glEnable(GL_CULL_FACE);
GLfloat light_ambient[]  = { 0.6f, 0.6f, 0.6f, 1.0f };
GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 0.6f };
GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat light_position[] = { 2.0f, 7.0f, 7.0f, 0.0f };

GLfloat mat_ambient[]    = { 0.7f, 1.0f, 0.7f, 1.0f };
GLfloat mat_diffuse[]    = { 1.0f, 1.0f, 0.8f, 1.0f };
GLfloat  mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat high_shininess[] = { 90.0f };
glCullFace(GL_BACK);

glEnable(GL_DEPTH_TEST);
glDepthFunc(GL_LESS);

glEnable(GL_LIGHT0);
glEnable(GL_NORMALIZE);
glEnable(GL_COLOR_MATERIAL);
glEnable(GL_LIGHTING);


glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
glLightfv(GL_LIGHT0, GL_POSITION, light_position);

glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
}

//////////////////////////////////////////////////////////////////////
float random(int min, int max){            // random function: self defined....needed to throw flames

   again: int i=(rand()%100)/10;
   if(max < 7){
	  if(i==8||i==7)
	    i= -1;
	  else if(i==9)
	    i = -2;
   }

   if(i>=min && i<=max)
	  return i;
	else
	 goto again;
}

float random2(int min, int max){                // needed to throw flames

  again: int i=(rand()%100);
  if(i>=min && i<=max)
	  return i;
  else
	 goto again;
}
void fire(int j){

	glPushMatrix();
	    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE);
	    glEnable(GL_BLEND);

		float flamethrower[5][3]={ {1,1, -.5}, {-1,1,-4.5}, {1,-2,-4.5}, {0,-2.5,0}, {-1,-4,0}  };    // {T_x, T_y, T_z} for diferent boosters and shuttle
//float flamethrower[5][3]={ {-.5,-1, -.5}, {0,-1,-4.5}, {-.5,-5,-4.5}, {-.5,-4.5,0}, {0,-5,0}  };
		for(int i=0; i<100; i++){
	       glPushMatrix();
	       glRotatef(anglefire, 1, 0, 0);
	      // glScalef(.5,.5,.5);
			  glTranslated(flamethrower[j][0] + random(-1,1), flamethrower[j][1]+random2(0,1)+(xScale1*2.2), flamethrower[j][2]-random(1,5));
	          glTranslated(0, -2, z_viewvol);
	                         // Translation ....must for cylinders

			  if(i%3==0){
			      glColor3f(.8,0.46, 0);

				  glutWireSphere(0.5, 32,32);
			   }
               else if(i%2==0)
			   { glColor3f(.5,0.64,0);
				 glutWireTetrahedron();
			  }
			  else{
				  glColor3f(0.85,0.75,0.2);
				  glutSolidOctahedron();
			  }
		   glPopMatrix();
	     }  // for loop ends here

	   glDisable(GL_BLEND);
	glPopMatrix();
}


void fire1(int j){

	glPushMatrix();
	    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE);
	    glEnable(GL_BLEND);

		float flamethrower[5][3]={ {-.5,-1, -.5}, {0,-1,-4.5}, {-.5,-5,-4.5}, {-.5,-4.5,0}, {0,-5,0}  };    // {T_x, T_y, T_z} for diferent boosters and shuttle

		for(int i=0; i<100; i++){
	       glPushMatrix();
	       //glRotatef(anglefire, 1, 0, 0);
	       glScalef(.5,.5,.8);
			  glTranslated(flamethrower[j][0] + random(-1,1), flamethrower[j][1]+random2(0,1), flamethrower[j][2]-random(1,5));
	          glTranslated(0, -2, z_viewvol);
	                         // Translation ....must for cylinders

			  if(i%3==0){
			      glColor3f(.8,0.46, 0);

				  glutWireSphere(0.5, 32,32);
			   }
               else if(i%2==0)
			   { glColor3f(.5,0.64,0);
				 glutWireTetrahedron();
			  }
			  else{
				  glColor3f(0.85,0.75,0.2);
				  glutSolidOctahedron();
			  }
		   glPopMatrix();
	     }  // for loop ends here

	   glDisable(GL_BLEND);
	glPopMatrix();
}


//////////////////////////////////////////////////////////////////////////
void draw_cylinder(GLfloat radius,
               GLfloat height,
               GLubyte R,
               GLubyte G,
               GLubyte B)
{
GLfloat x              =0.0;
GLfloat y              = 0.0;
GLfloat angle1          = 0.0;
GLfloat angle_stepsize = 0.1;

/** Draw the tube */

glBegin(GL_QUAD_STRIP);
angle1 = 0.0;
//glRotated(a,0,0,1);
//change();
    while( angle1 < 2*3.114) {
        x = radius * cos(angle1);
        y = radius * sin(angle1);
        glVertex3f(x, y , height);
        change();
        glVertex3f(x, y , 0.0);
        angle1 = angle1 + angle_stepsize;
    }
    glVertex3f(radius, 0.0, height);
    glVertex3f(radius, 0.0, 0.0);
glEnd();

}



//////////////////////////////////////////Stars//////////////////////////////////
void stars()
{

    glColor3f(1.0,1.0,1.0);
glPointSize(2);
glBegin(GL_POINTS);

glVertex3f(3,3,-8);
glVertex3f(2,2,-8);
glVertex3f(1,1,-8);
glVertex3f(2,2,-8);
glVertex3f(1,-3,-8);
glVertex3f(-3,4,-8);
glVertex3f(-4,1.5,-8);
glVertex3f(-3.5,3,-8);

glVertex3f(-3.5,2.1,-8);
glVertex3f(-3.5,.1,-8);
glVertex3f(-4,.1,-8);
glVertex3f(-6,3.1,-8);

glVertex3f(-4,.1,-8);
glVertex3f(-2,-1,-8);
glVertex3f(-1,-2.5,-8);
glVertex3f(1,-1.5,-8);
glVertex3f(2,-1.6,-8);
glVertex3f(3,2.3,-8);


glVertex3f(-3.9,3.5,-8);
glVertex3f(-4,3,-8);
glVertex3f(9,0,-8);
glVertex3f(-4,-10,-8);

glEnd();
/*glVertex2f(7,-1);
glVertex2f(-7,8);
glVertex2f(2,2);
glVertex2f(5,3);
glVertex2f(-4,3);
glVertex2f(6,-5);
glVertex2f(2,10);
glVertex2f(10,-3);
glVertex2f(-4,-4);
glVertex2f(-2,6);
glVertex2f(1,4);
glVertex2f(2,-3);
glVertex2f(9,-4);
glVertex2f(2,9);
glVertex2f(-4,2);
glVertex2f(-7,3);
glVertex2f(5,4);
glVertex2f(2,8);
glVertex2f(9,8);
glVertex2f(4,2);*/



}

void stars1()
{
  glColor3f(1.0,1.0,1.0);

glBegin(GL_POINTS);
glPointSize(2);
glVertex3f(3,3,-8);
glVertex3f(2,2,-8);
glVertex3f(1,1,-8);
glVertex3f(2,2,-8);
glVertex3f(1,-3,-8);
glVertex3f(-3,4,-8);
glVertex3f(-4,1.5,-8);
glVertex3f(-3.5,3,-8);
glPointSize(1);
glVertex3f(-3.5,2.1,-8);
glVertex3f(-3.5,.1,-8);
glVertex3f(-4,.1,-8);
glVertex3f(-2,-1,-8);
glVertex3f(-1,-2.5,-8);
glVertex3f(1,-1.5,-8);
glVertex3f(2,-1.6,-8);
glVertex3f(3,2.3,-8);
glVertex3f(1,-1.5,-8);

glVertex3f(-4,-4,-8);
glVertex3f(-3.6,-2.5,-8);
glVertex3f(4,3,-8);
glVertex3f(3,4,-8);
glVertex3f(4,-3.5,-8);
glVertex3f(4.1,4.5,-8);

glVertex3f(-6,3.1,-8);




glVertex3f(-3.9,3.5,-8);
glVertex3f(-4,3,-8);
glVertex3f(9,0,-8);
glVertex3f(-4,-10,-8);

glEnd();

}
////////////////////////////////////////////////////REnderScean1//////////////



////////////////////////////////////////////////////////////////////
void Scean1Rocket(){

const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
const double a = t*90.0;


glColor3d(1,0,0);

glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


////////////////////////////////////////////////////////////////////////////
glPushMatrix();
//glTranslatef(0,(xScale)*.7,-6);
fire(3);
glPopMatrix();
glPushMatrix();

glColor3f(1,1,1);
change();

glTranslatef(0,(xScale)*.7,-6);
glRotatef(angle, 1, 0, 0);
glScalef(.5,.5,.5);
glRotated(a*.01,0,0,1);

draw_cylinder(.2, 3, 255, 110, 100);
glPopMatrix();



glPushMatrix();


glColor3f(0,0,1);
change();
    glTranslatef(-0,(xScale)*.7,-6);
    glScalef(.5,.5,.5);
    glRotatef(-angle,1,0,0);
    glRotated(a,0,0,1);
    glutSolidCone(.2,.3,20,15);
    glEnd();
glPopMatrix();
/////////////////////////////////////////////////////////////////////////////
 glPushMatrix();

glColor3f(1,1,1);
change();
glTranslatef(-.38,(xScale)*1,-9);
glRotatef(angle, 1, 0, 0);
glScalef(.7,.7,.7);
glRotated(a*.01,0,0,1);
draw_cylinder(.2, 3, 255, 110, 100);
glPopMatrix();



glPushMatrix();


glColor3f(0,0,1);
change();
    glTranslatef(-.38,(xScale)*1,-9);
    glScalef(.7,.7,.7);
    glRotatef(-angle,1,0,0);
    glRotated(a,0,0,1);
    glutSolidCone(.2,.3,20,15);
    glEnd();
glPopMatrix();
///////////////////////////////////////////////////////////////////////
glPushMatrix();

glColor3f(1,1,1);
change();
glTranslatef(.38,(xScale)*1,-9);
glRotatef(angle, 1, 0, 0);
glScalef(.7,.7,.7);
glRotated(a*.01,0,0,1);
draw_cylinder(.2, 3, 255, 110, 100);
glPopMatrix();



glPushMatrix();


glColor3f(0,0,1);
change();
    glTranslatef(.38,(xScale)*1,-9);
    glScalef(.7,.7,.7);
    glRotatef(-angle,1,0,0);
    glRotated(a,0,0,1);
    glutSolidCone(.2,.3,20,100);
    glEnd();
glPopMatrix();

///////////////////////////////////////////////////////////////////////////////////////////
glPushMatrix();

glColor3f(.9,.85,.9);
change1();
glTranslatef(0.0,(xScale1)*2,-8.0);
glRotatef(angle, 1, 0, 0);

glRotated(a*.01,0,0,1);
draw_cylinder(.23, 2.9, 255, 160, 100);
glPopMatrix();



glPushMatrix();


glColor3f(0,0,1);
change();
    glTranslatef(0,(xScale1)*2,-8);
    glRotatef(-angle,1,0,0);
    glRotated(a,0,0,1);
    glutSolidCone(.23,.3,20,15);
    glEnd();
glPopMatrix();
/////////////////////////////////////////////Building Main/////////////////

 glPushMatrix();


glColor3f(0.45,.45,.45);

    glTranslatef(3,0,-8);
    glScaled(1.0,2.5,1.0);
    //glRotatef(-angle,1,0,0);
    //glRotated(a,0,0,1);
    glutSolidCube(2);
    glEnd();
glPopMatrix();
glPushMatrix();
/////////////////////////////////////////////////////////
/*glPushMatrix();


glColor3f(0.5,.5,.5);

    glTranslatef(-.9,-1.5,-7.5);
    glScaled(.1,7,.1);
    //glRotatef(-angle,1,0,0);
    //glRotated(a,0,0,1);
    glutSolidCube(1);
    glEnd();
glPopMatrix();
glPushMatrix();


glColor3f(0.5,.5,.5);

    glTranslatef(-.9,-1.5,-8.7);
    glScaled(.1,7,.1);
    //glRotatef(-angle,1,0,0);
    //glRotated(a,0,0,1);
    glutSolidCube(1);
    glEnd();
glPopMatrix();*/


///////////////////////Base Rocket///////////////////////////

glPushMatrix();


glColor3f(0.3,.3,.3);

    glTranslatef(1,-2.5,-8);
    glScaled(2,.08,1.0);
    //glRotatef(-angle,1,0,0);
    //glRotated(a,0,0,1);
    glutSolidCube(2);
    glEnd();
glPopMatrix();

glPushMatrix();

////////////////////////////////////////////////////////////////


glColor3f(0.2,.2,.3);



    //glRotated(a,0,0,1);
glScalef(1,1,1);
glTranslatef(1,(xScale2)*1.225,.5);
glRotatef(angle1*.002,1,0,0);
    glBegin(GL_POLYGON);
    glVertex3f(-.5,-3,-9);
glVertex3f(-1,-2,-9);
    glVertex3f(-1.5,-3,-9);

       glVertex3f(-1.5,-3.2,-9);
       //glVertex3f(-1,-2,-9);
       glVertex3f(-.5,-3.2,-9);
    //glutSolidCube(2);
    glEnd();
glPopMatrix();



glPushMatrix();

////////////////////////////////////////////////////////////////End Base//////////////

glPushMatrix();

            glColor3f(.6,.6,.6);
            renderBitmapString1(1.9,1.35,"SpaceX");

glPopMatrix();
glColor3f(0.2,.2,.3);

    glTranslatef(-.05,1,-8);
    glScaled(1.0,.3,1.0);
    //glRotatef(-angle,1,0,0);
    //glRotated(a,0,0,1);
    glBegin(GL_LINES);
    glVertex3f(2,2,1.1);
    glVertex3f(4,2,1.1);
       glVertex3f(4,4,1.1);
       glVertex3f(2,4,1.1);
    //glutSolidCube(2);
    glEnd();
glPopMatrix();
glPushMatrix();


glColor3f(0,.1,.1);

    glTranslatef(-.05,-3.1,-8);
    glScaled(1.0,.3,1.0);
    //glRotatef(-angle,1,0,0);
    //glRotated(a,0,0,1);
    glBegin(GL_POLYGON);
    glVertex3f(3.2,-3,1.05);
    glVertex3f(3.2,4,1.05);
       glVertex3f(2.8,4,1.05);
       glVertex3f(2.8,2,1.05);
    //glutSolidCube(2);
    glEnd();
glPopMatrix();


glPushMatrix();

        if(click==0){
            glColor3f(0,0,0);
            renderBitmapString(-4,2,"Press Dwn Arrow To Launch ");
            renderBitmapString(-4,1.8," Up Arrow to Move Down");


        }
glPopMatrix();


///////////////////////////////////////////////////////////////////////
glPushMatrix();


///////////////////////////////

///////////////////////////////
//sky
 glTranslatef(0,0,-10);
    glColor3f(0,0,1);
    glBegin(GL_QUADS);
    glColor3f(0,0,.8);
          glVertex3f(-10,10,0);
          glColor3f(0,.6,.9);
          glVertex3f(10,10,0);
          glColor3f(0,1,1);
          glVertex3f(10,-10,0);
          glVertex3f(-10,-10,0);
    glEnd();
glPopMatrix();
glPushMatrix();

    glTranslatef(0,-1,-6);
    glColor3f(0,1,.1);
    glRotatef(angle, 0.0, 1.0, 0);
    //glScalef(1.5,2.5,1.5);
//grass
    glBegin(GL_QUADS);
        glVertex3f(-30,-1.5,100);
        glVertex3f(-30,-1.5,-100);
        glVertex3f(30,-1.5,-100);
        glColor3f(.2,.8,.1);
        glVertex3f(30,-1.5,100);
    glEnd();
glPopMatrix();

//////////////////////////////////////////////////////////////////////////////////////////////////////////



glutSwapBuffers();

}



/////////////////
void renderScene1(void) {
xScale=.1;
yScale=.1;
zScale=.1;
xScale1=.1;
xScale2=1.9;

const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
const double a = t*90.0;


glColor3d(1,0,0);

glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


////////////////////////////////////////////////////////////////////////////
glPushMatrix();
fire(3);
glPopMatrix();
 glPushMatrix();

glColor3f(1,1,1);
change();
glTranslatef(0,(xScale)*-6,-6);
glRotatef(angle, 1, 0, 0);
glScalef(.5,.5,.5);
glRotated(a*.01,0,0,1);
draw_cylinder(.2, 3, 255, 110, 100);
glPopMatrix();



glPushMatrix();


glColor3f(0,0,1);
change();
    glTranslatef(-0,(xScale)*-6,-6);
    glScalef(.5,.5,.5);
    glRotatef(-angle,1,0,0);
    glRotated(a,0,0,1);
    glutSolidCone(.2,.3,20,15);
    glEnd();
glPopMatrix();
/////////////////////////////////////////////////////////////////////////////
 glPushMatrix();

glColor3f(1,1,1);
change();
glTranslatef(-.38,(xScale)*-9,-9);
glRotatef(angle, 1, 0, 0);
glScalef(.7,.7,.7);
glRotated(a*.01,0,0,1);
draw_cylinder(.2, 3, 255, 110, 100);
glPopMatrix();



glPushMatrix();


glColor3f(0,0,1);
change();
    glTranslatef(-.38,(xScale)*-9,-9);
    glScalef(.7,.7,.7);
    glRotatef(-angle,1,0,0);
    glRotated(a,0,0,1);
    glutSolidCone(.2,.3,20,15);
    glEnd();
glPopMatrix();
///////////////////////////////////////////////////////////////////////
glPushMatrix();

glColor3f(1,1,1);
change();
glTranslatef(.38,(xScale)*-9,-9);
glRotatef(angle, 1, 0, 0);
glScalef(.7,.7,.7);
glRotated(a*.01,0,0,1);
draw_cylinder(.2, 3, 255, 110, 100);
glPopMatrix();



glPushMatrix();


glColor3f(0,0,1);
change();
    glTranslatef(.38,(xScale)*-9,-9);
    glScalef(.7,.7,.7);
    glRotatef(-angle,1,0,0);
    glRotated(a,0,0,1);
    glutSolidCone(.2,.3,20,100);
    glEnd();
glPopMatrix();

///////////////////////////////////////////////////////////////////////////////////////////
glPushMatrix();

glColor3f(1,.9,.9);
change();
glTranslatef(0.0,(xScale1)*2,-8.0);
glRotatef(angle, 1, 0, 0);

glRotated(a*.01,0,0,1);
draw_cylinder(.23, 3, 255, 160, 100);
glPopMatrix();



glPushMatrix();


glColor3f(0,0,1);
change();
    glTranslatef(0,(xScale1)*2,-8);
    glRotatef(-angle,1,0,0);
    glRotated(a,0,0,1);
    glutSolidCone(.23,.3,20,15);
    glEnd();
glPopMatrix();
glPushMatrix();

////////////////////////////////////////////////////////////////


glColor3f(0.2,.2,.3);



    //glRotated(a,0,0,1);
glScalef(1,1,1);
glTranslatef(1,(xScale2)*.05,.5);
glRotatef(angle1*.009,1,0,0);
    glBegin(GL_POLYGON);
    glVertex3f(-.5,-3,-9);
glVertex3f(-1,-2,-9);
    glVertex3f(-1.5,-3,-9);

       glVertex3f(-1.5,-3.2,-9);
       //glVertex3f(-1,-2,-9);
       glVertex3f(-.5,-3.2,-9);
    //glutSolidCube(2);
    glEnd();
glPopMatrix();

/////////////////////////////////////////////Building Main/////////////////
if(counts<10){
 glPushMatrix();

///////////////////////////////
//sky

 glTranslatef(0,0,-10);
    glColor3f(0,0,1);
    glBegin(GL_QUADS);
    glColor3f(0,0,.8);
          glVertex3f(-10,10,0);
          glColor3f(0,.6,.9);
          glVertex3f(10,10,0);
          glColor3f(0,1,1);
          glVertex3f(10,-10,0);
          glVertex3f(-10,-10,0);
    glEnd();
glPopMatrix();
glutSwapBuffers();
}
else if(counts<15){
        glPushMatrix();
    glTranslatef(0,0,-10);
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
          glVertex3f(-10,10,0);
          glColor3f(0,.6,.9);
          glVertex3f(10,10,0);
          glColor3f(0,1,1);
          glVertex3f(10,-10,0);
          glVertex3f(-10,-10,0);
    glEnd();
glPopMatrix();
glutSwapBuffers();
}
 else if(counts<19){
        glPushMatrix();
    glTranslatef(0,0,-10);
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
          glVertex3f(-10,10,0);
          glColor3f(0,.6,.9);
          glVertex3f(10,10,0);
          glColor3f(0,.5,.5);
          glVertex3f(10,-10,0);
          glVertex3f(-10,-10,0);
    glEnd();
glPopMatrix();
glutSwapBuffers();
}

else if(counts<23){
        glPushMatrix();
    glTranslatef(0,0,-10);
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
          glVertex3f(-10,10,0);
          glColor3f(0,.6,.9);
          glVertex3f(10,10,0);
          glColor3f(0,.3,.3);
          glVertex3f(10,-10,0);
          glVertex3f(-10,-10,0);
    glEnd();
glPopMatrix();
glutSwapBuffers();
}
else if(counts<27){
        glPushMatrix();
    glTranslatef(0,0,-10);
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
          glVertex3f(-10,10,0);
          glColor3f(0,.5,.6);
          glVertex3f(10,10,0);
          glColor3f(0,.2,.2);
          glVertex3f(10,-10,0);
          glVertex3f(-10,-10,0);
    glEnd();
glPopMatrix();
glutSwapBuffers();
}
else if(counts<33){


/*glPushMatrix();
zoom=1;

glColor3d(.94,.2,0);
    glTranslated(-2.4,1.2,-10+(zoomit));
    glRotated(60,1,0,0);
    glRotated(a,0,0,1);
    glutSolidSphere(1.1,16,15);

glPopMatrix();*/



        glPushMatrix();

    glTranslatef(0,0,-10);
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
          glVertex3f(-10,10,0);
          glColor3f(0,.6,.9);
          glVertex3f(10,10,0);
          glColor3f(0,0,0);
          glVertex3f(10,-10,0);
          glVertex3f(-10,-10,0);
          glColor3f(1,1,1);

    glEnd();
    glPopMatrix();
    glPushMatrix();
stars();
glPopMatrix();


glutSwapBuffers();
}


else if(counts<70){


glPushMatrix();
zoom=1;

glColor3d(.94,.2,0);
    glTranslated(-2.4,1.2,-11+(zoomit));
    glRotated(60,1,0,0);
    glRotated(a,0,0,1);
    glutSolidSphere(1.1,16,15);

glPopMatrix();
if(counts>42){

        glPushMatrix();
    glColor3d(.94,.92,.50);
    glTranslated(2.5+xdir,2.5,-12+(zdir));
    glRotated(60,1,0,0);
    glRotated(a,0,0,1);
    glutSolidSphere(1.1,16,15);

glPopMatrix();
}

        glPushMatrix();

    glTranslatef(0,0,-10);
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
          glVertex3f(-10,10,0);
          glColor3f(0,.6,.9);
          glVertex3f(10,10,0);
          glColor3f(0,0,0);
          glVertex3f(10,-10,0);
          glVertex3f(-10,-10,0);
          glColor3f(1,1,1);

    glEnd();
    glPopMatrix();
    glPushMatrix();
stars1();
glPopMatrix();


glutSwapBuffers();
}
else{
    click=0;
    glPushMatrix();
    if(counts>71){
        if(click==0){
            glColor3f(1,1,1);
            renderBitmapString(1,2,"Click PageUp To Detach The Boosters");
        }

        }
glPopMatrix();

   glPushMatrix();

    glTranslatef(0,0,-10);
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
          glVertex3f(-10,10,0);
          glColor3f(0,.2,.2);
          glVertex3f(10,10,0);
          glColor3f(0,.2,.2);
          glVertex3f(10,-10,0);
          glVertex3f(-10,-10,0);
          glColor3f(1,1,1);

    glEnd();
    glPopMatrix();
    glPushMatrix();
stars1();
glPopMatrix();


glutSwapBuffers();
}

//glutSwapBuffers();
}

////////////////////////////////////////////////////////////////////
void renderScene2(void) {
xScale=.1;
yScale=.1;
zScale=.1;
xScale1=.1;
xScale2=1.9;

const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
const double a = t*90.0;


glColor3d(1,0,0);

glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


////////////////////////////////////////////////////////////////////////////
if(click!=1){
glPushMatrix();
fire(4);
glPopMatrix();
}
else{
  glPushMatrix();
fire1(4);
glPopMatrix();

}
 glPushMatrix();

glColor3f(1,1,1);
change();

glTranslatef(0,(xScale)*-6,-6+(aa));
glRotatef(angle, 1,0 , 0);
glScalef(.5,.5,.5);
glRotated(a,0,0,1);
draw_cylinder(.2, 3, 255, 110, 100);
glPopMatrix();

glPushMatrix();


glColor3f(0,0,1);
change();
    glTranslatef(0,(xScale)*-6,-6+(aa));
    glScalef(.5,.5,.5);
    glRotatef(-angle,1,0,0);
    glRotated(a,0,0,1);
    glutSolidCone(.2,.3,20,15);
    glEnd();
glPopMatrix();
/////////////////////////////////////////////////////////////////////////////
 glPushMatrix();

glColor3f(1,1,1);
change();
glTranslatef(-.38+(-aa),(xScale)*-9,-9);
glRotatef(angle, 1, 0, 0);
glScalef(.7,.7,.7);
glRotated(a,0,0,1);
draw_cylinder(.2, 3, 255, 110, 100);
glPopMatrix();



glPushMatrix();


glColor3f(0,0,1);
change();
    glTranslatef(-.38+(-aa),(xScale)*-9,-9);
    glScalef(.7,.7,.7);
    glRotatef(-angle,1,0,0);
    glRotated(a,0,0,1);
    glutSolidCone(.2,.3,20,15);
    glEnd();
glPopMatrix();
///////////////////////////////////////////////////////////////////////
glPushMatrix();

glColor3f(1,1,1);
change();
glTranslatef(.38+(aa),(xScale)*-9,-9);
glRotatef(angle, 1, 0, 0);
glScalef(.7,.7,.7);
glRotated(a*.01,0,0,1);
draw_cylinder(.2, 3, 255, 110, 100);
glPopMatrix();



glPushMatrix();


glColor3f(0,0,1);
change();
    glTranslatef(.38+(aa),(xScale)*-9,-9);
    glScalef(.7,.7,.7);
    glRotatef(-angle,1,0,0);
    glRotated(a,0,0,1);
    glutSolidCone(.2,.3,20,100);
    glEnd();
glPopMatrix();

///////////////////////////////////////////////////////////////////////////////////////////
glPushMatrix();

glColor3f(1,.9,.9);
change();
glTranslatef(0,(xScale1)*2,-8.0);
glRotatef(angle, 1, 0, 0);

glRotated(a*.01,0,0,1);
draw_cylinder(.23, 3, 255, 160, 100);
glPopMatrix();



glPushMatrix();


glColor3f(0,0,1);
change();
    glTranslatef(0,(xScale1)*2,-8);
    glRotatef(-angle,1,0,0);
    glRotated(a,0,0,1);
    glutSolidCone(.23,.3,20,15);
    glEnd();
glPopMatrix();
glPushMatrix();

////////////////////////////////////////////////////////////////


glColor3f(0.2,.2,.3);



    //glRotated(a,0,0,1);
glScalef(1,1,1);
glTranslatef(1,(xScale2)*.055,.5);
glRotatef(angle1*.01,1,0,0);
    glBegin(GL_POLYGON);
    glVertex3f(-.5,-3,-9);
glVertex3f(-1,-2,-9);
    glVertex3f(-1.5,-3,-9);

       glVertex3f(-1.5,-3.2,-9);
       //glVertex3f(-1,-2,-9);
       glVertex3f(-.5,-3.2,-9);
    //glutSolidCube(2);
    glEnd();
glPopMatrix();

/////////////////////////////////////////////Building Main/////////////////



        glPushMatrix();

    glTranslatef(0,0,-10);
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
          glVertex3f(-10,10,0);
          glColor3f(0,.2,.2);
          glVertex3f(10,10,0);
          glColor3f(0,.2,.2);
          glVertex3f(10,-10,0);
          glVertex3f(-10,-10,0);
          glColor3f(1,1,1);

    glEnd();
    glPopMatrix();
    glPushMatrix();
    stars1();
    glPopMatrix();



glutSwapBuffers();


//glutSwapBuffers();
}



//////////////////////////////////////////
void renderScene(void) {


if(counts>71&&Detach==1){

renderScene2();
flagDetach=1;
//
}
if(counts>5){
    if(flagDetach==0){
    renderScene1();
    flag=0;
   // flagDetach=1;
    }


}
else if(xScale>-.5){
        if(flag==0){
             xScale=1,yScale=1,zScale=1,xScale1=1;
             flag=1;
        }
    Scean1Rocket();

}


}
///////////////////////////////SECOND RENDER SCENE////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

void Initialize() {
glClearColor(0.0, 0.0, 0.0, 1.0);
glMatrixMode(GL_PROJECTION);

glLoadIdentity();
glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);

}
static void idle(void)
{
glutPostRedisplay();
}
int main(int argc, char **argv) {
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
glutInitWindowPosition(0,0);
glutInitWindowSize(1500,1000);
glutCreateWindow("Assignment ");
glEnable(GL_DEPTH_TEST);

glutReshapeFunc(resize);


glutDisplayFunc(renderScene);
glutSpecialFunc(rotateFunc);
Initialize();

glutIdleFunc(idle);

PlaySound("C:\\Users\\HP\\Documents\\ProjectXXX\\rocket.WAV", NULL, SND_ASYNC|SND_FILENAME);


glutMainLoop();
return 0;


}


