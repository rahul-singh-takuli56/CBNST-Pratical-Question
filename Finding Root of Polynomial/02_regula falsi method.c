// Regula falsi method
#include<stdio.h>
#include<math.h>

#define EPSILON 0.0001 // no of decimal places 
float func(float a){
      return a*a*a-2*a-5;
}
float bisect(float x1,float x2){
     return (x1*func(x2)-x2*func(x1))/(func(x2)-func(x1));
}

int main(){
    int i=1,max_iteration;
    float x,x1,x2,x3;
    printf("Enter the value of max iteration ");;
    scanf("%f",&max_iteration);
    printf("Enter the value of x1 and x2\n");
    scanf("%f%f",&x1,&x2);
    if(func(x1)*func(x2)>0){
        printf("Invalid values \n");
        return 0;  // there will some values in iteration whose condition will not 
    }              // be satisfy so iteration may be less from what you have given
    x=bisect(x1,x2);
    do{
        if(func(x1)*func(x)<0)
            x2=x;
        else 
           x1=x; 
           printf("Iteration =%d Roots =%f\n",i,x); // it will print each iteration with roots
        x3=bisect(x1,x2);
        if(fabs(x3-x)<EPSILON){ 
            printf("Rooot is %f Total iteration =%d",x,i);
            return 0;
        }
        x=x3; //imp step
        i++;
    }while(i<=max_iteration);
    printf("Root is %f Total iteratin is %d",x,--i);
    return 0;

}
