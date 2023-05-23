# SystemC definitions
SYSTEMCTOPFILE = factorial_cpp

# CHANGE TO YOUR OWN SYSTEMC_HOME
SYSTEMC_HOME ?= /opt/systemc-2.3.4
SYSTEMC_CFLAGS ?= -DSC_INCLUDE_FX -Wl,-rpath=${SYSTEMC_HOME}/lib64 -std=c++14
SYSTEMC_LIBS ?= -L${SYSTEMC_HOME}/lib64 -lsystemc
SYSTEMC_INCLUDES ?= -I${SYSTEMC_HOME}/include

# C++ Compiler definitions, default to Linux environments
CPPFLAGS = g++ ${SYSTEMC_CFLAGS}
LIBS = -L. -lm ${SYSTEMC_LIBS}
INCLUDES = -I. ${SYSTEMC_INCLUDES}

SOURCES = ${SYSTEMCTOPFILE}.cpp  sourcesink.cpp main.cpp
OUTPUT_FILE = ${SYSTEMCTOPFILE}.syscexe

all: systemverilog

systemverilog: FactorialBlk_TB.sv FactorialBlk.sv
	iverilog -y . -Y .sv -g2012 -o simul.iverout FactorialBlk_TB.sv
	@vvp simul.iverout -lxt2

sc: sc_compile sc_run

sc_compile: ${SOURCES}
	${CPPFLAGS} ${INCLUDES} ${LIBS} ${SOURCES} -o ${OUTPUT_FILE}

sc_run:
	./${OUTPUT_FILE}

clean:
	rm *.iverout
	rm ${OUTPUT_FILE}