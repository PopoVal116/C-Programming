#privet privet
#хорошего дня!!
int main() {
    int a[] = {4, 2};
    int n = sizeof(a) / sizeof(a[0]);
    printf("Массив до сортировки: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    insertionSort(a, n);  // Или shellSort(a,n);

    printf("Массив после сортировки: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    printf("hello git\n");
    return 0;
}
