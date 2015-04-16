#include<simplecpp>
#include<fstream>
#include<cstring>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>

using namespace std;

void selectSudoku(Text *t0, int matrix[9][9], int grid[9][9] ,char str[82]);
void generate(Text *t0, char str[], int matrix[9][9], int grid[9][9]);
//bool validateSoln(int matrix[][]);
bool FindUnassignedLocation(int grid[9][9], int &row, int &col);

// Checks whether it will be legal to assign num to the given row,col
bool isSafe(int grid[9][9], int row, int col, int num);

/* Takes a partially filled-in grid and attempts to assign values to
  all unassigned locations in such a way to meet the requirements
  for Sudoku solution (non-duplication across rows, columns, and boxes) */
bool SolveSudoku(int grid[9][9]);


int main()
{
            Text *t0;
            char str[82];
            char boolstr[9][9];
            int matrix[9][9];
            int num;

            for(int mat1=0;mat1<9;mat1++)
            {
                for(int mat2=0;mat2<9;mat2++)
                {
                    matrix[mat2][mat1]=0;
                }

            }
            //matrix is used to compare filled data with solution got from the autosolver
            int grid[9][9];

            //grid is used to store solved sudoku
            initCanvas("SUDOKU QUEST",500,500);for(int i=0;i<9999;i++){
             Rectangle r1(250,200,150,50); r1.setColor(COLOR(250,20,20));
             Rectangle r2(250,260,150,50); r2.setColor(COLOR(250,20,20));
             Rectangle r3(250,320,150,50); r3.setColor(COLOR(250,20,20));
             Rectangle r4(250,380,150,50); r4.setColor(COLOR(250,20,20));
             Rectangle R(250,250,350,350);
             Circle c1(72,72,7);c1.setColor(COLOR(250,0,0));c1.setFill();
            Circle c2(428,72,7);c2.setColor(COLOR(280,0,0));c2.setFill();
            Circle c3(428,428,7);c3.setColor(COLOR(250,0,0));c3.setFill();
            Circle c4(72,428,7);c4.setColor(COLOR(280,0,0));c4.setFill();
            Circle c5(97,428,5);c5.setColor(COLOR(250,0,0));c5.setFill();
            Circle c6(122,428,5);c6.setColor(COLOR(280,0,0));c6.setFill();
            Circle c7(147,428,5);c7.setColor(COLOR(250,0,0));c7.setFill();
            Circle c8(172,428,5);c8.setColor(COLOR(280,0,0));c8.setFill();
            Circle c9(197,428,5);c9.setColor(COLOR(250,0,0));c9.setFill();
            Circle c10(222,428,5);c10.setColor(COLOR(280,0,0));c10.setFill();
            Circle c11(247,428,5);c11.setColor(COLOR(250,0,0));c11.setFill();
            Circle c12(272,428,5);c12.setColor(COLOR(280,0,0));c12.setFill();
            Circle c13(297,428,5);c13.setColor(COLOR(250,0,0));c13.setFill();
            Circle c14(322,428,5);c14.setColor(COLOR(280,0,0));c14.setFill();
            Circle c15(347,428,5);c15.setColor(COLOR(250,0,0));c15.setFill();
            Circle c16(372,428,5);c16.setColor(COLOR(280,0,0));c16.setFill();
            Circle c17(397,428,5);c17.setColor(COLOR(250,0,0));c17.setFill();
            Circle c18(97,72,5);c18.setColor(COLOR(250,0,0));c18.setFill();
            Circle c19(122,72,5);c19.setColor(COLOR(280,0,0));c19.setFill();
            Circle c20(147,72,5);c20.setColor(COLOR(250,0,0));c20.setFill();
            Circle c21(172,72,5);c21.setColor(COLOR(280,0,0));c21.setFill();
            Circle c22(197,72,5);c22.setColor(COLOR(250,0,0));c22.setFill();
            Circle c23(222,72,5);c23.setColor(COLOR(280,0,0));c23.setFill();
            Circle c24(247,72,5);c24.setColor(COLOR(250,0,0));c24.setFill();
            Circle c25(272,72,5);c25.setColor(COLOR(280,0,0));c25.setFill();
            Circle c26(297,72,5);c26.setColor(COLOR(250,0,0));c26.setFill();
            Circle c27(322,72,5);c27.setColor(COLOR(280,0,0));c27.setFill();
            Circle c28(347,72,5);c28.setColor(COLOR(250,0,0));c28.setFill();
            Circle c29(372,72,5);c29.setColor(COLOR(280,0,0));c29.setFill();
            Circle c30(397,72,5);c30.setColor(COLOR(250,0,0));c30.setFill();
            Text s1(250,100,"SUDOKU");
             Text a1(250,200,"Sudoku Autosolver");
             Text g1(250,260,"Sudoku Generator");
             Text i1(250,320,"Instructions");
             Text e1(250,380,"Exit");
             int getpos=getClick();
             int x1,y1;
             x1=getpos/65536;
             y1=getpos%65536;
             if(x1>=175 && x1<=325 && y1>=175 && y1<=225){num=1;}
             if(x1>=175 && x1<=325 && y1>=235 && y1<=285){num=2;}
             if(x1>=175 && x1<=325 && y1>=355 && y1<=405){return 0;}
             if(x1>=175 && x1<=325 && y1>=295 && y1<=345){num=3;}
             s1.hide();a1.hide();g1.hide();i1.hide();r1.hide();r2.hide();r3.hide();R.hide();e1.hide();r4.hide();
             c1.hide();c2.hide();c3.hide();c4.hide();c5.hide();c6.hide();c7.hide();c8.hide();c9.hide();c10.hide();
             c11.hide();c12.hide();c13.hide();c14.hide();c15.hide();c16.hide();c17.hide();c18.hide();c19.hide();c20.hide();
             c21.hide();c22.hide();c23.hide();c24.hide();c25.hide();c26.hide();c27.hide();c28.hide();c29.hide();
          c30.hide();
           for(int ran=0;ran<999;ran++){
            if(num==1)
            {

                     for(int p=0;p<9;p++)
                    {
                        for(int q=0;q<9;q++)
                        {
                            grid[p][q]=0;

                        }

                    }

                    //9*9 sized rectangle
                    Rectangle r(220 , 220, 360, 360); r.setColor(YELLOW);

                    int i,j,cx,cy,cx1,cy1;

                    //creating the lines of the sudoku 9*9 box
                    //used coloured lines to define the 3*3 boxes
                    Line lv1(80,40 , 80,400);
                    Line lv2(120,40 , 120,400);
                    Line lv3(160,40 , 160,400);  lv3.setColor(YELLOW);
                    Line lv4(200,40 , 200,400);
                    Line lv5(240,40 , 240,400);
                    Line lv6(280,40 , 280,400);  lv6.setColor(YELLOW);
                    Line lv7(320,40 , 320,400);
                    Line lv8(360,40 , 360,400);

                    Line lh1(40,80 , 400,80);
                    Line lh2(40,120 , 400,120);
                    Line lh3(40,160 , 400,160);  lh3.setColor(YELLOW);
                    Line lh4(40,200 , 400,200);
                    Line lh5(40,240 , 400,240);
                    Line lh6(40,280 , 400,280);  lh6.setColor(YELLOW);
                    Line lh7(40,320 , 400,320);
                    Line lh8(40,360 , 400,360);

                    Rectangle b1(60,440,40,40);  Text t1(60,440,"1");
                    Rectangle b2(100,440,40,40); Text t2(100,440,"2");
                    Rectangle b3(140,440,40,40); Text t3(140,440,"3");
                    Rectangle b4(180,440,40,40); Text t4(180,440,"4");
                    Rectangle b5(220,440,40,40); Text t5(220,440,"5");
                    Rectangle b6(260,440,40,40); Text t6(260,440,"6");
                    Rectangle b7(300,440,40,40); Text t7(300,440,"7");
                    Rectangle b8(340,440,40,40); Text t8(340,440,"8");
                    Rectangle b9(380,440,40,40); Text t9(380,440,"9");
                    Rectangle b10(450,440,80,40); Text t10(450,440,"DELETE");
                    Rectangle restart(450,50,80,40); Text t11(450,50,"RESET");
                    Rectangle exit(450,380,80,40); Text t12(450,380,"EXIT");
                    Rectangle submit(450,320,80,40); Text t15(450,320,"SUBMIT");
                    //Rectangle solution(450,320,80,40); Text t13(450,320,"SOLUTION");
                     Text *t;
                    repeat(500)
                    {


                    int clickPos = getClick();
                    cx = clickPos/65536;
                    cy = clickPos % 65536;

                    //click lies within the reset box
                    if(cx<=490&&cx>=410&&cy<=60&&cy>=40)
                    {
                        for(i=80; i<440;i+=40)
                        {for(j=80;j<440;j+=40)
                        {

                            t=new Text(i-20,j-20,"  ");
                        }
                        }

                    }
                    //click within the exit box
                    if(cx<=490&&cx>=410&&cy<=400&&cy>=360){return 0;}
                    //click within the submit box
                    if(cx<=490&&cx>=410 && cy<=340&&cy>=300)

                    {
                        Text *t20;
                        SolveSudoku(grid);


                        for(int y=0;y<9;y++)
                        {
                            for(int z=0;z<9;z++)
                            {
                                if(matrix[y][z]!=grid[y][z])
                                {
                                    t20=new Text((y+1)*40+20 , (z+1)*40+20 , grid[y][z]);
                                    //if(boolstr[y][z] == 0)
                                    t20->setColor(GREEN);
                                    //Rectangle ra((y+1)*40+20 , (z+1)*40+20 , 30,30);ra.setColor(GREEN);

                                }
                            }
                        }
                    }

                    for(i=80; i<440;i+=40)
                        {

                            for(j=80; j<440;j+=40)
                            {

                                //finding in which square the player has clicked
                                if((i-20)-40/2<= cx && cx<= (i-20)+40/2 && (j-20)-40/2 <= cy && cy <= (j-20)+40/2)
                                {
                                    Rectangle r2(i-20,j-20 , 30,30);
                                    int clickPos2=getClick();
                                    cx1= clickPos2/65536;
                                    cy1=clickPos2 % 65536;
                                    //if click is within the delete box
                    if(cx1>=410&&cx1<=490&&cy1>=420&&cy1<=460)
                 {
                t=new Text(i-20,j-20,"     ");continue;

                 }

                  for(int k=80; k<440; k+=40)
                   {


                   if((k-20)-40/2<= cx1 && cx1<= (k-20)+40/2 && cy1>=(440)-40/2 && cy1 <= (440)+40/2)
                   {switch((k/40)-1)
                   {
                //assigning a number to the highlighted square based on where the player clicks and also storing it in matrix
                   case 1:

                        t=new Text(i-20,j-20,"1"); matrix[(i)/40-2][(j)/40-2]=1; grid[(i)/40-2][(j)/40-2]=1 ;break;

                   case 2:

                        t=new Text(i-20,j-20,"2"); matrix[(i)/40-2][(j)/40-2]=2; grid[(i)/40-2][(j)/40-2]=2 ;break;

                   case 3:

                        t=new Text(i-20,j-20,"3"); matrix[(i)/40-2][(j)/40-2]=3; grid[(i)/40-2][(j)/40-2]=3 ;break;

                   case 4:

                        t=new Text(i-20,j-20,"4"); matrix[(i)/40-2][(j)/40-2]=4;grid[(i)/40-2][(j)/40-2]=4 ; break;

                  case 5:

                        t=new Text(i-20,j-20,"5"); matrix[(i)/40-2][(j)/40-2]=5; grid[(i)/40-2][(j)/40-2]=5 ;break;

                   case 6:

                       t=new Text(i-20,j-20,"6"); matrix[(i)/40-2][(j)/40-2]=6; grid[(i)/40-2][(j)/40-2]=6 ;break;

                   case 7:

                       t=new Text(i-20,j-20,"7"); matrix[(i)/40-2][(j)/40-2]=7; grid[(i)/40-2][(j)/40-2]=7 ;break;

                  case 8:

                       t=new Text(i-20,j-20,"8"); matrix[(i)/40-2][(j)/40-2]=8; grid[(i)/40-2][(j)/40-2]=8 ;break;

                   case 9:

                        t=new Text(i-20,j-20,"9"); matrix[(i)/40-2][(j)/40-2]=9; grid[(i)/40-2][(j)/40-2]=9 ;break;}
                   }
                   }
                }
            }
            }

            }
            }
            else if(num==2)
            {

            selectSudoku(t0, matrix,grid, str);
            cout<<str;
            //generate(t0,str,matrix,grid);
            SolveSudoku(grid);



            //9*9 sized rectangle
            Rectangle r(220 , 220, 360, 360); r.setColor(YELLOW);

            int i,j;

            //creating the lines of the sudoku 9*9 box
            //used coloured lines to define the 3*3 boxes
            Line lv1(80,40 , 80,400);
            Line lv2(120,40 , 120,400);
            Line lv3(160,40 , 160,400);  lv3.setColor(YELLOW);
            Line lv4(200,40 , 200,400);
            Line lv5(240,40 , 240,400);
            Line lv6(280,40 , 280,400);  lv6.setColor(YELLOW);
            Line lv7(320,40 , 320,400);
            Line lv8(360,40 , 360,400);

            Line lh1(40,80 , 400,80);
            Line lh2(40,120 , 400,120);
            Line lh3(40,160 , 400,160);  lh3.setColor(YELLOW);
            Line lh4(40,200 , 400,200);
            Line lh5(40,240 , 400,240);
            Line lh6(40,280 , 400,280);  lh6.setColor(YELLOW);
            Line lh7(40,320 , 400,320);
            Line lh8(40,360 , 400,360);

            Rectangle b1(60,440,40,40);  Text t1(60,440,"1");
            Rectangle b2(100,440,40,40); Text t2(100,440,"2");
            Rectangle b3(140,440,40,40); Text t3(140,440,"3");
            Rectangle b4(180,440,40,40); Text t4(180,440,"4");
            Rectangle b5(220,440,40,40); Text t5(220,440,"5");
            Rectangle b6(260,440,40,40); Text t6(260,440,"6");
            Rectangle b7(300,440,40,40); Text t7(300,440,"7");
            Rectangle b8(340,440,40,40); Text t8(340,440,"8");
            Rectangle b9(380,440,40,40); Text t9(380,440,"9");
            Rectangle b10(450,440,80,40); Text t10(450,440,"DELETE");
            Rectangle restart(450,50,80,40); Text t11(450,50, "RESET");
            Rectangle exit(450,380,80,40); Text t12(450,380,"EXIT");
            Rectangle solution(450,320,80,40); Text t13(450,320,"SOLUTION");
            Rectangle submit(450,260,80,40); Text t14(450,260,"SUBMIT");

            //creating a 2d array to represent which elements are originally filled and which are not filled
            for (int num=0;num<9;num++)
            {
                if (str[num]=='0'){boolstr[num][0]=0;}
                else if (str[num]!='0') boolstr[num][0]=1;
            }
            for (int num=9;num<18;num++)
            {
                if (str[num]=='0'&&((num%9)!=0)){boolstr[num%9][1]=0;}
                else if(str[num]=='0'&&((num%9)==0)) boolstr[0][1]=0;
                else if(str[num]!='0'&&(num%9)!=0) boolstr[num%9][1]=1;
                else if(str[num]!='0'&&(num%9)==0) boolstr[0][1]=1;
            }
            for (int num=18;num<27;num++)
            {
                if (str[num]=='0'&&((num%9)!=0)){boolstr[num%9][2]=0;}
                else if(str[num]=='0'&&((num%9)==0)) boolstr[0][2]=0;
                else if(str[num]!='0'&&(num%9)!=0) boolstr[num%9][2]=1;
                else if(str[num]!='0'&&(num%9)==0) boolstr[0][2]=1;
            }
            for (int num=27;num<36;num++)
            {
                if (str[num]=='0'&&((num%9)!=0)){boolstr[num%9][3]=0;}
                else if(str[num]=='0'&&((num%9)==0)) boolstr[0][3]=0;
                else if(str[num]!='0'&&(num%9)!=0) boolstr[num%9][3]=1;
                else if(str[num]!='0'&&(num%9)==0) boolstr[0][3]=1;
            }
            for (int num=36;num<45;num++)
            {
                if (str[num]=='0'&&((num%9)!=0)){boolstr[num%9][4]=0;}
                else if(str[num]=='0'&&((num%9)==0)) boolstr[0][4]=0;
                else if(str[num]!='0'&&(num%9)!=0) boolstr[num%9][4]=1;
                else if(str[num]!='0'&&(num%9)==0) boolstr[0][4]=1;
            }
            for (int num=45;num<54;num++)
            {
                if (str[num]=='0'&&((num%9)!=0)){boolstr[num%9][5]=0;}
                else if(str[num]=='0'&&((num%9)==0)) boolstr[0][5]=0;
                else if(str[num]!='0'&&(num%9)!=0) boolstr[num%9][5]=1;
                else if(str[num]!='0'&&(num%9)==0) boolstr[0][5]=1;
            }
            for (int num=54;num<63;num++)
            {
                if (str[num]=='0'&&((num%9)!=0)){boolstr[num%9][6]=0;}
                else if(str[num]=='0'&&((num%9)==0)) boolstr[0][6]=0;
                else if(str[num]!='0'&&(num%9)!=0) boolstr[num%9][6]=1;
                else if(str[num]!='0'&&(num%9)==0) boolstr[0][6]=1;
            }
            for (int num=63;num<72;num++)
            {
                if (str[num]=='0'&&((num%9)!=0)){boolstr[num%9][7]=0;}
                else if(str[num]=='0'&&((num%9)==0)) boolstr[0][7]=0;
                else if(str[num]!='0'&&(num%9)!=0) boolstr[num%9][7]=1;
                else if(str[num]!='0'&&(num%9)==0) boolstr[0][7]=1;
            }
            for (int num=72;num<81;num++)
            {
                if (str[num]=='0'&&((num%9)!=0)){boolstr[num%9][8]=0;}
                else if(str[num]=='0'&&((num%9)==0)) boolstr[0][8]=0;
                else if(str[num]!='0'&&(num%9)!=0) boolstr[num%9][8]=1;
                else if(str[num]!='0'&&(num%9)==0) boolstr[0][8]=1;
            }

            repeat(1000){

                Text *t;
                int clickPos = getClick();
                int cx = clickPos/65536;
                int cy = clickPos % 65536;

                //click lies within the exit box
                if(cx<=490&&cx>=410&&cy<=400&&cy>=360){return 0;}
                //click lies within the reset box
                if(cx<=490&&cx>=410&&cy<=60&&cy>=40)
                {
                    for(i=80; i<440;i+=40)
                    {for(j=80;j<440;j+=40)
                    {

                        t=new Text(i-20,j-20,"  ");
                    }
                    }
                    generate(t0, str,matrix,grid);
                }

                //click within the submit box
                if(cx<=490&&cx>=410 && cy<=400&&cy>=360)

                {
                    Text *t20;
                  for(int y=0;y<9;y++)
                    {
                        for(int z=0;z<9;z++)
                        {
                            if(matrix[y][z]!=grid[y][z])
                        {
                             t20=new Text(220,480,"INCORRECT SOLUTION");wait (0.444);break;

                        }
                        }
                }t20=new Text(220,480,"                                                    ");
                }
                //click within the solution box

                if(cx<=490&&cx>=410 && cy<=340&&cy>=300)
                {
                    SolveSudoku(grid);
                    for(int y=0;y<9;y++)
                    {
                        for(int z=0;z<9;z++)
                        {
                            if(matrix[y][z]!=grid[y][z])
                            {
                                t0=new Text((y+1)*40+20 , (z+1)*40+20 , grid[y][z]);
                                if(boolstr[y][z] == 0)
                                    t0->setColor(RED);
                                Rectangle ra((y+1)*40+20 , (z+1)*40+20 , 30,30);ra.setColor(GREEN);

                            }
                        }
                    }
                }

            for(i=80; i<440;i+=40){

                for(j=80; j<440;j+=40)
            {

                //finding in which square the player has clicked
                if((i-20)-40/2<= cx && cx<= (i-20)+40/2 &&
                   (j-20)-40/2 <= cy && cy <= (j-20)+40/2)
                {
                //making sure the square wasn't initially filled in the question

                   if (boolstr[i/40-2][j/40-2]==1) {cout<<"cannot edit"<<endl;  continue;}

                 //creating a smaller square to highlight which square has been clicked

                    Rectangle r2(i-20,j-20 , 30,30);

                    int clickPos2=getClick();
                    int cx1= clickPos2/65536;
                    int cy1=clickPos2 % 65536;

                //if click is within the delete box
                    if(cx1>=410&&cx1<=490&&cy1>=420&&cy1<=460)
                 {
                t=new Text(i-20,j-20,"     ");continue;

                 }

                  for(int k=80; k<440; k+=40)
                   {

                   if((k-20)-40/2<= cx1 && cx1<= (k-20)+40/2 && cy1>=(440)-40/2 && cy1 <= (440)+40/2)
                   {switch((k/40)-1)
                   {
                //assigning a number to the highlighted square based on where the player clicks and also storing it in matrix
                   case 1:

                        t=new Text(i-20,j-20,"1"); t->setColor(GREEN); matrix[(i)/40-2][(j)/40-2]=1; break;

                   case 2:

                        t=new Text(i-20,j-20,"2");t->setColor(GREEN); matrix[(i)/40-2][(j)/40-2]=2; break;

                   case 3:

                        t=new Text(i-20,j-20,"3");t->setColor(GREEN); matrix[(i)/40-2][(j)/40-2]=3; break;

                   case 4:

                        t=new Text(i-20,j-20,"4");t->setColor(GREEN); matrix[(i)/40-2][(j)/40-2]=4; break;

                  case 5:

                        t=new Text(i-20,j-20,"5");t->setColor(GREEN); matrix[(i)/40-2][(j)/40-2]=5; break;

                   case 6:

                       t=new Text(i-20,j-20,"6");t->setColor(GREEN); matrix[(i)/40-2][(j)/40-2]=6; break;

                   case 7:

                       t=new Text(i-20,j-20,"7");t->setColor(GREEN); matrix[(i)/40-2][(j)/40-2]=7; break;

                  case 8:

                       t=new Text(i-20,j-20,"8");t->setColor(GREEN); matrix[(i)/40-2][(j)/40-2]=8; break;

                   case 9:

                        t=new Text(i-20,j-20,"9");t->setColor(GREEN); matrix[(i)/40-2][(j)/40-2]=9; break;}
                   }
                   }
                }
            }
            }

            }
            }

           else if(num==3){
           Text p4(250,100,"INSTRUCTIONS"); p4.setColor(RED);
           Text t(250,150,"1.A sudoku puzzle is a grid of nine by nine squares or cells,");
           Text q(250,170,"that has been subdivided into nine subgrids or 'regions'");
           Text r(250,190,"of three by three cells.");
           Text s(250,220,"2.The objective of sudoku is to enter a number from 1 to 9");
           Text p1(250,240,"in each cell, in such a way that:");
           Text p(250,260,"i) Every horizontal row contains every digit exactly once");
           Text p2(250,280,"ii) Every vertical column contains every digit exactly once");
           Text p3(250,300,"iii) Every subgrid or region contains every digit exactly once");
           Text p5(250,330,"3.Solving a sudoku puzzle does not require much knowledge");
           Text p6(250,350,"of mathematics,simple logic suffices.");
           Rectangle back(250,400,100,50);Text b1(250,400,"BACK");
           int getpo=getClick();
           int x3,y3;
           x3=getpo/65536;y3=getpo%65536;
           if(x3<=300&&x3>=200&&y3>=375&&y3<=425){break;}
wait(200);
}}}}
void selectSudoku(Text *t0, int matrix[9][9], int grid[9][9] ,char str[82])

{

    char l;
    int k1,k2,k3;
    cout<<"Enter a level :'E' for easy"<<endl;
    cout<<"              :'M' for medium"<<endl;
    cout<<"              :'H' for hard"<<endl;
    cin>>l;
    FILE *fp;


    k1=  (rand()%10)+1;
    k2=  (rand()%10)+11 ;
    k3=  (rand()%10)+21;
        if(l!='E' && l!='M'&& l!='H') {cout<<"Bad input!"<<endl; return ;}
        else if(l=='E')
        {
            switch(k1){
                //opening the preloaded sudoku on the canvas
                case 1: fp = fopen("1.txt" ,"r"); fread(str , 1 , 81 , fp); if(fp==NULL){cout<<"Cannot open file"; return ;} break;
                case 2: fp = fopen("2.txt" ,"r"); fread(str , 1 , 81 , fp); if(fp==NULL){cout<<"Cannot open file"; return ;}break;
                case 3: fp = fopen("3.txt" ,"r"); fread(str , 1 , 81 , fp); if(fp==NULL){cout<<"Cannot open file"; return ;}break;
                case 4: fp = fopen("4.txt" ,"r"); fread(str , 1 , 81 , fp); if(fp==NULL){cout<<"Cannot open file"; return ;}break;
                case 5: fp = fopen("5.txt" ,"r"); fread(str , 1 , 81 , fp); if(fp==NULL){cout<<"Cannot open file"; return ;}break;
                case 6: fp = fopen("6.txt" ,"r"); fread(str , 1 , 81 , fp); if(fp==NULL){cout<<"Cannot open file"; return ;}break;
                case 7: fp = fopen("7.txt" ,"r"); fread(str , 1 , 81 , fp); if(fp==NULL){cout<<"Cannot open file"; return ;}break;
                case 8: fp = fopen("8.txt" ,"r"); fread(str , 1 , 81 , fp); if(fp==NULL){cout<<"Cannot open file"; return ;}break;
                case 9: fp = fopen("9.txt" ,"r"); fread(str , 1 , 81 , fp); if(fp==NULL){cout<<"Cannot open file"; return ;}break;
                case 10: fp = fopen("10.txt" ,"r"); fread(str , 1 , 81 , fp); if(fp==NULL){cout<<"Cannot open file"; return ;}break;
            }

        }
        else if(l=='M')
        {
            switch(k2)
            {
                case 11: fp = fopen("11.txt" , "r"); fread(str , 1 , 81 , fp); if(fp==NULL){cout<<"Cannot open file"; return ;} break;
                case 12: fp = fopen("12.txt" , "r"); fread(str , 1 , 81 , fp); if(fp==NULL){cout<<"Cannot open file"; return ;} break;
                case 13: fp = fopen("13.txt" , "r"); fread(str , 1 , 81 , fp); if(fp==NULL){cout<<"Cannot open file"; return ;} break;
                case 14: fp = fopen("14.txt" , "r"); fread(str , 1 , 81 , fp); if(fp==NULL){cout<<"Cannot open file"; return ;} break;
                case 15: fp = fopen("15.txt" , "r"); fread(str , 1 , 81 , fp); if(fp==NULL){cout<<"Cannot open file"; return ;} break;
                case 16: fp = fopen("16.txt" , "r"); fread(str , 1 , 81 , fp); if(fp==NULL){cout<<"Cannot open file"; return ;} break;
                case 17: fp = fopen("17.txt" , "r"); fread(str , 1 , 81 , fp); if(fp==NULL){cout<<"Cannot open file"; return ;} break;
                case 18: fp = fopen("18.txt" ,"r"); fread(str , 1 , 81 , fp); if(fp==NULL){cout<<"Cannot open file"; return ;}break;
                case 19: fp = fopen("19.txt" ,"r"); fread(str , 1 , 81 , fp); if(fp==NULL){cout<<"Cannot open file"; return ;}break;
                case 20: fp = fopen("20.txt" ,"r"); fread(str , 1 , 81 , fp); if(fp==NULL){cout<<"Cannot open file"; return ;}break;

            }
        }
        else if(l=='H')
        {

            switch(k3)
            {
                case 21: fp = fopen("21.txt" ,"r"); fread(str , 1 , 81 , fp); if(fp==NULL){cout<<"Cannot open file"; return ;}break;
                case 22: fp = fopen("22.txt" ,"r"); fread(str , 1 , 81 , fp); if(fp==NULL){cout<<"Cannot open file"; return ;}break;
                case 23: fp = fopen("23.txt" ,"r"); fread(str , 1 , 81 , fp); if(fp==NULL){cout<<"Cannot open file"; return ;}break;
                case 24: fp = fopen("24.txt" ,"r"); fread(str , 1 , 81 , fp); if(fp==NULL){cout<<"Cannot open file"; return ;}break;
                case 25: fp = fopen("25.txt" ,"r"); fread(str , 1 , 81 , fp); if(fp==NULL){cout<<"Cannot open file"; return ;}break;
                case 26: fp = fopen("26.txt" ,"r"); fread(str , 1 , 81 , fp); if(fp==NULL){cout<<"Cannot open file"; return ;}break;
                case 27: fp = fopen("27.txt" ,"r"); fread(str , 1 , 81 , fp); if(fp==NULL){cout<<"Cannot open file"; return ;}break;
                case 28: fp = fopen("28.txt" ,"r"); fread(str , 1 , 81 , fp); if(fp==NULL){cout<<"Cannot open file"; return ;}break;
                case 29: fp = fopen("29.txt" ,"r"); fread(str , 1 , 81 , fp); if(fp==NULL){cout<<"Cannot open file"; return ;}break;
                case 30: fp = fopen("30.txt" ,"r"); fread(str , 1 , 81 , fp); if(fp==NULL){cout<<"Cannot open file"; return ;}break;

        }
        }

         generate(t0 , str , matrix , grid);


return ;
}
void generate(Text *t0,char str[], int matrix[9][9], int grid[9][9])
{
        int x = 0;
        int a;
        for(int m=60; m<=380; m=m+40)
        {
            for(int n=60;n<=380;n=n+40)
                {
                       a=str[x];
                       //cout << a << " ";
                       if(str[x]=='0'){t0=new Text(n,m," ");}
                       else {
                        t0=new Text(n , m , a-48);} matrix[(n-20)/40-1][(m-20)/40-1]=(a-48);
                        grid[(n-20)/40-1][(m-20)/40-1]=matrix[(n-20)/40-1][(m-20)/40-1];
                        x++;//cout<<matrix[(n-20)/40-1][(m-20)/40-1]<< "\n";
                }
        }
return ;
}


bool SolveSudoku(int grid[9][9])
{
    int row, col;

    // If there is no unassigned location, we are done
    if (!FindUnassignedLocation(grid, row, col))
       {/*cout<<grid;*/ return true; }// success!

    // consider digits 1 to 9
    for (int num = 1; num <= 9; num++)
    {
        // if looks promising
        if (isSafe(grid, row, col, num))
        {
            // make tentative assignment
            grid[row][col] = num;

            // return, if success, yay!
            if (SolveSudoku(grid))
                return true;

            // failure, unmake & try again
            grid[row][col] = 0;
        }
    }


    return false; // this triggers backtracking
}

/* Searches the grid to find an entry that is still unassigned. If
   found, the reference parameters row, col will be set the location
   that is unassigned, and true is returned. If no unassigned entries
   remain, false is returned. */
bool FindUnassignedLocation(int grid[9][9], int &row, int &col)
{
    for (row = 0; row < 9; row++)
        for (col = 0; col < 9; col++)
            if (grid[row][col] == 0)
                return true;
    return false;
}

/* Returns a boolean which indicates whether any assigned entry
   in the specified row matches the given number. */
bool UsedInRow(int grid[9][9], int row, int num)
{
    for (int col = 0; col < 9; col++)
        if (grid[row][col] == num)
            return true;
    return false;
}

/* Returns a boolean which indicates whether any assigned entry
   in the specified column matches the given number. */
bool UsedInCol(int grid[9][9], int col, int num)
{
    for (int row = 0; row < 9; row++)
        if (grid[row][col] == num)
            return true;
    return false;
}

/* Returns a boolean which indicates whether any assigned entry
   within the specified 3x3 box matches the given number. */
bool UsedInBox(int grid[9][9], int boxStartRow, int boxStartCol, int num)
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (grid[row+boxStartRow][col+boxStartCol] == num)
                return true;
    return false;
}

/* Returns a boolean which indicates whether it will be legal to assign
   num to the given row,col location. */
bool isSafe(int grid[9][9], int row, int col, int num)
{
    /* Check if 'num' is not already placed in current row,
       current column and current 3x3 box */
    return !UsedInRow(grid, row, num) &&
           !UsedInCol(grid, col, num) &&
           !UsedInBox(grid, row - row%3 , col - col%3, num);

}



