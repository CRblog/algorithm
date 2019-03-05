#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>

int length;

struct SORT_DATA {
  char name[20];
  double time;
} data[8];

void display(char* sortname, int* show, int *reset);

void insertSort(int* array);
void bubbleSort(int* array);
void shellSort(int* array);
void selectionSort(int* array);
void mergeSort(int* array, int first, int end);
void merge(int* array, int first, int mid, int end);
void quickSort(int* array, int left, int right);
void heapSort(int* array, int length);
void heapBuild(int* array, int root, int length);
void radixSort(int* array, int length);
int maxBit(int* array, int length);

int cmp(const void* one, const void* two) {
  SORT_DATA x = *(SORT_DATA*)one;
  SORT_DATA y = *(SORT_DATA*)two;
  return x.time - y.time;
}

int main(void) {
  char select;
  clock_t start, stop;
  double ans;
  srand(time(NULL));

  printf("How many numbers : ");
  do {
    scanf("%d", &length);
  } while (length < 1);
  printf("Show ? (Y or N): ");
  do {
    scanf("%c", &select);
  } while(select != 'Y' && select != 'N');
  
  int* array = (int *)malloc(sizeof(int) * length);
  int* temp = (int *)malloc(sizeof(int) * length);

  start = clock();
  for (int i = 0; i < length; i++) {
    array[i] = rand() % length;
    temp[i] = array[i];
  } // Initialization
  stop = clock();
  ans = ((double)(stop - start)) / CLK_TCK;
  printf("Initialization Time : %lf\n", ans);

  if (select == 'Y') {
    printf("Before Sort: \n");
    for (int i = 0; i < length; i++) {
      if (i + 1 % 10 == 0) {
        putchar(10);
      }
      printf("%-6d", array[i]);
    }
    putchar(10);  
  }
  
  start = clock();
  insertSort(array);
  stop = clock();
  ans = ((double)(stop - start)) / CLK_TCK;
  if (select == 'Y') {
    display("Insert Sort", array, temp);
  } else {
    for (int i = 0; i < length; i++) {
      array[i] = temp[i];
    } // Reinitialization
  }
  printf("Insert Sort Time : %lf\n", ans);
  strcpy(data[0].name, "Insert Sort");
  data[0].time = ans;

  start = clock();
  bubbleSort(array);
  stop = clock();
  ans = ((double)(stop - start)) / CLK_TCK;
  if (select == 'Y') {
    display("Bubble Sort", array, temp);
  } else {
    for (int i = 0; i < length; i++) {
      array[i] = temp[i];
    } // Reinitialization
  }
  printf("Bubble Sort Time : %lf\n", ans);
  strcpy(data[1].name, "Bubble Sort");
  data[1].time = ans;

  start = clock();
  shellSort(array);
  stop = clock();
  ans = ((double)(stop - start)) / CLK_TCK;
  if (select == 'Y') {
    display("Shell Sort", array, temp);
  } else {
    for (int i = 0; i < length; i++) {
      array[i] = temp[i];
    } // Reinitialization
  }
  printf("Shell Sort Time : %lf\n", ans);
  strcpy(data[2].name, "Shell Sort");
  data[2].time = ans;

  start = clock();
  selectionSort(array);
  stop = clock();
  ans = ((double)(stop - start)) / CLK_TCK;
  if (select == 'Y') {
    display("Selection Sort", array, temp);
  } else {
    for (int i = 0; i < length; i++) {
      array[i] = temp[i];
    } // Reinitialization
  }
  printf("Selection Sort Time : %lf\n", ans);
  strcpy(data[3].name, "Selection Sort");
  data[3].time = ans;

  start = clock();
  mergeSort(array, 0, length - 1);
  stop = clock();
  ans = ((double)(stop - start)) / CLK_TCK;
  if (select == 'Y') {
    display("Merge Sort", array, temp);
  } else {
    for (int i = 0; i < length; i++) {
      array[i] = temp[i];
    } // Reinitialization
  }
  printf("Merge Sort Time : %lf\n", ans);
  strcpy(data[4].name, "Merge Sort");
  data[4].time = ans;

  start = clock();
  quickSort(array, 0, length - 1);
  stop = clock();
  ans = ((double)(stop - start)) / CLK_TCK;
  if (select == 'Y') {
    display("Quick Sort", array, temp);
  } else {
    for (int i = 0; i < length; i++) {
      array[i] = temp[i];
    } // Reinitialization
  }
  printf("Quick Sort Time : %lf\n", ans);
  strcpy(data[5].name, "Quick Sort");
  data[5].time = ans;

  start = clock();
  heapSort(array, length);
  stop = clock();
  ans = ((double)(stop - start)) / CLK_TCK;
  if (select == 'Y') {
    display("Heap Sort", array, temp);
  } else {
    for (int i = 0; i < length; i++) {
      array[i] = temp[i];
    } // Reinitialization
  }
  printf("Heap Sort Time : %lf\n", ans);
  strcpy(data[6].name, "Heap Sort");
  data[6].time = ans;

  start = clock();
  radixSort(array, length);
  stop = clock();
  ans = ((double)(stop - start)) / CLK_TCK;
  if (select == 'Y') {
    display("Readix Sort", array, temp);
  } else {
    for (int i = 0; i < length; i++) {
      array[i] = temp[i];
    } // Reinitialization
  }
  printf("Readix Sort Time : %lf\n", ans);
  strcpy(data[7].name, "Readix Sort");
  data[7].time = ans;
  
  qsort(data, 8, sizeof(data[0]), cmp);
  if (data[0].time == 0) {
    printf("All is ok!\n");
  } else {
    printf("Recommend : %s\n", data[0].name);
  }
  system("pause");

  return 0;
}

void display(char *sortname, int *show, int *reset) {
  printf("\n%s:\n", sortname);
  for (int i = 0; i < length; i++) {
    if (i + 1 % 10 == 0) {
      putchar(10);
    }
    printf("%-6d", show[i]);
    show[i] = reset[i];
  }
  putchar(10);
}

void insertSort(int* array) {
  int temp;
  for (int i = 1; i < length; i++) {
    for (int j = 0; j < i; j++) {
      if (array[j] > array[i]) {
        temp = array[i];
        for (int k = i - 1; k >= j; k--) {
          array[k + 1] = array[k];
        }
        array[j] = temp;
      }
    }
  }
}

void bubbleSort(int* array) {
  for (int i = 0; i < length - 1; i++) {
    for (int j = 0; j < length - i - 1; j++) {
      if (array[j] > array[j + 1]) {
        array[j] ^= array[j + 1];
        array[j + 1] ^= array[j];
        array[j] ^= array[j + 1];
      }
    }
  }
}

void shellSort(int* array) {
  int k;
  int temp;
  for (int group = length / 2; group > 0; group /= 2) {
    for (int i = 0; i < group; i++) {
      for (int j = i + group; j < length; j += group) {
        if (array[j - group] > array[j]) {
          temp = array[j];
          k = j - group;
          while (k >= 0 && array[k] > temp) {
            array[k + group] = array[k];
            k -= group;
          }
          array[k + group] = temp;
        }
      }
    }
  }
}

void selectionSort(int* array) {
  for (int i = 0; i < length; i++) {
    int j = i;
    for (int k = i + 1; k < length; k++) {
      if (array[k] < array[j]) {
        j = k;
      }
    }
    if (j != i) {
      array[j] ^= array[i];
      array[i] ^= array[j];
      array[j] ^= array[i];
    }
  }
}

void mergeSort(int* array, int first, int end) {
  if (first < end) {
    int mid = (first + end) / 2;
    mergeSort(array, first, mid);
    mergeSort(array, mid + 1, end);
    merge(array, first, mid, end);
  }
}

void merge(int* array, int first, int mid, int end) {
  int n1 = mid - first + 1;
  int n2 = end - mid;
  int* leftgroup = (int*)malloc(sizeof(int) * n1);
  int* rightgroup = (int*)malloc(sizeof(int) * n2);
  for (int i = 0; i < n1; i++) {
    leftgroup[i] = array[first + i];
  }
  for (int i = 0; i < n2; i++) {
    rightgroup[i] = array[mid + i + 1];
  }
  int i = 0, j = 0, k = first;
  while (i < n1 && j < n2) {
    if (leftgroup[i] < rightgroup[j]) {
      array[k++] = leftgroup[i++];
    } else {
      array[k++] = rightgroup[j++];
    }
  }
  while (i < n1) {
    array[k++] = leftgroup[i++];
  }
  while (j < n2) {
    array[k++] = rightgroup[j++];
  }
  free(leftgroup);
  free(rightgroup);
}

void quickSort(int* array, int left, int right) {
  if (left < right) {
    int i = left;
    int j = right;
    int key = array[i];
    while (i < j) {
      while (i < j && array[j] >= key) {
        j--;
      }
      if (i < j) {
        array[i++] = array[j];
      }
      while (i < j && array[i] < key) {
        i++;
      }
      if (i < j) {
        array[j--] = array[i];
      }
    }
    array[i] = key;
    quickSort(array, left, i - 1);
    quickSort(array, i + 1, right);
  }
}

void heapBuild(int* array, int root, int length) {
  int lchild = root * 2 + 1;
  if (lchild < length) {
    int largest = lchild;
    int rchild = lchild + 1;
    if (rchild < length) {
      if (array[rchild] > array[largest])
      {
        largest = rchild;
      }
    }
    if (array[root] < array[largest]) {
      array[root] ^= array[largest];
      array[largest] ^= array[root];
      array[root] ^= array[largest];
      heapBuild(array, largest, length);
    }
  }
}

void heapSort(int* array, int length) {
  for (int i = length / 2; i >= 0; i--) {
    heapBuild(array, i, length);
  }
  for (int j = length - 1; j >= 1; j--) {
    array[0] ^= array[j];
    array[j] ^= array[0];
    array[0] ^= array[j];
    heapBuild(array, 0, --length);
  }
}

int maxBit(int* array, int length) {
  int bit = 1;
  int radix = 10;
  for (int i = 0; i < length; i++) {
    while (array[i] >= radix) {
      radix *= 10;
      bit++;
    }
  }
  return bit;
}

void radixSort(int* array, int len) {
  int bitCount = maxBit(array, len);
  int* temp = (int*)malloc(sizeof(int) * len);
  int* count = (int*)malloc(sizeof(int) * length);
  int radix = 1;
  for (int i = 0; i < bitCount; i++) {
    for (int j = 0; j < length; j++) {
      count[j] = 0;
    }
    for (int j = 0; j < len; j++) {
      int k;
      k = (array[j] / radix) % length;
      count[k]++;
    }
    for (int j = 1; j < length; j++) {
      count[j] = count[j] + count[j - 1];
    }
    for (int j = len - 1; j >= 0; j--) {
      int k;
      k = (array[j] / radix) % length;
      temp[count[k] - 1] = array[j];
      count[k]--;
    }
    for (int j = 0; j < len; j++) {
      array[j] = temp[j];
    }
    radix *= 10;
  }

  free(temp);
  free(count);
}
