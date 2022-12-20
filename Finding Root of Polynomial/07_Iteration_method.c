#include<stdio.h>
#include<math.h>
#define EPLISON 0.0001
float func(float x){
    return x*x*x+x*x-1;
}
float findat(float x){
    return 1/sqrt(x+1);
}
float diff(float x){
    return 1/2.0*(pow(1,pow((1,x),3/2.0)));
}

int main(){
    int i=1,max_iteration;
    float x1,x2,x0,x;
    printf("Enter the max iteration ");
    scanf("%d",&max_iteration);
    printf("Enter the two values of x1 and x2");
    scanf("%f%f",&x1,&x2);
    if(func(x1)*func(x2)>0){
        printf("Invalid value of x1 and x2");
        return 0;
    }
    x0=(x1+x2)/2;
    while(i<=max_iteration){
        x=findat(x0);
        if(fabs(x-x0)<EPLISON){
            printf("Iteration =%d Final root =%f\n",i,x);
            return 0;
        }
        printf("Iteration =%d Roots =%f\n",i,x);
        x0=x;
        i++;
    }
    printf("Total iteration =%d Root is %f",--i,x);
    return 0;
}
