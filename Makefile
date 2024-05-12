all:
	g++ linear_regression.cpp -o linear_regression -std=c++11

fclean:
	rm -f linear_regression

run: all
	./linear_regression data.csv price

install_python:
	pip3 install pandas
	pip3 install scikit-learn

reset_file:
	g++ reset_file.cpp -o reset_file -std=c++11
	./reset_file
	rm -f reset_file