#include<iostream>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<string>
#include<cstring>
using namespace std;
#include"kiteLib.h"
#include"winmenu/Mybutton.h"
#include"winmenu/winmenu.h"
#include"predtextbox.h"
#include"predbutton.h"
#include"button_temp.h"
#include"messagebox.h"
int isprefix(char child[],char parent[]);
void search_word(vector<string>& word);
void enter_word(vector<string>& word);
void populate_found(vector <string>& found, vector<string>& word, char name_cpy[30]);

  int main()
   {
     char ch;
     int L;
   Mywin w1("Suggestive Messaging", 50 ,20 ,600,500);
   w1.GetSetForeColor(RGB(200,0,0));
   L=w1.strpixlen("Suggestive Message Typing");
   w1.winPrint((600-L)/2,50,"Suggestive Message Typing");
   w1.line(0,431,599,431,RGB(0,255,0));
   w1.line(0,432,599,432,RGB(0,255,0));
   w1.line(0,433,599,433,RGB(0,255,0));
   w1.GetSetForeColor(RGB(0,0,230));
   w1.winPrint(100,130,"Aadish Deshpande");
   w1.winPrint(350,130,"Mukund Pande");
   w1.winPrint(100,160,"WCE Sangli     " );
   w1.winPrint(350,160,"WCE Sangli     " );
   w1.winPrint(100,190,"3rd Semester     " ); 
   w1.winPrint(100,220,"Information Technology       ");
   w1.winPrint(350,190,"3rd Semester     " ); 
   w1.winPrint(350,220,"Computer Science and Engineering       ");
   w1.GetSetForeColor(RGB(0,170,0));
   L=w1.strpixlen("UNDER GUIDANCE OF");
   w1.winPrint((600-L)/2,270,"UNDER GUIDANCE OF");
   L=w1.strpixlen("Khirwadkar Sir");
   w1.winPrint(((600-L)/2)-10,300,"  Khirwadkar Sir  ");
   Label L1(w1,300,360,"KHIRWADKAR INSTITUTE for TECHNOLOGICAL EXCELLENCE",Label::CENTER,RGB(255,0,0));
   w1.GetSetForeColor(RGB(0,0,0));
                                                                                                    
   w1.winPrint(150,460,"Press any key to continue...");
   w1.kiteGetche(380,490);
   w1.close();
      
    Mywin w2("Menu",50, 20, 600, 500);
    int user_choice;
    char x[3][50]={"Enter word(s)","Type message","Quit Program"};
    char temp[100];
    vector<string>word;
   do
    {
      winmenu m1(w2,"Menu",x,3);
      user_choice=m1.getchoice(w2);
     // strcat(temp, x[user_choice-1]); 
     switch(user_choice)
     {
        case 1:enter_word(word); break;
	case 2:search_word(word); break;
      	case 3:break; 
     }
   }while(user_choice!=3);
    messagebox(170,300,"BYE","Hope you enjoyed the program!");
 }
void enter_word(vector<string>& word)
{
	string name;
	POINT p1;
	char ch;
	char iname[30];
        ifstream f1;
	string temp;
	f1.open("suggest.txt");
	if(f1)
	{
		getline(f1,name,'\n');
		while(!f1.eof())
		{
			getline(f1,name,'\n');
		}
	}
	f1.close();
	ofstream f2;
	Mywin w1("Suggestion",100,100,600,400);
	Label L1(w1,300,20,"Enter Word:",Label::CENTER,RGB(255,0,0));
	Label L2(w1,220,100,"Word: ",Label::RIGHT,RGB(0,0,255));
	//Label L3(w1,220,150,"Number: ",Label::RIGHT,RGB(0,0,255));
	Textbox t1(w1,240,100,RGB(0,255,255),29);
	//Textbox t2(w1,240,150,RGB(0,255,255),10);
	Button b1(w1,'q',"save & stop",140,240,150,35);
        Button b2(w1,'n',"add words",350,240,150,35);
        while(true)
	{
		p1=w1.kiteGetch(ch);
		if(t1.is_clicked(w1,p1,ch))
		  {   t1.input_value(w1,iname,29);
		      temp=iname;}
		else if(b1.is_clicked(w1,p1,ch))
		{       
			word.push_back(temp);
			break;
		}
		else if(b2.is_clicked(w1,p1,ch))
		{      
		        word.push_back(temp);
			t1.clear(w1);
                }
	  }
	f2.open("suggest.txt",ios::app);
	for(int i=0;i<word.size();i++)
	{
		f2<<word[i]<<endl;
	//	f2<<it->second<<endl;
	}
	f2.close();
	Label L4(w1,300,320,"Press ENTER to exit..",Label::CENTER,RGB(0,0,255));
	w1.kiteGetche(300,340);
	w1.close();
 }
 
 
void search_word(vector<string>& word)
  {
  	int k,n,j;int i=0;
	ifstream f1;
	string t_name;
        string tem;
	char narray[30];
	vector<string> found(6);
	POINT p3,p2;
	char ch2;
	f1.open("suggest.txt");
	if(!f1)
	{ 
	  messagebox(400,200,"Fatal Error!","Could not open file");
	  exit(1);
	}  
        getline(f1,t_name,'\n');
	word.push_back(t_name);
	while(!f1.eof())
	{       
		getline(f1,t_name,'\n');
		word.push_back(t_name);
	}
	f1.close();
        
  	char ch,iname[10];
	char parent_name[30];
	Mywin w1("TYPE MESSAGE",100,100,600,400);
	Label L1(w1,300,20,"TYPE",Label::CENTER,RGB(255,0,0));
	Label L2(w1,100,100,"ENTER MESSAGE:",Label::RIGHT,RGB(0,0,255));
	Button b1(w1,'q',"Stop",310,340,150,35);

	char name[30],name_cpy[30];
	POINT p1;
        i=0;k=0;
	int x=125, msg1_ptr=0;
	w1.GetSetBackColor(RGB(255,255,255));
        Button_temp a[6];
	char message1[150];
	char message2[30];
        do{
	    p1=w1.kiteGetch(ch);
            if(b1.is_clicked(w1,p1,ch))
            {
  	      break;
            }  
	    if(ch==13)
  	      break;
	    if(ch==32)
	    {
	       msg1_ptr += i;
	       i = 0;
	       message1[msg1_ptr]=ch;
	       message1[msg1_ptr+1] = '\0';
	       continue;
	    }
	    if(ch != 0)
	    {
	      name[i]=ch;
	      message1[msg1_ptr+i]=ch;
	      name_cpy[i]=name[i];
	      if(isupper(name_cpy[i]))
	          name_cpy[i]=tolower(name_cpy[i]);
	      i++;
	      name[i]='\0';
	      name_cpy[i]='\0';
	      message1[msg1_ptr+i] = '\0';
	    			
              populate_found(found, word, name_cpy);

	      for(int t=0;t<3;t++)
	      {
	        a[t].set_Button(w1,(char)(t+65),found[t].c_str(),40+(150*t),170,120,35);
              }
	    
	      for(int t=3;t<6;t++)
	      {
	         a[t].set_Button(w1,(char)(t+65),found[t].c_str(),40+(150*(t-3)),240,120,35);
	      }  
	    }
	    char ch1 = '\0';
            for(int m=0;m<6;m++)
	    { 
	      if(a[m].is_clicked(w1,p1,ch1))
	      { 
	        strcpy(message2, a[m].getdata());
                w1.clrnchars(125,100,10);
		int mln=strlen(message2);
		int g;
		for(g=0;g<mln;g++)
		{
		   message1[msg1_ptr+g]=message2[g];
		}  
		message1[msg1_ptr+g]= ' ';
		msg1_ptr += (mln+1);
	        i=0;
	      }
	      
	    }
	    w1.winPrint(125,100,message1);
	} while(ch!=13);
        w1.winPrint(10,300,"Your entered message was: ");
	int L=w1.strpixlen("Your entered message was: ");
       
        w1.winPrint(10+L,300,message1);
	w1.winPrint(40,380,"Press ENTER to continue. . .");
	int L5=w1.strpixlen("Press ENTER to continue. . . ");
        w1.kiteGetche(160+L5,380);
	    w1.close();
       
}

void populate_found(vector <string>& found, vector<string>& word, char name_cpy[30])
{
   int j, k=0;
   for(j=0; j<6; j++)
      found[j] = "";
   for(j=0;j<word.size();j++)
   {
      char temp1[30];
      strcpy(temp1,word[j].c_str());
      if(isprefix(name_cpy,temp1))
      {
         found[k]=temp1;
	 k++;
      }
      if(k==6)
	  break;
   }
}

int isprefix(char child[],char parent[])
{
	int i,n,flag,l;
	i=0;
	l=strlen(parent);
	n=strlen(child);
	flag=0;
	for(i=0;i<l;i++)
	{
		if(isupper(parent[i]))
			parent[i]=tolower(parent[i]);
	}
	for(i=0;i<n;i++)
	{
		if(isupper(child[i]))
			child[i]=tolower(child[i]);
	}
	i=0;
	while(child[i]==parent[i] && i<n)
		i++;
	if(i==n)
		flag=1;
	return flag;
}

