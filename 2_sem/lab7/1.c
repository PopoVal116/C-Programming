#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void* children_func1(void* arg){
    for(int i = 1; i <= 5; i++){
        printf("пупс: строка %d\n", i);
    }
    return NULL;
}

void ex1(){
    printf("\nзадание 1\n");
    pthread_t children;
    pthread_create(&children, NULL, children_func1, NULL);

    for(int i = 1; i <= 5; i++){
        printf("main: line %d\n", i);
    }

    pthread_join(children, NULL);
}

void ex2(){
    printf("\nзадание 2\n");
    pthread_t children;
    pthread_create(&children, NULL, children_func1, NULL);

    pthread_join(children, NULL);

    for(int i = 1; i <= 5; i++){
        printf("main: line %d\n", i);
    }
}

void* children_func3(void* arg){
    char* task = (char*)arg;
    for(int i = 1; i <= 5; i++){
        printf("пупс %s: строка %d\n", task, i);
    }
    return NULL;
}

void ex3(){
    printf("\nзадание 3\n");
    pthread_t children[4];
    char* tasks[]={
        "играет в шахматы",
        "играет с 1 пупсом в шахматы",
        "запускает воздушного змея",
        "помогает маме"
    };

    for(int i=0; i<4; i++){
        pthread_create(&children[i], NULL, children_func3, tasks[i]);
    }

    for(int i=0; i<4; i++){
        pthread_join(children[i], NULL);
    }
    
    for(int i = 1; i <= 5; i++){
        printf("main: line %d\n", i);
    }
}

void* children_func4(void* arg){
    int id = *(int*)arg;
    for(int i = 1; i <= 10; i++){
        printf("пупс %d: что-то делает (%d сек)\n", id, i);
        sleep(1);
    }
    return NULL;
}

void ex4(){
    printf("\nзадание 4\n");
    pthread_t children[4];
    int ids[]={1, 2, 3, 4};

    for(int i=0; i<4; i++){
        pthread_create(&children[i], NULL, children_func4, &ids[i]);
    }

    sleep(2);
    printf("Пупсы, обед!\n");

    for(int i=0; i<4; i++){
        pthread_cancel(children[i]);
    }
}

void cleanup_handler(void* arg) {
    int id = *(int*)arg;
    printf("пупс %d: мам, я прибрался\n", id);
}

void* children_func5(void* arg) {
    int id = *(int*)arg;
    
    pthread_cleanup_push(cleanup_handler, arg);
    
    for(int i = 1; i <= 10; i++) {
        printf("пупс %d: что-то делает (%d сек)\n", id, i);
        sleep(1);
    }
    
    pthread_cleanup_pop(1);
    return NULL;
}

void ex5() {
    printf("\nзадание 5\n");

    pthread_t children[4];
    int ids[] = {1, 2, 3, 4};

    for(int i = 0; i < 4; i++) {
        pthread_create(&children[i], NULL, children_func5, &ids[i]); 
    }

    sleep(2);
    printf("Пупсы, обед!\n");

    for(int i = 0; i < 4; i++) {
        pthread_cancel(children[i]);
    }
    
    sleep(1);
}

void* sleepsort(void* arg){
    int time = *(int*)arg;
    sleep(time);
    printf("%d\n", time);
}

void ex6(){

    printf("\nзадание 6\n");

    int numbers[]={1, 13, 6, 8, 5, 9, 3};
    int count=sizeof(numbers)/sizeof(numbers[0]);
    pthread_t threads[count];

    for(int i=0; i < count; i++){
        pthread_create(&threads[i], NULL, sleepsort, &numbers[i]);
    }

    for(int i =0; i < count; i++){
        pthread_join(threads[i], NULL);
    }
}

int main(){
    int choice;
    
    printf("Выберите вариант (1-6): ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            ex1();
            break;
        case 2:
            ex2();
            break;
        case 3:
            ex3();
            break;
        case 4:
            ex4();
            break;
        case 5:
            ex5();
            break;
        case 6:
            ex6();
            break;
        default:
            printf("Неверный выбор!\n");
    }
    
    return 0;
}