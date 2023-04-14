CFLAGS = -Wall -Werror

CC     = gcc

SA     = stack_array
SL     = stack_list

ALL: $(SA) $(SL)

$(SA):  main_stack_array.o stack_array.o
		$(CC) $^ $(CFLAGS) -o $@

$(SL):  main_stack_list.o stack_list.o
		$(CC) $^ $(CFLAGS) -o $@

%.o: %.c
		$(CC) -c $< $(CFLAGS) -o $@
