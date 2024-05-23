#include <stdio.h>

struct element{
    int i, j, x;
};
struct sparse{
    int m, n, num;
    struct element *e;
};
void create(struct sparse *s){
    printf("Enter dimensions:\n");
    scanf("%d %d", &(*s).m, &(*s).n);
    printf("Enter number of elements:\n");
    scanf("%d", &(*s).num);
    printf("Enter all elements:\n");
    s->e = (struct element*)malloc(s->num*sizeof(struct element));
    for(int i = 0;i < s->num;i++){
        scanf("%d %d %d", &(*s).e[i].i, &(*s).e[i].j, &(*s).e[i].x);
    }
    return;
}
void Display(struct sparse *s){
    int k = 0;
    for(int i = 0;i < (*s).m;i++){
        for(int j = 0;j < (*s).n;j++){
            if(i==(*s).e[k].i && j==(*s).e[k].j){
                printf("%d ", (*s).e[k++].x);
            }
            else printf("0 ");
        }
        printf("\n");
    }
}
struct sparse * add(struct sparse *s1, struct sparse *s2){
    if(s1->m != s2->m || s1->n != s2->n)return NULL;
    struct sparse *sum;
    sum = (struct sparse *)malloc(sizeof(struct sparse));
    sum->m = s1->m;
    sum->n = s1->n;
    sum->num = s1->num+s2->num;
    sum->e = (struct element *)malloc(sizeof(struct element)*(sum->num));
    int i = 0,j = 0, k = 0;
    while(i < s1->num && j < s2->num){
        if(s1->e[i].i < s2->e[j].i)sum->e[k++] = s1->e[i++];
        else if(s1->e[i].i > s2->e[j].i)sum->e[k++] = s2->e[j++];
        else{
            if(s1->e[i].j < s2->e[j].j)sum->e[k++] = s1->e[i++];
            else if(s1->e[i].j > s2->e[j].j)sum->e[k++] = s2->e[j++];
            else{
                sum->e[k] = s1->e[i++];
                sum->e[k++].x += s2->e[j++].x;
            }
        }
    }
    while(i < s1->num){
        sum->e[k++] = s1->e[i++];
    }
    while(j < s2->num){
        sum->e[k++] = s2->e[j++];
    }
    return sum;
};
int main(){
    struct sparse a, b;
    struct sparse *c;
    create(&a);
    create(&b);
    Display(&a);
    printf("\n\n");
    Display(&b);
    printf("\n\n");
    c = add(&a, &b);
    Display(c);
}
