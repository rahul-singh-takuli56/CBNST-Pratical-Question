// secant method
#include<stdio.h>
#include<math.h>
#define EPSILON 0.0001
float func(float x){
    return x*x*x-5*x+1;
}
float findat(float x1,float x2){
    return (x1*(func(x2))-x2*(func(x1))/(func(x2)-func(x1)));
}
int main(){
    int i=1,max_iteration;
    float x1,x2,x;
    printf("Enter the value max iteartion ");
    scanf("%d",&max_iteration);
    printf("Enter two values ");
    scanf("%f%f",&x1,&x2);
    x=findat(x1,x2);
    do{
        x1=x2; // only  change as cmp to regula falsi and we do
        x2=x;  // not compare funcion value >0
        printf("Iteration =%d Root =%f\n",i,x);
        x=findat(x1,x2);
        if(fabs(x-x2)<EPSILON){
            printf("Iteration =%d Roots =%f",i+1,x);
            return 0;
        }
        i++;
    }while(i<=max_iteration);
    printf("Final root =%f ",x);
    return 0;
}
