#include<stdio.h>

// 计算一行的字符ASCII码和
int sum_Asciirow(char row[], int len) {
    int sum = 0;
    for (int i = 0; i < len; i++) {
        sum += row[i];
    }
    return sum;
}

// 交换两行
void swap_row(char arr[][6], int row1, int row2) {
    char tmp[2];
    for (int i = 0; i < 6; i++) {
        tmp[i] = arr[row1][i];
        arr[row1][i] = arr[row2][i];
        arr[row2][i] = tmp[i];
    }
}

// 对一行进行排序（升序）
void sort_row(char row[], int len) {
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (row[j] < row[i]) {
                char tmp = row[i];
                row[i] = row[j];
                row[j] = tmp;
            }
        }
    }
}

// 对二维数组进行排序
void sort_2Darray(char arr[][6], int rows) {
    // 先对每一行进行升序排序
    for (int i = 0; i < rows; i++) {
        sort_row(arr[i], 6);
    }

    // 按ASCII码和的大小排序行
    for (int i = 0; i < rows - 1; i++) {
        for (int j = i + 1; j < rows; j++) {
            if (sum_Asciirow(arr[i], 6) > sum_Asciirow(arr[j], 6)) {
                swap_row(arr, i, j);
            }
        }
    }
}

int main() {
    // 示例二维数组 A
 char A[][6] = {
        {'S', 'D', 'U', 'Y', 'E', 'S'},
        {'C', 'H', 'I', 'N', 'A', '!'},
        {'A', 'F', 'T', 'E', 'R', 'X'},
        {'h', 'e', 'r', 'o', 'a', 'b'},
        {'C', 'y', 'y', 'D', 'S', '!'}
    };

    int rows = sizeof(A) / sizeof(A[0]); // 获取二维数组的行数

    printf("Before Sorting:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 6; j++) {
            printf("%c ", A[i][j]);
        }
        printf("\n");
    }

    // 排序二维数组
    sort_2Darray(A, rows);

    printf("After Sorting:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 6; j++) {
            printf("%c ", A[i][j]);
        }
        printf("\n");
    }

    return 0;
}

