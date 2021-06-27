void show(float element) { writeln element; }

void f(<float> vector, int size) {
    !! "show" aplicado a cada elemento da zona de memória
    with vector apply show in size / 3 .. size / 2;
}

int *fir() -> 0 {
    <float> p = [3];
    p[0] = 1.1;
    p[1] = 2.2;
    p[2] = 3.3;

    f(p, 5);
}
