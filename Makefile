all: hello-cpp-world hello-c-world depth_search

%: %.cc
	g++ -std=c++11 $< -o $@

%: %.c
	gcc $< -o $@

clean:
	rm -f hello-c-world hello-cpp-world depth_search
