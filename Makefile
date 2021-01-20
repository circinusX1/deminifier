CXX=${CROSS_COMPILE}g++
src = $(wildcard *.cpp)
obj = $(src:.cpp=.o)

deminiif: $(obj)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(obj) deminiff



