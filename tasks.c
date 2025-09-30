#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // 用于strcmp函数
#define MAX_LEN 11

int main(){
    char order[MAX_LEN];  // 修复：指定数组大小
    char user_name;       // 用户名是单个字符
    
    while (1) {
        printf("请输入：");
        // 读取输入并处理换行符
        if (fgets(order, MAX_LEN, stdin) != NULL) {
            // 去除fgets读取的换行符
            order[strcspn(order, "\n")] = '\0';
        }
        
        // 用strcmp比较字符串（修复：替换==）
        if (strcmp(order, "Login") == 0) {
            printf("请输入用户名：");
            // 修复：格式字符串加引号，%c前加空格跳过空白字符
            scanf(" %c", &user_name);
            
            // 打开文件保存用户名
            FILE *fp = fopen("data.txt", "w");
            if (fp != NULL) {
                fputc(user_name, fp);
                fclose(fp);
                printf("用户名已保存\n");
            } else {
                printf("文件打开失败\n");
            }
            
            // 清除scanf后的缓冲区残留（避免影响下一次输入）
            while (getchar() != '\n');
        } else if (strcmp(order, "Exit") == 0) {  // 修复：替换==
            printf("继续循环...\n");
            continue;
        } else if (strcmp(order, "Quit") == 0) {  // 修复：替换==
            printf("程序退出\n");
            exit(0);
        } else {
            printf("未知命令，请重新输入\n");
        }
    }
    return 0;
}
