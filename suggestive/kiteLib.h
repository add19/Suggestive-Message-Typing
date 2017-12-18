#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>		/* getenv(), etc. */
#include <unistd.h>		/* sleep(), etc.  */
#include <X11/Xos.h>
#include <X11/Xatom.h>
#include <X11/keysym.h>
#define BORDER_WIDTH 2

typedef char * COLORREF;
COLORREF RGB(int r, int g, int b); /* utility function by sanjay */

typedef XPoint POINT;


/*Program to draw lines and rectangles--draw.c
*On Linux compile as gcc draw.c -L /usr/X11R6/lib -lX11
*/

class Mywin
{
  private:
    static Display *display;
    int screen_num;
    int depth;
    unsigned long theBlackPixel;
    unsigned long theWhitePixel;
    XEvent report;
    XFontStruct *font_info;       /* Font structure, used for drawing text.    */
    //char* font_name = "*-helvetica-*-12-*"; /* font to use for drawing text.   */
    char font_name[50];   /* font to use for drawing text.   */
    Window theWindow;
    XTextProperty nameProperty;
    GC theGC, green_gc, red_gc;
    XColor green_col, red_col;
    Colormap colormap;
    COLORREF fg_color, bg_color;
    XColor fg_col, bg_col;
//    XTextProperty nameProperty;
//    char green[] = "#00FF00";
//    char red[] = "#FF0000";
    char wintitle[100];

  public:
    Mywin();
    Mywin(char *title, int x0, int y0, int width, int height);
    // ~mywin();
    // void activate( );
    void clear( );
    Display *getDisplay();
    XEvent getReport();
    // void messenger();
    void kiteFlush();
    void close();
    void winPrint(int x, int y, char str[ ]);
    int strpixlen(const char *str);
    int kiteGetchar(int x, int y);
    int kiteGetche(int x, int y);
    POINT kiteGetch(char& ch);
    Bool kiteIsHit( );
    Bool kiteIsHit(POINT& p1, char& ch);
    int kiteGetint(int x, int y, int n=0);
    double kiteGetdouble(int x, int y);
    int kiteGetstr(int x, int y, char *str, int n);
    // HWND editBox(UINT x0, UINT y0, UINT w, UINT h);
    int getWinWidth();
    int getWinHeight();
    void drawRectangle(int x, int y, int width, int height);
    void point(int x, int y, COLORREF c);
    void line(int x1, int y1, int x2, int y2, COLORREF c = RGB(0, 0, 0),
              int penWidth = 0, int penStyle = 0);
    //          int penWidth = 0, int penStyle = PS_SOLID);
    void circle(int xc, int yc, int r, COLORREF c = RGB(0, 0, 0));
    void ellipse(int xc, int yc, int xr, int yr, COLORREF c = RGB(0, 0, 0));
    //void ellipse(int xc, int yc, int xr, int yr, double ang_deg, COLORREF c);
    void polygon(POINT *apt, int n, COLORREF c = RGB(0, 0, 0));
    void arc(int xc, int yc, int xr, int yr, int start_ang, int included_ang, 
             COLORREF c = RGB(0, 0, 0)); // Angles different from win version - IMP note
    void filledRectang(int x, int y, int width, int height,
         COLORREF c = RGB(192, 192, 192), int pattern = -1);
    void filledEllipse(int xc, int yc, int xr, int yr,
         COLORREF c = RGB(192, 192, 192), int pattern = -1);
    void filledPolygon(POINT *apt, int n,
         COLORREF c = RGB(192, 192, 192), int pattern = -1);
    void clrnchars(int x, int y, int n);
    COLORREF GetSetForeColor(COLORREF fg);
    COLORREF GetSetBackColor(COLORREF bg);

/*	green_gc = XCreateGC(theDisplay, theWindow, 0, 0);
	XParseColor(theDisplay, colormap, green, &green_col);
	XAllocColor(theDisplay, colormap, &green_col);

	XSetForeground(theDisplay, green_gc, green_col.pixel);
	XSetBackground(theDisplay, green_gc, theBlackPixel);

	red_gc = XCreateGC(theDisplay, win2, 0, 0);
	XParseColor(theDisplay, colormap, red, &red_col);
	XAllocColor(theDisplay, colormap, &red_col);

	XSetForeground(theDisplay, red_gc, red_col.pixel);

*/
};  // class Mywin ends

