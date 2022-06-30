#include <func.h>

// 将标准输出重定向到log1文件，标准错误输出重定向到log2文件。
int main(int argc, char* argv[])
{
    Error_Unequal_Check(argc, 3, "Error argument.");
    
    // open files
    int log1 = open(argv[1], O_RDWR | O_CREAT | O_TRUNC, 0775);
    Error_Equal_Check(log1, -1, "open");
    int log2 = open(argv[2], O_RDWR | O_CREAT | O_TRUNC, 0775);
    Error_Equal_Check(log2, -1, "open");
    
    // redirect log1
    int ret_log1 = dup2(log1, STDOUT_FILENO);
    Error_Equal_Check(ret_log1, -1, "dup2");
    int ret_log2 = dup2(log2, STDERR_FILENO);
    Error_Equal_Check(ret_log2, -1, "dup2");

    // test
    puts("log1: you are so pretty.");
    fprintf(stderr,"%s","log2: Hello Kitty\n.");

    return 0;
}

