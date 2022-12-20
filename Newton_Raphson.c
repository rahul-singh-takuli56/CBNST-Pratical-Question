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
