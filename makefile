all:
	@clear
	@g++ main.cpp -o exeMain
	@./exeMain < entrada.in
	@rm exeMain