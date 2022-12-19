 #include<stdlib.h>
 #include<stdio.h>

float func(float x){
    return x*x-4*x+1;
}

float bisect(float a,float b){
    return (a+b)/2;
}

int main(){
    int i=1, max_iteration;
    float x1,x2,x;
    printf("Enter the maximum iteration ");
    scanf("%f",&max_iteration);

    printf("Enter the two values ");
    scanf("%f%f",&x1,&x2);

    if(func(x1)*func(x2)>0){
        printf("Invalid roots\n");
        return 0;
    }
    while(i<=max_iteration){
        x=bisect(x1,x2);
        if(func(x)*func(x1)<0)
            x2=x;
        else if(func(x)*func(x2)<0)
            x1=x;
    printf("Iteration = %d Roots = %f\n",i,x);
    i++;
    }
    printf("Root =%f Total Iteration =%d",x,--i);
    return 0;
}
