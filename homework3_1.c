#include <stdio.h>

#define COLS 6  // 定义列数
#define ROWS 5  // 定义行数

int i, j;

// 计算某行的 ASCII 值和
int sum_Asciirow(char row[], int len) {
    int sum = 0;
    for (i = 0; i < len; i++) {  // 遍历每个字符
        sum += row[i];  // 累加ASCII值
    }
    return sum;
}

// 交换二维数组的两行
void swap_row(char arr[][COLS], int row1, int row2) {
    char tmp[COLS];
    for (i = 0; i < COLS; i++) {
        tmp[i] = arr[row1][i];
        arr[row1][i] = arr[row2][i];
        arr[row2][i] = tmp[i];
    }
}

// 对某行的字符进行升序排序
void sort_row(char row[], int len) {
    for (i = 0; i < len - 1; i++) {  // 外层循环
        for (j = i + 1; j < len; j++) {  // 内层循环
            if (row[j] < row[i]) {  // 如果后面的字符小于前面的字符，交换
                char tmp = row[i];
                row[i] = row[j];
                row[j] = tmp;
            }
        }
    }
}

// 对二维数组进行排序
void sort_2Darray(char arr[][COLS], int rows) {
    // 按每行的 ASCII 码和对行进行排序
    for (i = 0; i < rows - 1; i++) {
        for (j = i + 1; j < rows; j++) {
            if (sum_Asciirow(arr[i], COLS) > sum_Asciirow(arr[j], COLS)) {
                swap_row(arr, i, j);  // 交换两行
            }
        }
    }

    // 对每行进行升序排序
    for (i = 0; i < rows; i++) {
        sort_row(arr[i], COLS);  // 对每行进行升序排序
    }
}

int main() {
    char A[ROWS][COLS] = {
        {'S', 'D', 'U', 'Y', 'E', 'S'},
        {'C', 'H', 'I', 'N', 'A', '!'},
        {'A', 'F', 'T', 'E', 'R', 'X'},
        {'h', 'e', 'r', 'o', 'a', 'b'},
        {'C', 'y', 'y', 'D', 'S', '!'}
    };

    int rows = sizeof(A) / sizeof(A[0]);  // 计算行数
    printf("Rows: %d\n", rows);

    printf("Before sorting:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c ", A[i][j]);
        }
        printf("\n");
    }
    sort_2Darray(A, rows);

    printf("\nAfter sorting:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c ", A[i][j]);
        }
        printf("\n"）;
	return 0;
    }
}
