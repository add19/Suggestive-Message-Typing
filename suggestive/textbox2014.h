// textbox2014.h
#define TRUE 1
#include "math.h"
#include "string.h"

class Label
{
 public:
   enum justification {LEFT, CENTER, RIGHT};
   Label(Mywin& w1, int x, int y, char *label,
           justification j = LEFT, 
	   COLORREF label_color = RGB(0, 0, 0))
   {
     int L=w1.strpixlen(label);
     COLORREF temp1;
     temp1 = w1.GetSetForeColor(label_color);
     switch(j)
     {
       case LEFT:
         w1.winPrint(x, y, label);
         break;
       case CENTER:
         w1.winPrint(x-L/2, y, label);
	 break;
       case RIGHT:
         w1.winPrint(x-L, y, label);
	 break;
     }
     w1.GetSetForeColor(temp1);
   }
};   

class Textbox
{
 private:
   int x, y, width;
   COLORREF box_color;
 public:
   Textbox(Mywin& w1, int x1, int y1,
             COLORREF box_color, int size = 6)
   {
     COLORREF temp1;
     x = x1; y = y1;
     width = size;
     this->box_color = box_color;
     temp1 = w1.GetSetBackColor(box_color);
     w1.clrnchars(x, y, width);
     w1.GetSetBackColor(temp1);
   }
   void clear(Mywin& w1)
   {
     COLORREF temp1;
     temp1 = w1.GetSetBackColor(box_color);
     w1.clrnchars(x, y, width);
     w1.GetSetBackColor(temp1);
   }
   bool is_clicked (Mywin& w1, POINT p1, char ch1)  
   {
    if( (p1.x >= x-1 && p1.y >= y-17)
        && (p1.x < x+width*8+1 && p1.y < y+1)
      ) // Height of chars assumed to be 17 pixels 
        // and average width to be 8 pixels
      return true;
    else
      return false;
   }
   void input_value(Mywin &w1, int &value, int maxDigits)
   {
     COLORREF temp1;
     temp1 = w1.GetSetBackColor(box_color);
     value=w1.kiteGetint(x+2, y, maxDigits);
     w1.GetSetBackColor(temp1);
   }
   void input_value(Mywin &w1, float &f)
   {
     COLORREF temp1;
     temp1 = w1.GetSetBackColor(box_color);
     f=float(w1.kiteGetdouble(x+2, y));
     w1.GetSetBackColor(temp1);
   }
   void input_value(Mywin &w1, double &f)
   {
     COLORREF temp1;
     temp1 = w1.GetSetBackColor(box_color);
     f=w1.kiteGetdouble(x+2, y);
     w1.GetSetBackColor(temp1);
   }
   void input_value(Mywin &w1, char s1[], int maxChars)
   {
     COLORREF temp1;
     temp1 = w1.GetSetBackColor(box_color);
     w1.kiteGetstr(x+2, y, s1, maxChars);
     w1.GetSetBackColor(temp1);
   }
};

