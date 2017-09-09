OBJECTS = inverse.o \
		  linspace.o \
		  meshgrid.o \
		  gdatav4.o \
		  BiharmonicSplineInterp.o \
		  main.o

BiharmonicSplineInterpolation : $(OBJECTS)
	g++ -o BiharmonicSplineInterpolation $(OBJECTS)

$(OBJECTS) : BiharmonicSplineInterp.h

.PHONY : clean
clean :
	-rm BiharmonicSplineInterpolation $(OBJECTS)

.PHONY : cleanw32
cleanw32 :
	-del BiharmonicSplineInterpolation.exe $(OBJECTS)
