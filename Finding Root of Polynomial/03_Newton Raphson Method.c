#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define    f(x)    3*x - cos(x) -1  // function of which root to be find

#define   g(x)   3 + sin(x)  // derivation of function

void main()
{
	 float x0, x1, f0, f1, g0, e;
	 int step = 1, N;

	 printf("\nEnter initial guess:\n");
	 scanf("%f", &x0);
	 printf("Enter tolerable error:\n");
	 scanf("%f", &e);
	 printf("Enter maximum iteration:\n");
	 scanf("%d", &N);
	 // Implementing Newton Raphson Method 
	 printf("\nStep\t\tx0\t\tf(x0)\t\tx1\t\tf(x1)\n");
	 do
	 {
		  g0 = g(x0);
		  f0 = f(x0);
		  if(g0 == 0.0)
		  {
			   printf("Mathematical Error.");
			   exit(0);
		  }
		  x1 = x0 - f0/g0;
		  printf("%d\t\t%f\t%f\t%f\t%f\n",step,x0,f0,x1,f1);
		  x0 = x1;
		  step = step+1;
		  if(step > N)
		  {
			   printf("Not Convergent.");
			   exit(0);
		  }
		  f1 = f(x1);
		  
	 }while(fabs(f1)>e);
	
	 printf("\nRoot is: %f", x1);
	 getch();
}


// 2nd method
//Newton raphson method
#include<stdio.h>
#include<math.h>
#define EPSILON 0.0001
float func(float x){
    return x*x*x-3*x-5;
}

float diff(float x){
    return 3*x*x*-3;
}

int main(){
    int i=1,max_iteration;
    float x1,x2,x0,x;
    printf("Enter the max iteration ");
    scanf("%d",&max_iteration);
    printf("Enter the value of x1 and x2 ");
    scanf("%f%f",&x1,&x2);
    if(func(x1)*func(x2)>0){
        printf("Invalid value ");
        return 0;
    }
    //find x0 you can also use x0=(x1+x2)/2
    if(fabs(x1)<fabs(x2))
        x0=x1; // take smaller value
    else 
        x1=x2;
    while(i<=max_iteration){
        x=x0-(func(x0)/diff(x0));
        if(fabs(x-x0)<EPSILON){
            printf("Iteration =%d Final Root =%f\n",i,x);
            return 0;
        }
        printf("Iteration =%d Roots =%f\n",i,x);
        x0=x; // imp step 
        i++;
    }
    printf("Roots =%f Total iteration =%d ",x,--i);
    return 0;
}
