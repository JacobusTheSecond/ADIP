#include <stdio.h>

int main(){
        char x1,x2,result;
        x1 = 35;
        x2 = 85;
        result = x1+ x2;
        printf("Beispiel 1: %hi + %hi = %hi\n",x1,x2,result);
        //(char) 35 = # = 0x23
        //(char) 85 = U = 0x55
        //(char)120 = X = 0x78

        x1 = 85;
        x2 = 85;
        result = x1+ x2;
        printf("Beispiel 1: %hi + %hi = %hi\n",x1,x2,result);
        //(char) 85 = U = 0x55
        //(char) 85 = U = 0x55
        //(char) 0xaa = 170 > 0x7f (chars sign byte +3 byte) -> 0xaa= -86  
}
