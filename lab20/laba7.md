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

Задание 2: Последовательное выполнение потоков

В этом задании программа сначала дожидается завершения дочернего потока с помощью pthread_join, а затем продолжает выполнение в основном потоке.

```
void ex2(){
    printf("\nзадание 2\n");
    pthread_t children;
    pthread_create(&children, NULL, children_func1, NULL);

    pthread_join(children, NULL);

    for(int i = 1; i <= 5; i++){
        printf("main: line %d\n", i);
    }
}
```
Ключевое отличие от задания 1 — pthread_join вызывается до основного цикла main, что гарантирует завершение дочернего потока перед началом вывода основного.
Результат вполнения 2 задания:
![image](https://github.com/user-attachments/assets/32274da8-4460-4282-b558-78f3d72d9389)

Задание 3: Несколько потоков с разными задачами

Создание нескольких потоков, каждый из которых выполняет свою "задачу", переданную через массив строк.

```
void* children_func3(void* arg){
    char* task = (char*)arg;
    for(int i = 1; i <= 5; i++){
        printf("пупс %s: строка %d\n", task, i);
    }
    return NULL;
}
```
```
void ex3(){
    printf("\nзадание 3\n");
    pthread_t children[4];
    char* tasks[] = {
        "играет в шахматы",
        "играет с 1 пупсом в шахматы",
        "запускает воздушного змея",
        "помогает маме"
    };

    for(int i = 0; i < 4; i++){
        pthread_create(&children[i], NULL, children_func3, tasks[i]);
    }

    for(int i = 0; i < 4; i++){
        pthread_join(children[i], NULL);
    }

    for(int i = 1; i <= 5; i++){
        printf("main: line %d\n", i);
    }
}
```

Каждому потоку передается уникальное описание задачи — это демонстрирует передачу аргументов в потоки.
Результат вполнения 3 задания:
![image](https://github.com/user-attachments/assets/32274da8-4460-4282-b558-78f3d72d9389)
Задание 4: Прерывание потоков

Используется pthread_cancel для прерывания работы потоков после 2 секунд.

```
void* children_func4(void* arg){
    int id = *(int*)arg;
    for(int i = 1; i <= 10; i++){
        printf("пупс %d: что-то делает (%d сек)\n", id, i);
        sleep(1);
    }
    return NULL;
}
```
```
void ex4(){
    printf("\nзадание 4\n");
    pthread_t children[4];
    int ids[] = {1, 2, 3, 4};

    for(int i = 0; i < 4; i++){
        pthread_create(&children[i], NULL, children_func4, &ids[i]);
    }

    sleep(2);
    printf("Пупсы, обед!\n");

    for(int i = 0; i < 4; i++){
        pthread_cancel(children[i]);
    }
}
```

Здесь показано использование pthread_cancel.
Результат вполнения 4 задания:
![image](https://github.com/user-attachments/assets/32274da8-4460-4282-b558-78f3d72d9389)


Задание 5: Очистка при отмене потока

Добавлена функция-обработчик pthread_cleanup_push, вызываемая при отмене потока.

```
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
```
```
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
```

В отличие от ex4, в этом примере каждый поток завершает работу с вызовом очистки, что делает отмену "чистой".
Результат вполнения 5 задания:
![image](https://github.com/user-attachments/assets/32274da8-4460-4282-b558-78f3d72d9389)


Задание 6: Сортировка с помощью потоков (Sleep Sort)

Алгоритм Sleep Sort — каждый поток "спит" количество секунд, соответствующее значению числа, и затем выводит его.

```
void* sleepsort(void* arg){
    int time = *(int*)arg;
    sleep(time);
    printf("%d\n", time);
}
```
```
void ex6(){
    printf("\nзадание 6\n");

    int numbers[] = {1, 13, 6, 8, 5, 9, 3};
    int count = sizeof(numbers)/sizeof(numbers[0]);
    pthread_t threads[count];

    for(int i = 0; i < count; i++){
        pthread_create(&threads[i], NULL, sleepsort, &numbers[i]);
    }

    for(int i = 0; i < count; i++){
        pthread_join(threads[i], NULL);
    }
}
```

Такой подход демонстрирует оригинальный способ сортировки с использованием параллелизма. Подходит для демонстрации, но неэффективен для практического использования.

Результат вполнения 6 задания:
![image](https://github.com/user-attachments/assets/32274da8-4460-4282-b558-78f3d72d9389)
