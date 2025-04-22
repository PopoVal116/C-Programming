Практическое задание 7. Знакомство с POSIX потоками

Задание 1: Создать поток
Написать программу, которая создает поток с помощью pthread_create().
Использовать атрибуты по умолчанию. Родительский и дочерний потоки должны вывести 
на экран по 5 строк текста.


Функции, создающие поток.
```
void* children_func1(void* arg){
    for(int i = 1; i <= 5; i++){
        printf("пупс: строка %d\n", i);
    }
    return NULL;
}
```
В функции children_func1 описываются действия дочернего потока, то есть вывод строки с номер, соответсвтующим номеру дочернего потока.
```
void ex1(){
    printf("\nзадание 1\n");
    pthread_t children;
    pthread_create(&children, NULL, children_func1, NULL);

    for(int i = 1; i <= 5; i++){
        printf("main: line %d\n", i);
    }

    pthread_join(children, NULL);
}
```
Функция ex1 содержит в себе:
1. pthread_t children; - это идентификация переменной children для хранения дочернего потока
2. pthread_create(&children, NULL, children_func1, NULL); - само создание потока, для которого передается переменная children, хранящая в себе дочерний поток, и children_func1
Результат вполнения 1 задания:
![image](https://github.com/user-attachments/assets/32274da8-4460-4282-b558-78f3d72d9389)
