Program Description:
	This program is designed to find all sets of FIRST(X) and FOLLOW(X)
	given a grammer. The program uses the algorithm that was given in the
	CSE 570/670 website. FIRST and FOLLOW are maps that uses the non-terminal
	as a key which contains the set that is produced by their respective
	algorithms. The parsing of the grammer initially maps the terminals to FIRST, and
	then it parses the productions which gets stored into a set. 


Run the program by entering:
	
	make grammer

and then to execute the program, enter:

	./grammer
