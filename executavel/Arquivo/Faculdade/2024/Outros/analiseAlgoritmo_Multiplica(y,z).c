#include <stdio.h>

int main()
{
    int y=2,z=8;

	printf("%d * %d = %d",y,z,multiplica(y,z));

    return 0;
}

int multiplica(int y, int z){
    int x=0;
    int resto;
    int contador=0;

    while(z>0){
    	resto = z % 2;
    	printf("%d == 1\n",resto);
        if(z % 2 == 1){
        	x=x+y;
            printf("x+y=%d\n",x);
        }
        y=2*y;
        printf("2*y=%d\n",y);
        z=z/2;
        printf("2/z=%d\n",z);

        printf("%d° loop\n\n",contador++);
    }
    return x;
}
