#include <stdio.h>   
#include <string.h>  
#include <stdlib.h>  

//структура даты рождения
typedef struct {
    int day;    
    int month;  
    int year;   
} Birthday;

//структура для хранения данных о человеке
typedef struct {
    char surname[50];    
    char name[50];      
    char zodiac[20];    
    Birthday birthday; 
} Person;

//функция создания файла с данными
//filename - имя создаваемого файла  N - количество записей для ввода
void create_file(const char* filename, int N) {
    //открытие файла в бинарном режиме для записи ("wb")
    FILE* file = fopen(filename, "wb");
    
    //поверка открытия файла
    if (!file) {
        //если ошибка выводим сообщение об ошибке
        perror("Ошибка создания файла");
        //и завершаем программу с кодом ошибки
        exit(EXIT_FAILURE);
    }

    //временная переменная для хранения данных одного человека
    Person p;
    
    //цикл для ввода N записей
    for (int i = 0; i < N; i++) {
        //номер текущей записи
        printf("\nЗапись #%d\n", i+1);
        
        //ввод фамилии
        printf("Фамилия: ");
        scanf("%49s", p.surname);
        
        //ввод имени
        printf("Имя: ");
        scanf("%49s", p.name);
        
        //ввод знака зодиака
        printf("Знак Зодиака: ");
        scanf("%19s", p.zodiac);
        
        //ввод даты рождения
        printf("День рождения (дд мм гггг): ");
        //день, месяц, год
        scanf("%d %d %d", &p.birthday.day, &p.birthday.month, &p.birthday.year);

        //запись структуры в файл:
        //&p - адрес структуры для записи
        //sizeof(Person) - размер одной структуры
        //1 - количество элементов для записи
        //file - указатель на файл
        fwrite(&p, sizeof(Person), 1, file);
    }
    
    //закрываем файл после записи
    fclose(file);
}

//функция поиска людей по знаку зодиака filename - имя файла с данными

void search_by_zodiac(const char* filename) {
    // открытие файла в бинарном режиме для чтения ("rb")
    FILE* file = fopen(filename, "rb");
    
    //проверка успешности открытия
    if (!file) {
        perror("Ошибка открытия файла");
        exit(EXIT_FAILURE);
    }

    //массив для хранения искомого знака зодиака
    char search_zodiac[20];
    
    printf("\nВведите знак Зодиака для поиска: ");
    scanf("%19s", search_zodiac);

    //переменная для чтения данных из файла
    Person p;
    
    //флаг отслеживания совпадений
    int found = 0;
    
    printf("\nРезультаты поиска:\n");
    
    //чтение файла построчно, пока есть данные
    //fread возвращает количество успешно прочитанных элементов
    while (fread(&p, sizeof(Person), 1, file) == 1) {
        //сравнение знак зодиака из файла с искомым
        //strcmp возвращает 0, если строки идентичны
        if (strcmp(p.zodiac, search_zodiac) == 0) {
            printf(" %s  %s %s %02d.%02d.%04d    \n",
                  p.surname, p.name, p.zodiac,
                  p.birthday.day, p.birthday.month, p.birthday.year);
            //флаг, что найдено хотя бы одно совпадение
            found = 1;
        }
    }

    //если совпадений не найдено
    if (!found) {
        printf("Люди с таким знаком Зодиака не найдены\n");
    }
    
    //закрытие файла
    fclose(file);
}

int main() {
    //файл для хранения данных
    const char* filename = "Znak.dat";
    
    //количество записей
    int N;
    
    printf("Введите количество записей: ");
    scanf("%d", &N);
    
    //очистка буфера ввода после
    getchar();

    //создание файл и заполнение его данными
    create_file(filename, N);
    
    //поиск по знаку зодиака
    search_by_zodiac(filename);

    return 0;
}