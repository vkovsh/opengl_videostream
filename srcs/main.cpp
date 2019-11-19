#include "glut.h"
#include <stdio.h>
#include <unistd.h>

#include "Texture.hpp"

Texture t;

void Reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);
    glMatrixMode(GL_MODELVIEW);
}

void Draw(void)
{
    float angle = 0.0;

    glEnable(GL_TEXTURE_2D);
glBindTexture( GL_TEXTURE_2D, t.getTextureName() ); //bind the texture

glPushMatrix();
glRotatef( angle, 0.0f, 0.0f, 1.0f );
glBegin( GL_QUADS );
glTexCoord2d(0.0,0.0); glVertex2d(-1.0,-1.0);
glTexCoord2d(1.0,0.0); glVertex2d(+1.0,-1.0);
glTexCoord2d(1.0,1.0); glVertex2d(+1.0,+1.0);
glTexCoord2d(0.0,1.0); glVertex2d(-1.0,+1.0);
glEnd();
glPopMatrix();
glutSwapBuffers();
//glutSolidCube(2);
    // glClear(GL_COLOR_BUFFER_BIT);

    // glColor3f(0.0f, 0.0f, 1.0f);
    // glLineWidth(1);

    // glBegin(GL_LINES);
    // glVertex2f(0, 0.5f);
    // glVertex2f(0, -0.5f);
    // glEnd();TextureStatus&  TextureStatus::loadTextureFromPng(const char* name, int width, int height)
// {
//     //test if png
//    int is_png = !png_sig_cmp(header, 0, 8);
//    if (!is_png) {
//      fclose(fp);
//      return TEXTURE_LOAD_ERROR;
//    }
 
//    //create png struct
//    png_structp png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL,
//        NULL, NULL);
//    if (!png_ptr) {
//      fclose(fp);
//      return TEXTURE_LOAD_ERROR;
//    }
 
//    //create png info struct
//    png_infop info_ptr = png_create_info_struct(png_ptr);
//    if (!info_ptr) {
//      png_destroy_read_struct(&png_ptr, (png_infopp) NULL, (png_infopp) NULL);
//      fclose(fp);
//      return TEXTURE_LOAD_ERROR;
//    }
 
//    //create png info struct
//    png_infop end_info = png_create_info_struct(png_ptr);
//    if (!end_info) {
//      png_destroy_read_struct(&png_ptr, &info_ptr, (png_infopp) NULL);
//      fclose(fp);
//      return TEXTURE_LOAD_ERROR;
//    }
 
//    //png error stuff, not sure libpng man suggests this.
//    if (setjmp(png_jmpbuf(png_ptr))) {
//      png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
//      fclose(fp);
//      return TEXTURE_LOAD_ERROR;
//    }
 
//    //init png reading
//    png_init_io(png_ptr, fp);
 
//    //let libpng know you already read the first 8 bytes
//    png_set_sig_bytes(png_ptr, 8);
 
//    // read all the info up to the image data
//    png_read_info(png_ptr, info_ptr);
 
//    //variables to pass to get info
//    int bit_depth, color_type;
//    png_uint_32 twidth, theight;
 
//    // get info about png
//    png_get_IHDR(png_ptr, info_ptr, &twidth, &theight, &bit_depth, &color_type,
//        NULL, NULL, NULL);
 
//    //update width and height based on png info
//    width = twidth;
//    height = theight;
 
//    // Update the png info struct.
//    png_read_update_info(png_ptr, info_ptr);
 
//    // Row size in bytes.
//    int rowbytes = png_get_rowbytes(png_ptr, info_ptr);
 
//    // Allocate the image_data as a big block, to be given to opengl
//    png_byte *image_data = new png_byte[rowbytes * height];
//    if (!image_data) {
//      //clean up memory and close stuff
//      png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
//      fclose(fp);
//      return TEXTURE_LOAD_ERROR;
//    }
 
//    //row_pointers is for pointing to image_data for reading the png with libpng
//    png_bytep *row_pointers = new png_bytep[height];
//    if (!row_pointers) {
//      //clean up memory and close stuff
//      png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
//      delete[] image_data;
//      fclose(fp);
//      return TEXTURE_LOAD_ERROR;
//    }
//    // set the individual row_pointers to point at the correct offsets of image_data
//    for (int i = 0; i < height; ++i)
//      row_pointers[height - 1 - i] = image_data + i * rowbytes;
 
//    //read the png into image_data through row_pointers
//    png_read_image(png_ptr, row_pointers);
 
//    //Now generate the OpenGL texture object
//    GLuint texture;
//    glGenTextures(1, &texture);
//    glBindTexture(GL_TEXTURE_2D, texture);
//    glTexImage2D(GL_TEXTURE_2D,0, GL_RGBA, width, height, 0,
//        GL_RGBA, GL_UNSIGNED_BYTE, (GLvoid*) image_data);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
 
//    //clean up memory and close stuff
//    png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
//    delete[] image_data;
//    delete[] row_pointers;
//    fclose(fp);
 
//    return texture;
// }

    // glFlush();  
}

int main(int argc, char** argv)
{
    //init
    {
        glutInit(&argc, argv);
        glutInitWindowSize(640, 480);
        glutInitWindowPosition(0, 0);
        // glutInitDisplayMode(GLUT_RGB);
        glutInitDisplayMode(GLUT_DOUBLE);
        glutCreateWindow("Player for chinese camera");
    }

    printf("code = %d\n", t.loadTexture("Pikachu.png", 640, 480));
    
    {
        glutReshapeFunc(Reshape);
        glutDisplayFunc(Draw);
        glClearColor(0, 0, 0, 0);
    }

    glutMainLoop();
    return 0;
}