import test_logs as test_logs
import shell_printing as sp
from general_test import general_test as gn

TEXT_MENU = 1
TEXT_SELECT = 2
TEXT_BUILDING = 3
TEXT_QUIT = 42

def menu():	
	sp.print_centered_title("GENIUS TESTS")
	sp.print_text(TEXT_MENU)
	choice = sp.print_text(TEXT_SELECT)

	print("\n")
	if choice == "1":
		gn.general_test()
	elif choice == "2":
		sp.print_text(3)
	elif choice == "3":
		sp.print_text(TEXT_QUIT)
	return 0


if __name__ == "__main__":
	test_logs.create_folder()
	test_logs.create_test_file()
	menu()
	