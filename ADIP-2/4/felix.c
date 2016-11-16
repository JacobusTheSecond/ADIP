//schleifen start ende
#define LIMIT 10
#ifndef START
#define J4 0
#define J3 0
#define J2 0
#define J1 1
 
#define I4 0
#define I3 0
#define I2 0
#define I1 1
#endif
#define ZAHL(ID) (ID##4 *8 + ID##3 *4 + ID##2 *2 + ID##1 )
 
#ifndef START
    #define START
    #include <stdio.h>
    int main() {
    //printf("Check\n");
#endif
 
//Loop von I = 0 bis I < LIMIT
#if ZAHL(I) < LIMIT+1
    //Loop von J = 0 bis J < LIMIT
    #if ZAHL(J) < LIMIT+1
        printf("%i x %i = %i\n", ZAHL(I), ZAHL(J), ZAHL(I) * ZAHL(J));
        //Addiere 1 auf J
        //#define ID J
        //printf("Check Add J = \n");
        #if J1 == 0
            #undef J1
            #define J1 1
        #else
            #undef J1
            #define J1 0
            #if J2 == 0
                #undef J2
                #define J2 1
            #else
                #undef J2
                #define J2 0
                #if J3 == 0
                    #undef J3
                    #define J3 1
                #else
                    #undef J3
                    #define J3 0
                    #if J4 == 0
                        #undef J4
                        #define J4 1
                    #else
                        #undef J4
                        #define J4 0
                    #endif
                #endif
            #endif
        #endif
    #else
        //loop j end
        //Addiere 1 auf I
        //#define ID I
        //printf("Check Add =\n");
        #if I1 == 0
            #undef I1
            #define I1 1
        #else
            #undef I1
            #define I1 0
            #if I2 == 0
                #undef I2
                #define I2 1
            #else
                #undef I2
                #define I2 0
                #if I3 == 0
                    #undef I3
                    #define I3 1
                #else
                    #undef I3
                    #define I3 0
                    #if I4 == 0
                        #undef I4
                        #define I4 1
                    #else
                        #undef I4
                        #define I4 0
                    #endif
                #endif
            #endif
        #endif
        //setze J auf 1
        #undef J4
        #define J4 0
        #undef J3
        #define J3 0
        #undef J2
        #define J2 0
        #undef J1
        #define J1 1
 
    #endif
#else
    //loop i end
    #define ENDE
#endif
 
#ifdef ENDE
    //printf("Ende\n");
    }
#else
    #include "felix.c"
#endif
