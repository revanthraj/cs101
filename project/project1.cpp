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
            cout<<"    SUDOKU QUEST   "<<endl;
            cout<<" Enter 1 or 2 or 3: \n (1)Sudoku Autosolver \n (2)Sudoku Geneerator \n (3)Instructions"<<endl;
            cin>>num;
            if(num!=1 && num!=2 &&num!=3)
            {
                cout<<"Error"<<endl;
                cin>>num;
            }

            if(num==1)
            {

                     for(int p=0;p<9;p++)
                    {
                        for(int q=0;q<9;q++)
                        {
                            grid[p][q]=0;

                        }

                    }
                    initCanvas();
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
                    Rectangle restart(450,50,80,40); Text t11(450,50, "RESET");
                    Rectangle submit(450,380,80,40); Text t12(450,380,"SUBMIT");
                    //Rectangle solution(450,320,80,40); Text t13(450,320,"SOLUTION");
                     Text *t;
                    repeat(200)
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


                    //click within the submit box
                    if(cx<=490&&cx>=410 && cy<=400&&cy>=360)

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

            initCanvas();
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
            Rectangle submit(450,380,80,40); Text t12(450,380,"SUBMIT");
            Rectangle solution(450,320,80,40); Text t13(450,320,"SOLUTION");

            //creating a 2d array to represent which elements are originally filled and which aren't
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

            repeat(200){

                Text *t;
                int clickPos = getClick();
                int cx = clickPos/65536;
                int cy = clickPos % 65536;

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
                //making sure the square wasnt initially filled in the question

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

                        t=new Text(i-20,j-20,"1"); t->setColor(YELLOW); matrix[(i)/40-2][(j)/40-2]=1; break;

                   case 2:

                        t=new Text(i-20,j-20,"2");t->setColor(YELLOW); matrix[(i)/40-2][(j)/40-2]=2; break;

                   case 3:

                        t=new Text(i-20,j-20,"3");t->setColor(YELLOW); matrix[(i)/40-2][(j)/40-2]=3; break;

                   case 4:

                        t=new Text(i-20,j-20,"4");t->setColor(YELLOW); matrix[(i)/40-2][(j)/40-2]=4; break;

                  case 5:

                        t=new Text(i-20,j-20,"5");t->setColor(YELLOW); matrix[(i)/40-2][(j)/40-2]=5; break;

                   case 6:

                       t=new Text(i-20,j-20,"6");t->setColor(YELLOW); matrix[(i)/40-2][(j)/40-2]=6; break;

                   case 7:

                       t=new Text(i-20,j-20,"7");t->setColor(YELLOW); matrix[(i)/40-2][(j)/40-2]=7; break;

                  case 8:

                       t=new Text(i-20,j-20,"8");t->setColor(YELLOW); matrix[(i)/40-2][(j)/40-2]=8; break;

                   case 9:

                        t=new Text(i-20,j-20,"9");t->setColor(YELLOW); matrix[(i)/40-2][(j)/40-2]=9; break;}
                   }
                   }
                }
            }
            }

            }
            }

           else if(num==3){
               initCanvas();
           Text p4(250,100,"INSTRUCTIONS"); p4.setColor(RED);
           Text t(250,150,"1.A sudoku puzzle is a grid of nine by nine squares or cells,");
           Text q(250,170,"that has been subdivided into nine subgrids or 'regions'");
           Text r(250,190,"of three by three cells.");
           Text s(250,220,"2.The objective of sudoku is to enter a digit from 1 through 9");
           Text p1(250,240,"in each cell, in such a way that:");
           Text p(250,260,"i) Each horizontal row contains each digit exactly once");
           Text p2(250,280,"ii) Each vertical column contains each digit exactly once");
           Text p3(250,300,"iii) Each subgrid or region contains each digit exactly once");
           Text p5(250,330,"3.Solving a sudoku puzzle does not require knowledge");
           Text p6(250,350,"of mathematics,simple logic suffices.");
wait(200);
}}
void selectSudoku(Text *t0, int matrix[9][9], int grid[9][9] ,char str[82])

{

    char l;
    int k1;int k2;
    cout<<"Enter a level :'E' for easy and 'H' for hard : ";
    cin>>l;
    FILE *fp;


    k1=  (rand() % 7) ;
    k2=  (rand() % 7)+8 ;

        if(l!='E' && l!='H') {cout<<"Bad input!"<<endl; return ;}
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

            }

        }
        else if(l=='H')
        {
            switch(k2)
            {
                case 8: fp = fopen("8.txt" , "r"); fread(str , 1 , 81 , fp); if(fp==NULL){cout<<"Cannot open file"; return ;} break;
                case 9: fp = fopen("9.txt" , "r"); fread(str , 1 , 81 , fp); if(fp==NULL){cout<<"Cannot open file"; return ;} break;
                case 10: fp = fopen("10.txt" , "r"); fread(str , 1 , 81 , fp); if(fp==NULL){cout<<"Cannot open file"; return ;} break;
                case 11: fp = fopen("11.txt" , "r"); fread(str , 1 , 81 , fp); if(fp==NULL){cout<<"Cannot open file"; return ;} break;
                case 12: fp = fopen("12.txt" , "r"); fread(str , 1 , 81 , fp); if(fp==NULL){cout<<"Cannot open file"; return ;} break;
                case 13: fp = fopen("13.txt" , "r"); fread(str , 1 , 81 , fp); if(fp==NULL){cout<<"Cannot open file"; return ;} break;
                case 14: fp = fopen("14.txt" , "r"); fread(str , 1 , 81 , fp); if(fp==NULL){cout<<"Cannot open file"; return ;} break;


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



