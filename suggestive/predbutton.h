// button2014.h
const int MIN_WIDTH = 35, MIN_HEIGHT = 35;
class Button
{
 private:
   int x, y, w, h;
   char ch, title[30];
 public:
   Button()
   {
   }
   Button(Mywin& w1, char kbd_shortcut, const char *button_text, int a, int b,
              int width=MIN_WIDTH, int height=MIN_HEIGHT)
   {
   	set_Button(w1,kbd_shortcut,button_text,a,b,width,height);
   }
   void set_Button(Mywin& w1, char kbd_shortcut, const char *button_text, int a, int b,
              int width=MIN_WIDTH, int height=MIN_HEIGHT)
   {
    int L, s;
    COLORREF c_ori;
    x=a; y=b; ch = toupper(kbd_shortcut);
    strcpy(title, button_text);
    L = w1.strpixlen(title);
    if (width <= MIN_WIDTH)
       w = MIN_WIDTH;
    else
       w = width;
    if (w < L+20)
       w = L + 20;
    if (height <= MIN_HEIGHT)
       h = MIN_HEIGHT;
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

   bool is_clicked(Mywin& w1, POINT p1, char ch1)   
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

      return true;
    }
    else
      return false;
   }
};


