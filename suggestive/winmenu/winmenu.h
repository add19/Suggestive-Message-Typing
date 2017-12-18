class winmenu
 { 
  private:
  char title[80];
  char name[3][50];
  int choice;
  int num;
  Button29 b[8];
  public:

  int getchoice(Mywin& w1);

  winmenu (Mywin& w1,string ttl,char n[8][50],int num);
  };
  
  winmenu::winmenu(Mywin& w1,string ttl,char n[8][50],int num)
  {
   w1.clear();
   int i;
   int L;
   char ch='a';
   strcpy(title,ttl.c_str());
   L = w1.strpixlen(title);
   w1.winPrint((600-L)/2,50,title);
   this->num=num;
   for(i=0;i<num;i++)
  {
   b[i].Setdata(w1,ch+i,n[i],(600-L)/2,120+i* 40);
  }

  }

  int winmenu::getchoice(Mywin& w1)
 {
  char ch;
  int i;
  POINT p1;
  while(true)
  {
   p1 = w1.kiteGetch(ch);
   for(i=0;i<num;i++)
 
   if(b[i].is_clicked(w1,p1,ch))
   { 
   return(i+1);
   }    
 }
}

