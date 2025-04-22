Практическое задание 7. Знакомство с POSIX потоками

Задание 1: Создать поток
Написать программу, которая создает поток с помощью pthread_create().
Использовать атрибуты по умолчанию. Родительский и дочерний потоки должны вывести 
на экран по 5 строк текста.

```
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
```

![image](https://github.com/user-attachments/assets/32274da8-4460-4282-b558-78f3d72d9389)
