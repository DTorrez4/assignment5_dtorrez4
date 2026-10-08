
// this is where i created my header.

#ifndef pixel_h
#define pixel_h
/* this is where i create my Struct where it holds on to the values of
 * the x and y numbers of the file. and it holds the values for
 * red , green and blue.
*/

struct _Pixel{
    float r;
    float g;
    float b;
    int x;
    int y;
};
typedef _Pixel Pixel;

#endif