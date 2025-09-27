#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义存储键值对的结构体
typedef struct {
    char key[11];   // 键，最多10个字符
    char value[11]; // 值，最多10个字符
} KeyValue;

KeyValue pairs[100]; // 假设最多100个键值对
int count = 0;       // 实际存储的键值对数量

// 从文件读取并解析键值对
void loadData() {
    FILE *file = fopen("data.txt", "r");
    if (file == NULL) {
        printf("无法打开data.txt文件\n");
        return;
    }

    char line[100];
    while (fgets(line, sizeof(line), file) != NULL && count < 100) {
        // 查找冒号位置
        char *colon = strchr(line, ':');
        if (colon == NULL) continue; // 没有冒号的行跳过

        // 计算键和值的长度
        int keyLen = colon - line;
        int valueLen = strlen(colon + 1);

        // 去除值末尾的换行符
        if (valueLen > 0 && colon[valueLen] == '\n') {
            colon[valueLen] = '\0';
            valueLen--;
        }

        // 检查长度是否符合要求
        if (keyLen <= 10 && valueLen <= 10) {
            // 复制键
            strncpy(pairs[count].key, line, keyLen);
            pairs[count].key[keyLen] = '\0';

            // 复制值
            strncpy(pairs[count].value, colon + 1, valueLen);
            pairs[count].value[valueLen] = '\0';

            count++;
        }
    }

    fclose(file);
}

// 根据键查找值
const char* findValue(const char* key) {
    for (int i = 0; i < count; i++) {
        if (strcmp(pairs[i].key, key) == 0) {
            return pairs[i].value;
        }
    }
    return "Error";
}

int main() {
    loadData();

    char input[11];
    while (1) {
        printf("请输入键（输入Quit退出）：");
        scanf("%10s", input); // 限制输入长度为10

        // 检查是否退出
        if (strcmp(input, "Quit") == 0) {
            break;
        }

        // 查找并输出结果
        printf("%s\n", findValue(input));
    }

    return 0;
}
