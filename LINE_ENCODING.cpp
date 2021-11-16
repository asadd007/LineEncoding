#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
int lps(char *str)
{
   int n = strlen(str);
   int i, j, cl;
   int L[n][n];

   for (i = 0; i < n; i++)
      L[i][i] = 1;

    for (cl=2; cl<=n; cl++)
    {
        for (i=0; i<n-cl+1; i++)
        {
            j = i+cl-1;
            if (str[i] == str[j] && cl == 2)
               L[i][j] = 2;
            else if (str[i] == str[j])
               L[i][j] = L[i+1][j-1] + 2;
            else
               L[i][j] = max(L[i][j-1], L[i+1][j]);
        }
    }

    return L[0][n-1];
}
void NRZL(vector<int>v)
{
    int gd = DETECT, gm;


    initwindow(1300,800);
   //initgraph(&gd, &gm, "C:\\TC\\BGI");
   int xini=0,yini=400,xfin=10,yfin=400;

   line(0,400,1300,400);
   for(int i=0;i<150;i++)
   {
       if(v[i]==1)
       {
           setcolor(2);
           line(xini,yini,xini,yfin-25);
           setcolor(14);
           line(xini,yini-25,xfin,yfin-25);

           xini+=10;
           xfin+=10;
           setcolor(2);
           line(xini,yini,xini,yfin-25);
       }
       else
       {
           setcolor(4);
           line(xini,yini,xini,yfin+25);
           setcolor(14);
           line(xini,yini+25,xfin,yfin+25);

           xini+=10;
           xfin+=10;
           setcolor(4);
           line(xini,yini,xini,yfin+25);
       }
   }

   getch();
   closegraph();
}
void NRZI(vector<int>v)
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    line(0,200,800,200);

    int xini=0,xfin=10,yini=175,yfin=175;
    line(xini,yini,xfin,yfin);
    xini+=10;
    xfin+=10;
    int up=1;
    int liner=0;
    for(int i=1;i<80;i++)
    {
        int flag=0;
        setcolor(15);
        if(v[i]==1)
        {
            up=!up;
            flag=1;
            if(up==0)
            {
               yini+=50;
               yfin+=50;
            }
            else
            {
                yini-=50;
                yfin-=50;
            }
            liner=1;

        }
        if(up==0 && flag==1)
        {

            line(xini,yini-50,xini,yini);
        }
        else if(flag==1)
        {

            line(xini,yini+50,xini,yini);
        }

         setcolor(14);
        line(xini,yini,xfin,yfin);
        xini+=10;
        xfin+=10;
    }
    getch();
    closegraph();
}
void manchester(vector<int>v)
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    line(0,200,800,200);

    int xini=0,xfin=5,yini=200,yfin=200;
    int flag;
    if(v[0]==1)
        flag=1;
    else
        flag=0;
    int counter=3;
    for(int i=0;i<100;i++)
    {

        if(v[i]==0)
        {
            if(counter==0)
            {
                line(xini,yini-25,xini,yfin+25);
            }
           counter=0;
           line(xini,yini-25,xfin,yfin-25);
           line(xfin,yfin-25,xfin,yfin+25);
           xini+=5;
           xfin+=5;

           line(xini,yini+25,xfin,yfin+25);
           xini+=5;
           xfin+=5;
        }
        else
        {
            if(counter==1)
            {
                line(xini,yini-25,xini,yfin+25);
            }
            counter=1;
           line(xini,yini+25,xfin,yfin+25);
           line(xfin,yfin+25,xfin,yfin-25);
           xini+=5;
           xfin+=5;
           line(xini,yini-25,xfin,yfin-25);
           xini+=5;
           xfin+=5;

        }
    }



    getch();
    closegraph();
}
void diffmanchester(vector<int>v)
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    line(0,200,800,200);
    int xini=0,xfin=5,yini=200,yfin=200;
    line(xini,yini-25,xfin,yfin-25);
    xini+=5;
    xfin+=5;
    line(xini,yini-25,xini,yini+25);
    line(xini,yini+25,xfin,yini+25);
    xini+=5;
    xfin+=5;
    int flag=0;
    for(int i=1;i<100;i++)
    {
        if(v[i]==0 && flag==0)
        {
            line(xini,yini+25,xini,yini-25);
            line(xini,yini-25,xfin,yini-25);
            xini+=5;
            xfin+=5;
            line(xini,yini-25,xini,yini+25);
            line(xini,yini+25,xfin,yini+25);
            xini+=5;
            xfin+=5;
        }
        else if(v[i]==1 && flag==0)
        {
            line(xini,yini+25,xfin,yini+25);
            xini+=5;
            xfin+=5;
            line(xini,yini+25,xini,yini-25);
            line(xini,yini-25,xfin,yini-25);
            xini+=5;
            xfin+=5;
            flag=1;
        }
        else if(flag==1 && v[i]==0)
        {
            line(xini,yini-25,xini,yini+25);
            line(xini,yini+25,xfin,yini+25);
            xini+=5;
            xfin+=5;
            line(xini,yini+25,xini,yini-25);
            line(xini,yini-25,xfin,yini-25);
            xini+=5;
            xfin+=5;
        }
        else
        {
            line(xini,yini-25,xfin,yini-25);
            xini+=5;
            xfin+=5;
            line(xini,yini-25,xini,yini+25);
            line(xini,yini+25,xfin,yini+25);
            xini+=5;
            xfin+=5;
            flag=0;
        }
    }


    getch();
    closegraph();
}
void AMI(vector<int>v)
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    line(0,200,800,200);
    int xini=0,xfin=10,yini=200,yfin=200;
    int flag;
    if(v[0]==0)
    {
        line(xini,yini,xfin,yini);
        xini+=10;
        xfin+=10;
        flag=0;
    }
    else
    {
        line(xini,yini-25,xfin,yini-25);
        xini+=10;
        xfin+=10;
        flag=1;
    }
    for(int i=1;i<100;i++)
    {
        if(v[i]==1 && flag==0)
        {
            line(xini,yini,xini,yini-25);
            line(xini,yini-25,xfin,yini-25);
            xini+=10;
            xfin+=10;
            flag=1;
        }
        else if(v[i]==1 && flag==1)
        {
            line(xini,yini-25,xfin,yini-25);
            xini+=10;
            xfin+=10;

        }
        else if(v[i]==0 && flag==1)
        {
            line(xini,yini-25,xini,yini);
            line(xini,yini,xfin,yini);
            xini+=10;
            xfin+=10;
            flag=0;
        }
        else
        {
            line(xini,yini,xfin,yini);
            xini+=10;
            xfin+=10;

        }
    }
    getch();
    closegraph();
}
void HDB3(vector<int>v)
{
    int gd = DETECT, gm;
    char v2[100];
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    line(0,200,800,200);
    int xini=0,xfin=10,yini=200,yfin=200;
    int nonzero=0;
    int countzero=0;
    int flag=0;
    for(int i=0;i<100;i++)
    {
        if(v[i]==0)
        {
            countzero++;
        }
        else
        {
            countzero=0;
        }
        if(v[i]==1)
        {
            nonzero++;
        }
        if(v[i]==1 && flag==0)
        {
            line(xini,yini,xini,yini-25);
            line(xini,yini-25,xfin,yini-25);
            line(xfin,yini-25,xfin,yini);
            xini+=10;
            xfin+=10;
            flag=1;
            v2[i]='1';
        }
        else if(v[i]==1 && flag==1)
        {
            line(xini,yini,xini,yini+25);
            line(xini,yini+25,xfin,yini+25);
            line(xfin,yini+25,xfin,yini);
            xini+=10;
            xfin+=10;
            flag=0;
            v2[i]='1';
        }
        else if(v[i]==0)
        {
            xini+=10;
            xfin+=10;
            v2[i]='0';
        }
        if(countzero==4)
        {
            for(int j=0;j<4;j++)
            {
                v2[i-j]='0';
            }
            if(nonzero%2==0)
            {
                v2[i-3]='1';
                v2[i-2]='0';
                v2[i-1]='0';
                v2[i]='1';
                int bxini=xini-40;
                int bxfin=bxini+10;
                int vxini=xini-10;
                int vxfin=vxini+10;
                if(flag==0)
                {
                    line(bxini,yini,bxini,yini-25);
                    line(bxini,yini-25,bxfin,yini-25);
                    line(bxfin,yini-25,bxfin,yini);
                    line(vxini,yini,vxini,yini-25);
                    line(vxini,yini-25,vxfin,yini-25);
                    line(vxfin,yini-25,vxfin,yini);
                    flag=1;
                    nonzero+=2;
                }
                else if(flag==1)
                {
                    line(bxini,yini,bxini,yini+25);
                    line(bxini,yini+25,bxfin,yini+25);
                    line(bxfin,yini+25,bxfin,yini);
                    line(vxini,yini,vxini,yini+25);
                    line(vxini,yini+25,vxfin,yini+25);
                    line(vxfin,yini+25,vxfin,yini);
                    flag=0;
                    nonzero+=2;
                }

            }
            else
            {
                v2[i-3]='0';
                v2[i-2]='0';
                v2[i-1]='0';
                v2[i]='1';
                int vxini=xini-10;
                int vxfin=vxini+10;
                if(flag==0)
                {
                    line(vxini,yini,vxini,yini-25);
                    line(vxini,yini-25,vxfin,yini-25);
                    line(vxfin,yini-25,vxfin,yini);
                    flag=1;
                    nonzero++;
                }
                else
                {
                    line(vxini,yini,vxini,yini+25);
                    line(vxini,yini+25,vxfin,yini+25);
                    line(vxfin,yini+25,vxfin,yini);
                    flag=0;
                    nonzero++;
                }

            }
            countzero=0;
        }



    }

    getch();
    closegraph();
    cout<<"Length of Longest Palindromic Subsequence is "<<lps(v2)<<endl;

}
void B8ZS(vector<int>v)
{
    int gd = DETECT, gm;
    char v2[100];
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    line(0,200,800,200);
    int xini=0,xfin=10,yini=200,yfin=200;
    int nonzero=0;
    int countzero=0;
    int flag=0;
    for(int i=0;i<100;i++)
    {
        if(v[i]==0)
        {
            countzero++;
        }
        else
        {
            countzero=0;
        }

        if(v[i]==1 && flag==0)
        {
            line(xini,yini,xini,yini-25);
            line(xini,yini-25,xfin,yini-25);
            line(xfin,yini-25,xfin,yini);
            xini+=10;
            xfin+=10;
            flag=1;
            v2[i]='1';
        }
        else if(v[i]==1 && flag==1)
        {
            line(xini,yini,xini,yini+25);
            line(xini,yini+25,xfin,yini+25);
            line(xfin,yini+25,xfin,yini);
            xini+=10;
            xfin+=10;
            flag=0;
            v2[i]='1';
        }
        else if(v[i]==0)
        {
            xini+=10;
            xfin+=10;
        }
        if(countzero==8)
        {
                for(int j=0;j<8;j++)
                {
                    v2[i-j]='0';
                }
                int v1ini=xini-50;
                int v1fin=v1ini+10;
                int b1ini=v1fin;
                int b1fin=b1ini+10;
                int v2ini=b1fin+10;
                int v2fin=v2ini+10;
                int b2ini=v2fin;
                int b2fin=b2ini+10;
                v2[i-7]='0';
                v2[i-6]='0';
                v2[i-5]='0';
                v2[i-4]='1';
                v2[i-3]='1';
                v2[i-2]='0';
                v2[i-1]='1';
                v2[i]='0';
                if(flag==0)
                {
                    line(v1ini,yini,v1ini,yini+25);
                    line(v1ini,yini+25,v1fin,yini+25);
                    line(v1fin,yini+25,v1fin,yini);
                    line(b1ini,yini,b1ini,yini-25);
                    line(b1ini,yini-25,b1fin,yini-25);
                    line(b1fin,yini-25,b1fin,yini);
                    line(v2ini,yini,v2ini,yini-25);
                    line(v2ini,yini-25,v2fin,yini-25);
                    line(v2fin,yini-25,v2fin,yini);
                    line(b2ini,yini,b2ini,yini+25);
                    line(b2ini,yini+25,b2fin,yini+25);
                    line(b2fin,yini+25,b2fin,yini);


                }
                else if(flag==1)
                {
                    line(v1ini,yini,v1ini,yini-25);
                    line(v1ini,yini-25,v1fin,yini-25);
                    line(v1fin,yini-25,v1fin,yini);
                    line(b1ini,yini,b1ini,yini+25);
                    line(b1ini,yini+25,b1fin,yini+25);
                    line(b1fin,yini+25,b1fin,yini);
                    line(v2ini,yini,v2ini,yini+25);
                    line(v2ini,yini+25,v2fin,yini+25);
                    line(v2fin,yini+25,v2fin,yini);
                    line(b2ini,yini,b2ini,yini-25);
                    line(b2ini,yini-25,b2fin,yini-25);
                    line(b2fin,yini-25,b2fin,yini);

                }



            countzero=0;
        }



    }
    getch();
    closegraph();
    cout<<"The Length of Longest Palindromic Subsequence is "<<lps(v2)<<endl;
}
int main()
{

    vector<int> v;
    cout<<"Hello there! Welcome to the signal encoder and visualizer..."<<endl;
    cout<<"Press 1 for completely random binary sequence\nPress 2 for random binary sequence with fixed subsequences..."<<endl;
    int flager;
    cin>>flager;
    if(flager==2)
    {
    	srand(time(0));
       	for (int n = 0; n<200; ++n)
	{
	    int flag=0;
	    if(((int)rand()%10)==0)
	    {
	    	for(int i=1;i<=4;i++)
	    	v.push_back(0);
		}
		else if(((int)rand()%10)==1)
		 {
	    	for(int i=1;i<=8;i++)
	    	v.push_back(0);
		}
	    else
	    {
	    	v.push_back((int)rand()%2);
		}
	}
	    }
    else
    {
        srand(time(0));
        for(int i=0;i<200;i++)
        {
            v.push_back(rand()%2);
            cout<<v[i]<<' ';
        }
    }
    cout<<endl;
    char seq[200];
    for(int i=0;i<200;i++)
    {
        if(v[i]==1)
            seq[i]='1';
        else
            seq[i]='0';
    }
    cout<<"Length of Longest palindromic subsequence="<<lps(seq)<<endl;
    cout<<"Now choose type of encoding-\nPress 1 for NRZ-L\nPress 2 for NRZ-I\nPress 3 for Manchester\nPress 4 for Differential Manchester\nPress 5 for AMI"<<endl;
    int enc;
    cin>>enc;
    if(enc==1)
    {
        NRZL(v);
    }
    else if(enc==2)
    {
        NRZI(v);
    }
    else if(enc==3)
    {
        manchester(v);
    }
    else if(enc==4)
    {
        diffmanchester(v);
    }
    else if(enc==5)
    {
        cout<<"Is Scrambling to be performed?\nPress 1 for YES\nPress 2 for NO"<<endl;
        int scr;
        cin>>scr;
        if(scr==2)
        {
            AMI(v);
        }
        else if(scr==1)
        {
            cout<<"Press 1 for B8ZS Scrambling\nPress 2 for HDB3 Scrambling"<<endl;
            cout<<"NOTE:On choosing option first window represents AMI encoding and Second Window represents scrambled signal."<<endl;
            int ty;
            cin>>ty;
            if(ty==1)
            {
                AMI(v);
                B8ZS(v);
            }
            else if(ty==2)
            {
                AMI(v);
                HDB3(v);
            }
            else
            {
                cout<<"Incorrect Option"<<endl;
            }
        }
        else
        {
            cout<<"Incorrect Option"<<endl;
        }
    }
    else
    {
        cout<<"Invalid Option"<<endl;
    }
    return 0;
}

