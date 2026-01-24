#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>
int roundOff(float a);

int main(){
    int gd=DETECT,gm; // gd=graphics driver (detects best graphics driver and assigns it as default, gm=graphics mode. 
    int x1,y1,x2,y2,steps,k;
    char point1[20], point2[20];
    float xinc,yinc,x,y,dx,dy;
    initgraph(&gd, &gm, "");
    outtextxy(300,20,"DDA");
    outtextxy(5,5,"Set x1 to -1 to exit the program!!!");
    while(1){
        printf("Enter x1 y1: ");
        scanf("%d%d",&x1,&y1);
        if(x1==-1){
            outtextxy(50,50,"Exitting...");
            delay(1000);
            return 0;
        }
            
        printf("\nEnter x2 y2: ");
        scanf("%d%d",&x2,&y2);
        dx=x2-x1;
        dy=y2-y1;
        if(abs(dx)>abs(dy))
            steps=abs(dx);
        else   
            steps=abs(dy);
        xinc=dx/steps;
        yinc=dy/steps;
        x=x1;
        y=y1;
        for(k=0;k<=steps;k++){
            delay(10);
            putpixel(roundOff(x),roundOff(y),WHITE);
            x+=xinc;
            y+=yinc;
        }
        
        sprintf(point1, "(%d,%d)", x1, y1);
        outtextxy(x1 - 5, y1, point1);
        sprintf(point2, "(%d,%d)", x2, y2);
        outtextxy(x2 - 5, y2, point2);
    }
    getch();
    closegraph();
    return 0;
}

int roundOff(float a){
    return (int)(a+0.5);
}
