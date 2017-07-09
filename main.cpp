int main (void)
{
	initscr();
	noecho();
	keypad(stdscr, TRUE);
	curs_set(0);
	nodelay(stdscr, TRUE);
	Player p;
	Bullet b(10, 0, 1);
	while(1)
	{
		Drawable::move_all();
		Drawable::draw_all();
		refresh();
		clear();
		usleep(60);
	}
	endwin();
	return 0;
}