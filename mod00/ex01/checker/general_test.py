import random
import sys
from rich.live import Live
import threading

import test_logs
from animation import loading_animation
import test_library
import test_exec

INT_MAX = 2147483647
INT_MIN = -2147483648
stop_event = threading.Event()

def tester(inputs, test_nbr):
	message = "Test: " + str(test_nbr + 1)
	test_logs.append_to_test_file(message)
	test_logs.append_to_test_file("Input: " + str(inputs))
	stop_event.clear()
	animation_thread = threading.Thread(target=loading_animation, args=(stop_event, message))
	animation_thread.start()
	result = test_exec.push_swap_prog(inputs)
	test_logs.append_to_test_file("\n\n")

	stop_event.set()
	animation_thread.join()
	if result == 0:
		sys.stdout.write("\033[F\033[2K")
		with Live ("", refresh_per_second=10) as live:
			live.update(f"{message} ✅")
	else:
		sys.stdout.write("\033[F\033[2K")
		with Live ("", refresh_per_second=10) as live:
			live.update(f"{message} ❌")

def general_test():
	test_exec.make_prog()
	test_nbr = 0
	test_logs.append_to_test_file("TEST TWO INPUTS")
	test_logs.append_to_test_file("\n\n") 

	test_logs.append_to_test_file("TEST THREE INPUTS") 
	test_logs.append_to_test_file("\n\n") 

	test_logs.append_to_test_file("TEST INT_MAX/INT_MIN") 
	test_logs.append_to_test_file("\n\n") 

