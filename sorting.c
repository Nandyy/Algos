#include <stdio.h>

char menu[][100] = {
    "1. Bubble Sort\n",
    "2. Insertion Sort\n",
    "3. Selection Sort\n",
    "4. Merge Sort\n",
    "5. Quick Sort\n",
    "6. Exit\n",
    "Enter option: "
};

typedef void (*pfn)(int *, int);

void swap(int * a, int * b)
{
    int temp = *a; *a = *b; *b = temp;
}

void bubble_sort(int *input, int size)
{
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - 1; j++){
            if(*(input + j) > *(input + j + 1))
                swap(input + j, input + j + 1);
        }
    }
}

void insertion_sort(int *input, int size)
{
    int i, j;
    for(i = 1; i < size; i++){
        int key = *(input + i);
        for(j = i - 1; (j >= 0) && (key < *(input + j)); j--){
            *(input + j + 1) = *(input + j);
        }
        *(input + j + 1) = key;
    }
}

void selection_sort(int *input, int size)
{
	int i, j;
	for(i = 0; i < size - 1; i++){
		int key = i;
		for(j = i + 1; j < size; j++){
			if(*(input + key) > *(input + j))
				key = j;
		}
        if(i != key)
            swap(input + i, input + key);
	}
}

int print_menu(void)
{
    int option;
    int size = sizeof(menu)/sizeof(menu[0]);
    for(int i = 0; i < size; i++)
        printf("%s", menu[i]);
    scanf("%d", &option);

    if(option >= 1 && option <= 6)  
        return option;
    
    return -1;
}

void print_arr(int *input, int num)
{
    for(int i = 0; i < num; i++){
        printf("%d", *(input + i));
        if(i < num - 1) printf(" ");       
    }
    printf("\n");
}

int main()
{
    int option, num;
    pfn sort_type[5];
    sort_type[0] = bubble_sort;
    sort_type[1] = insertion_sort;
    sort_type[2] = selection_sort;
    sort_type[3] = bubble_sort;
    sort_type[4] = bubble_sort;

    while(1)
    {
        option = print_menu();
        if(option < 0){
            printf("Unknown option!\n");
            continue;
        }
        if(option == 6) break;
        printf("Enter total number of inputs: ");
        scanf("%d", &num);
        int input[num];
        for(int i = 0; i < num; i++)
            scanf("%d", &input[i]);
        
        printf("%s", menu[option - 1]);
        sort_type[option - 1](input, num);

        print_arr(input, num);
    }
    
    return 0;
}
