#include "push_swap.h"

void arg_validation(int argc, char *argv[])
{
    int i = 1;
    int j;

    while (i < argc)
    {
        j = 0;
        while (argv[i][j])
        {
            if (argv[i][j] == '+' || argv[i][j] == '-')
            {
                if (argv[i][j + 1] >= '0' && argv[i][j + 1] <= '9')
                    j++;
                else
                    err_message("+- 형식 유효성");
            }
            else if ((argv[i][j] >= '0' && argv[i][j] <= '9') || argv[i][j] == ' ')
                j++;
            else
                err_message("일반 유효성");
        }
        i++;
    }
}

void convert(t_stack *a_stack, char *str)
{
    int i = 0;
    int j;
    int num;
    int len = ft_strlen(str);

    while (i < len)
    {
        j = 0;
        while (str[i] == ' ')
            i++;
        while (str[i + j] != '\0' && str[i + j != ' '])
            j++;
        num = ftpw_atoi(&str[i], j);
        push_bottom(a_stack, num);
        i = i + j;
        i++;
    }
}

void arg_convert(int argc, char *argv[], t_stack *a_stack)
{
    int i = 1;
    int len;

    while (i < argc)
    {
        len = ft_strlen(argv[i]);
        if (len == 0)
            err_message("인자값 미입력");
        else
            convert(a_stack, argv[i]);
        i++;
    }
}

void check_duplicate(t_stack *a_stack)
{
    int temp;
    t_node *i = a_stack->top;
    t_node *j;

    while (i)
    {
        temp = i->data;
        j = i->prev;

        while (j)
        {
            if (temp == j->data)
            {
                clear(a_stack);
                err_message("중복값 입력");
            }
            j = j->prev;
        }
        i = i->prev;
    }
}

int main(int argc, char *argv[])
{
    // 스택 자료구조 생성 (사실상 덱)
    t_stack *a_stack = stack_init();
    t_stack *b_stack = stack_init();

    if (argc < 2)
        return 0;

    arg_validation(argc, argv);       // 입력값 유효성 검사
    arg_convert(argc, argv, a_stack); // 숫자 문자열 변환
    check_duplicate(a_stack);         // 중복값 체크
    atob(a_stack, b_stack);
    clear(a_stack);
    clear(b_stack);
    return 0;
}