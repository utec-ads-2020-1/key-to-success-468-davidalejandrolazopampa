//David Lazo 201810010
//UVA 468
#include<iostream>
#define valor 10000
#define t0 10
#define t1 130
using namespace std;
int inicio;
char str[t0], first[valor], second[valor];
struct node {
    int inicio, seg;
    node() {
        inicio = 0;
        seg = 0;
    }
};
int key(const void *i, const void *j) {
    node *first, *second;
    first = (node *)i;
    second = (node *)j;
    return second->inicio - first->inicio;
}
int main(int argc, char const *argv[]) {
    cin>>inicio;
    gets(str);
    while(inicio--) {
        node primero[t1], segundo[t1];
        gets(str),gets(first),gets(second);
        for(int i = 0; i < t1; i++){primero[i].seg = segundo[i].seg = i;}
        for(int j = 0; first[j]; j++){primero[first[j]].inicio++;}
        for(int k = 0; second[k]; k++){segundo[second[k]].inicio++;}
        qsort(primero, t1, sizeof(node), key);
        qsort(segundo, t1, sizeof(node), key);
        int mapa[t1] = {};
        for(int l = 0; l < t1; l++) {mapa[segundo[l].seg] = primero[l].seg;}
        for(int m = 0; second[m]; m++){putchar(mapa[second[m]]);}
        puts("");
        if(inicio){puts("");}
    }
    return 0;
}