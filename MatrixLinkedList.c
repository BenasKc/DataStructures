#include <stdio.h>


struct Node{
    struct Node *prev, *next;
    int value, index;
};

int find(struct Node *matrix, int m, int col){
    int times = 0;
    if(!matrix)
        return -1;
    while(matrix){
        if(matrix->index >= col)
            return times;
        ++times;
        matrix = matrix->next;
    }
    return 0;
}

int find_and_change(struct Node *matrix, int m, int col, int val){
    int times = 0;
    if(!matrix)
        return -1;
    while(matrix){
        if(matrix->index == col){
            matrix->value += val;
            return times;
        }
        ++times;
        matrix = matrix->next;
    }
    return -1;
}
void modify(struct Node **matrix, int n, int m, int row, int col, int val){
    if(matrix[row] == NULL){
        matrix[row] = (struct Node *) malloc(sizeof(struct Node));
        matrix[row]->prev = NULL;
        matrix[row]->next = NULL;
        matrix[row]->value = val;
        matrix[row]->index = col;
    }
    else{
        int index = find(matrix[row], m, col);
        if(index != -1){
            struct Node *first = matrix[row];
            struct Node *temp_node  = matrix[row];
            while(index){
                temp_node = temp_node->next;
            }
            if(temp_node->index == col)
                temp_node->value = val;
            else if(col < temp_node->index){
                printf("%d\n", val);
                struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
                new_node->next = temp_node;
                if(temp_node->prev){
                    temp_node->prev->next = new_node;
                }
                new_node->prev = temp_node->prev;
                temp_node->prev = new_node;
                new_node->index = col;
                new_node->value = val;
                if(temp_node == first && temp_node->index > new_node->index)
                    matrix[row] = new_node;
            }
            else{
                struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
                new_node->next = NULL;
                temp_node->next = new_node;
                new_node->prev = temp_node;
                new_node->index = col;
                new_node->value = val;
            }
        }
        else{
            matrix[row] = (struct Node *)malloc(sizeof(struct Node));
            matrix[row]->prev = NULL;
            matrix[row]->next = NULL;
            matrix[row]->index = col;
            matrix[row]->value = val;
        }
    }
}
void print(struct Node **matrix, int n, int m){
    for(int i = 0; i < n; ++i){
        struct Node *ptr = matrix[i];
        int cur_index = -1;
        if(ptr)
            cur_index = ptr->index;
        for(int j = 0; j < m; ++j){
            if(cur_index != j){
                printf("0 ");
            }
            else{
                printf("%d ", ptr->value);
                ptr = ptr->next;
                if(ptr){
                    cur_index = ptr->index;
                }
                else
                    cur_index = -1;
            }
        }
        printf("\n");
    }
}
void add_matrices(struct Node **arr1, struct Node **arr2, int n, int m){ // sum will be in ptr two
    for(int i = 0; i < n; ++i){
        struct Node *ptr = arr1[i];
        struct node *ptr2 = arr2[i];
        while(ptr){
            int index = find_and_change(ptr2, m, ptr->index, ptr->value);
            if(index == -1)
                modify(arr2, n, m, i, ptr->index, ptr->value);
            ptr = ptr->next;
        }
    }
}
int main(){
    int n = 3;
    int m = 4;
    struct Node **s;
    s = (struct Node *) malloc(sizeof(struct Node)*n);
    modify(s, n, m, 0, 0, 1);
    modify(s, n, m, 2, 3, 2);
    modify(s, n, m, 2, 2, 1);
    struct Node **d;
    d = (struct Node *) malloc(sizeof(struct Node)*n);
    modify(d, n, m, 0, 0, 1);
    modify(d, n, m, 1, 3, 1);
    modify(d, n, m, 2, 3, 2);
    modify(d, n, m, 2, 2, 1);
    modify(d, n, m, 2, 1, 1);
    add_matrices(s, d, n, m);
    print(d, n, m);
}
