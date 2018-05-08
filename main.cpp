    #include<stdio.h>
    #include<iostream>
    using namespace std;
    #include<GL/glut.h>
    #include<math.h>
    #include<windows.h>
    #include<mmsystem.h>
    #define c1 3.14/180
    char call=0;
    float xdir=0,zdir=0;
    int p=0,pagednflg=0,clickpagedn=0;
    int i,zoom=0;
    float aa=0, z_viewvol= -8,aaa=0,mainbooster=0;
    float zoomit=1,zoom2=0,showcar=0;
    int flagDetach=0,Detach=0;
    int flag=1,click=0,f=0;
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


    //gluLookAt(0.0, 0.0, 0.0, 0.0, 0.0, -100.0, 0.0, 1.0, 0.0);
//gluLookAt(10.0,4.0,10,0.0,0.0,3.0,0.0,0.0,1.0);

   //gluLookAt(0.0, 0.0, 0.0, 0.0, 0.0, -100.0, 0.0, 1.0, 0.0);
  //gluLookAt(10.0,4.0,10,0.0,0.0,3.0,0.0,0.0,1.0);



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
    if(aaa>2.8){
        zoom2+=.02;
    }



    break;
    case GLUT_KEY_END:
        showcar==1;
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
        zdir+=.02;
        xdir+=.005;
    }


    counts-=.1;
    break;
    case GLUT_KEY_PAGE_UP:
    Detach=1;
    aa+=.05;
    click=1;



    break;
    case GLUT_KEY_PAGE_DOWN:
    mainbooster=1;
    clickpagedn=1;
    pagednflg=1.5;
    if(aa>6){
        f+=1;
    }
    if(aa>8){
        aaa+=.01;
    }
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
    void fire2(int j){

    glPushMatrix();
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE);
        glEnable(GL_BLEND);

        float flamethrower[5][3]={ {-.5,-1, -.5}, {0,-1,-4.5}, {-.5,-5,-4.5}, {-.5,-4.5,0}, {0,-5,0}  };    // {T_x, T_y, T_z} for diferent boosters and shuttle

        for(int i=0; i<100; i++){
           glPushMatrix();
           //glRotatef(anglefire, 1, 0, 0);
           glScalef(.5,.5,.8);
              glTranslated(flamethrower[j][0] + random(-1,1), flamethrower[j][1]+random2(0,1)-aaa-1, flamethrower[j][2]-random(1,5));
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
    void fire3(int j){

    glPushMatrix();
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE);
        glEnable(GL_BLEND);

        float flamethrower[5][3]={ {-.5,-1, -.5}, {0,-1,-4.5}, {-.5,-5,-4.5}, {-.5,-4.5,0}, {0,-5,0}  };    // {T_x, T_y, T_z} for diferent boosters and shuttle

        for(int i=0; i<100; i++){
           glPushMatrix();
          // glRotatef(anglefire, 1, 0, 0);
          //glRotatef(angle, 1, 0, 0);
           glScalef(.5,.5,.8);
              glTranslated(flamethrower[j][0] + random(0,0), flamethrower[j][1]+random2(0,2.5)+3.7, flamethrower[j][2]-random(1,3));
              glTranslated(0, -3, z_viewvol);
                             // Translation ....must for cylinders

              if(i%3==0){
                    glRotatef(angle, 1, 0, 0);
                  glColor3f(.8,0.46, 0);
glScalef(.5,.5,.5);
                  glutWireSphere(0.5, 32,32);
               }
               else if(i%2==0)
               {
                   glRotatef(angle, 1, 0, 0);
                   glColor3f(.5,0.54,0);
               glScalef(.5,.5,.5);
                 glutWireTetrahedron();
              }
              else{
                    glRotatef(angle, 1, 0, 0);
                  glColor3f(0.85,0.75,0.2);
                  glScalef(.4,.4,.4);
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
    void stars2()
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
    glVertex3f(-1,0,-8);
    glVertex3f(-2,0,-8);
    glVertex3f(-2,-1,-8);
    glVertex3f(-2,-3,-8);
    glVertex3f(-2.5,-1,-8);
    glVertex3f(-2.5,-1.4,-8);
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
    glVertex3f(3,-3.1,-8);
    glVertex3f(4,-3.1,-8);
    glVertex3f(4,-4.1,-8);

    glVertex3f(-3.9,3.5,-8);
    glVertex3f(-4,3,-8);
    glVertex3f(3,0,-8);
    glVertex3f(-4,-4,-8);

    glEnd();

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

    //////////////////////////////////CAR////////////////////////////////////////////



    void Scean1Rocket(){

    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = t*90.0;


    glColor3d(1,0,0);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1.8, 1.8, -1.0, 1.0, 2.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
gluLookAt(0.0, 0.0, 0.0, 0.0, 0.0, -100.0, 0.0, 1.0, 0.0);

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

    glColor3f(1,.4,.4);
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
    ///////////Building Two///////////////////////
    glPushMatrix();


    glColor3f(0.45,.45,.45);

    glTranslatef(-4,0,-8);
    glScaled(.5,2.5,1.0);
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


    glColor3f(0.3,.3,.3);

    glTranslatef(-2,-2.5,-8);
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
            renderBitmapString(-4,2,"Press Up Arrow To Launch ");
            renderBitmapString(-4,1.8," Down Arrow to Move Down");


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
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1.8, 1.8, -1.0, 1.0, 2.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
gluLookAt(0.0, 0.0, 0.0, 0.0, 0.0, -100.0, 0.0, 1.0, 0.0);


    ////////////////////////////////////////////////////////////////////////////
    glPushMatrix();

    glPopMatrix();

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

    glColor3f(1,.4,.4);
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
    if(counts>73){
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
    stars2();
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
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1.8, 1.8, -1.0, 1.0, 2.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
gluLookAt(0.0, 0.0, 0.0, 0.0, 0.0, -100.0, 0.0, 1.0, 0.0);


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
    /////////////////////////////////////////////////////////////////////////////////////////////////////
    if(aa>8){
    if(clickpagedn==0){
        glColor3f(1,1,1);
            renderBitmapString(1,2,"Click PageDn To Detach The MainBoosters");
    }
    }
    glPopMatrix();
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

    glColor3f(1,.5,.5);
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
    stars2();
    glPopMatrix();

    glutSwapBuffers();
//glutSwapBuffers();
    }
    //////////////////////////////////////////Secan 3/////////////////////////////////
    void renderScene3(void) {
    xScale=.1;
    yScale=.1;
    zScale=.1;
    xScale1=.1;
    xScale2=1.9;

    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = t*90.0;


    glColor3d(1,0,0);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1.8, 1.8, -1.0, 1.0, 2.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
gluLookAt(0.0, 0.0, 0.0, 0.0, 0.0, -100.0, 0.0, 1.0, 0.0);


    ////////////////////////////////////////////////////////////////////////////
    if(click!=1){
    glPushMatrix();
    fire(4);
    glPopMatrix();
    }
    else{
    glPushMatrix();
    fire2(4);
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
    glColor3f(1,.5,.5);
    change();
    glTranslatef(0,(xScale1)*-8.1+(-aaa),-8.0);
    glRotatef(angle, 1, 0, 0);

    glRotated(a*.01,0,0,1);
    draw_cylinder(.23, 2, 255, 160, 100);
    glPopMatrix();
    glPushMatrix();

    ////////////////////Smaller cylinder////////////////
    glPushMatrix();

    glColor3f(1,.5,.5);
    change();
    glTranslatef(0,(xScale1)*1.6,-8.0);
    glRotatef(angle, 1, 0, 0);
    glRotated(a*.01,0,0,1);
    draw_cylinder(.23, 1, 255, 160, 100);
    glPopMatrix();
    glPushMatrix();
    ////////////////////////
    glColor3f(0,0,1);
    change();
    glTranslatef(0,(xScale1)*2,-8);
    glRotatef(-angle,1,0,0);
    glRotated(a,0,0,1);
    glutSolidCone(.23,.3,20,15);
    glEnd();
    glPopMatrix();
    //////////////////////////////Down cone/////////
    glPushMatrix();
    ////////////////////////
    glColor3f(0.7,.5,.5);
    change();
    glTranslatef(0,(xScale1)*-9.5,-8);
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
    glTranslatef(1,(xScale2)*.055-aaa,.5);
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
    stars2();
    glPopMatrix();
    glutSwapBuffers();
    //glutSwapBuffers();
    }
    ////////////////////////////////Secen 444444444444444444444444444444444//////////////
     void renderScene4(void) {
    xScale=.1;
    yScale=.1;
    zScale=.1;
    xScale1=.1;
    xScale2=1.9;


    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = t*90.0;


    glColor3d(1,0,0);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1.8, 1.8, -1.0, 1.0, 2.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
gluLookAt(0.0, 0.0, 0.0, 0.0, 0.0, -100.0, 0.0, 1.0, 0.0);


    ///////////////////////////////////////////////////////////////////////////////////////////
glPushMatrix();



    glColor3d(.74,.2,0);
    glTranslated(0,1.7,-12+(zoom2));
    glRotated(60,1,0,0);
    glRotated(a/2,0,0,1);
    glutSolidSphere(1.2,16,15);
    glPopMatrix();
glPushMatrix();
    fire3(4);
    glPopMatrix();
    ////////////////////Smaller cylinder////////////////
    glPushMatrix();

    glColor3f(1,.5,.5);
    change();
    glTranslatef(0,(xScale1)*1.6,-8.0);
    glRotatef(angle, 1, 0, 0);
    glRotated(a*.01,0,0,1);
    draw_cylinder(.23, 1, 255, 160, 100);
    glPopMatrix();
    glPushMatrix();
    ////////////////////////
    glColor3f(0,0,1);
    change();
    glTranslatef(0,(xScale1)*2,-8);
    glRotatef(-angle,1,0,0);
    glRotated(a,0,0,1);
    glutSolidCone(.23,.3,20,15);
    glEnd();
    glPopMatrix();
    //////////////////////////////Down cone/////////
    glPushMatrix();
    ////////////////////////
    glColor3f(0.7,.5,.5);
    change();
    glTranslatef(0,(xScale1)*-9.5,-8);
    glRotatef(-angle,1,0,0);
    glRotated(a,0,0,1);
    glutSolidCone(.23,.3,20,15);
    glEnd();
    glPopMatrix();
    glPushMatrix();

    ////////////////////////////////////////////////////////////////


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
    stars2();
    glPopMatrix();
    glutSwapBuffers();
    //glutSwapBuffers();
    }
    //////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////





float pc[]={5.5,-2.5,1},q[]={5.5,-7.5,1},r[]={10.7,-7.5,1},s[]={10.7,-2.5,1};

float p1[]={10.7,-9,3},s1[]={12.7,-9,3},q1[]={10.7,-1,3},r1[]={12.7,-1,3};

float p2[]={0.5,-1,1},s2[]={5.5,-1,1},q2[]={0.5,-9,1},r2[]={5.5,-9,1};

float p3[]={-15,-6.5,1},q3[]={-15,-3.5,1},r3[]={0.5,-2.5,1},s3[]={0.5,-7.5,1};

float p4[]={-13,-6.5,1},q4[]={-13,-6.5,2.5},r4[]={0.5,-7.5,3.5},s4[]={0.5,-7.5,1};

float p5[]={-13,-3.5,1},q5[]={-13,-3.5,2.5},r5[]={0.5,-2.5,3.5},s5[]={0.5,-2.5,1};

float p6[]={5.5,-2.5,1},q6[]={5.5,-2.5,3.5},r6[]={10.7,-2.5,3.5},s6[]={10.7,-2.5,1};

float p7[]={5.5,-7.5,1},q7[]={5.5,-7.5,3.5},r7[]={10.7,-7.5,3.5},s7[]={10.7,-7.5,1};

float p8[]={5.5,-7.5,3.5},q8[]={10.7,-7.5,3.5},r8[]={10.7,-6,3.5},s8[]={5.5,-6,3.5};

float p9[]={5.5,-2.5,3.5},q9[]={5.5,-4,3.5},r9[]={10.7,-4,3.5},s9[]={10.7,-2.5,3.5};

float p10[]={5.5,-4,3.5},q10[]={10.7,-4,3.5},r10[]={10.7,-5,4.5},s10[]={5.5,-5,5.5};

float p11[]={5.5,-6,3.5},q11[]={10.7,-6,3.5},r11[]={10.7,-5,4.5},s11[]={5.5,-5,5.5};

float p12[]={10.7,-9,2},q12[]={10.7,-9,4},r12[]={12.7,-9,4},s12[]={12.7,-9,2};
float p13[]={10.7,-1,2},q13[]={10.7,-1,4},r13[]={12.7,-1,4},s13[]={12.7,-1,2};


float p14[]={0.5,-1,1},q14[]={0.5,-1,3},r14[]={5.5,-1,3},s14[]={5.5,-1,1};

float p15[]={0.5,-9,1},q15[]={0.5,-9,3},r15[]={5.5,-9,3},s15[]={5.5,-9,1};

float p16[]={0.5,-1,1},q16[]={0.5,-1,3},r16[]={0.5,-2.5,3.5},s16[]={0.5,-2.5,1};

float p17[]={0.5,-7.5,1},q17[]={0.5,-7.5,3.5},r17[]={0.5,-9,3},s17[]={0.5,-9,1};

float p18[]={5.5,-1,1},q18[]={5.5,-1,3},r18[]={5.5,-2.5,3.5},s18[]={5.5,-2.5,1};

float p19[]={5.5,-7.5,1},q19[]={5.5,-7.5,3.5},r19[]={5.5,-9,3},s19[]={5.5,-9,1};

float p20[]={10.7,-7.5,1},q20[]={10.7,-7.5,3.5},r20[]={10.7,-2.5,3.5},
s20[]={10.7,-2.5,1};

float p21[]={4,-2.5,3.5},q21[]={5.5,-2.5,3.5},r21[]={5.5,-7.5,3.5},s21[]={4,-7.5,3.5};



void tri(float a[],float b[],float z[])
{
glBegin(GL_TRIANGLES);
    glVertex3fv(a);
    glVertex3fv(b);
    glVertex3fv(z);
glEnd();
}
void cylinder(float r,float l)
{
float x,y,z;
int d;
glBegin(GL_QUAD_STRIP);
for(d=0;d<=362;d+=1)
{
    x=r*cos(c1*d);
    z=r*sin(c1*d);
    y=0;
    glVertex3f(x,y,z);

    y=l;
    glVertex3f(x,y,z);
}
glEnd();
}
void circle(float R)
{
float X,Y,Z;
int i;
glBegin(GL_POLYGON);
for( i=0;i<=360;i++)
{
    X=R*cos(c1*i);
    Z=R*sin(c1*i);
    Y=0;
    glVertex3f(X,Y,Z);
}
glEnd();
}
void driver()
{
glColor3f(0.8,0.9,0.8);
//Legs
glPushMatrix();
    glTranslatef(3,-3.5,1.5);

glRotatef(90,0,0,1);
    cylinder(0.4,3);
glPopMatrix();

glPushMatrix();

    glTranslatef(3,-6.5,1.5);
    glRotatef(90,0,0,1);
    cylinder(0.4,3);
glPopMatrix();

//Hands
glPushMatrix();
    glTranslatef(3,-4,2.5);
    glRotatef(90,0,0,1);
    cylinder(0.4,3);
glPopMatrix();

glPushMatrix();
    glTranslatef(3,-7,2.5);
    glRotatef(90,0,0,1);
    cylinder(0.4,3);
glPopMatrix();

//Head

glPushMatrix();
glColor3f(.9,.95,.9);
    glTranslatef(3,-5.5,4);
    glutSolidSphere (.8, 20, 16);



glPopMatrix();


//Body
glPushMatrix();
glColor3f(.7,.8,.8);
    glTranslatef(3,-5.5,1);
    glRotatef(90,1,0,0);
    cylinder(1,2);
glPopMatrix();

//Circle
glPushMatrix();
    glTranslatef(3,-5.5,3);
    glRotatef(90,1,0,0);
    circle(1);
glPopMatrix();
glEnd();
}

void alloy(float R1,float R2)
{
float X,Y,Z;
int y;
//glColor3f(0,0,0);
glBegin(GL_QUAD_STRIP);
for(y=0;y<=361;y+=1)
{
    X=R1*cos(c1*y);
    Z=R1*sin(c1*y);
    Y=0;
    glVertex3f(X,Y,Z);

    X=R2*cos(c1*y);
    Z=R2*sin(c1*y);
    Y=0;
    glVertex3f(X,Y,Z);

}
glEnd();
}
void rect(float pc[],float q[],float r[],float s[])
{
glBegin(GL_POLYGON);
    glVertex3fv(pc);
    glVertex3fv(q);
    glVertex3fv(r);
glVertex3fv(s);
glEnd();
}
void actall(float R1,float R2)
{
float X,Y,Z;
int i;
glBegin(GL_QUADS);
for( i=0;i<=361;i+=120)
{
    glColor3f(0,0.5,0.5);
    X=R1*cos(c1*i);
    Y=0;
    Z=R1*sin(c1*i);
    glVertex3f(X,Y,Z);

    X=R1*cos(c1*(i+30));
    Y=0;

        Z=R1*sin(c1*(i+30));
    glVertex3f(X,Y,Z);

    X=R2*cos(c1*(i+30));
    Y=0;
    Z=R2*sin(c1*(i+30));
    glVertex3f(X,Y,Z);

    X=R2*cos(c1*i);
    Y=0;
    Z=R2*sin(c1*i);
    glVertex3f(X,Y,Z);
}
glEnd();
}

void wheels()
{
//axle

glColor3f(0.2,0.5,0.3);
cylinder(0.4,9);

//1st Wheel
glColor3f(.4,.4,.4);
cylinder(2,2);
alloy(2,1.4);
actall(1.4,0.8);
glColor3f(1,0.5,0.4);
circle(0.8);


/*glPushMatrix();
    glTranslatef(0,2,0);
    alloy(2,1.4);
    actall(1.4,0.8);
    glColor3f(0,0.5,0.4);
    circle(0.8);
glPopMatrix();
*/

//2nd Wheel
glPushMatrix();
    glTranslatef(0,8,0);
    glColor3f(.4,.4,.4);
    cylinder(2,2);
    alloy(2,1.4);
    actall(1.4,0.8);
    glColor3f(0,0.5,0.4);
    circle(0.8);
glPopMatrix();

/*glPushMatrix();
    glTranslatef(0,10,0);
    actall(1.4,0.8);
    alloy(2,1.4);
    glColor3f(0,0.5,0.4);
    circle(0.8);
glPopMatrix();*/
glEnd();

}

void chassis()
{
//Parameters For glMaterialfv() function
GLfloat specular[] = { 0.7, 0.7, 0.7, 1.0 };
GLfloat ambient[]={1,1,1,1},diffuse[]={0.7,0.7,0.7,1};
GLfloat full_shininess[]={100.0};

//Material Properties
glMaterialfv(GL_FRONT,GL_AMBIENT,ambient);
glMaterialfv(GL_FRONT,GL_SPECULAR,specular);
glMaterialfv(GL_FRONT,GL_DIFFUSE,diffuse);
glMaterialfv(GL_FRONT,GL_SHININESS, full_shininess);
glColor3f(0.1,.1,.1);
rect(p5,q5,r5,s5);
rect(p4,q4,r4,s4);
rect(q5,q4,r4,r5);
/////////////////////////////////////////////////////
glColor3f(.8,.3,.1);

rect(pc,q,r,s);
rect(p2,q2,r2,s2);

rect(p3,q3,r3,s3);



//legspace
rect(p6,q6,r6,s6);
rect(p7,q7,r7,s7);
glColor3f(1,.1,.1);
rect(p8,q8,r8,s8);
rect(p9,q9,r9,s9);

//glColor3f(1,0.6,0);
glColor3f(1,.5,.5);
rect(p1,q1,r1,s1);
rect(q5,q4,p3,q3);
glColor3f(1,.5,.5);
tri(p4,q4,p3);
tri(p5,q5,q3);
//rect(p10,q10,r10,s10);
//rect(p11,q11,r11,s11);
rect(r16,r18,q18,q16);//driver side
rect(q17,q19,r19,r17);
rect(p21,q21,r21,s21);


glColor3f(.7,0.1,0.1);

rect(p12,q12,r12,s12);

rect(p13,q13,r13,s13);
rect(p14,q14,r14,s14);
rect(p15,q15,r15,s15);
rect(p16,q16,r16,s16);

rect(p17,q17,r17,s17);
glColor3f(.4,0.4,0.4);
rect(p18,q18,r18,s18);
rect(p19,q19,r19,s19);
rect(r18,q19,p19,s18);
rect(p20,q20,r20,s20);
}
void changeme(){
    //glEnable(GL_CULL_FACE);
    //glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);


    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
   // glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    //glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    //glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    //glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
    }
void car()
{
// glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

glPushMatrix();
    glRotatef(180,0,0,1);

    chassis();

glPushMatrix();
    glTranslatef(8,-10,1);
    glRotatef(20,0,1,0);
wheels();
glPopMatrix();


glPushMatrix();
    glTranslatef(-12,-10,1);
    glRotatef(20,0,1,0);
    wheels();
glPopMatrix();

    driver();

    //rot+=90;
    //if(rot>360) rot-=360;

glPopMatrix();
glEnd();
}
void renderSceneCar(void) {
// glClearColor(.15,.15,.15,1);

    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = t*90.0;


    glColor3d(1,0,0);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1.8, 1.8, -1.0, 1.0, 2.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
gluLookAt(10.0,4.0,10,0.0,0.0,3.0,0.0,0.0,1.0);

//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//gluLookAt(10.0,4.0,10,0.0,0.0,3.0,0.0,0.0,1.0);

        glPushMatrix();
car();

        glPopMatrix();
/*glPushMatrix();
//sky
 glTranslatef(0,0,-10);
    glColor3f(0,0,1);
    glBegin(GL_QUADS);
    glColor3f(1,0,.8);
          glVertex3f(-10,10,0);
          glColor3f(1,.2,.2);
          glVertex3f(10,10,0);
          glColor3f(1,.3,.2);
          glVertex3f(10,-10,0);
          glVertex3f(-10,-10,0);
    glEnd();
glPopMatrix();*/
glPushMatrix();
glTranslatef(-10,-25,-10);
changeme();
    glColor3f(.1,.4,1);

    glutSolidSphere(8,18,15);

    //glEnd();
    glPopMatrix();
    glPushMatrix();
glTranslatef(-10,-23,-10);
//changeme();
    glColor3f(0,0,0);

    glutSolidSphere(8,18,15);

    //glEnd();
    glPopMatrix();
glPushMatrix();
glColor3f(1,1,1);
renderBitmapString(-60,-70,"On February 7th 2018 Tesla Roadster became the first car ever to float on space");
glPopMatrix();


//////////////////////////////////////////////////////////////////////////////////

 glutSwapBuffers();
 glFlush();

}


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////
    void renderScene(void) {
if(zoom2>9&&aaa>2.8){

renderSceneCar();
}
    else if(aaa>2.8&&pagednflg==1&&showcar==0){
            renderScene4();
    flag=1;
        }

    else if(aa>8&&mainbooster==1){

    renderScene3();
    flag=1;

    }
    else if(counts>73&&Detach==1){

    renderScene2();
    flagDetach=1;
    //
    }
   else if(counts>5){
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
        //one();
   Scean1Rocket();
  // renderSceneCar();

    }
    }
    ///////////////////////////////SECOND RENDER SCENE////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////

    void Initialize() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();
    glOrtho(-20.0, 20.0, -20.0, 20.0, -20.0, 20.0);
    //glOrtho(-10.0, 10.0, -12.0, 10.0, -10.0, 12.0);
    glMatrixMode(GL_MODELVIEW);

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
    glutCreateWindow("Mini Project:) ");
    glEnable(GL_DEPTH_TEST);
//glutReshapeFunc(resize);
    glutDisplayFunc(renderScene);

    glutSpecialFunc(rotateFunc);
    glutIdleFunc(idle);
    Initialize();

    PlaySound("C:\\Users\\HP\\Documents\\ProjectXXX\\rocket.WAV", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
    glutMainLoop();
    return 0;

    }


