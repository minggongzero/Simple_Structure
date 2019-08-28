source = $(wildcard *.cpp)
obj = $(patsubst %.cpp, %.o, $(source))
CLASF = -Wall -g
target = main

$(target): $(obj)
	g++ $(CLASF) -o $@ $^

%.o: %.cpp
	g++ $(CLASF) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(obj) $(target)
