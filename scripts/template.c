#include <stdio.h>
#include <math.h>

int p1(unsigned long int n, unsigned long int w){
    /* プレイヤー１の関数の中身 */
}

int p2(unsigned long int n, unsigned long int w){
    /* プレイヤー２の関数の中身 */
}



int main(void){
    unsigned long int n, w1 = 0, w2 = 0;
    int h1, h2;

    if (n == 0 && (p1(0, 0) != 0 && p2(0, 0) != 0)){
        printf("Saisho ha gu yade\np1=%d, p2=%d\n", p1(0, 0), p2(0, 0));
        return 1;
    }

    for(n = 1; (w1 < 10000) && (w2 < 10000); n++){
        h1 = p1(n, w1);
        h2 = p2(n, w2);

        if((h1 - h2 == -1) || (h1 == 2 && h2 == 0)){
            w1++;
        }
        else if((h2 - h1 == -1) || (h2 == 2 && h1 == 0)){
            w2++;
        }
        else if(h1 > 2 || h1 < 0 || h2 > 2 || h2 < 0){
            printf("error(n=%7lu p1=%d p2=%d w1=%5lu w2=%5lu)\n", n, h1, h2, w1, w2);
            return 1;
        }
        printf("n=%7lu p1=%d p2=%d w1=%5lu w2=%5lu\n", n, h1, h2, w1, w2);

        if(n == 1000000 && (w1 < 10000 && w2 < 10000)){
            printf("aiko bakka yanke\n");
            n++;
            break;
        }
    }

    if(w1 == 10000){
        printf("winner p1\n");
    }
    else if(w2 == 10000){
        printf("winner p2\n");
    }

    printf("w1=%lu\nw2=%lu\nn=%lu\n", w1, w2, n - 1);

    return 0;
}