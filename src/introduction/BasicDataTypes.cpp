#include "BasicDataTypes.h"

    BasicDataTypes::BasicDataTypes(){}

    void print_value_by_type(){

        int d;
        long ld;
        char c;
        float f;
        double lf;

        scanf("%d %ld %c %f %lf", &d, &ld, &c, &f, &lf);

        printf("%d\n", d);
        printf("%ld\n", ld);
        printf("%c\n", c);
        printf("%.3f\n", f);
        printf("%.9lf",lf);

    }