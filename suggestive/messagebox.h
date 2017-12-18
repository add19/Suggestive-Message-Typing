void messagebox(int posX,int posY,char *title, char *message)
{
 int width=10*strlen(message)+50;
 Mywin mb(title , posX, posY, width, 95);
 int pixlen=mb.strpixlen(message);
 int start= (width-pixlen)/2;
 if(start<5)
   start=5;
 mb.winPrint(start, 20, message);
 mb.filledRectang(width/2-40,50,80,40,RGB(180,180,180));
 pixlen=mb.strpixlen("OK");
 start=(width-pixlen)/2;
 mb.GetSetBackColor(RGB(180,180,180));
 mb.winPrint(start,75,"OK");
 mb.kiteFlush();
 char ch;
 mb.kiteGetch(ch);
 mb.close();
}
 
