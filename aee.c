#include <stdio.h>

int main() {
     int a, b;
    printf("Algoritmo Extendido de Euclides\n");
    printf("Ingrese el valor de a: ");
    scanf("%d", &a);
    printf("Ingrese el valor de b: ");
    scanf("%d", &b);
    printf("\n");

    int a_original = a;
    int m_original = b;


    int x0 = 1, x1 = 0;
    int y0 = 0, y1 = 1;

    for (; b != 0; ) {
        int q = a / b;
        int r = a % b;

        int x_temp = x0 - q * x1;
        int y_temp = y0 - q * y1;

        a = b;
        b = r;

        x0 = x1;
        x1 = x_temp;

        y0 = y1;
        y1 = y_temp;
    }

    int mcd = a;

    printf("\nMCD: %d\n", mcd);
    printf("Coeficiente x: %d\n", x0);
    printf("Coeficiente y: %d\n", y0);

    ///////////////////INVERSO MODULAR///////////////////////////////////
    if (mcd == 1) {
        int inverso = x0 % m_original;

        if (inverso < 0) //DEBE SER POSITIVO
		inverso += m_original;

        printf("\nEl inverso modular de %d mod %d es: %d\n", a_original, m_original, inverso);
    } else {
        printf("\nNo existe inverso modular (MCD distinto de 1)\n");
    }

    return 0;
}
