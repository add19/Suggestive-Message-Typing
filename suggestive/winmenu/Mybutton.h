// buttonTbox.h
#define TRUE 1
#include "math.h"
#include "string.h"

class Button29
{
 private:
   int x, y, w, h;
   char ch, title[30];
 public:
   Button29(Mywin& w1,char key, char str[], int a, int b,
              int width=60,int height=35)
   {
    int L, s;
    COLORREF c_ori;
    x=a; y=b; ch = toupper(key);
    strcpy(title, str);
    L = w1.strpixlen(title);
    if (width <= 60)
       w = 60;
    else
       w = width;
    if (w < L+20)
       w = L + 20;
    if (height <= 35)
       h = 35;
    else
       h = height;
    s = (w - L)/2;
    w1.filledRectang(x, y, w, h, RGB(170,170,170));
    c_ori = w1.GetSetBackColor(RGB(170,170,170));
    w1.winPrint(x+s, y + h/2 + 8, title);
    w1.GetSetBackColor(c_ori);
    //bright shade lines
    w1.line(x-1, y-1, x-1, y+h+1, RGB(200,200,200));
    w1.line(x-2, y-2, x-2, y+h+2, RGB(220,220,220));
    w1.line(x-3, y-3, x-3, y+h+3, RGB(240,240,240));
    w1.line(x-1, y-1, x+w+1, y-1, RGB(200,200,200));
    w1.line(x-2, y-2, x+w+2, y-2, RGB(220,220,220));
    w1.line(x-3, y-3, x+w+3, y-3, RGB(240,240,240));
    //dark shade lines
    w1.line(x, y+h-1, x+w, y+h-1, RGB(125,125,125));
    w1.line(x-1, y+h, x+w+1, y+h, RGB(100,100,100));
    w1.line(x-2, y+h+1, x+w+2, y+h+1, RGB(75,75,75));
    w1.line(x+w-1, y, x+w-1, y+h-1, RGB(125,125,125));
    w1.line(x+w, y-1, x+w, y+h, RGB(100,100,100));
    w1.line(x+w+1, y-2, x+w+1, y+h+1, RGB(75,75,75));
   }
   
   Button29()
   {
 
   }
   
 void Setdata(Mywin& w1,char key, char str[], int a, int b,int width=150,int height=30)

   {
   int L,s;
    COLORREF c_ori;
    x=a; y=b; ch = toupper(key);
    strcpy(title, str);
    L = w1.strpixlen(title);
    if (width <= L)
       w = L;
    else
       w = width;
    if (w < L+10)
       w = L +10;
    if (height <= 30)
       h = 30;
    else
       h = height;
    s = (w - L)/2;
    w1.filledRectang(x, y, w, h, RGB(170,170,170));
    c_ori = w1.GetSetBackColor(RGB(170,170,170));
    w1.winPrint(x+s, y + h/2 + 8, title);
    w1.GetSetBackColor(c_ori);
    
    w1.line(x-1, y-1, x-1, y+h+1, RGB(200,200,200));
    w1.line(x-2, y-2, x-2, y+h+2, RGB(220,220,220));
    w1.line(x-3, y-3, x-3, y+h+3, RGB(240,240,240));
    w1.line(x-1, y-1, x+w+1, y-1, RGB(200,200,200));
    w1.line(x-2, y-2, x+w+2, y-2, RGB(220,220,220));
    w1.line(x-3, y-3, x+w+3, y-3, RGB(240,240,240));
                                                                               
    w1.line(x, y+h-1, x+w, y+h-1, RGB(125,125,125));
    w1.line(x-1, y+h, x+w+1, y+h, RGB(100,100,100));
    w1.line(x-2, y+h+1, x+w+2, y+h+1, RGB(75,75,75));
    w1.line(x+w-1, y, x+w-1, y+h-1, RGB(125,125,125));
    w1.line(x+w, y-1, x+w, y+h, RGB(100,100,100));
    w1.line(x+w+1, y-2, x+w+1, y+h+1, RGB(75,75,75));

   }
   
    int is_clicked (Mywin& w1, POINT p1, char ch1)    // for mouse click
   {
    if(    (p1.x >= x-1 && p1.y >= y-1)
        && (p1.x < x+w+1 && p1.y < y+h+1)
        || (toupper(ch1) == ch)
      )
     {
      //dark shade lines
      w1.line(x-1, y-1, x-1, y+h+1, RGB(125,125,125));
      w1.line(x-2, y-2, x-2, y+h+2, RGB(100,100,100));
      w1.line(x-3, y-3, x-3, y+h+3, RGB(75,75,75));
      w1.line(x-1, y-1, x+w+1, y-1, RGB(125,125,125));
      w1.line(x-2, y-2, x+w+2, y-2, RGB(100,100,100));
      w1.line(x-3, y-3, x+w+3, y-3, RGB(75,75,75));
      //bright shade lines
      w1.line(x, y+h-1, x+w, y+h-1, RGB(200,200,200));
      w1.line(x-1, y+h, x+w+1, y+h, RGB(220,220,220));
      w1.line(x-2, y+h+1, x+w+2, y+h+1, RGB(240,240,240));
      w1.line(x+w-1, y, x+w-1, y+h-1, RGB(200,200,200));
      w1.line(x+w, y-1, x+w, y+h, RGB(220,220,220));
      w1.line(x+w+1, y-2, x+w+1, y+h+1, RGB(240,240,240));

      usleep ((unsigned int)250000);

      //bright shade lines
      w1.line(x-1, y-1, x-1, y+h+1, RGB(200,200,200));
      w1.line(x-2, y-2, x-2, y+h+2, RGB(220,220,220));
      w1.line(x-3, y-3, x-3, y+h+3, RGB(240,240,240));
      w1.line(x-1, y-1, x+w+1, y-1, RGB(200,200,200));
      w1.line(x-2, y-2, x+w+2, y-2, RGB(220,220,220));
      w1.line(x-3, y-3, x+w+3, y-3, RGB(240,240,240));
      //dark shade lines
      w1.line(x, y+h-1, x+w, y+h-1, RGB(125,125,125));
      w1.line(x-1, y+h, x+w+1, y+h, RGB(100,100,100));
      w1.line(x-2, y+h+1, x+w+2, y+h+1, RGB(75,75,75));
      w1.line(x+w-1, y, x+w-1, y+h-1, RGB(125,125,125));
      w1.line(x+w, y-1, x+w, y+h, RGB(100,100,100));
      w1.line(x+w+1, y-2, x+w+1, y+h+1, RGB(75,75,75));

      return 1;
     }
    else
      return 0;
   }
};
//----------------------------------------------------

void MessageBox(char *parent, char *message, char *title, int nb)
{
  int width = 10 * strlen(message) + 50;
  Mywin mb(title, (800-width)/2, 250, width, 95);
  int pixlen = mb.strpixlen(message);
  int start = (width - pixlen)/2;
  if(start < 5) 
    start = 5;
  mb.winPrint(start, 20, message);
  mb.filledRectang(width/2 -40, 50, 80, 40, RGB(180, 180, 180));
  pixlen = mb.strpixlen("OK");
  start = (width - pixlen)/2;
  mb.GetSetBackColor(RGB(180, 180, 180));
  mb.winPrint(start, 75, "OK");
  char ch;
  mb.kiteGetch(ch);
  mb.close();
}


// My Text Box Class
class Textbox1
{
 private:
   int L, x, y, sz;
   char label[100];
   COLORREF label_color;
   COLORREF box_color;
 public:
   Textbox1(Mywin& w1, int x1, int y1, char title[],
           COLORREF label_color, COLORREF box_color, int size)
   {
    x = x1;
    y = y1;
    strcpy(label, title);
    L=w1.strpixlen(label);
    // x1=x+L+7; y1=y;
    this->label_color = label_color;
    this->box_color = box_color;
    sz=size;
   }

   void draw(Mywin& w1)
   {
    COLORREF temp1, temp2;
    int x1=x+L+7; 
    temp1 = w1.GetSetForeColor(label_color);
    w1.winPrint(x, y, label);
    temp2 = w1.GetSetBackColor(box_color);
    w1.clrnchars(x+L+5, y, sz);
    w1.GetSetBackColor(temp2);
    w1.GetSetForeColor(temp1);
   }
   
   
   void getvalue(Mywin &w1, int min, int max, int &value)
   {
    COLORREF temp1;
    char msg_str[100];
    sprintf(msg_str, "Valid range is %d to %d!", min, max);
    int x1=x+L+7; 
    temp1 = w1.GetSetBackColor(box_color);
    do
     {
      value=w1.kiteGetint(x1, y, sz);
      if((value < min)||(value > max))
        {
           MessageBox(NULL, msg_str, "Out-of-range Error",0);
           w1.clrnchars(x1-2, y, sz);
        }
     }while((value < min)||(value > max));
    w1.GetSetBackColor(temp1);
   }


   void getvalue(Mywin &w1, char s1[])
   {
    COLORREF temp1;
    temp1 = w1.GetSetBackColor(box_color);
    w1.kiteGetstr(x+L+7, y, s1, sz);
    w1.GetSetBackColor(temp1);
   }

   void erase(Mywin& w1)
   {
     int temp = strlen(label) + sz;
     w1.clrnchars(x, y, temp);
   }
};
/*
class Clickable_textbox
{
 private:
   int x1,y1,n;
   COLORREF box_color;
 public:
   Clickable_textbox()
   {}
   Clickable_textbox(Mywin& w1, int x, int y, COLORREF box_color,
                             int size = 6)
   {
    COLORREF temp1;
    x1=x+2; y1=y;
    this->box_color = box_color;
    temp1 = w1.GetSetBackColor(box_color);
    w1.clrnchars(x, y, size);
    n=size;
    w1.GetSetBackColor(temp1);
   }

   void set(Mywin& w1, int x, int y, COLORREF box_color,
                             int size = 6)
   {
    COLORREF temp1;
    x1=x+2; y1=y;
    this->box_color = box_color;
    temp1 = w1.GetSetBackColor(box_color);
    w1.clrnchars(x, y, size);
    n=size;
    w1.GetSetBackColor(temp1);
   }

   int is_clicked (Mywin& w1, POINT p1, char ch1)    // for mouse click
   {
    if( (p1.x >= x1-1 && p1.y >= y1-17)
        && (p1.x < x1+n*8+1 && p1.y < y1+1)
      ) // Height of chars assumed to be 17 pixels and average width
                              // to be 8 pixels
      return 1;
    else
      return 0;
   }

   void readvalue(Mywin &w1, double &f)
   {
    COLORREF temp1;
    temp1 = w1.GetSetBackColor(box_color);
    f=w1.kiteGetdouble(x1,y1);
    w1.GetSetBackColor(temp1);
   }
};
*/


