#include <iostream>
#include <cstring>
struct Lower_Triangular_Matrix{
    int size;
    int *values;
};
void create(Lower_Triangular_Matrix *m, int s){
    (*m).size = s;
     (*m).values = (int *)malloc(s*(s+1)/2*sizeof(int));
     return;
}
int Get(Lower_Triangular_Matrix *m, int i, int j){
    if(j > i)return 0;
    return (*m).values[i*(i+1)/2+j];
}
void Set(Lower_Triangular_Matrix *m, int i, int j, int val){
    if(j > i)return;
    (*m).values[i*(i+1)/2+j] = val;
    return;
}
void Display(Lower_Triangular_Matrix *m){
    for(int i = 0;i < (*m).size;i++){
        for(int j = 0;j < (*m).size;j++){
            if(j > i)printf("0 ");
            else printf("%d ", (*m).values[i*(i+1)/2+j]);
        }
        printf("\n");
    }
    return;
}
int main(){
    Lower_Triangular_Matrix M;
    int siz, choice, i, j, el;
    printf("Enter matrix size:\n");
    scanf("%d", &siz);
    create(&M, siz);
    do{
        printf("Options:\n1. Get\n2. Set\n3. Display\n4. Exit\n\n");
        scanf("%d", &choice);
        switch(choice){
        case 1:
            printf("Enter indices of element:\n");
            scanf("%d %d", &i, &j);
            printf("%d\n", Get(&M, i, j));
            break;
        case 2:
            printf("Enter indices of element and the element itself:\n");
            scanf("%d %d %d", &i, &j, &el);
            Set(&M, i, j, el);
            break;
        case 3:
            Display(&M);
            break;
        case 4:
            return 0;
        }
    }
    while(1);
}
