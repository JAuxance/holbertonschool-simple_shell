#include <ncurses.h>
#include <locale.h>
#include <string.h>

int main(void)
{
    char buffer[256];
    int i, ch;
    int start_y, start_x;

    setlocale(LC_ALL, "");
    initscr();
    cbreak();
    noecho();                 // ⬅️ IMPORTANT
    keypad(stdscr, TRUE);
    set_escdelay(25);
    curs_set(1);

    while (1)
    {
        memset(buffer, 0, sizeof(buffer));
        i = 0;

        clear();
        printw("☾ - ");
        getyx(stdscr, start_y, start_x);   // position protégée
        refresh();

        while (1)
        {
            ch = getch();

            /* ENTER */
            if (ch == '\n')
                break;

            /* BACKSPACE */
            if (ch == KEY_BACKSPACE || ch == 127)
            {
                int y, x;
                getyx(stdscr, y, x);

                if (x > start_x && i > 0)
                {
                    i--;
                    buffer[i] = '\0';
                    mvdelch(y, x - 1);
                    move(y, x - 1);
                }
                continue;
            }

            /* Alt + e */
            if (ch == 27)
            {
                int next = getch();
                if (next == 'e')
                    goto exit_shell;
                continue;
            }

            /* caractères imprimables uniquement */
            if (ch >= 32 && ch <= 126 && i < 255)
            {
                buffer[i++] = ch;
                addch(ch);
            }
        }

        if (strcmp(buffer, "exit") == 0 || strcmp(buffer, "!kill") == 0)
            break;

        printw("\nCommande inconnue : %s", buffer);
        printw("\nAppuie sur une touche...");
        refresh();
        getch();
    }

exit_shell:
    endwin();
    return 0;
}
