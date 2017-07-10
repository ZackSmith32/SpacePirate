#include <iostream>
#include <ncurses.h>
#include <menu.h>
#include "header.hpp"

// int Drawable::difficulty = 0;

int	menu(void) {
	int max_x;
	int max_y;
	int i, c;
	int	n_choices = 3;
	ITEM **my_items;
	MENU *my_menu;
	WINDOW *my_menu_win;
	char const	* const choices[3] = {
							"Easy",
							"Medium",
							"Hard",
						};
	
	getmaxyx(stdscr, max_y, max_x);
	my_items = (ITEM **)calloc(n_choices + 1, sizeof(ITEM *));
	for ( i = 0; i < n_choices; i++)
		my_items[i] = new_item("-", choices[i]);		
	my_items[n_choices] = (ITEM *)NULL;

	my_menu = new_menu((ITEM **)my_items);
	
	/* Menu size and location */
	my_menu_win = newwin(10, 40, max_y / 2 - 20, max_x / 3);
	keypad(my_menu_win, TRUE);

	/* Set main window and sub window */
	set_menu_win(my_menu, my_menu_win);
	set_menu_sub(my_menu, derwin(my_menu_win, 6, 38, 3, 1));
	set_menu_mark(my_menu, " * ");

	/* Print a border around the main window and print a title */
	char const *menu_name = "Space Pirate";
	char const *enter_start = "Press Enter to Start";
	box(my_menu_win, 0, 0);
	print_in_middle(my_menu_win, 1, 0, 40, (char*)menu_name, COLOR_PAIR(1));
	print_in_middle(my_menu_win, 8, 0, 40, (char*)enter_start, COLOR_PAIR(1));
	mvwaddch(my_menu_win, 2, 0, ACS_LTEE);
	mvwhline(my_menu_win, 2, 1, ACS_HLINE, 38);
	mvwaddch(my_menu_win, 2, 39, ACS_RTEE);
	mvprintw(LINES - 2, 0, "F1 to exit");
	refresh();
	mvprintw(LINES - 2, 0, "F1 to Exit");
	
	post_menu(my_menu);
	wrefresh(my_menu_win);
	int selection = 0;
	int difficulty = 0;
	while((c = wgetch(my_menu_win)) != KEY_F(1))
	{       
		switch(c)
		{	
	        case KEY_DOWN:
				menu_driver(my_menu, REQ_DOWN_ITEM);
				break;
			case KEY_UP:
				menu_driver(my_menu, REQ_UP_ITEM);
				break;
			case 10: /* Enter */
			{	
				ITEM *cur;
				cur = current_item(my_menu);
				difficulty = item_index(cur) + 1;
				selection = 1;
				break;
			}
			break;
		}
		if (selection)
			break;
        wrefresh(my_menu_win);
	}	
	unpost_menu(my_menu);
	free_menu(my_menu);
	for(i = 0; i < n_choices; ++i)
		free_item(my_items[i]);
	return difficulty;
}


void print_in_middle(WINDOW *win, int starty, int startx,
						int width, char *string, chtype color)
{	int length, x, y;
	float temp;

	if(win == NULL)
		win = stdscr;
	getyx(win, y, x);
	if(startx != 0)
		x = startx;
	if(starty != 0)
		y = starty;
	if(width == 0)
		width = 80;

	length = strlen(string);
	temp = (width - length)/ 2;
	x = startx + (int)temp;
	wattron(win, color);
	mvwprintw(win, y, x, "%s", string);
	wattroff(win, color);
	refresh();
}




























